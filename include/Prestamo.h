#ifndef PRESTAMO_H
#define PRESTAMO_H
#include <iostream>
#include <string.h>
#include "Cliente.h"
#include "Fecha.h"
#include "Pago.h"
#define TDL 5

class Prestamo
{
    public:
        Prestamo();
        Prestamo(int np, Cliente *cli, Fecha *fa, float ma);
        virtual ~Prestamo();
        int getNumeroPrestamo();
        void setNumeroPrestamo(int np);
        Cliente *getCliente();
        void setCliente(Cliente *cli);
        void setFechaAprobacion(Fecha *fa);
        Fecha* getFechaAprobacion();
        void setMontoAprobado(float ma);
        float getMontoAprobado();
        bool hacerPago(Pago *pg);
        Pago** getLstPagos();
        float getSaldoPendiente();
        int getContadorPagos();

    protected:

    private:
        int numeroPrestamo;
        Cliente *cliente;
        Fecha *fechaAprobacion;
        float montoAprobado;
        Pago *lstPagos[TDL];
        float saldoPendiente;
        int contadorPagos;
};

#endif // PRESTAMO_H
