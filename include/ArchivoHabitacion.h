#ifndef ARCHIVOHABITACION_H
#define ARCHIVOHABITACION_H
#include "Habitacion.h"

class ArchivoHabitacion
{
  public:

  Habitacion leer(int nroRegistro);

  bool leerTodos(Habitacion [], int cantidad);

  bool guardar(Habitacion reg) ;

  bool guardar(Habitacion reg, int nroRegistro) ;

  int getCantidad() ;

  int buscar(int r);

  //BACK UP
  bool grabarBackUp(Habitacion habitaciones[], int cantidad);


  protected:

  private:
};

#endif // ARCHIVOHABITACION_H
