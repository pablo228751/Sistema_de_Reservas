#ifndef HABITACION_H
#define HABITACION_H

class Habitacion{
        public:
        //GETS
        int getNumero();
        int getTipo();
        float getPrecio();
        bool getEstado();

        //SETS
        void setNumero(int numero);
        void setTipo(int tipo);
        void setPrecio(float precio);
        void setEstado(bool estado);

        //METODOS
        void mostrarDesocupadas();
        void mostrarOcupadas();
        void cargarHabitacion(int numero);
        void mostrarHabitacion();

        //se va a utilizar el cargar habitacion dentro
        void crearHabitacion();
        //mostrar todas las habitaciones que hay
        void mostrarHabitaciones();



        private:
        int _numero;
        int _tipo;
        float _precio;
        bool _estado;


};

#endif // HABITACION_H
