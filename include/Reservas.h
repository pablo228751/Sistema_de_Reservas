#ifndef RESERVAS_H
#define RESERVAS_H
#include "Fecha.h"
#include "Habitacion.h"
#include "Cliente.h"

class Reservas
{


  public:
    //SETS
    void setDniCliente(const char* d);
    void setNumeroHabitacion(int n);
    void setFechaReserva(Fecha f);
    void setFechaIngreso( Fecha f);
    void setFechaEgreso(Fecha f );
    void setEstadoReserva(bool e);
    void setMetodoPago(int m);
    void setNumeroReserva(int r);
    void setImporteReserva(int i);
    void setCancelar(bool can);/////CANCELA LAS RESERVAS

    //GETS
    const char* getDniCliente();
    int getHabitacionReserva();
    bool getEstadoReserva();
    int getNumeroReserva();
    int getMetodoPago();
    Fecha getFechaIngresoReserva();
    Fecha getFechaEgresoReserva();
    float getImporteReserva();
    bool getCancelar();/////CANCELA LAS RESERVAS


    //METODOS
    void cargarReserva(const char* dni, int habitacion, Fecha fechaIngresoReservaMetodo, Fecha fechaEgresoReservaMetodo);
    void mostrarReserva();
    void mostrasTodasLasReservas();

    int incrementarNumeroReserva();

    void consultarReserva();

    //RESERVA
    bool buscarDisponibilidad(bool vecHab[], Fecha fIngresoR, Fecha fEgresoR);
    void hacerReserva(bool vecHab[],Fecha fIngresoR, Fecha fEgresoR, Cliente cliente);
    void mostrarDisponibles(bool vecHab[],Fecha fIngresoR, Fecha fEgresoR);
    void cargarDiasOcupados(bool vecDias[], int tam, Fecha fIngresoR, Fecha fEgresoR);
    void cargarOcupacion2(bool matrizMesDias[][31],int meses, int dias, Fecha fIngresoR, Fecha fEgresoR);
    void cargarOcupacion3(bool matrizMesDias[][31],int meses, int dias, Fecha fIngresoR, Fecha fEgresoR, int anio);
    int calcularDias(int dI=0, int mI=0, int aI=0, int dE=0, int mE=0, int aE=0);
    float obtenerImporteReserva(Fecha fIngresoR, Fecha fEgresoR, int numHabitacion);
    bool limiteReservas(Fecha fIngresoR, const char* dni);

    //CANCELAR RESERVA
    void cancelarReserva();




    //APARECEN EN MENU
    //punto 1
    void reservar(Cliente cliente);
    //punto 5
    void disponibilidad();


  protected:

  private:
    char _dniCliente[9];
    int _numeroHabitacion;
    Fecha _fechaReserva;
    Fecha _fechaIngreso;
    Fecha _fechaEgreso;
    bool _estado;//--►este estado es para saber si la habitacion esta disponible o no
    bool _cancelar;//--►este estado muestra si la reserva fue cancelada o no
    int _numeroReserva;//FALTA ASIGNAR UN SET.
    int _metodoPago;
    float _importeReserva;


};

#endif // RESERVAS_H
