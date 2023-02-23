#include<iostream>
using namespace std;
#include "ArchivoReservas.h"

Reservas ArchivoReservas::leer(int nroRegistro) {
  Reservas reg;
  FILE* p;
  p = fopen("reservas.dat", "rb");
  if (p == NULL) {
    cout<<"No hay nada en el archivo de reservas"<<endl;
    return reg;
  }
  fseek(p, nroRegistro * sizeof(Reservas), SEEK_SET);
  fread(&reg, sizeof(Reservas), 1, p);
  fclose(p);
  //cout<<"Existen registros en el archivo de reservas"<<endl;
  return reg;
}

bool ArchivoReservas::leerTodos(Reservas reservas[], int cantidad) {
  FILE* p;
  p = fopen("reservas.dat", "rb");
  if (p == NULL) {
    return false;
  }
  fread(reservas, sizeof(Reservas), cantidad, p);
  fclose(p);
  return true;
}

bool ArchivoReservas::guardar(Reservas reg) {
  FILE* p = fopen("reservas.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool ok = fwrite(&reg, sizeof(Reservas), 1, p);
  fclose(p);
  return ok;
}

bool ArchivoReservas::guardar(Reservas reg, int nroRegistro) {
  FILE* p = fopen("reservas.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Reservas), SEEK_SET);
  bool ok = fwrite(&reg, sizeof(Reservas), 1, p);
  fclose(p);
  return ok;
}

int ArchivoReservas::getCantidad() {
  FILE* p = fopen("reservas.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Reservas);
  fclose(p);
  return cant;
}

int ArchivoReservas::buscar(int r) {
  int cant = getCantidad();
  Reservas reserva;
  for (int i = 0; i < cant; i++) {
    reserva = leer(i);
    if (reserva.getNumeroReserva()== r) {
      return i;
    }
  }
  return -1;
}



//SOBRE ESCRIBIR  -  BACK UP
bool ArchivoReservas::grabarBackUp(Reservas reservas[], int cantidad) {
  FILE* p;
  p = fopen("reservas.dat", "wb");
  if (p == NULL) {
    return false;
  }
  fwrite(reservas, sizeof(Reservas), cantidad, p);
  fclose(p);
  return true;
}


