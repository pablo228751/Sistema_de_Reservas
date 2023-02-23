#ifndef VENTAS_H
#define VENTAS_H
#include "Fecha.h"


  class Ventas{
    public:
    //Constructor
    Ventas();

    //GETS
    const char* getDniCliente();
    int getNumeroReserva(int indice);
    Fecha getFechaPago();
    int getNumeroVenta();
    float getPagoTotal();

    //SETS
    void setDniCliente(const char*dniCliente);
    void setNumeroReserva(int numeroReserva[],int indice);
    void setFechaPago(Fecha fechaPago);
    void setNumeroVenta(int numeroVenta);///falta incrementar numero venta
    void setPagoToal(float pagoTotal);

    //MOSTRAR
    void mostrarVenta();

    //CARGAR
    void cargarVenta(int numeroVenta,int numeroReserva, float pagoTotal);

    //METODOS
    void activarVenta(Ventas &ventas, Fecha fechaActual, const char* dni);
    int incrementarNumeroVenta();

    //Como limite el mismo cliente tiene 3 reservas del mismo dia de ingreso
    private:
    char _dniCliente[9];
    int _numeroReserva[3];
    Fecha _fechaPago;
    int _numeroVenta;
    float _pagoTotal;
  };

#endif // VENTAS_H
