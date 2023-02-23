#ifndef USUARIOS_H
#define USUARIOS_H
#include "Persona.h"
#include <string>
#include "rlutil.h"
#include <algorithm>

using namespace std;




 class Usuarios : public Persona
 {
    private:
        int _nivel_acceso;
        char _contrasenia[50];
        Fecha fecha_registro;
        char _legajo[9];

    public:
        //SETS
        void SetLegajo(const char* legajo);
        void setAcceso(int s);
        void CargarFechaRegistro();

        //GETS
        const char* GetLegajo();
        int getAcceso();
        const char* getContrasenia();

        //METODOS
        void MostrarUsuario();
        bool CrearUsuario();
        void crearPrimerAdmin();
        bool ChequearLegajo(const char *legajo);
        //ARCHIVOS
        void GuardarUsuario();
        void ListaUsuarios();//MOSTRAR
        bool BuscarUsuario(const char* legajo);
        int  ContarCantidadArchivos();
        int leerUsuario(const char* legajo);
        bool bajaOaltaLogica(int pos,bool estado);
        bool modificarUsuario();
        bool leerTodos(Usuarios usuarios[], int cantidad);

        //BACK UP
        bool grabarBackUp(Usuarios usuarios[], int cantidad);

 };

#endif // USUARIOS_H
