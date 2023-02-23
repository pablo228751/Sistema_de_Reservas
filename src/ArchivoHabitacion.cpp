#include<iostream>
using namespace std;
#include "ArchivoHabitacion.h"

Habitacion ArchivoHabitacion::leer(int nroRegistro) {
  Habitacion reg;
  FILE* p;
  p = fopen("habitaciones.dat", "rb");
  if (p == NULL) {
    return reg;
  }
  fseek(p, nroRegistro * sizeof(Habitacion), SEEK_SET);
  fread(&reg, sizeof(Habitacion), 1, p);
  fclose(p);
  return reg;
}

bool ArchivoHabitacion::leerTodos(Habitacion habitacion[], int cantidad) {
  FILE* p;
  p = fopen("habitaciones.dat", "rb");
  if (p == NULL) {
    return false;
  }
  fread(habitacion, sizeof(Habitacion), cantidad, p);
  fclose(p);
  return true;
}

bool ArchivoHabitacion::guardar(Habitacion reg) {
  FILE* p = fopen("habitaciones.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool ok = fwrite(&reg, sizeof(Habitacion), 1, p);
  fclose(p);
  return ok;
}

bool ArchivoHabitacion::guardar(Habitacion reg, int nroRegistro) {
  FILE* p = fopen("habitaciones.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Habitacion), SEEK_SET);
  bool ok = fwrite(&reg, sizeof(Habitacion), 1, p);
  fclose(p);
  return ok;
}

int ArchivoHabitacion::getCantidad() {
  FILE* p = fopen("habitaciones.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Habitacion);
  fclose(p);
  return cant;
}

int ArchivoHabitacion::buscar(int r) {
  int cant = getCantidad();
  Habitacion habitacion;
  for (int i = 0; i < cant; i++) {
    habitacion = leer(i);
    if (habitacion.getNumero()== r) {
      return i;
    }
  }
  return -1;
}


//BACK UP
bool ArchivoHabitacion::grabarBackUp(Habitacion habitaciones[], int cantidad) {
  FILE* p;
  p = fopen("habitaciones.dat", "wb");
  if (p == NULL) {
    return false;
  }
  fwrite(habitaciones, sizeof(Habitacion), cantidad, p);
  fclose(p);
  return true;
}






