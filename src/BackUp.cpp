#include<iostream>
using namespace std;
#include "BackUp.h"

///REALIZAR COPIAS DE SEGURIDAD
void BackUp::realizarCopiaSeguridad()
{

    Usuarios usuariosAux;
    char pass[50];
    char _legajo[9];
    cout<<"Para ingresar necesita privilegios de ADMIN"<<endl;
    cout<<"Legajo: ";
    cargarCadena(_legajo,8);

    if(usuariosAux.leerUsuario(_legajo) == -1)
    {
        return ;
    }
    cout<<"Contraseña:";
    cargarCadena(pass,49);


    if(usuariosAux.getAcceso() ==2 )
    {
        cout<<"Necesita Permisos de ADMIN para Modificar"<<endl;

        return ;
    }
    else
    {
        if(!strcmp(pass,usuariosAux.getContrasenia())==0)
        {
            cout<<"La contraseña es incorrecta"<<endl;
            system("pause");
            system("cls");
            return ;
        }
        cout<<endl<<"Usuario ADMIN: "<<usuariosAux.GetNombre()<<endl<<endl;

    }




    cout<<"ESTA SEGURO QUE DESEA GENERAR UNA COPIA DE SEGURIDAD?"<<endl;
    cout<<"1 PARA CONFIRMAR"<<endl;
    cout<<"0 PARA SALIR ";
    int opcion=-1;
    while(opcion!=0 && opcion!=1)
    {
        cin>>opcion;
        if (opcion==0)
        {
          return;
        }

    }


    Fecha fechaActual;
    fechaActual.AsignarFechaActual(fechaActual);
    string fechaParametro=to_string(fechaActual.getDia())+to_string(fechaActual.getMes())+to_string(fechaActual.getAnio());

    ///CARGAMOS LOS VECTORES DINAMICOS Y LOS GUARDAMOS EN UN ARCHIVO APARTE
    ArchivoCliente archivoCliente;
    int cantClientes=archivoCliente.getCantidad();
    Cliente *cliente=new Cliente[cantClientes];
    if (cliente==NULL)
    {
        cout<<"NO HAY CLIENTES REGISTRADOS.";
    }
    else
    {
        for(int i=0; i<cantClientes; i++)
        {
            cliente[i]=archivoCliente.leer(i);
        }
        this->guardarTodos(fechaParametro, cliente, cantClientes);
    }

    ArchivoHabitacion archivoHabitacion;
    int cantHabitaciones=archivoHabitacion.getCantidad();
    Habitacion *habitacion=new Habitacion[cantHabitaciones];
    if (habitacion==NULL)
    {
        cout<<"NO HAY HABITACIONES REGISTRADAS.";
    }
    else
    {
        for(int i=0; i<cantHabitaciones; i++)
        {
            habitacion[i]=archivoHabitacion.leer(i);
        }
        this->guardarTodos(fechaParametro, habitacion, cantHabitaciones);
    }

    ArchivoReservas archivoReservas;
    int cantReservas=archivoReservas.getCantidad();
    Reservas *reservas=new Reservas[cantReservas];
    if (reservas==NULL)
    {
        cout<<"NO HAY RESERVAS REGISTRADAS. ";
    }
    else
    {
        for (int i=0; i<cantReservas; i++)
        {
            reservas[i]=archivoReservas.leer(i);
        }
        this->guardarTodos(fechaParametro,reservas, cantReservas);
    }



    ArchivoVentas archivoVentas;
    int cantVentas=archivoVentas.getCantidad();
    Ventas *ventas=new Ventas[cantVentas];
    if (ventas==NULL)
    {
        cout<<"NO HAY VENTAS REGISTRADAS. ";
    }
    else
    {
        for(int i=0; i<cantVentas; i++)
        {
            ventas[i]=archivoVentas.leer(i);
        }
        this->guardarTodos(fechaParametro, ventas, cantVentas);
    }


    Usuarios *usuarios, aux;
    int pos=0;
    int cantidadUsuarios=aux.ContarCantidadArchivos();
    usuarios=new Usuarios [cantidadUsuarios];
    if (usuarios==NULL)
    {
        cout<<"NO HAY USUARIOS REGISTRADOS. ";
    }
    else
    {
        aux.leerTodos(usuarios, cantidadUsuarios);
        this->guardarTodos(fechaParametro,usuarios, cantidadUsuarios);
    }


    cout<<"\nCOPIA DE SEGURIDAD GUARDADA CON EXITO."<<endl<<endl;
    delete [] cliente;
    delete [] habitacion;
    delete [] reservas;
    delete [] ventas;
    delete [] usuarios;

}

//GUARDAR ARCHIVO DEL METODO REALIZAR COPIAS DE SEGURIDAD

bool BackUp::guardarTodos(string fecha, Reservas reservas[], int cantidad)
{
    FILE* p;
    int const tam=30;
    char archivo[tam];
    strcpy(archivo,"BackUpReservas_");
    strcat(archivo,fecha.c_str());
    strcat(archivo,".dat");
    p = fopen(archivo, "wb");
    if (p == NULL)
    {
        return false;
    }
    fwrite(reservas, sizeof(Reservas), cantidad, p);
    fclose(p);
    return true;
}


bool BackUp::guardarTodos(string fecha, Ventas ventas[], int cantidad)
{
    FILE* p;
    int const tam=30;
    char archivo[tam];
    strcpy(archivo,"BackUpVentas_");
    strcat(archivo,fecha.c_str());
    strcat(archivo,".dat");
    p = fopen(archivo, "wb");
    if (p == NULL)
    {
        return false;
    }
    fwrite(ventas, sizeof(Ventas), cantidad, p);
    fclose(p);
    return true;
}


bool BackUp::guardarTodos(string fecha, Cliente clientes[], int cantidad)
{
    FILE* p;
    int const tam=30;
    char archivo[tam];
    strcpy(archivo,"BackUpClientes_");
    strcat(archivo,fecha.c_str());
    strcat(archivo,".dat");
    p = fopen(archivo, "wb");
    if (p == NULL)
    {
        return false;
    }
    fwrite(clientes, sizeof(Cliente), cantidad, p);
    fclose(p);
    return true;
}


bool BackUp::guardarTodos(string fecha, Habitacion habitacion[], int cantidad)
{
    FILE* p;
    int const tam=30;
    char archivo[tam];
    strcpy(archivo,"BackUpHabitaciones_");
    strcat(archivo,fecha.c_str());
    strcat(archivo,".dat");
    p = fopen(archivo, "wb");
    if (p == NULL)
    {
        return false;
    }
    fwrite(habitacion, sizeof(Habitacion), cantidad, p);
    fclose(p);
    return true;
}


bool BackUp::guardarTodos(string fecha, Usuarios usuarios[], int cantidad)
{
    FILE* p;
    int const tam=30;
    char archivo[tam];
    strcpy(archivo,"BackUpUsuarios_");
    strcat(archivo,fecha.c_str());
    strcat(archivo,".dat");
    p = fopen(archivo, "wb");
    if (p == NULL)
    {
        return false;
    }
    fwrite(usuarios, sizeof(Usuarios), cantidad, p);
    fclose(p);
    return true;
}




///RESTAURAR COPIAS DE SEGURIDAD

void BackUp::restaurarCopiaSeguridad()
{
    Usuarios usuariosAux;
    char pass[50];
    char _legajo[9];
    cout<<"Para ingresar necesita privilegios de ADMIN"<<endl;
    cout<<"Legajo: ";
    cargarCadena(_legajo,8);

    if(usuariosAux.leerUsuario(_legajo) == -1)
    {
        return ;
    }
    cout<<"Contraseña:";
    cargarCadena(pass,49);


    if(usuariosAux.getAcceso() ==2 )
    {
        cout<<"Necesita Permisos de ADMIN para Modificar"<<endl;

        return ;
    }
    else
    {
        if(!strcmp(pass,usuariosAux.getContrasenia())==0)
        {
            cout<<"La contraseña es incorrecta"<<endl;
            system("pause");
            system("cls");
            return ;
        }
        cout<<endl<<"Usuario ADMIN: "<<usuariosAux.GetNombre()<<endl<<endl;

    }


    cout<<"ESTA SEGURO QUE DESEA RESTAURAR LOS DATOS?"<<endl;
    cout<<"1 PARA CONFIRMAR"<<endl;
    cout<<"0 PARA SALIR ";
    int opcion=-1;
    while(opcion!=0 && opcion!=1)
    {
        cin>>opcion;
        if (opcion==0)
        {
            return;
        }

    }

    char fecha[9];
    cout<<"\nINGRESE FECHA DEL BACK UP A RESTAURAR ";
    cargarCadena(fecha,8);

    //Reservas
    int const tam=30;
    char archivoReservas[tam];
    strcpy(archivoReservas,"BackUpReservas_");
    strcat(archivoReservas,fecha);
    strcat(archivoReservas,".dat");

    int cantReservas=this->getCantidadReservas(archivoReservas);

    ArchivoReservas archivosR;
    Reservas *reservas=new Reservas[cantReservas];
    if (reservas==NULL)
    {
        cout<<"\nNO HAY RESERVAS REGISTRADAS.";
    }
    else
    {
        this->leerTodos(archivoReservas,reservas, cantReservas);
        if(archivosR.grabarBackUp(reservas,cantReservas))
        {
            cout<<"\nRESERVAS RESTAURADAS."<<endl;
        }
        else
        {
            cout<<"\nNO SE PUDO RESTAURAR LAS RESERVAS.";
        }
    }


    //Ventas
    char archivoVentas[tam];
    strcpy(archivoVentas,"BackUpVentas_");
    strcat(archivoVentas,fecha);
    strcat(archivoVentas,".dat");

    int cantVentas=this->getCantidadVentas(archivoVentas);

    ArchivoVentas archivosV;

    Ventas *ventas=new Ventas[cantVentas];
    if (ventas==NULL)
    {
        cout<<"NO HAY VENTAS REGISTRADAS. ";
    }
    else
    {
        this->leerTodos(archivoVentas, ventas, cantVentas);
        if(archivosV.grabarBackUp(ventas,cantVentas))
        {
            cout<<"VENTAS RESTAURADAS."<<endl;
        }
        else
        {
            cout<<"\nNO SE PUDO RESTAURAR LAS VENTAS.";
        }
    }


    //Clientes
    char archivoClientes[tam];
    strcpy(archivoClientes,"BackUpClientes_");
    strcat(archivoClientes,fecha);
    strcat(archivoClientes,".dat");

    int cantClientes=this->getCantidadClientes(archivoClientes);

    ArchivoCliente archivosC;

    Cliente *clientes=new Cliente[cantClientes];
    if (clientes==NULL)
    {
        cout<<"NO HAY CLIENTES REGISTRADOS. ";
    }
    else
    {
        this->leerTodos(archivoClientes, clientes, cantClientes);
        if(archivosC.grabarBackUp(clientes,cantClientes))
        {
            cout<<"CLIENTES RESTAURADOS."<<endl;
        }
        else
        {
            cout<<"\nNO SE PUDO RESTAURAR LOS CLIENTES.";
        }
    }


    //Habitaciones
    char archivoHabitaciones[tam];
    strcpy(archivoHabitaciones,"BackUpHabitaciones_");
    strcat(archivoHabitaciones,fecha);
    strcat(archivoHabitaciones,".dat");

    int cantHabitaciones=this->getCantidadHabitaciones(archivoHabitaciones);

    ArchivoHabitacion archivosH;
    Habitacion *habitaciones=new Habitacion[cantHabitaciones];
    if (habitaciones==NULL)
    {
        cout<<"NO HAY RESERVAS REGISTRADAS. ";
    }
    else
    {
        this->leerTodos(archivoHabitaciones,habitaciones, cantHabitaciones);
        if(archivosH.grabarBackUp(habitaciones,cantHabitaciones))
        {
            cout<<"HABITACIONES RESTAURADAS."<<endl;
        }
        else
        {
            cout<<"NO SE PUDO RESTAURAR LAS HABITACIONES.";
        }
    }

    ///Usuarios
    char archivoUsuarios[tam];
    strcpy(archivoUsuarios,"BackUpUsuarios_");
    strcat(archivoUsuarios,fecha);
    strcat(archivoUsuarios,".dat");

    int cantUsuarios=this->getCantidadUsuarios(archivoUsuarios);

    Usuarios archivosU;
    Usuarios *usuarios=new Usuarios[cantUsuarios];
    if (usuarios==NULL)
    {
        cout<<"NO HAY USUARIOS REGISTRADAS. ";
    }
    else
    {
        this->leerTodos(archivoUsuarios,usuarios, cantUsuarios);
        if(archivosU.grabarBackUp(usuarios,cantUsuarios))
        {
            cout<<"USUARIOS RESTAURADAS."<<endl;
        }
        else
        {
            cout<<"NO SE PUDO RESTAURAR LOS USUARIOS.";
        }
    }


    delete [] habitaciones;
    delete [] usuarios;
    delete [] reservas;
    delete [] ventas;
    delete [] clientes;
  }


    //RESERVAS
    bool BackUp::leerTodos(const char* archivoReservas, Reservas reservas[], int cantidad)
    {
        FILE* p;
        p = fopen(archivoReservas, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return false;
        }
        fread(reservas, sizeof(Reservas), cantidad, p);
        fclose(p);
        return true;
    }

    int BackUp::getCantidadReservas(const char* archivoReservas)
    {
        FILE* p = fopen(archivoReservas, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return 0;
        }
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Reservas);
        fclose(p);
        return cant;
    }

    //HABITACIONES
    bool BackUp::leerTodos(const char* archivoHabitaciones, Habitacion habitaciones[], int cantidad)
    {
        FILE* p;
        p = fopen(archivoHabitaciones, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return false;
        }
        fread(habitaciones, sizeof(Habitacion), cantidad, p);
        fclose(p);
        return true;
    }

    int BackUp::getCantidadHabitaciones(const char* archivoHabitaciones)
    {
        FILE* p = fopen(archivoHabitaciones, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return 0;
        }
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Habitacion);
        fclose(p);
        return cant;
    }



    //USUARIOS
    bool BackUp::leerTodos(const char* archivoUsuarios, Usuarios usuarios[], int cantidad)
    {
        FILE* p;
        p = fopen(archivoUsuarios, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return false;
        }
        fread(usuarios, sizeof(Usuarios), cantidad, p);
        fclose(p);
        return true;
    }

    int BackUp::getCantidadUsuarios(const char* archivoUsuarios)
    {
        FILE* p = fopen(archivoUsuarios, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return 0;
        }
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Usuarios);
        fclose(p);
        return cant;
    }





    //CLIENTES
    bool BackUp::leerTodos(const char* archivoClientes, Cliente clientes[], int cantidad)
    {
        FILE* p;
        p = fopen(archivoClientes, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return false;
        }
        fread(clientes, sizeof(Cliente), cantidad, p);
        fclose(p);
        return true;
    }


    int BackUp::getCantidadClientes(const char* archivoClientes)
    {
        FILE* p = fopen(archivoClientes, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return 0;
        }
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Cliente);
        fclose(p);
        return cant;
    }




    //VENTAS
    bool BackUp::leerTodos(const char* archivoVentas, Ventas ventas[], int cantidad)
    {
        FILE* p;
        p = fopen(archivoVentas, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return false;
        }
        fread(ventas, sizeof(Ventas), cantidad, p);
        fclose(p);
        return true;
    }


    int BackUp::getCantidadVentas(const char* archivoVentas)
    {
        FILE* p = fopen(archivoVentas, "rb");
        if (p == NULL)
        {
            cout<<"NO EXISTE EL ARCHIVO"<<endl;
            return 0;
        }
        fseek(p, 0, SEEK_END);
        int cant = ftell(p) / sizeof(Ventas);
        fclose(p);
        return cant;
    }
