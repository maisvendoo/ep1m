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

    RUK_395 = 20,

    STRELKA_TM = 21,
    STRELKA_UR = 22,
    STRELKA_GR = 23,
    STRELKA_TC = 24,

    SIGNAL_TUMBLER_LOCK_VVK = 31, // Блокирование ВВК
    SIGNAL_TUMBLER_PANT1 = 32, // Токоприемник 1
    SIGNAL_TUMBLER_PANT2 = 33, // Токоприемник 2
    SIGNAL_TUMBLER_RETURN_PROTECTION = 35, // Возврат защиты ГВ
    SIGNAL_TUMBLER_MAIN_SWITCH = 36, // Главный выключатель

    SIGNAL_PANT1 = 40, // Передний токоприемник
    SIGNAL_PANT2 = 41, // Задний токоприемник

    LAMP_GV = 42,

    LAMP_MK1 = 50,
    LAMP_MK2 = 51,
    LAMP_MV1 = 52,
    LAMP_MV2 = 53,
    LAMP_MV3 = 54,

    SIGNAL_TUMBLER_AUX_MACHINES = 65, // Вспомогательные машины
    SIGNAL_TUMBLER_COMPRESSOR = 66, // Компрессор
    SIGNAL_TUMBLER_MOTOR_FAN1 = 67, // Вентилятор 1
    SIGNAL_TUMBLER_MOTOR_FAN2 = 68, // Вентилятор 2
    SIGNAL_TUMBLER_MOTOR_FAN3 = 69, // Вентилятор 3

    STRELKA_U_KS = 98, // Напряжение КС

    SIGNAL_TUMBLER_EPT = 100, // ЭПТ

    SIGNAL_REVERS = 101, // Реверсивка
    SIGNAL_KONTROLLER = 102, // Главная рукоятка КМ

    // КЛУБ-У
    SIGNAL_KLUB_U_POWER_SUPPLAY = 150,   // питание
    SIGNAL_KLUB_U_EPK           = 151,   // ЭПК
    SIGNAL_KLUB_U_ALSN          = 152,   // код АЛСН
    SIGNAL_KLUB_U_ALSN_FB       = 153,   // кол-во свободных БУ
    SIGNAL_KLUB_U_COORDINATE    = 154,
    SIGNAL_KLUB_U_STATION_NUM   = 155,
    SIGNAL_KLUB_U_BDITELNOST    = 156,
    SIGNAL_KLUB_U_M             = 157,
    SIGNAL_KLUB_U_P             = 158,
    SIGNAL_KLUB_U_CASSETE       = 159,
    SIGNAL_KLUB_U_SPEED         = 160,
    SIGNAL_KLUB_U_SPEED_LIMIT   = 161,
    SIGNAL_KLUB_U_SPEED_LIMIT_2 = 162,
    SIGNAL_KLUB_U_REVERSOR      = 163,
    SIGNAL_KLUB_U_TARGET_DIST   = 164,
    SIGNAL_KLUB_U_TARGET_NAME   = 165,
    SIGNAL_KLUB_U_PRESSURE_TM   = 166,
    SIGNAL_KLUB_U_PRESSURE_UR   = 167,
    SIGNAL_KLUB_U_ACCELERATION  = 168,
    SIGNAL_KLUB_U_ZAPRET_OTPUSKA= 169,

    // МСУД
    SIGNAL_MSUD_MODE            = 170, // авторег/ручное
    SIGNAL_MSUD_TC              = 171,
    SIGNAL_MSUD_DB              = 172,
    SIGNAL_MSUD_MK              = 173,
    SIGNAL_MSUD_DM              = 174,
    SIGNAL_MSUD_NC              = 175,
    SIGNAL_MSUD_OB              = 176,
    SIGNAL_MSUD_KZ              = 177,
    SIGNAL_MSUD_OV              = 178,
    SIGNAL_MSUD_MPK             = 179,
    SIGNAL_MSUD_REVERSOR        = 180, // вперед/назад
    SIGNAL_MSUD_TRACTION_TYPE   = 181, // тяга/рекуперация
    SIGNAL_MSUD_TRACTION_STATE  = 182, // собрана/разобрана
    SIGNAL_MSUD_TRACTION        = 183, // Тяга
    SIGNAL_MSUD_CURCUIT_VOZB    = 184, // Ток возбуждения
    SIGNAL_MSUD_SPEED1          = 185, // Скорость
    SIGNAL_MSUD_SPEED2          = 186, //
    SIGNAL_MSUD_CURRENT_ANHCOR1 = 187, // Ток якоря
    SIGNAL_MSUD_CURRENT_ANHCOR2 = 188, //
    SIGNAL_MSUD_CURRENT_EPT     = 189, // ТОК ЭПТ
    SIGNAL_MSUD_VOLTAGE_EPT     = 190, // НАПРЯЖЕНИЕ ЭПТ
    SIGNAL_MSUD_OSLAB_POLE1     = 191, // Ослбаление поля 1
    SIGNAL_MSUD_OSLAB_POLE2     = 192, // Ослбаление поля 2
    SIGNAL_MSUD_OSLAB_POLE3     = 193, // Ослбаление поля 3



    // Колесные пары
    SIGNAL_WHEEL1 = 194, // Колесная пара 1
    SIGNAL_WHEEL2 = 195, // Колесная пара 2
    SIGNAL_WHEEL3 = 196, // Колесная пара 3
    SIGNAL_WHEEL4 = 197, // Колесная пара 4
    SIGNAL_WHEEL5 = 198, // Колесная пара 5
    SIGNAL_WHEEL6 = 199  // Колесная пара 6
};

#endif // EP1M_SIGNALS_H
