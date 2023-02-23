#ifndef ARCHIVORESERVAS_H
#define ARCHIVORESERVAS_H
#include "Reservas.h"

class ArchivoReservas
{
  public:

  Reservas leer(int nroRegistro);

  bool leerTodos(Reservas reserva[], int cantidad);

  bool guardar(Reservas reg) ;

  bool guardar(Reservas reg, int nroRegistro) ;

  int getCantidad() ;

  int buscar(int r);


  //BACK UP
  bool grabarBackUp(Reservas reservas[], int cantidad);


  protected:

  private:
};

#endif // ARCHIVORESERVAS_H
