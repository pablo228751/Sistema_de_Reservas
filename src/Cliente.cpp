#include<iostream>
using namespace std;
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Usuarios.h"

Cliente::Cliente()
{
    strcpy(_dni, "0");
}


//SETS
void Cliente::SetDni(const char* dni)
{
    strcpy(_dni,dni);
}

//GETS
const char* Cliente::GetDni()
{
    return _dni;
}



//METODOS
void Cliente::CargarContacto()
{
    _contacto.CargarContacto();
}

void Cliente::MostrarContacto()
{
    _contacto.MostrarContacto();
}


void Cliente::cargarCliente(const char* dni)
{
Persona :
    CargarPersona();
    _contacto.CargarContacto();
    strcpy(_dni,dni);

}

void Cliente::mostrarCliente()
{
    cout<<endl<<"DNI: "<<_dni;
Persona :
    MostrarPersona();
    _contacto.MostrarContacto();
}





//Cargar clientes de cero independientemente de reservas
void Cliente:: crearCliente()
{
    Cliente cliente;
    ArchivoCliente archivoCliente;
    const int tam=9;
    char dni[tam];
    cout<<endl<<"Ingrese el numero de documento del cliente: ";

    cargarCadena(dni,8);

    if(archivoCliente.buscar(dni)==-1)
    {

        cliente.cargarCliente(dni);
        archivoCliente.guardar(cliente);
        cout<<endl<<"Cliente cargado con exito"<<endl;
    }

    else
    {
        cout<<endl<<"El cliente con el Dni: "<<dni<<" ya se encuentra registrado"<<endl;

    }

}
void Cliente:: ModificarCliente()
{
    Usuarios usu;
    char pass[50];
    char legajo[9];
    cout<<"Para ingresar necesita privilegios de ADMIN"<<endl;
    cout<<"Legajo: ";
    cargarCadena(legajo,8);
    if(usu.leerUsuario(legajo) == -1)
    {
        return;
    }
    cout<<"Contraseña:";
    cargarCadena(pass,49);
    cout<<endl;
    if(usu.getAcceso() ==2 )
    {
        cout<<"El usuario:"<<usu.GetNombre()<<" ,no posee Nivel de Usuario: ADMIN"<<endl;
        cout<<"Necesita Permisos de ADMIN para Modificar"<<endl;
        return;
    }
    else
    {
        if(!strcmp(pass,usu.getContrasenia())==0){
            cout<<"La contraseña es incorrecta"<<endl;
            return;
        }
        cout<<"Usuario ADMIN: "<<usu.GetNombre()<<" "<<usu.GetApellido()<<endl;
        ArchivoCliente archivocliente;
        int cantCliente= archivocliente.getCantidad();
        Cliente *clientes= new Cliente[cantCliente];

        for(int i=0; i<cantCliente; i++)
        {


            clientes[i]=archivocliente.leer(i);

        }

        char dni[9];
        cout<<endl<<"Ingrese del dni del cliente que desea modificar: ";
        cargarCadena(dni,8);

        for(int i=0; i<cantCliente; i++)
        {

            if(strcmp(clientes[i].GetDni(),dni)==0)
            {

                clientes[i].mostrarCliente();

                cout<<endl<<"presione 1 para modificar el nombre y  el apellido y 2 para el contacto: ";
                int opcion;
                cin>>opcion;
                cout<<endl;

                switch(opcion)
                {
                case 1:
                    char nombre[50], apellido[50];
                    cout<<"Introduzca nuevo nombre: ";
                    cargarCadena(nombre, 49);
                    clientes[i].SetNombre(nombre);

                    cout<<endl<<"Introduzca nuevo apellido: ";
                    cargarCadena(apellido,49);
                    clientes[i].SetApellido(apellido);

                    cout<<endl<<"Nuevos datos del cliente: "<<endl;
                    clientes[i].mostrarCliente();
                    cout<<endl;

                    archivocliente.guardar(clientes[i],i);
                    break;
                case 2:
                    clientes[i].CargarContacto();
                    if(archivocliente.guardar(clientes[i],i)){
                        cout<<endl<<"SE MODIFICARON LOS DATOS CORRECTAMENTE"<<endl;
                    }
                    clientes[i].mostrarCliente();
                    cout<<endl;
                    break;

                }

            }
        }


    }

}
