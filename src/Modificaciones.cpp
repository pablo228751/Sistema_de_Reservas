#include<iostream>
using namespace std;
#include "Modificaciones.h"

void Modificaciones::modificarHabitaciones()
{
    bool encontro=false;
    Usuarios usuarios;
    char pass[50];
    char _legajo[9];
    cout<<"Para ingresar necesita privilegios de ADMIN"<<endl;
    cout<<"Legajo: ";
    cargarCadena(_legajo,8);

    if(usuarios.leerUsuario(_legajo) == -1)
    {
        return ;
    }
    cout<<"Contraseña:";
    cargarCadena(pass,49);


    if(usuarios.getAcceso() ==2 )
    {
        cout<<"Necesita Permisos de ADMIN para Modificar"<<endl;

        return ;
    }
    else
    {
        if(!strcmp(pass,usuarios.getContrasenia())==0)
        {
            cout<<"La contraseña es incorrecta"<<endl;
            system("pause");
            system("cls");
            return ;
        }
        cout<<endl<<"Usuario ADMIN: "<<usuarios.GetNombre()<<endl<<endl;

        char c;
        int op=-1;
        while(op !=0)
        {
            system("cls");
            usuarios.MostrarUsuario();
            cout<<endl;

            cout<<"ELIJA UN OPCIÓN"<<endl;
            cout<<"1. MODIFICAR PRECIO DE HABITACION"<<endl;
            cout<<"2. MODIFICAR ESTADO DE HABITACION"<<endl;
            cout<<"0. SALIR"<<endl;
            cin>>op;
            switch(op)
            {
            case 1:
            {
                int numHabitacion;
                cout<<"INGRESE NUMERO DE HABITACION A MODIFICAR EL PRECIO "<<endl;
                cin>>numHabitacion;

                ArchivoHabitacion archivoHabitacion;
                int cantHabitacion=archivoHabitacion.getCantidad();
                Habitacion *habitacion=new Habitacion[cantHabitacion];

                for (int i=0; i<cantHabitacion; i++)
                {
                    habitacion[i]=archivoHabitacion.leer(i);
                }

                for (int i=0; i<cantHabitacion; i++)
                {
                    if (habitacion[i].getNumero()==numHabitacion)
                    {
                        encontro=true;
                        cout<<"PRECIO ACTUAL: ";
                        cout<<habitacion[i].getPrecio();
                        cout<<endl;
                        float nuevoPrecio;
                        cout<<"INGRESE NUEVO PRECIO: ";
                        cin>>nuevoPrecio;
                        habitacion[i].setPrecio(nuevoPrecio);
                        if(archivoHabitacion.guardar(habitacion[i], i))
                        {
                            cout<<"PRECIO MODIFICADO CORRECTAMENTE. EL NUEVO PRECIO ES: ";
                            cout<<habitacion[i].getPrecio();
                            cout<<endl;
                        }
                        else
                        {
                            cout<<"NO SE PUDO MODIFICAR EL PRECIO. "<<endl;
                        }
                    }

                }

                if(encontro==false)
                {
                    cout<<"NO SE ENCONTRO LA HABITACION INGRESADA ."<<endl;
                }
                delete [] habitacion;
            }
            system("pause");
            break;
            case 2:
            {
                int numHabitacion;
                cout<<"INGRESE NUMERO DE HABITACION A DAR DE BAJA O A DAR DE ALTA"<<endl;
                cin>>numHabitacion;

                ArchivoHabitacion archivoHabitacion;
                int cantHabitacion=archivoHabitacion.getCantidad();
                Habitacion *habitacion=new Habitacion[cantHabitacion];

                for (int i=0; i<cantHabitacion; i++)
                {
                    habitacion[i]=archivoHabitacion.leer(i);
                }

                for (int i=0; i<cantHabitacion; i++)
                {
                    if (habitacion[i].getNumero()==numHabitacion)
                    {
                        encontro=true;
                        bool nuevoEstado;
                        cout<<"INGRESE NUEVO ESTADO 1 PARA ACTIVO Y 0 PARA INACTIVO: ";
                        cin>>nuevoEstado;
                        habitacion[i].setEstado(nuevoEstado);
                        if(archivoHabitacion.guardar(habitacion[i], i))
                        {
                            cout<<"ESTADO MODIFICADO CORRECTAMENTE A"<<habitacion[i].getEstado()<<endl;
                        }
                        else
                        {
                            cout<<"NO SE PUDO MODIFICAR EL ESTADO. "<<endl;
                        }
                    }

                }

                if(encontro==false)
                {
                    cout<<"NO SE ENCONTRO LA HABITACION INGRESADA ."<<endl;
                }
                delete [] habitacion;
            }
            system("pause");
            break;

            case 0:
                system("cls");
                break;
            default:
                cout<<"Opción Incorrecta, intente nuevamente..."<<endl;
                system("pause");
                system("cls");
            }
        }
    }
}


void Modificaciones:: llamadoAModificarMain()
{
    int opcion;
    cout<<"\nINGRESE 1 PARA MODIFICAR HABITACION"<<endl;
    cout<<"INGRESE 2 PARA MODIFICAR USUARIOS"<<endl;
    cout<<"INGRESE 3 PARA MODIFICAR CLIENTES"<<endl;
    cout<<"INGRESE 0 PARA VOLVER AL MENU ANTERIOR: ";
    cin>>opcion;
    switch(opcion)
    {
    case 1:
    {
        Modificaciones modificar;
        modificar.modificarHabitaciones();
    }
    break;
    case 2:
    {
        Usuarios usuarios;
        usuarios.modificarUsuario();
    }
    break;
    case 3:{
        Cliente cliente;
        cliente.ModificarCliente();
    }
    break;
    case 0:
    {
    }
    break;
    default:
    {
        cout<<"\nOPCION INCORRECTA, INTENTE NUEVAMENTE"<<endl;
    }
    break;
    }

system("pause");

}









