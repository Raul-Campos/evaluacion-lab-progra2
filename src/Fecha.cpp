#include "Fecha.h"
#include <string.h>
using namespace std;

Fecha::Fecha(int d, int m, int a)
{
    this->dia = d;
    this->mes = m;
    this->anio = a;
    //ctor
}

Fecha::~Fecha()
{
    //dtor
}

void Fecha::mostrarFecha(){
    cout << this->dia << "/" << this->mes << "/" << this->anio ;
}
