#include "Persona.h"
#include <string.h>
#include <iostream>
#include "rlutil.h"
#include <algorithm>
using namespace std;


  //SETS
  void Persona::SetNombre(const char* nombre){

    strcpy(_nombre,nombre);
  }
  void Persona::SetApellido(const char* apellido){

    strcpy(_apellido,apellido);
  }


  void Persona::setEstado(bool e){
  _estado=e;
  }



  //METODOS
  void Persona::CargarFecha(){
    fecha_nacimiento.CargarFecha();
  }

  void Persona::MostrarPersona(){

    cout<<endl<<"Nombre: "<<_nombre;
    cout<<endl<<"Apellido: "<<_apellido;
    cout<<endl<<"Fecha de nacimiento: ";
    fecha_nacimiento.MostrarFecha();

  }

  void Persona::CargarPersona(){

    cout<<endl<<"Nombre: ";
    cargarCadena(_nombre, 49);
    cout<<endl<<"Apellido: ";
    cargarCadena(_apellido, 49);

    cout<<endl<<"Fecha de Nacimiento: ";
    CargarFecha();

    _estado=true;
  }


  ///GETS


  const char* Persona::GetNombre(){
      return _nombre;

  }


  const char* Persona::GetApellido(){
      return _apellido;
  }

  bool Persona::getEstado(){
    return _estado;
  }






