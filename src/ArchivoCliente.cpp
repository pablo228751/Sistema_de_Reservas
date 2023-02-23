#include<iostream>
using namespace std;
#include "ArchivoCliente.h"


Cliente ArchivoCliente::leer(int nroRegistro) {
  Cliente reg;
  FILE* p;
  p = fopen("clientes.dat", "rb");
  if (p == NULL) {
    return reg;
  }
  fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
  fread(&reg, sizeof(Cliente), 1, p);
  fclose(p);
  return reg;
}

bool ArchivoCliente::leerTodos(Cliente clientes[], int cantidad) {
  FILE* p;
  p = fopen("clientes.dat", "rb");
  if (p == NULL) {
    return false;
  }
  fread(clientes, sizeof(Cliente), cantidad, p);
  fclose(p);
  return true;
}

bool ArchivoCliente::guardar(Cliente reg) {
  FILE* p = fopen("clientes.dat", "ab");
  if (p == NULL) {
    return false;
  }
  bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
  fclose(p);
  return ok;
}

bool ArchivoCliente::guardar(Cliente reg, int nroRegistro) {
  FILE* p = fopen("clientes.dat", "rb+");
  if (p == NULL) {
    return false;
  }
  fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
  bool ok = fwrite(&reg, sizeof(Cliente), 1, p);
  fclose(p);
  return ok;
}

int ArchivoCliente::getCantidad() {
  FILE* p = fopen("clientes.dat", "rb");
  if (p == NULL) {
    return 0;
  }
  fseek(p, 0, SEEK_END);
  int cant = ftell(p) / sizeof(Cliente);
  fclose(p);
  return cant;
}

int ArchivoCliente::buscar(const char* dni) {
  int cant = getCantidad();
  Cliente cliente;
  for (int i = 0; i < cant; i++) {
    cliente = leer(i);
    if (strcmp(dni,cliente.GetDni())==0) {
      return i;
    }
  }
  return -1;
}




//BACK UP

//SOBRE ESCRIBIR  -  BACK UP
bool ArchivoCliente::grabarBackUp(Cliente clientes[], int cantidad) {
  FILE* p;
  p = fopen("clientes.dat", "wb");
  if (p == NULL) {
    return false;
  }
  fwrite(clientes, sizeof(Cliente), cantidad, p);
  fclose(p);
  return true;
}




