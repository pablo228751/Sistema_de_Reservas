#include <iostream>
#include <string>
#include "rlutil.h"
#include "ArchivoReservas.h"
#include "ArchivoHabitacion.h"
#include "Funciones.h"
#include "Usuarios.h"
#include "Cliente.h"
#include "RegistroYLogin.h"
#include "ArchivoVentas.h"
#include "Check_In.h"
#include "Check_Out.h"
#include "Listados.h"
#include "Informes.h"
#include "Modificaciones.h"
#include "CrearMenu.h"
#include "BackUp.h"

using namespace std;
int main()
{
    RegistroYLogin entrar;
    CrearMenu elegirMenu;

    rlutil::setColor(rlutil::WHITE);
    setlocale(LC_CTYPE, "Spanish");
    int opcion=-1;
    while(opcion != 0)
    {
        opcion=elegirMenu.menuInicio();
        rlutil::cls();
        switch(opcion)
        {
        case 1:
        {
            int opcion2=-1;
            bool log=entrar.login();
            while(opcion2 != 0)
            {
                if (log)
                {
                    opcion2=elegirMenu.menuUsuario(entrar.usuarioLogueado);
                    rlutil::cls();
                    switch(opcion2)
                    {
                    case 1:
                    {
                        Cliente cliente;
                        Reservas reserva;
                        reserva.reservar(cliente);
                        system("pause");
                    }
                    break;
                    case 2:
                    {
                        Check_In checkIn;
                        checkIn.hacerCheckIn();
                        system("pause");

                    }
                    break;
                    case 3:
                    {
                        Check_Out checkOut;
                        checkOut.hacerCheckOut();
                        system("pause");

                    }
                    break;

                    case 4:
                    {
                        Reservas reservas;
                        reservas.cancelarReserva();
                        system("pause");
                    }
                    break;

                    case 5:
                    {
                        Reservas reservas;
                        reservas.consultarReserva();
                        system("pause");
                    }
                    break;

                    case 6:
                    {
                        Reservas reserva;
                        reserva.disponibilidad();
                        system("pause");
                    }
                    break;

                    case 7:
                    {
                        Listados listados;
                        listados.listadoClientes();
                        listados.listadoHabitaciones();
                        listados.listadoUsuarios();
                        listados.listadoReservas();
                        system("pause");

                    }
                    break;

                    case 8:{
                        Listados listados;
                        listados.consultasPorListado();
                        system("pause");
                    }

                    break;

                    case 9:
                    {
                        Informes informes;
                        informes.consultasPorInformes();
                        system("pause");

                    }
                    break;

                    case 10:
                    {
                        Modificaciones modificar;
                        modificar.llamadoAModificarMain();
                    }
                    break;


                    case 11:
                    {
                        Habitacion habitacion;
                        habitacion.crearHabitacion();
                        system("pause");

                    }
                    break;

                    case 12:
                    {
                        Cliente cliente;
                        cliente.crearCliente();
                        system("pause");
                    }
                    break;

                    case 13:
                    {
                        BackUp backUp;
                        backUp.realizarCopiaSeguridad();
                        system("pause");
                    }
                    break;

                    case 14:
                    {
                        BackUp backUp;
                        backUp.restaurarCopiaSeguridad();
                        system("pause");

                    }
                    break;

                    case 0:
                        break;

                        system("pause");

                    }
                }
                else
                {
                    cout<<"No se pudo ingresar. Intente nuevamente."<<endl;
                    system("pause");
                    opcion2=0;
                }


        }
        }
        break;
        case 2:
        {
            RegistroYLogin registroYlogin;
            registroYlogin.FiltroRegistro();
            system("pause");

        }

        break;
        case 3:
        {
            RegistroYLogin registroYlogin;
            registroYlogin.listarUsuarios();


        }
        break;
        case 4:
        {
            RegistroYLogin registroYlogin;
            registroYlogin.buscarPorLegajo();
            system("pause");
        }
        break;
        case 5:{
            elegirMenu.integrantes();
        }
        break;
        case 0:
        {
            cout << "SALIÓ DEL SISTEMA" << endl;
        }
        break;
        default:
            cout << "Error, vuelva a intentarlo" << endl;
            system("pause");
        }
    }
    return 0;
}


