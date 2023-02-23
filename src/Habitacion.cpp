#include <iostream>
using namespace std;
#include "Habitacion.h"
#include "ArchivoHabitacion.h"
#include "Usuarios.h"

//GETS

int  Habitacion:: getNumero()
{

    return _numero;
}

int  Habitacion:: getTipo()
{

    return _tipo;
}

float  Habitacion:: getPrecio()
{

    return _precio;
}

bool  Habitacion:: getEstado()
{

    return _estado;
}

//SETS

void Habitacion :: setNumero(int numero)
{

    _numero=numero;

}

void Habitacion :: setTipo(int tipo)
{

    _tipo=tipo;

}

void Habitacion :: setPrecio(float precio)
{

    _precio=precio;
}

void Habitacion :: setEstado(bool estado)
{

    _estado=estado;

}

//MOSTRAR

void Habitacion::mostrarDesocupadas()
{

    if(_estado=true)
    {

        cout<<endl<<"Habitacion N#: ";
        cout<<_numero;

        cout<<endl<<"Tipo de la habitacion: ";
        cout<<_tipo<<" cama/camas ";

        cout<<endl<<"Precio de la habitacion: $";
        cout<<_precio;

    }

}

void Habitacion::mostrarOcupadas()
{

    if(_estado=false)
    {

        cout<<endl<<"Habitacion N#: ";
        cout<<_numero;

        cout<<endl<<"Tipo de la habitacion: ";
        cout<<_tipo<<" cama/camas ";

        cout<<endl<<"Precio de la habitacion: $";
        cout<<_precio;
    }
}



void Habitacion::mostrarHabitacion()
{
    cout<<endl<<"Habitacion N#: ";
    cout<<_numero;

    cout<<endl<<"Tipo de la habitacion: ";
    cout<<_tipo<<" cama/camas ";

    cout<<endl<<"Precio de la habitacion: $";
    cout<<_precio;

}

//CARGAR

void Habitacion::cargarHabitacion(int numero)
{

    _numero=numero+1;
    cout<<endl<<"Ingrese tipo de habitacion: ";
    cin>>_tipo;
    cout<<endl<<"Ingrese precio de la habitacion: $";
    cin>>_precio;
    _estado=true;


}



//CREAR HABITACIONES, VA A HACER EL PROCESO DE SUMARLE 1 AL NUMERO DE HABITACION ANTERIOR, PARA QUE EL NUMERO NUNCA SE REPITA Y SIEMPRE ESTE EN ORDEN.
void Habitacion::crearHabitacion()
{

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
    }

    cout<<endl<<"Usuario ADMIN: "<<usuarios.GetNombre()<<endl<<endl;

    Habitacion habitacion;
    ArchivoHabitacion archivoHabitacion;


    int cantidadHabitaciones= archivoHabitacion.getCantidad();

    if(cantidadHabitaciones==0)
    {

        habitacion.cargarHabitacion(0);
        archivoHabitacion.guardar(habitacion);
        cout<<endl<<"Cargo Primera habitacion en el sistema"<<endl;

    }

    else
    {


        Habitacion* vecHabitaciones= new Habitacion[cantidadHabitaciones];

        for(int i=0; i<cantidadHabitaciones; i++)
        {

            vecHabitaciones[i]=archivoHabitacion.leer(i);


        }

        int maximo=vecHabitaciones[0].getNumero();
        for(int i=0; i<cantidadHabitaciones; i++)
        {

            if(vecHabitaciones[i].getNumero()>maximo)
            {

                maximo=vecHabitaciones[i].getNumero();
            }
        }
        habitacion.cargarHabitacion(maximo);
        archivoHabitacion.guardar(habitacion);





        delete [] vecHabitaciones;
    }


    Habitacion habitacionAux;
    habitacionAux.mostrarHabitaciones();

}




//va a mostrar todas las habitaciones que hay cargadas
void Habitacion:: mostrarHabitaciones()
{

    ArchivoHabitacion archivoHabitacion;

    int cantidadHabitaciones =archivoHabitacion.getCantidad();

    Habitacion* vecHabitaciones= new Habitacion[cantidadHabitaciones];

    for(int i=0; i<cantidadHabitaciones; i++)
    {

        vecHabitaciones[i]=archivoHabitacion.leer(i);

    }

    for(int i=0; i<cantidadHabitaciones; i++)
    {

        cout<<endl<<"Habitacion Numero#: "<<vecHabitaciones[i].getNumero();

        cout<<endl<<"Tipo de habitacion: "<<vecHabitaciones[i].getTipo()<<" cama/camas";

        cout<<endl<<"Precio: $"<<vecHabitaciones[i].getPrecio();

        cout<<endl<<"Estado: "<<vecHabitaciones[i].getEstado();

        cout<<endl;
    }


    delete [] vecHabitaciones;
}


