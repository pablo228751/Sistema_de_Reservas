#include<iostream>
#include<cstring>
using namespace std;
#include "Ventas.h"
#include "ArchivoVentas.h"
#include "ArchivoReservas.h"

//GETS

const char* Ventas::getDniCliente(){
return _dniCliente;
}
int Ventas::getNumeroReserva(int indice){
return _numeroReserva[indice];
}
Fecha Ventas::getFechaPago(){
return _fechaPago;
}
int Ventas::getNumeroVenta(){
return _numeroVenta;
}
float Ventas::getPagoTotal(){
return _pagoTotal;
}

//SETS


void Ventas:: setDniCliente(const char* dniCliente){
strcpy(_dniCliente, dniCliente);
}

void Ventas:: setNumeroReserva(int numeroReserva[], int indice){
for(int i=0;i<indice;i++){
_numeroReserva[i]=numeroReserva[i];
}
}

void Ventas:: setFechaPago(Fecha fechaPago){

_fechaPago=fechaPago;

}

void Ventas:: setNumeroVenta(int numeroVenta){
_numeroVenta=numeroVenta+1;
}

void Ventas:: setPagoToal(float pagoTotal){

_pagoTotal=pagoTotal;

}

///




//CREAR NUMERO DE RESERVA INCREMENTAL, VA A HACER EL PROCESO DE SUMARLE 1 AL NUMERO DE RESERVA ANTERIOR, PARA QUE EL NUMERO NUNCA SE REPITA Y SIEMPRE ESTE EN ORDEN.
int Ventas::incrementarNumeroVenta()
  {
    Ventas ventas;
    ArchivoVentas archivoVentas;

    int cantidadVentas= archivoVentas.getCantidad();
    if(cantidadVentas==0)
    {
      return 0;
    }

    else
    {

      Ventas* vecVentas= new Ventas[cantidadVentas];

      for(int i=0; i<cantidadVentas; i++)
      {
        vecVentas[i]=archivoVentas.leer(i);
      }

      int maximo=vecVentas[0].getNumeroVenta();
      for(int i=0; i<cantidadVentas; i++)
      {
        if(vecVentas[i].getNumeroVenta()>maximo)
        {
          maximo=vecVentas[i].getNumeroVenta();
        }
      }

      delete [] vecVentas;
      return maximo;
    }


  }





//MOSTRAR

void Ventas:: mostrarVenta(){

cout<<endl<<"Venta N#: ";
cout<<_numeroVenta;

cout<<endl<<"De la reserva N: ";
for(int i=0;i<3;i++){
    if(getNumeroReserva(i)>0){
      cout<<"#";
      cout<<getNumeroReserva(i);
      cout<<", ";
    }

  }
cout<<endl<<"Cliente Dni N#: ";
cout<<_dniCliente;

cout<<endl<<"Fecha de pago: ";
_fechaPago.MostrarFecha();

cout<<"Pago total de: $";
cout<<_pagoTotal<<endl;

}



//CARGAR

//recive como parametro informacion chequeada por una funcion, para asegurar de que no permita cargar 2 veces la misma informacion;
//exepto por el pago, que dicha funcion le pasa el valor total de la venta
void Ventas::cargarVenta(int numeroVenta,int numeroReserva, float pagoTotal){

 cout<<endl<<"Ingrese del DNI del cliente: ";
 cin >>_dniCliente;

 cout<<"Ingrese la fecha de Pago: ";
 _fechaPago.CargarFecha();

}


//Constructor
    Ventas::Ventas(){
    _numeroReserva[0]=0;
    _numeroReserva[1]=0;
    _numeroReserva[2]=0;
  }

///METODOS
//Check in activa ventas
void Ventas::activarVenta(Ventas &ventas, Fecha fechaActual, const char* dni){

  ArchivoVentas archivoVentas;

  ArchivoReservas archivoReservas;
  int cant=archivoReservas.getCantidad();
  Reservas *reservas=new Reservas[cant];
  const int tam=3;
  int vecReservas[tam]={0}, cont=0, j=0;
  bool encontro=false;
  float importeTotal=0;

  for (int i=0;i<cant;i++){
    reservas[i]=archivoReservas.leer(i);
  }

  //Buscamos reserva segun Dni y fecha de reserva para dar de alta la venta
  for (int i=0;i<cant;i++){
    if (strcmp(reservas[i].getDniCliente(),dni)==0 && reservas[i].getCancelar()==false && reservas[i].getEstadoReserva()==true){
      if (reservas[i].getFechaIngresoReserva()==fechaActual){
        vecReservas[j]=reservas[i].getNumeroReserva();
        j++;
        cont++;
        encontro=true;
        importeTotal+=reservas[i].getImporteReserva();

      }
    }
  }


  //Si encontro coincidencia, seteamos ventas y guardamos
  if(encontro==true){
  ventas.setNumeroReserva(vecReservas, cont);
  ventas.setDniCliente(dni);
  //ventas.setNumeroReserva(vecReservas, tam);
  ventas._fechaPago.AsignarFechaActual(_fechaPago);
  //_fechaPago.CargarFecha(); // --► podriamos usar la funcion para que traiga la fecha actual.
  int numVenta=ventas.incrementarNumeroVenta();
  ventas.setNumeroVenta(numVenta);
  ventas.setPagoToal(importeTotal);
  }



  delete [] reservas;

}




