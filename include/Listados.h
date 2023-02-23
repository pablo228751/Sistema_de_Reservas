#ifndef LISTADOS_H
#define LISTADOS_H
#include "ArchivoCliente.h"
#include "ArchivoHabitacion.h"
#include "ArchivoReservas.h"
#include "ArchivoVentas.h"
#include "Usuarios.h"


class Listados
{
  public:
  void listadoClientes();
  void listadoHabitaciones();
  void listadoUsuarios();
  void listadoReservas();

  void consultasPorListado();
  void consultaPorCliente();
  void consultaPorVentas();
  void consultaPorHabitacion();

};

#endif // LISTADOS_H
