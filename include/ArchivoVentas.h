#ifndef ARCHIVOVENTAS_H
#define ARCHIVOVENTAS_H
#include "Ventas.h"


class ArchivoVentas
{
  public:

  Ventas leer(int nroRegistro);

  bool leerTodos(Ventas [], int cantidad);

  bool guardar(Ventas reg) ;

  bool guardar(Ventas reg, int nroRegistro) ;

  int getCantidad() ;

  int buscar(int r);

  //BACK UP
  bool grabarBackUp(Ventas ventas[], int cantidad);





  protected:

  private:
};

#endif // ARCHIVOVENTAS_H
