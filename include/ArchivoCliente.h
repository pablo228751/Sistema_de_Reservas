#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H
#include "Cliente.h"

class ArchivoCliente
{
  public:

  Cliente leer(int nroRegistro);

  bool leerTodos(Cliente clientes[], int cantidad);

  bool guardar(Cliente reg) ;

  bool guardar(Cliente reg, int nroRegistro) ;

  int getCantidad() ;

  int buscar(const char* dni);

  //BACK UP
  bool grabarBackUp(Cliente clientes[], int cantidad);



  protected:

  private:
};

#endif // ARCHIVOCLIENTE_H
