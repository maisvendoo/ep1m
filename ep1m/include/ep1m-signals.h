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

    // Колесные пары
    SIGNAL_WHEEL1 = 194, // Колесная пара 1
    SIGNAL_WHEEL2 = 195, // Колесная пара 2
    SIGNAL_WHEEL3 = 196, // Колесная пара 3
    SIGNAL_WHEEL4 = 197, // Колесная пара 4
    SIGNAL_WHEEL5 = 198, // Колесная пара 5
    SIGNAL_WHEEL6 = 199  // Колесная пара 6
};

#endif // EP1M_SIGNALS_H
