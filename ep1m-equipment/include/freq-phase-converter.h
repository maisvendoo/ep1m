#ifndef     FREQ_PHASE_CONVERTER_H
#define     FREQ_PHASE_CONVERTER_H

#include    "device.h"

//------------------------------------------------------------------------------
//  Преобразователь частоты и числа фаз (ПЧФ)
//------------------------------------------------------------------------------
class FreqPhaseConverter : public Device
{
public:

    FreqPhaseConverter(QObject *parent = Q_NULLPTR);

    ~FreqPhaseConverter();

    double getFrequency() const { return freq_cur; }

private:

    /// Текущая частота питания вспомогательных машин
    double freq_cur;

    void preStep(state_vector_t &Y, double t);

    void ode_system(const state_vector_t &Y, state_vector_t &dYdt, double t);

    void load_config(CfgReader &cfg);
};

#endif // FREQ_PHASE_CONVERTER_H
