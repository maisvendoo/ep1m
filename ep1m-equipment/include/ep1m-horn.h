#ifndef     EP1MHORN_H
#define     EP1MHORN_H

#include    "train-horn.h"

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
class EP1mHorn : public TrainHorn
{
public:

    EP1mHorn(QObject *parent = Q_NULLPTR);

    ~EP1mHorn();

private:
};

#endif // EP1MHORN_H
