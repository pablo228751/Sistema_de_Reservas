#include<iostream>
using namespace std;
#include"Check_Out.h"
#include"ArchivoHabitacion.h"
#include"ArchivoReservas.h"

//Segun un Dni, damos la baja logica de la reserva (false) y la habitacion la seteamos en (true) como disponible
void Check_Out::hacerCheckOut(){

  this->mostrarReservasChekOut();
  cout<<"=============================="<<endl;


  char dni[9];
  cout<<"Ingrese DNI del cliente para hacer el chekout :"<<endl;
  cargarCadena(dni,8);
  bool encontro=false;

  ArchivoReservas archivoReservas;
  int cantReservas=archivoReservas.getCantidad();
  Reservas reservasAux, *reservas=new Reservas[cantReservas];

  for (int i=0;i<cantReservas;i++){
    reservas[i]=archivoReservas.leer(i);
  }

  ArchivoHabitacion archivoHabitacion;
  int cantHabitacion=archivoHabitacion.getCantidad();
  Habitacion habitacionAux, *habitacion=new Habitacion[cantHabitacion];


  for (int i=0;i<cantHabitacion;i++){
    habitacion[i]=archivoHabitacion.leer(i);
  }

  for(int j=0;j<cantReservas;j++){

    if(strcmp(reservas[j].getDniCliente(), dni)==0){
      reservas[j].mostrarReserva();
      cout<<"================="<<endl;
      encontro=true;
    }
  }

  if (encontro==false){
    cout<<"NO HAY RESERVAS CON EL NUMERO DE DNI INGRESADO ."<<endl;
    return;
  }

  int opcion;

  int numReserva;
  cout<<"INGRESE NUMERO DE RESERVA PARA HACER EL CHECK OUT: ";
  cin>>numReserva;

  //Preguntamos si es esta la reserva que quiere dar de baja.
  for (int i=0;i<cantHabitacion;i++){
    for(int j=0;j<cantReservas;j++){

      if(strcmp(reservas[j].getDniCliente(), dni)==0 && reservas[j].getNumeroReserva()==numReserva){

          cout<<"INGRESE 1 PARA CONFIRMAR EL CHECKOUT"<<endl;
          cout<<"INGRESE 0 PARA VOLVER AL MENU ANTERIOR: ";
          while(opcion!=1 && opcion!=2 && opcion!=0){
            cin>>opcion;
            switch(opcion){
            case 1:{
            reservasAux=archivoReservas.leer(j);
            habitacionAux=archivoHabitacion.leer(i);
            reservasAux.setEstadoReserva(false);
            //habitacionAux.setEstado(true);
            if(archivoReservas.guardar(reservasAux, j)){cout<<"CHECK OUT DE RESERVA EXITOSO"<<endl;}
            if(archivoHabitacion.guardar(habitacionAux, i)){cout<<"CHECK OUT DE HABITACION EXITOSO"<<endl;}

            system("pause");
            system("cls");
            }
            break;

            case 0:{
            system("pause");
            system("cls");
            }
            return;

            default:
            cout<<"OPCION INCORRECTA. INGRESE 1 PARA CONFIRMAR EL CHECKOUT, 2 PARA SEGUIR CON OTRA RESERVA, Y 0 PARA VOLVER AL MENU ANTERIOR:";

            }

          }

      }
      if (opcion==0 || opcion==1){return;}
    }
    if (opcion==0 || opcion==1){return;}
  }

  delete [] reservas;
  delete [] habitacion;

}


void Check_Out::mostrarReservasChekOut(){
  ArchivoReservas archivoReservas;
  Reservas reserva;
  Fecha fechaActual;
  fechaActual.AsignarFechaActual(fechaActual);
  bool encontro=false;

  int cant=archivoReservas.getCantidad();
  Reservas *reservas=new Reservas[cant];

  for (int i=0;i<cant;i++){
    reservas[i]=archivoReservas.leer(i);
  }

  for (int i=0;i<cant;i++){

   if(reservas[i].getFechaEgresoReserva()==fechaActual){
    reservas[i].mostrarReserva();
    encontro=true;
   }
  }

  if(encontro==false){
    cout<<"NO HAY CHECK OUT PARA EL DIA DE HOY."<<endl;
  }

  delete [] reservas;

}

