#include<iostream>
using namespace std;
#include "ArchivoVentas.h"


Ventas ArchivoVentas::leer(int nroRegistro) {
  Ventas reg;
  FILE* p;
  p = fopen("ventas.dat", "rb");
  if (p == NULL) {
    return reg;
  }
  fseek(p, nroRegistro * sizeof(Ventas), SEEK_SET);
  fread(&reg, sizeof(Ventas), 1, p);
  fclose(p);
  return reg;
}

bool ArchivoVentas::leerTodos(Ventas ventas[], int cantidad) {
  FILE* p;
  p = fopen("ventas.dat", "rb");
  if (p == NULL) {
    return false;
  }
  fread(ventas, sizeof(Ventas), cantidad, p);
  fclose(p);
  return true;
}

bool ArchivoVentas::guardar(Ventas reg) {
  FILE* p = fopen("ventas.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool ok = fwrite(&reg, sizeof(Ventas), 1, p);
  fclose(p);
  return ok;
}

bool ArchivoVentas::guardar(Ventas reg, int nroRegistro) {
  FILE* p = fopen("ventas.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Ventas), SEEK_SET);
  bool ok = fwrite(&reg, sizeof(Ventas), 1, p);
  fclose(p);
  return ok;
}

int ArchivoVentas::getCantidad() {
  FILE* p = fopen("ventas.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Ventas);
  fclose(p);
  return cant;
}

int ArchivoVentas::buscar(int r) {
  int cant = getCantidad();
  Ventas ventas;
  for (int i = 0; i < cant; i++) {
    ventas = leer(i);
    for(int i=0;i<3;i++){///--►VECTOR DE 3 RESERVAS COMO MAXIMO
    if (ventas.getNumeroReserva(i)== r) {
      return i;
    }
    }
  }
  return -1;
}


//SOBRE ESCRIBIR  -  BACK UP
bool ArchivoVentas::grabarBackUp(Ventas ventas[], int cantidad) {
  FILE* p;
  p = fopen("ventas.dat", "wb");
  if (p == NULL) {
    return false;
  }
  fwrite(ventas, sizeof(Ventas), cantidad, p);
  fclose(p);
  return true;
}






