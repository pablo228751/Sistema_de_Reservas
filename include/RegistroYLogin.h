#ifndef REGISTROYLOGIN_H
#define REGISTROYLOGIN_H
#include "Usuarios.h"


class RegistroYLogin
{

    public:
       bool login();
       bool registrarse();
       void listarUsuarios();
       void buscarPorLegajo();
       bool FiltroRegistro();
       Usuarios usuarioLogueado;


};

#endif // REGISTROYLOGIN_H
