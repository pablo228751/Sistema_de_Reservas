#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
#include "Contacto.h"

class Cliente : public Persona{
  public:
    Cliente();
    //SETS
    void SetDni(const char* dni);
    //GETS
    const char* GetDni();
    //METODOS
    void cargarCliente(const char* dni);
    void mostrarCliente();
    void crearCliente();
    void CargarContacto();
    void MostrarContacto();
    void ModificarCliente();


  private:
    char _dni[9];
    Contacto _contacto;
};

#endif // CLIENTE_H


