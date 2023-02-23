#include<iostream>
#include "rlutil.h"
using namespace std;
#include "Listados.h"
using namespace rlutil;
#include "CrearMenu.h"

  void Listados::listadoClientes(){
    ArchivoCliente archivoCliente;
    int cantClientes=archivoCliente.getCantidad();

    Cliente *cliente=new Cliente[cantClientes];
    if (cliente==NULL){cout<<"NO HAY CLIENTES REGISTRADOS.";delete [] cliente;return;}

    setColor(CYAN);
    cout<<"==================="<<endl;
    cout<<"LISTADO DE CLIENTES "<<endl;
    cout<<"==================="<<endl;
    setColor(WHITE);

    for(int i=0;i<cantClientes;i++){
      cliente[i]=archivoCliente.leer(i);
      cliente[i].mostrarCliente();
    }

    cout<<endl;

    delete [] cliente;
  }


  void Listados::listadoHabitaciones(){
    bool existeSimple, existeDoble, existeTriple;
    ArchivoHabitacion archivoHabitacion;
    int cantHabitaciones=archivoHabitacion.getCantidad();

    Habitacion *habitacion=new Habitacion[cantHabitaciones];
    if (habitacion==NULL){cout<<"NO HAY HABITACIONES REGISTRADAS.";delete [] habitacion;return;}



    for(int i=0;i<cantHabitaciones;i++){
      habitacion[i]=archivoHabitacion.leer(i);
      if(habitacion[i].getTipo()==1){
        existeSimple=true;
      }
      if(habitacion[i].getTipo()==2){
        existeDoble=true;
      }
      if(habitacion[i].getTipo()==3){
        existeTriple=true;
      }

    }

    setColor(CYAN);
    cout<<"======================="<<endl;
    cout<<"LISTADO DE HABITACIONES "<<endl;
    cout<<"======================="<<endl;
    setColor(WHITE);

    if(existeSimple==true){

    setColor(CYAN);
    cout<<"===================="<<endl;
    cout<<"HABITACIONES SIMPLES"<<endl;
    cout<<"===================="<<endl;
    setColor(WHITE);

    for(int i=0;i<cantHabitaciones;i++){
      if(habitacion[i].getTipo()==1){
          habitacion[i].mostrarHabitacion();
      }
    }
    cout<<endl;
    }


    if(existeDoble==true){
    setColor(CYAN);
    cout<<"===================="<<endl;
    cout<<"HABITACIONES DOBLES"<<endl;
    cout<<"===================="<<endl;
    setColor(WHITE);

    for(int i=0;i<cantHabitaciones;i++){
      if(habitacion[i].getTipo()==2){
        habitacion[i].mostrarHabitacion();
      }
    }
    cout<<endl;
    }


    if(existeTriple==true){
    setColor(CYAN);
    cout<<"===================="<<endl;
    cout<<"HABITACIONES TRIPLES"<<endl;
    cout<<"===================="<<endl;
    setColor(WHITE);

    for(int i=0;i<cantHabitaciones;i++){
      if(habitacion[i].getTipo()==3){
        habitacion[i].mostrarHabitacion();
      }
    }
    cout<<endl;
    }
    cout<<endl;
    delete [] habitacion;
  }


  void Listados::listadoUsuarios(){
    Usuarios usuarios;

    FILE *p;
    p=fopen("usuarios.dat", "rb");
    if(p==NULL)
    {
      cout<<endl<<"Error al Leer Lista de Usuarios"<<endl;
      return;
    }

    setColor(CYAN);
    cout<<"=================="<<endl;
    cout<<"LISTA DE USUARIOS"<<endl;
    cout<<"=================="<<endl;
    setColor(WHITE);
    usuarios.ListaUsuarios();
    fclose (p);
  }



  void Listados::listadoReservas(){
    ArchivoReservas archivoReservas;
    int cantReservas=archivoReservas.getCantidad();
    Reservas *reservas=new Reservas[cantReservas];
    if (reservas==NULL){cout<<"NO HAY RESERVAS REGISTRADAS. ";delete [] reservas;return;}
    for (int i=0;i<cantReservas;i++){
      reservas[i]=archivoReservas.leer(i);
    }

    setColor(CYAN);
    cout<<"==================="<<endl;
    cout<<"LISTADO DE RESERVAS"<<endl;
    cout<<"==================="<<endl;
    setColor(WHITE);

    for (int i=0;i<cantReservas;i++){
      if (reservas[i].getEstadoReserva()==true && reservas[i].getCancelar()==false){
            reservas[i].mostrarReserva();
            cout<<endl;
        }
    }

    delete [] reservas;

  }




  //METODO ENCARGADO DE ENCAPSULAR TODO LO RELACIONADO CON CONSULTAS POR LISTADO

  void Listados::consultasPorListado(){
    CrearMenu submenu;
    int opcion;
    opcion=submenu.menuConsultasListados();

  switch(opcion){
  case 1:{
    this->consultaPorCliente();
    }
    break;
    case 2:{
    this->consultaPorVentas();
    }
    break;
    case 3:{
    this->consultaPorHabitacion();
    }
    break;
    case 0:
    break;
    }
  }




  //METODO PARA CONSULTRAR POR CLIENTE
   void Listados::consultaPorCliente(){
   ArchivoCliente archivoCliente;
   int cantClientes=archivoCliente.getCantidad();
   Cliente *clientes= new Cliente[cantClientes];

   for(int i=0;i<cantClientes;i++){
    clientes[i]=archivoCliente.leer(i);
   }

   char dni[9];
   cout<<"Ingrese el dni del cliente el cual desdea consultar: ";
   cargarCadena(dni,8);
   bool encontro=false;
   for(int i=0;i<cantClientes;i++){
    if(strcmp(clientes[i].GetDni(),dni)==0){

    clientes[i].mostrarCliente();
    cout<<endl;
    encontro=true;
    }

   }
   if(encontro==false){
    cout<<"No hay ningun cliente con ese dni"<<endl;
   }
   delete []clientes;
   }

//METODO PARA CONSULTAR POR VENTAS
   void Listados::consultaPorVentas(){

   ArchivoVentas archivoVentas;
   int cantVentas=archivoVentas.getCantidad();

   Ventas *ventas= new Ventas[cantVentas];

   for(int i=0;i<cantVentas;i++){
    ventas[i]=archivoVentas.leer(i);
   }
   int opcion=-1;
   cout<<endl<<"Ingrese 1 para consultar ventar por dni de cliente, 2 por numero de venta y 0 para volver al menu anterior ";
   while(opcion !=1 && opcion !=2 && opcion !=0){
   cin>>opcion;
   switch(opcion){
   case 1:{
          char dni[9];
          bool encontro=false;
          cout<<"Ingrese el dni del cliente del cual desea consultar las ventas: ";
          cargarCadena(dni,8);
           cout<<endl;

           for(int i=0;i<cantVentas;i++){
            if(strcmp(ventas[i].getDniCliente(), dni)==0){

                ventas[i].mostrarVenta();
                cout<<endl;
                encontro=true;
            }
           }

           if(encontro==false){

            cout<<endl<<"No hay ventas relacionadas a ese cliente"<<endl;
           }

   }
   break;


   case 2:{

        int codigoVenta;
          bool encontro=false;
          cout<<"Ingrese el numero de la venta que desea consultar: ";
          cin>>codigoVenta;
           cout<<endl;

           for(int i=0;i<cantVentas;i++){
            if(ventas[i].getNumeroVenta()==codigoVenta){

                ventas[i].mostrarVenta();
                cout<<endl;
                encontro=true;
            }

           }

           if(encontro==false){

            cout<<endl<<"No hay ninguna venta con ese numero de venta"<<endl;
           }

   }
    break;

   case 0:
    break;

   }
   }
   delete []ventas;
   }

//METODO PARA CONSULTAR POR HABITACION
   void Listados:: consultaPorHabitacion(){

   ArchivoHabitacion archivoHabitacion;
   int cantHabitaciones=archivoHabitacion.getCantidad();

   Habitacion *habitaciones= new Habitacion[cantHabitaciones];

   for(int i=0;i<cantHabitaciones;i++){
    habitaciones[i]=archivoHabitacion.leer(i);
    }

   int opcion=-1;
   cout<<endl<<"Ingrese 1 para consultar habitacion por numero de habitacion, 2 por tipo de habitacion y 0 para volver al menu anterior ";
   while(opcion !=1 && opcion !=2 && opcion !=0){
   cin>>opcion;
   switch(opcion){
   case 1:{
         int numeroHabitacion;
          bool encontro=false;
          cout<<"Ingrese el numero de la habitacion que desea consultar ";
          cin>>numeroHabitacion;
           cout<<endl;

           for(int i=0;i<cantHabitaciones;i++){
            if(habitaciones[i].getNumero()==numeroHabitacion){

                habitaciones[i].mostrarHabitacion();
                cout<<endl;
                encontro=true;
            }
           }

           if(encontro=false){

            cout<<endl<<"No hay ninguna habitacion con ese numero"<<endl;
           }

   }
   break;


   case 2:{

        int tipoHabitacion;
          bool encontro=false;
          cout<<"Ingrese el tipo de habitacion que desea consultar ";
          cin>>tipoHabitacion;
           cout<<endl;

           for(int i=0;i<cantHabitaciones;i++){
            if(habitaciones[i].getTipo()==tipoHabitacion){
                habitaciones[i].mostrarHabitacion();
                encontro=true;
            }

           }

           if(encontro=false){

            cout<<endl<<"No hay ninguna habitacion con ese tipo"<<endl;
           }

   }
    break;

    case 0:
    break;

   }

   }

   delete []habitaciones;
   }


