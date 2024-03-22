#include "Pago.h"
#include "Fecha.h"
#include <string.h>

Pago::Pago(Fecha *fp, float mp)
{
    this->fechaPago = fp;
    this->montoPago = mp;
}

Pago::~Pago()
{
    //dtor
}

Fecha* Pago::getFechaPago(){
    return this->fechaPago;
}
float Pago::getMontoPago(){
    return this->montoPago;
}

