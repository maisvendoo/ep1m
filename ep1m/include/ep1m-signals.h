#ifndef     EP1M_SIGNALS_H
#define     EP1M_SIGNALS_H

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    SIGNAL_UNLOCK_KEY = 0, // Ключ блокировки тумблеров

    // Тумблеры блока выключателей
    SIGNAL_TUMBLER_MSUD = 1, // МСУД
    SIGNAL_TUMBLER_LOCK_VVK = 2, // Блокирование ВВК
    SIGNAL_TUMBLER_PANT1 = 3, // Токоприемник 1
    SIGNAL_TUMBLER_PANT2 = 4, // Токоприемник 2
    SIGNAL_TUMBLER_RETURN_PROTECTION = 5, // Возврат защиты ГВ
    SIGNAL_TUMBLER_MAIN_SWITCH = 6, // Главный выключатель

    SIGNAL_TUMBLER_AUX_MACHINES = 7, // Вспомогательные машины
    SIGNAL_TUMBLER_COMPRESSOR = 8, // Компрессор
    SIGNAL_TUMBLER_MOTOR_FAN1 = 9, // Вентилятор 1
    SIGNAL_TUMBLER_MOTOR_FAN2 = 10, // Вентилятор 2
    SIGNAL_TUMBLER_MOTOR_FAN3 = 11, // Вентилятор 3
    SIGNAL_TUMBLER_EPT = 12, // ЭПТ

    // КЛУБ-У
    SIGNAL_KLUB_U_POWER_SUPPLAY = 50,   // питание
    SIGNAL_KLUB_U_EPK           = 51,   // ЭПК
    SIGNAL_KLUB_U_ALSN          = 52,   // код АЛСН
    SIGNAL_KLUB_U_ALSN_FB       = 53,   // кол-во свободных БУ
    SIGNAL_KLUB_U_COORDINATE    = 54,
    SIGNAL_KLUB_U_STATION_NUM   = 55,
    SIGNAL_KLUB_U_BDITELNOST    = 56,
    SIGNAL_KLUB_U_M             = 57,
    SIGNAL_KLUB_U_P             = 58,
    SIGNAL_KLUB_U_CASSETE       = 59,
    SIGNAL_KLUB_U_SPEED         = 60,
    SIGNAL_KLUB_U_SPEED_LIMIT   = 61,
    SIGNAL_KLUB_U_SPEED_LIMIT_2 = 62,
    SIGNAL_KLUB_U_REVERSOR      = 63,
    SIGNAL_KLUB_U_TARGET_DIST   = 64,
    SIGNAL_KLUB_U_TARGET_NAME   = 65,
    SIGNAL_KLUB_U_PRESSURE_TM   = 66,
    SIGNAL_KLUB_U_PRESSURE_UR   = 67,
    SIGNAL_KLUB_U_ACCELERATION  = 68,
    SIGNAL_KLUB_U_ZAPRET_OTPUSKA= 69,


    // Колесные пары
    SIGNAL_WHEEL1 = 194, // Колесная пара 1
    SIGNAL_WHEEL2 = 195, // Колесная пара 2
    SIGNAL_WHEEL3 = 196, // Колесная пара 3
    SIGNAL_WHEEL4 = 197, // Колесная пара 4
    SIGNAL_WHEEL5 = 198, // Колесная пара 5
    SIGNAL_WHEEL6 = 199  // Колесная пара 6
};

#endif // EP1M_SIGNALS_H
