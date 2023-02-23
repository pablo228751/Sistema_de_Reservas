#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"
#include <string>
#include "Funciones.h"
#include "Contacto.h"


class Persona{

    private:
        char _nombre[50],_apellido[50];
        Fecha fecha_nacimiento;
        bool _estado;

    public:
        //sets
        void SetNombre(const char* nombre);
        void SetApellido(const char* apellido);

        void setEstado(bool e);
        //metodos
        void CargarFecha();
        void CargarPersona();
        void MostrarPersona();
        //gets

        const char* GetNombre();
        const char* GetApellido();
        bool getEstado();
};

#endif // PERSONA_H
