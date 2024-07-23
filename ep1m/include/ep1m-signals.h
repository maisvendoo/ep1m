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

    REF_SPEED = 3,

    // РБ
    RB1 = 4,

    // РБС
    RBS = 5,

    STRELKA_EPT_AMP = 10,

    LAMP_TC3 = 12,
    LAMP_TC2 = 13,
    LAMP_TC1 = 14,

    SIGNAL_TUMBLER_PCHF = 15,
    SIGNAL_TUMBLER_SIGNAL_PANEL = 16,
    SIGNAL_TUMBLER_AUTO_MODE = 17,
    SIGNAL_TUMBLER_MPK = 18,

    LAMP_NCH = 19,

    RUK_395 = 20,

    STRELKA_TM = 21,
    STRELKA_UR = 22,
    STRELKA_GR = 23,
    STRELKA_TC = 24,

    KVT215_AXIS = 29,
    KVT215_RUK = 30,

    SIGNAL_TUMBLER_LOCK_VVK = 31, // Блокирование ВВК
    SIGNAL_TUMBLER_PANT1 = 32, // Токоприемник 1
    SIGNAL_TUMBLER_PANT2 = 33, // Токоприемник 2
    SIGNAL_TUMBLER_RETURN_PROTECTION = 35, // Возврат защиты ГВ
    SIGNAL_TUMBLER_MAIN_SWITCH = 36, // Главный выключатель

    SIGNAL_PANT1 = 40, // Передний токоприемник
    SIGNAL_PANT2 = 41, // Задний токоприемник

    LAMP_GV = 42,

    LAMP_EPT_O = 44,
    LAMP_EPT_P = 45,
    LAMP_EPT_T = 46,

    LAMP_MK1 = 50,
    LAMP_MK2 = 51,
    LAMP_MV1 = 52,
    LAMP_MV2 = 53,
    LAMP_MV3 = 54,

    LAMP_TD1 = 55,
    LAMP_TD2 = 56,
    LAMP_TD3 = 57,
    LAMP_TD4 = 58,
    LAMP_TD5 = 59,
    LAMP_TD6 = 60,
    LAMP_DM1 = 61,
    LAMP_DM2 = 62,

    BUTTON_SVISTOK = 63,
    BUTTON_TIFON = 64,

    SIGNAL_TUMBLER_AUX_MACHINES = 65, // Вспомогательные машины
    SIGNAL_TUMBLER_COMPRESSOR = 66, // Компрессор
    SIGNAL_TUMBLER_MOTOR_FAN1 = 67, // Вентилятор 1
    SIGNAL_TUMBLER_MOTOR_FAN2 = 68, // Вентилятор 2
    SIGNAL_TUMBLER_MOTOR_FAN3 = 69, // Вентилятор 3

    BUTTON_BRAKE_RELEASE = 70, // Кнопка "Отпуск тормозов"

    STRELKA_I_TED = 97, // Ток якоря тяговых двигателей
    STRELKA_U_KS = 98, // Напряжение КС

    STRELKA_EPT_VOLT = 99,

    SIGNAL_TUMBLER_EPT = 100, // ЭПТ

    SIGNAL_REVERS = 101, // Реверсивка
    SIGNAL_KONTROLLER = 102, // Главная рукоятка КМ

    // КЛУБ-У
    SIGNAL_KLUB_U_ZAPRET_OTPUSKA= 149,
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

    // МСУД
    SIGNAL_MSUD_POWER_SUPPLAY   = 169,
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
    SIGNAL_MSUD_VIP_ZONE        = 96,  // Зона ВИП



    // Колесные пары
    SIGNAL_WHEEL1 = 194, // Колесная пара 1
    SIGNAL_WHEEL2 = 195, // Колесная пара 2
    SIGNAL_WHEEL3 = 196, // Колесная пара 3
    SIGNAL_WHEEL4 = 197, // Колесная пара 4
    SIGNAL_WHEEL5 = 198, // Колесная пара 5
    SIGNAL_WHEEL6 = 199,  // Колесная пара 6

    // Звуки
    SOUND_SVISTOK = 201,
    SOUND_TIFON = 202,

    SOUND_REVERSOR = 203,
    SOUND_CONTROLLER = 204,

    SOUND_BRAKE_LOCK_CHANGE_LOCK_POS = 208,
    SOUND_BRAKE_LOCK_CHANGE_COMB_POS = 209,
    SOUND_BRAKE_LOCK_BP_DRAIN_FLOW = 210,
    SOUND_BRAKE_CRANE_CHANGE_POS = 211,
    SOUND_BRAKE_CRANE_ER_STAB_FLOW = 212,
    SOUND_BRAKE_CRANE_ER_FILL_FLOW = 213,
    SOUND_BRAKE_CRANE_ER_DRAIN_FLOW = 214,
    SOUND_BRAKE_CRANE_BP_FILL_FLOW = 215,
    SOUND_BRAKE_CRANE_BP_DRAIN_FLOW = 216,
    SOUND_LOCO_CRANE_CHANGE_POS = 217,
    SOUND_LOCO_CRANE_BC_FILL_FLOW = 218,
    SOUND_LOCO_CRANE_BC_DRAIN_FLOW = 219,

    SOUND_TUMBLER_MSUD_ON = 220,
    SOUND_TUMBLER_MSUD_OFF = 221,
    SOUND_TUMBLER_LOCK_VVK_ON = 222,
    SOUND_TUMBLER_LOCK_VVK_OFF = 223,
    SOUND_TUMBLER_PANT1_ON = 224,
    SOUND_TUMBLER_PANT1_OFF = 225,
    SOUND_TUMBLER_PANT2_ON = 226,
    SOUND_TUMBLER_PANT2_OFF = 227,
    SOUND_TUMBLER_RETURN_PROTECTION_ON = 228,
    SOUND_TUMBLER_RETURN_PROTECTION_OFF = 229,
    SOUND_TUMBLER_MAIN_SWITCH_ON = 230,
    SOUND_TUMBLER_MAIN_SWITCH_OFF = 231,
    SOUND_TUMBLER_AUX_MACHINES_ON = 232,
    SOUND_TUMBLER_AUX_MACHINES_OFF = 233,
    SOUND_TUMBLER_COMPRESSOR_ON = 234,
    SOUND_TUMBLER_COMPRESSOR_OFF = 235,
    SOUND_TUMBLER_MOTOR_FAN1_ON = 236,
    SOUND_TUMBLER_MOTOR_FAN1_OFF = 237,
    SOUND_TUMBLER_MOTOR_FAN2_ON = 238,
    SOUND_TUMBLER_MOTOR_FAN2_OFF = 239,
    SOUND_TUMBLER_MOTOR_FAN3_ON = 240,
    SOUND_TUMBLER_MOTOR_FAN3_OFF = 241,
    SOUND_TUMBLER_EPT_ON = 242,
    SOUND_TUMBLER_EPT_OFF = 243,

    SOUND_TRANSFORMER = 244,

    SOUND_FAN1_LOW = 245,
    SOUND_FAN1_HIGH = 246,
    SOUND_FAN2_LOW = 247,
    SOUND_FAN2_HIGH = 248,
    SOUND_FAN3_LOW = 249,
    SOUND_FAN3_HIGH = 250,
    SOUND_FAN4 = 251,

    SOUND_TUMBLER_PCHF_ON = 252,
    SOUND_TUMBLER_PCHF_OFF = 253,
    SOUND_TUMBLER_SIGNALING_ON = 254,
    SOUND_TUMBLER_SIGNALING_OFF = 255,
    SOUND_TUMBLER_AUTOREG_ON = 256,
    SOUND_TUMBLER_AUTOREG_OFF = 257,
    SOUND_TUMBLER_MPK_ON = 258,
    SOUND_TUMBLER_MPK_OFF = 259,

    SOUND_COMPRESSOR = 260,
    SOUND_PANT2_UP = 261,
    SOUND_PANT2_DOWN = 262,
    SOUND_PANT1_UP = 263,
    SOUND_PANT1_DOWN = 264,

    SOUND_MAIN_SWITCH_ON = 265,
    SOUND_MAIN_SWITCH_OFF = 266,

    SOUND_EPK_KEY_ON = 267,
    SOUND_EPK_KEY_OFF = 268,

    SOUND_KM5 = 269,
    SOUND_VZ6 = 270,
    SOUND_KV44 = 271,
    SOUND_KV39 = 272,
    SOUND_KV21 = 273,
    SOUND_KV22 = 274,
    SOUND_KV23 = 275,
    SOUND_KV41 = 276,
    SOUND_KM7 = 277,
    SOUND_KM8 = 278,
    SOUND_KM9 = 279,
    SOUND_KM11 = 280,
    SOUND_KM12 = 281,
    SOUND_KM13 = 282,

    SOUND_KM43 = 283,
    SOUND_KV11 = 284,
    SOUND_KV12 = 285,
    SOUND_KV13 = 286,
    SOUND_KV14 = 287,
    SOUND_KV15 = 288,
    SOUND_KT10 = 289,
    SOUND_KT1 = 290,
    SOUND_KM41 = 291,
    SOUND_KM42 = 292,
    SOUND_KT4 = 293,
    SOUND_KT5 = 294,
    SOUND_KM14 = 295,
    SOUND_K1 = 296
};

#endif // EP1M_SIGNALS_H
