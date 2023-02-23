#ifndef CREARMENU_H
#define CREARMENU_H
#include "DiseniarMenu.h"
#include <string>
#include "Usuarios.h"
#include "rlutil.h"



class CrearMenu
{
    private:
    public:
        int menuInicio();
        int menuUsuario(Usuarios &usuarioLogueado);
        int nivelUsuario();
        void integrantes();
        int menuConsultasListados();
        int menuConsultasInformes();
};

#endif // CREARMENU_H
