#ifndef FECHA_H
#define FECHA_H

  class Fecha{
    private:
      int _dia,_mes,_anio,_horas,_minutos,_segundos;
      bool bisiesto;

    public:
      //GETS
      int getDia();
      int getMes();
      int getAnio();

      //SETS
      int setDia(int d);
      int setMes(int m);
      int setAnio(int a);

      //METODOS
      void CargarFecha();
      void FechaActual();
      void MostrarFecha();
      void AsignarFechaActual(Fecha &aux);
      bool esBisiesto(int a);
      bool operator >(Fecha &aux);
      bool operator <(Fecha &aux);
      bool operator ==(Fecha &aux);
      int NumeroSerie();
  };

#endif // FECHA_H
