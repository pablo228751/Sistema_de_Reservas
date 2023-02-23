#include "Fecha.h"
#include <ctime>
#include <iostream>
using namespace std;

 //GETS
    int Fecha::getDia(){ return _dia;}
    int Fecha::getMes(){return _mes;}
    int Fecha::getAnio(){return _anio;}

//SETS
    int Fecha::setDia(int d){_dia=d;}
    int Fecha::setMes(int m){_mes=m;}
    int Fecha::setAnio(int a){_anio=a;}


//METODOS
    void Fecha::CargarFecha(){
        int dato;
        cout<<endl<<" DIA: ";
        cin>>dato;

        while(dato<=0 || dato>31){

            cout<<endl<<"Los dias son del 1 hasta el 31, carguelos nuevamente: ";
            cin>>dato;
        }
        _dia=dato;
        cout<<" MES: ";
        cin>>dato;
        while(dato<=0 || dato>12){

            cout<<endl<<"Los meses son del 1 hasta el 12, carguelos nuevamente: ";
            cin>>dato;
        }
        _mes=dato;
        cout<<" AÑO: ";
        cin>>dato;
        while(dato<1900){

            cout<<endl<<"Los años validos son a partir del año 1900, carguelos nuevamente: ";
            cin>>dato;
        }
        _anio=dato;
    }

    void Fecha::MostrarFecha(){
        cout<<_dia<<"/"<<_mes<<"/"<<_anio<<endl;
    }

    void Fecha::FechaActual(){
        time_t t;
        t= time(NULL);
        struct tm *fecha;
        fecha= localtime(&t);
        cout<<endl<<" Fecha Actual: "<<fecha->tm_mday<<"/"<<fecha->tm_mon+1<<"/"<<fecha->tm_year+1900<<endl<<endl;
    }


    void Fecha::AsignarFechaActual(Fecha &aux){
        time_t t;
        t= time(NULL);
        struct tm *fecha;
        fecha= localtime(&t);

        aux.setDia(fecha->tm_mday);
        aux.setMes(fecha->tm_mon+1);
        aux.setAnio(fecha->tm_year+1900);
        //cout<<endl<<" Fecha Actual: "<<fecha->tm_mday<<"/"<<fecha->tm_mon+1<<"/"<<fecha->tm_year+1900<<endl<<endl;
    }

    bool Fecha::esBisiesto(int a){
      bisiesto=false;
      if(a%4==0){
        bisiesto=true;
      }
      if((a%100==0) && (a%400!=0)){
        bisiesto=false;
      }
      return bisiesto;
    }

  ///SOBRECARGA PARA COMPARAR ENTRE 2 OBJETOS FECHA.

    bool Fecha::operator>(Fecha &aux){
     if(NumeroSerie()>aux.NumeroSerie()){
      return true;
      }
      return false;
    }


    bool Fecha::operator<(Fecha &aux){
      if(NumeroSerie()<aux.NumeroSerie()){
      return true;
      }
      return false;
    }


    bool Fecha::operator==(Fecha &aux){
      if(NumeroSerie()==aux.NumeroSerie()){
      return true;
      }
      return false;
    }


  ///DE FECHA A NUMERO DE SERIE PARA PODER COMPARAR SI LAS FECHAS SON IGUALES, MENORES O MAYORES CON LA SOBRECARGA Y ASI SABER SI LA HABITACION ESTA DISPONIBLE O NO
  int Fecha::NumeroSerie(){
    int cont=0,i;
    for(i=1900;i<_anio;i++)
        if(esBisiesto(i)) {cont++;}
      int vmes[]={31,28,31,30,31,30,31,31,30,31,31,31},suma=0;
      if(esBisiesto(_anio)) {vmes[1]=29;}
        for(int i=0;i<_mes-1;i++) {suma+=vmes[i];}
      int cantdias=(_anio-1900)*365+cont+suma+_dia;
      return cantdias;
  }
