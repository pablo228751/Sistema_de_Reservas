#ifndef CONTACTO_H
#define CONTACTO_H
#include <cstring>

class Contacto{
  public:
    //sets
    void setMail(const char* m);
    void setTelefono(const char* t);
    //gets
    const char* getMail();
    const char* getTelefono();
    //metodos
    void CargarContacto();
    void MostrarContacto();


  private:
  char _mail[40];
  char _telefono[40];

};

#endif // CONTACTO_H
