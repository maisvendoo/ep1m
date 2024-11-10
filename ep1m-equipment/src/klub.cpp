#include    "klub.h"

#include    <QTextStream>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
KLUB::KLUB(QObject *parent) : Device(parent)
{
    epk_state.set();

    connect(safety_timer, &Timer::process, this, &KLUB::onSafetyTimer);
    connect(beepTimer, &Timer::process, this, &KLUB::onBeepTimer);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
KLUB::~KLUB()
{

}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::step(double t, double dt)
{
    safety_timer->step(t, dt);
    beepTimer->step(t, dt);

    calc_acceleration(t, dt);

    Device::step(t, dt);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::loadStationsMap(QString path)
{
    QFile stations_file(path);

    if (!stations_file.open(QIODevice::ReadOnly))
    {
        return;
    }

    QTextStream stream(&stations_file);

    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        QStringList tokens = line.split('\t');

        station_t station;
        station.name = tokens[0];
        station.coord.x = tokens[1].toDouble();
        station.coord.y = tokens[2].toDouble();
        station.coord.z = tokens[3].toDouble();

        stations.push_back(station);
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
QString KLUB::getStationText() const
{
    QString tmp = station_text;
    tmp.resize(STATION_MAX_SYMBOLS, QChar(' '));
    return tmp;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
QString KLUB::getInfoText() const
{
    QString tmp = info_text;
    tmp.resize(INFO_MAX_SYMBOLS, QChar(' '));
    return tmp;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::preStep(state_vector_t &Y, double t)
{
    Q_UNUSED(Y);
    Q_UNUSED(t);

    // Очищаем состояние ламп
    std::fill(lamps.begin(), lamps.end(), 0.0f);

    // Ничего не делаем при выключенном питании
    if (hs_n(U_pow - 0.95 * U_nom))
    {
        is_red.reset();
        is_dislplay_ON = false;
        is_trac_allowed = false;
        station_text = "";
        info_text = "";
        return;
    }

    is_dislplay_ON = true;
    is_trac_allowed = true;

    stations_process();

    // ТЕСТОВАЯ ЗАГЛУШКА
    info_text = "светофор-(test)литер нм1";

    speed_control();

    // Ничего не делаем при выключенном ЭПК
    if (!key_epk)
    {
        if (v_kmh > 1.0)
            epk_state.reset();

        if (code_alsn == ALSN::RED_YELLOW)
            epk_state.reset();

        key_epk_old = false;
        is_red.reset();

        return;
    }

    if (code_alsn < old_code_alsn)
    {
        epk_state.reset();
        safety_timer->stop();
    }

    if (is_red.getState())
    {
        lamps[RED_LAMP] = 1.0f;
        check_vigilance = true;
        epk_state.reset();
        is_trac_allowed = false;
        safety_timer->stop();
        return;
    }

    alsn_process(code_alsn);

    if (code_alsn == ALSN::RED_YELLOW)
    {
        if (v_kmh > 60.0)
        {
            epk_state.reset();
            return;
        }

        if (v_kmh > 5)
        {
            if (!safety_timer->isStarted())
                safety_timer->start();
        }
        else
        {
            safety_timer->stop();
        }
    }

    if (code_alsn == ALSN::YELLOW)
    {
        if (v_kmh > 60.0)
        {
            if (!safety_timer->isStarted())
                safety_timer->start();
        }
        else
        {
            safety_timer->stop();
        }
    }

    if (state_RB || state_RBS)
    {
        epk_state.set();
        safety_timer->stop();
    }

    check_vigilance = !epk_state.getState();

    sounds_process();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::ode_system(const state_vector_t &Y,
                      state_vector_t &dYdt,
                      double t)
{
    Q_UNUSED(Y);
    Q_UNUSED(dYdt);
    Q_UNUSED(t);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::load_config(CfgReader &cfg)
{
    QString secName = "Device";

    double safety_check_interval = 45.0;

    cfg.getDouble(secName, "SafetyCheckInterval", safety_check_interval);

    safety_timer->setTimeout(safety_check_interval);

    //cfg.getDouble(secName, "BeepInterval", beep_interval);

    //beepTimer->setTimeout(beep_interval);
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::alsn_process(ALSN code_alsn)
{
    switch (code_alsn)
    {
    case ALSN::NO_CODE:
        {
            if (old_code_alsn == ALSN::RED_YELLOW)
            {
                lamps[RED_LAMP] = 1.0f;
                is_red.set();
            }
            else
            {
                if (!is_red.getState())
                    lamps[WHITE_LAMP] = 1.0f;
            }

            break;
        }
    case ALSN::RED_YELLOW:
        {
            lamps[RED_YELLOW_LAMP] = 1.0f;

            break;
        }

    case ALSN::YELLOW:
        {
            lamps[YELLOW_LAMP] = 1.0f;

            break;
        }

    case ALSN::GREEN:
        {
            lamps[GREEN_LAMP1] = 1.0f;

            break;
        }
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::sounds_process()
{
    if ( (state_RB && (!state_RB_old)) ||
         (state_RB_old && (!state_RB)) )
    {
        sound_states[BUTTON_SOUND].play(true);
    }

    if ( (state_RBS && (!state_RBS_old)) ||
         (state_RBS_old && (!state_RBS)) )
    {
        sound_states[BUTTON_SOUND].play(true);
    }

    if (key_epk && !key_epk_old)
    {
        sound_states[ON_SOUND].play(true);
    }

    state_RB_old = state_RB;
    state_RBS_old = state_RBS;
    key_epk_old = key_epk;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::calc_acceleration(double t, double dt)
{
    Q_UNUSED(t)

    if (v < 1e-4)
    {
        acceleration = 0;
        return;
    }

    if (t_diff >= delta_t)
    {
        v_i[v_count] = v;
        t_diff = 0;
        v_count++;
    }

    if (v_count >= v_i.size())
    {
        v_count = 0;
        t_diff = 0;

        acceleration = (3 * v_i[2] - 4 * v_i[1] + v_i[0]) / 2.0 / delta_t;
    }

    t_diff += dt;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::speed_control()
{
    calc_speed_limits();

    int V_kmh = qRound(v_kmh);

    if (V_kmh <= current_limit - 3)
    {
        beepTimer->stop();
    }
    else
    {
        if (!beepTimer->isStarted())
            beepTimer->start();
    }

    if (V_kmh > current_limit)
    {
        epk_state.reset();
    }
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::calc_speed_limits()
{
    if (!key_epk)
    {
        current_limit = v_max;
        next_limit = v_max;
        return;
    }

    current_limit = speedmap->getCurrentLimit();
    next_limit = speedmap->getNextLimit();

    double v_lim = v_max;
    if (current_limit > next_limit)
    {
        double a = 0.7;
        target_dist = speedmap->getNextLimitDistance();
        v_lim = sqrt( pow(next_limit / Physics::kmh, 2) + 2 * a * target_dist) * Physics::kmh;
    }

    current_limit = min(v_lim, current_limit) + 1;
    next_limit = min(v_max, next_limit) + 1;
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::stations_process()
{
    station_idx = -1;
    if (stations.empty())
        return;

    double min_distance = station_search_radius;
    for (size_t i = 0; i < stations.size(); ++i)
    {
        double distance = length(coord - stations[i].coord);
        if (min_distance > distance)
        {
            min_distance = distance;
            station_idx = i;
        }
    }
    if (station_idx >= 0)
        station_text = stations[station_idx].name;
    else
        station_text = "";
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::onSafetyTimer()
{
    epk_state.reset();
}

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
void KLUB::onBeepTimer()
{
    sound_states[BUTTON_SOUND].play(true);
}
