#ifndef     EP1M_SIGNALS_H
#define     EP1M_SIGNALS_H

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
enum
{
    // Тумблеры блока выключателей
    SIGNAL_TUMBLER_MSUD = 0, // МСУД
    SIGNAL_TUMBLER_VVK = 1, // Блокирование ВВК
    SIGNAL_TUMBLER_PANT1 = 2, // Токоприемник 1
    SIGNAL_TUMBLER_PANT2 = 3, // Токоприемник 2
    SIGNAL_TUMBLER_RETURN_PROTECTION = 4, // Возврат защиты ГВ
    SIGNAL_TUMBLER_MAIN_SWITCH = 5, // Главный выключатель

    SIGNAL_TUMBLER_AUX_MACHINES = 6, // Вспомогательные машины
    SIGNAL_TUMBLER_COMPRESSOR = 7, // Компрессор
    SIGNAL_TUMBLER_MOTOR_FAN1 = 8, // Вентилятор 1
    SIGNAL_TUMBLER_MOTOR_FAN2 = 9, // Вентилятор 2
    SIGNAL_TUMBLER_MOTOR_FAN3 = 10, // Вентилятор 3
    SIGNAL_TUMBLER_EPT = 11, // ЭПТ

    // Колесные пары
    SIGNAL_WHEEL1 = 194, // Колесная пара 1
    SIGNAL_WHEEL2 = 195, // Колесная пара 2
    SIGNAL_WHEEL3 = 196, // Колесная пара 3
    SIGNAL_WHEEL4 = 197, // Колесная пара 4
    SIGNAL_WHEEL5 = 198, // Колесная пара 5
    SIGNAL_WHEEL6 = 199  // Колесная пара 6
};

#endif // EP1M_SIGNALS_H
