#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <string.h>


class Fecha
{
    public:
        Fecha(int d, int m, int a);
        virtual ~Fecha();
        void mostrarFecha();
    protected:

    private:
        int dia;
        int mes;
        int anio;
};

#endif // FECHA_H
