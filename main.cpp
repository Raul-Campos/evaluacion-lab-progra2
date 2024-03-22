#include <iostream>
#include <stdlib.h>
#include "Fecha.h"
#include "Cliente.h"
#include "Pago.h"
#include "Prestamo.h"
#define TML 5

using namespace std;

int menu(){
    int op;
    system("cls");
    cout << "MENU DE OPCIONES\n";
    cout << "1. Agregar clientes a la lista\n";
    cout << "2. Agregar prestamo a la lista\n";
    cout << "3. Hacer pagos de prestamos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de prestamos\n";
    cout << "6. Mostrar detalles del prestamo\n";
    cout << "7. Salir\n";
    cout << "Digite la opcion : ";
    cin >> op;
    return op;

}

Cliente *BuscarCliente(Cliente *lst[], int cont, int db){
    bool encontrado = false;
    int contador = 0;
    Cliente *cli = NULL;
    while (contador < cont && !encontrado){
        if (lst[contador]->getIdCliente() == db){
            encontrado = true;
            cli = lst[contador];
        }
        else{
            contador++;
        }
    }
    return cli;
}

Prestamo *BuscarPrestamo(Prestamo *lst[], int cont, int db){
    bool encontrado = false;
    int contador = 0;
    Prestamo *ptmo = NULL;
    while (contador < cont && !encontrado){
        if (lst[contador]->getNumeroPrestamo() == db){
            encontrado = true;
            ptmo = lst[contador];
        }
        else{
            contador++;
        }
    }
    return ptmo;
}

Cliente *agregarCliente(){
    int id;
    string n, a;
    Cliente *cli;
    cout << "Digite el id del cliente : ";
    cin >> id;
    cout << "Digite el nombre del cliente : ";
    cin >> n;
    cout << "Digite el apellido del cliente : ";
    cin >> a;
    cli = new Cliente(id, n, a);
    return cli;
}
Prestamo *agregarPrestamo(Cliente *cli){
    int np;
    int d, m ,a;
    Fecha *fa;
    float ma;
    Prestamo *ptmo;
    cout << "Digite el numero del prestamo : ";
    cin >> np;
    cout << "Digite el dia, mes y anio: \n";
    cin >> d;
    cin >> m;
    cin >> a;
    fa = new Fecha(d, m, a);
    cout << "Digite el monto aprobado : ";
    cin >> ma;
    ptmo = new Prestamo(np, cli, fa, ma);
    return ptmo;
}

void registrarPago(Prestamo *ptmo){
    int d,m,a;
    Fecha *fp;
    float mp;
    Pago *pg;
    cout << "Digite la fecha de pago : \n";
    cin >> d;
    cin >> m;
    cin >> a;
    cout << "Digite el monto del pago : ";
    cin >> mp;
    fp = new Fecha(d,m,a);
    pg = new Pago(fp, mp);
    ptmo->hacerPago(pg);
}

void verDetalles(Prestamo *ptmo){
    cout << "El numero : " << ptmo->getNumeroPrestamo() << endl;
    cout << "Cliente : " << ptmo->getCliente()->getNombre() << " " << ptmo->getCliente()->getApellido() << endl;
    cout << "Fecha aprobacion : ";
    ptmo->getFechaAprobacion()->mostrarFecha();
    cout << "\nMonto aprobado : " << ptmo->getMontoAprobado() << endl;
    cout << "Saldo pendiente : " << ptmo->getSaldoPendiente() << endl;
    if (ptmo->getContadorPagos() == 0){
        cout << "No tienes pagos registrados\n";
    }
    else{
        Pago **lista = ptmo->getLstPagos();
        cout << "Pagos realizados\n";///sadjh
        cout << "No\tFecha\t\tMonto\n";
        for (int i=0;i<ptmo->getContadorPagos();i++){
            cout << (i+1) << "\t";
            lista[i]->getFechaPago()->mostrarFecha();
            cout << "\t" << lista[i]->getMontoPago() << endl;
        }
    }
}

int main(){
    Cliente *lstCliente[TML];
    Prestamo *lstPrestamo[TML];
    Cliente *cli=NULL;
    Prestamo *ptmo=NULL;
    int opc, contCli=0, contPtmo=0, idCli, idPtmo;
    do{
        //system("cls");//
        opc = menu();
        switch(opc){
            case 1:
                ///agregar clientes
                if(contCli < TML){
                    lstCliente[contCli] = agregarCliente();
                    contCli++;
                    cout << "El cliente se agrego con exito\n";
                }
                else{
                    cout << "La lista de clientes esta llena\n";
                }
                break;
            case 2:
                ///agregar prestamos
                if(contPtmo < TML){
                    cout << "Digite el id del cliente : ";
                    cin >> idCli;
                    cli = BuscarCliente(lstCliente, contCli, idCli);
                    if (cli){
                        lstPrestamo[contPtmo] = agregarPrestamo(cli);
                        contPtmo = contPtmo + 1;
                        cout << "El prestamo se agrego con exito\n";
                    }
                    else{
                        cout << "La lista de prestamos esta llena\n";
                    }
                }
                else{
                    cout << "La lista esta llena\n";
                }
                break;
            case 3:
                ///pagos de prestamos
                cout << "Digite el numero del prestamo : ";
                cin >> idPtmo;
                ptmo = BuscarPrestamo(lstPrestamo, contPtmo, idPtmo);
                if (ptmo){
                    registrarPago(ptmo);
                    cout << "El pago se registro con exito\n";
                }
                else{
                    cout << "El cliente no existe, no se puede agregar el pago\n";
                }
                break;
            case 4:
                ///mostrar clientes
                if (contCli == 0){
                    cout << "La lista esta vacia\n";
                }
                else{
                    cout << "id\tNombre\tApellido\n";
                    for (int i=0;i<contCli;i++){
                        cout << lstCliente[i]->getIdCliente() << "\t";
                        cout << lstCliente[i]->getNombre() << "\t";
                        cout << lstCliente[i]->getApellido() << "\n";
                    }
                }
                break;
            case 5:
                ///mostrar prestamos
                if (contCli == 0){
                    cout << "La lista esta vacia\n";
                }
                else{
                    cout << "No\tCliente\t\tFecha\t\tMonto\tSaldo\n";
                    for (int i=0;i<contPtmo;i++){
                        cout << lstPrestamo[i]->getNumeroPrestamo() << "\t";
                        cout << lstPrestamo[i]->getCliente()->getNombre() << " " << lstPrestamo[i]->getCliente()->getApellido() << "\t";///sin t
                        lstPrestamo[i]->getFechaAprobacion()->mostrarFecha();
                        cout << "\t" << lstPrestamo[i]->getMontoAprobado() << "\t";
                        cout << lstPrestamo[i]->getSaldoPendiente() << endl;
                    }
                }
                break;
            case 6:
                ///detalles de prestamo
                cout << "Digite el numero del prestamo : ";
                cin >> idPtmo;
                ptmo = BuscarPrestamo(lstPrestamo, contPtmo, idPtmo);
                if (ptmo){
                    verDetalles(ptmo);
                }
                else{
                    cout << "El prestamo no existe, no se pueden validar los detalles";
                }
                break;
            case 7:
                cout << "Saliendo del programa\n";
                break;
            default:
                cout << "Error, esa opcion no es valida\n";
                break;
        }
        system("pause");
    }while (opc!=7);

    return 0;
}
