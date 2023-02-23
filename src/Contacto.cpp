#include<iostream>
using namespace std;
#include "Contacto.h"
#include "Funciones.h"



    //sets
    void Contacto::setMail(const char* m){
    strcpy(_mail, m);
    }

    void Contacto::setTelefono(const char* t){
    strcpy(_telefono, t);
    }


    //gets
    const char* Contacto::getMail(){
    return _mail;
    }

    const char* Contacto::getTelefono(){
    return _telefono;
    }

    //METODOS
    void Contacto::CargarContacto(){
      cout<<"EMAIL: "<<endl;
      cargarCadena(_mail,39);
      cout<<"TELEFONO: "<<endl;
      cargarCadena(_telefono,39);
    }


    void Contacto::MostrarContacto(){
      cout<<"EMAIL: "<<_mail<<endl;
      cout<<"TELEFONO: "<<_telefono<<endl;
    }
