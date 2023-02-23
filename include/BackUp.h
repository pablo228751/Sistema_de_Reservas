#ifndef BACKUP_H
#define BACKUP_H
#include "ArchivoCliente.h"
#include "ArchivoHabitacion.h"
#include "ArchivoReservas.h"
#include "ArchivoVentas.h"
#include "Usuarios.h"

class BackUp
{
  public:
  //REALIZAR COPIA DE SEGURIDAD
  void realizarCopiaSeguridad();
  bool guardarTodos(string fecha, Usuarios usuarios[], int cantidad);
  bool guardarTodos(string fecha, Habitacion habitacion[], int cantidad);
  bool guardarTodos(string fecha, Cliente clientes[], int cantidad);
  bool guardarTodos(string fecha, Ventas ventas[], int cantidad);
  bool guardarTodos(string fecha, Reservas reservas[], int cantidad);

  //RESTAURAR COPIA DE SEGURIDAD


  void restaurarCopiaSeguridad();

  //Habitaciones
  bool leerTodos(const char* archivoHabitaciones, Habitacion habitaciones[], int cantidad);
  int  getCantidadHabitaciones(const char* archivoHabitaciones);

  //Usuarios
  bool leerTodos(const char* archivoUsuarios, Usuarios usuarios[], int cantidad);
  int  getCantidadUsuarios(const char* archivoUsuarios);

  //Reservas
  bool leerTodos(const char* archivoReservas, Reservas reservas[], int cantidad);
  int getCantidadReservas(const char* archivoReservas);
  //Ventas
  bool leerTodos(const char* archivoVentas, Ventas ventas[], int cantidad);
  int getCantidadVentas(const char* archivoVentas);
  //Clientes
  int getCantidadClientes(const char* archivoClientes);
  bool leerTodos(const char* archivoClientes, Cliente clientes[], int cantidad);


  protected:

  private:
};

#endif // BACKUP_H
