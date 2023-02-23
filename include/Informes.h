#ifndef INFORMES_H
#define INFORMES_H
#include "ArchivoCliente.h"
#include "ArchivoHabitacion.h"
#include "ArchivoReservas.h"
#include "ArchivoVentas.h"


class Informes
{
  public:
  void consultasPorInformes();
  void recaudacionAnual();
  void recaudacionAnualPorCliente();
  void recaudacionAnualPorHabitacion();

};

#endif // INFORMES_H
