#include<iostream>
using namespace std;
#include "ArchivoReservas.h"
#include "Check_In.h"
#include "ArchivoVentas.h"


void Check_In::hacerCheckIn(){
  ArchivoReservas archivoReservas;
  Reservas reservas;
  Fecha fechaActual;
  fechaActual.AsignarFechaActual(fechaActual);
  if(mostrarReservasActual()){
      char dni[9];
      int opcion=-1;

      cout<<"QUIERE CONSULTAR POR DNI?"<<endl;
      cout<<"INGRESE 1 PARA CONFIRMAR"<<endl;
      cout<<"INGRESE 2 PARA VOLVER AL MENU ANTERIOR :";
      while(opcion!=2 && opcion!=1){
      cin>>opcion;
      cout<<endl;

      switch (opcion)
      {
      case 1:
        cout<<"Ingrese DNI :"<<endl;
        cargarCadena(dni,8);
        mostrarReservaActualXdni(fechaActual, dni);
        break;
      case 2:
        return;
        break;
      default:
        cout<<"OPCION INCORRECTA. INGRESE 1 PARA CONSULTAR RESERVAS POR DNI Y 2 PARA VOLVER AL MENU ANTERIOR."<<endl;
          break;
      }
      }

      ArchivoVentas archivoVentas;
      Ventas ventas;
      ventas.activarVenta(ventas,fechaActual, dni);
      ventas.mostrarVenta();

      cout<<"CONFIRMA VENTA? 1 PARA CONFIRMAR, 2 PARA CANCELAR Y 0 PARA VOLVER AL MENU ANTERIOR "<<endl;
      opcion=-1;
      while(opcion!=1 && opcion!=2 && opcion!=0){
      cin>>opcion;
      switch (opcion)
      {
      case 1:
        if(archivoVentas.guardar(ventas)){cout<<"VENTA GUARDADA CON EXITO"<<endl;}
        //modificar estado de facturacion de reserva
        break;
      case 2:
        reservas.cancelarReserva();
        break;
      case 0:
        break;
      default:
        cout<<"OPCION INCORRECTA. INGRESE 1 PARA CONFIRMAR, 2 PARA CANCELAR Y 0 PARA VOLVER AL MENU ANTERIOR"<<endl;
        break;
      }
      }


  }

}



bool Check_In::mostrarReservasActual(){
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

   if(reservas[i].getFechaIngresoReserva()==fechaActual){
      reservas[i].mostrarReserva();
      encontro=true;
   }

  }

  if(encontro==false){
    cout<<"NO HAY RESERVAS PARA EL DIA DE HOY."<<endl;
    delete [] reservas;
    return false;
  }

  delete [] reservas;
  return true;

}


void Check_In::mostrarReservaActualXdni(Fecha fechaActual, const char* dni){

  ArchivoReservas archivoReservas;
  Reservas reserva;

  int cant=archivoReservas.getCantidad();
  Reservas *reservas=new Reservas[cant];

  for (int i=0;i<cant;i++){
    reservas[i]=archivoReservas.leer(i);
  }

  for (int i=0;i<cant;i++){
    if(strcmp(reservas[i].getDniCliente(),dni)==0 && reservas[i].getFechaIngresoReserva()==fechaActual){
      reservas[i].mostrarReserva();
    }

  }
}


