#ifndef CHECK_IN_H
#define CHECK_IN_H


class Check_In
{
  public:

  //METODOS
  void hacerCheckIn();
  bool mostrarReservasActual();
  void mostrarReservaActualXdni(Fecha fechaActual, const char* dni);

};

#endif // CHECK_IN_H
