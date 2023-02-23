#include<iostream>
#include "rlutil.h"
using namespace std;
#include "Reservas.h"
#include "ArchivoHabitacion.h"
#include "ArchivoReservas.h"
#include "Funciones.h"
#include<cstring>
#include "ArchivoCliente.h"
using namespace rlutil;




//SETS
void Reservas::setDniCliente(const char* d)
{
    strcpy(_dniCliente,d);
}

void Reservas::setNumeroHabitacion(int n)
{
    _numeroHabitacion=n;
}

void Reservas::setFechaReserva(Fecha f)
{
    _fechaReserva.CargarFecha();
}

void Reservas::setFechaIngreso(Fecha f)
{
    _fechaIngreso.CargarFecha();
}

void Reservas::setFechaEgreso(Fecha f)
{
    _fechaEgreso.CargarFecha();
}

void Reservas::setEstadoReserva(bool e)
{
    _estado=e;
}

void Reservas::setMetodoPago(int m)
{
    _metodoPago=m;
}

void Reservas::setNumeroReserva(int r)
{
    _numeroReserva=r+1;
}



void Reservas::setImporteReserva(int i)
{
    _importeReserva=i;
}


void Reservas:: setCancelar(bool can)
{
    _cancelar=can;
}




//GETS
const char* Reservas::getDniCliente()
{
    return _dniCliente;
}
int Reservas::getHabitacionReserva()
{
    return _numeroHabitacion;
}
bool Reservas::getEstadoReserva()
{
    return _estado;

}

int Reservas::getNumeroReserva()
{
    return _numeroReserva;
}

int Reservas::getMetodoPago()
{
    return _metodoPago;
}

Fecha Reservas::getFechaIngresoReserva()
{
    return _fechaIngreso;
}

Fecha Reservas::getFechaEgresoReserva()
{
    return _fechaEgreso;
}


float Reservas::getImporteReserva()
{
    return _importeReserva;
}



bool Reservas:: getCancelar()
{
    return _cancelar;
}


//METODOS
void Reservas::cargarReserva(const char* dni, int habitacion, Fecha fechaIngresoReservaMetodo, Fecha fechaEgresoReservaMetodo)
{
    strcpy(_dniCliente,dni);
    cout<<"DNI: "<<_dniCliente<<endl;
    _numeroHabitacion=habitacion;
    cout<<"Numero de habitacion: "<<_numeroHabitacion<<endl;

    cout<<"Ingrese fecha de reserva: "<<endl;
    _fechaReserva.CargarFecha(); // --► podriamos usar la funcion para que traiga la fecha actual.

    cout<<"Fecha de ingreso: "<<endl;
    _fechaIngreso=fechaIngresoReservaMetodo;
    fechaIngresoReservaMetodo.MostrarFecha();
    //_fechaIngreso.CargarFecha();
    cout<<"Fecha de egreso: "<<endl;
    _fechaEgreso=fechaEgresoReservaMetodo;
    fechaEgresoReservaMetodo.MostrarFecha();
    //_fechaEgreso.CargarFecha();

    _importeReserva=obtenerImporteReserva(fechaIngresoReservaMetodo, fechaEgresoReservaMetodo,  _numeroHabitacion);
    cout<<"Total a abonar :"<<_importeReserva<<endl;

    cout<<"Ingrese metodo de pago: "<<endl;
    cin>>_metodoPago;

    _estado=true;
    _cancelar=false;
}


//MOSTRAR RESERVAS  (SOLO ACTIVAS)
void Reservas::mostrarReserva()
{
    if (_estado==true && _cancelar==false)
    {
        cout<<"DNI: "<<_dniCliente<<endl;
        cout<<"Numero de habitacion: "<<_numeroHabitacion<<endl;
        cout<<"Fecha de reserva: "<<endl;
        _fechaReserva.MostrarFecha();
        cout<<"Fecha de ingreso: "<<endl;
        _fechaIngreso.MostrarFecha();
        cout<<"Fecha de egreso: "<<endl;
        _fechaEgreso.MostrarFecha();
        cout<<"Metodo de pago: "<<_metodoPago<<endl;
        cout<<"Numero de reserva: "<<_numeroReserva<<endl;
        cout<<"Estado de reserva: "<<_estado<<endl;
        cout<<"Cancelada: "<<_cancelar<<endl;
    }
}


//Muestra TODAS las reservas
void Reservas::mostrasTodasLasReservas()
{

    cout<<"DNI: "<<_dniCliente<<endl;
    cout<<"Numero de habitacion: "<<_numeroHabitacion<<endl;
    cout<<"Fecha de reserva: "<<endl;
    _fechaReserva.MostrarFecha();
    cout<<"Fecha de ingreso: "<<endl;
    _fechaIngreso.MostrarFecha();
    cout<<"Fecha de egreso: "<<endl;
    _fechaEgreso.MostrarFecha();
    cout<<"Metodo de pago: "<<_metodoPago<<endl;
    cout<<"Numero de reserva: "<<_numeroReserva<<endl;
    cout<<"Estado de reserva: "<<_estado<<endl;
    cout<<"Cancelada: "<<_cancelar<<endl;


}



//CREAR NUMERO DE RESERVA INCREMENTAL, VA A HACER EL PROCESO DE SUMARLE 1 AL NUMERO DE RESERVA ANTERIOR, PARA QUE EL NUMERO NUNCA SE REPITA Y SIEMPRE ESTE EN ORDEN.
int Reservas::incrementarNumeroReserva()
{

    Reservas reserva;
    ArchivoReservas archivoReservas;

    int cantidadReservas= archivoReservas.getCantidad();
    if(cantidadReservas==0)
    {
        return 0;
    }

    else
    {

        Reservas* vecReservas= new Reservas[cantidadReservas];

        for(int i=0; i<cantidadReservas; i++)
        {

            vecReservas[i]=archivoReservas.leer(i);


        }

        int maximo=vecReservas[0].getNumeroReserva();
        for(int i=0; i<cantidadReservas; i++)
        {

            if(vecReservas[i].getNumeroReserva()>maximo)
            {

                maximo=vecReservas[i].getNumeroReserva();
            }
        }


        delete [] vecReservas;
        return maximo;
    }
}





///RESERVAS
//Busca y devuelve false si no esta disponible alguna habitacion en la fecha solicitada.
bool Reservas::buscarDisponibilidad(bool vecHab[],Fecha fIngresoR, Fecha fEgresoR)
{
    int tipoHabitacion;
    cout<<"\nINGRESE TIPO DE HABITACION"<<endl;
    cout<<"1 PARA HABITACION SIMPLE"<<endl;
    cout<<"2 PARA HABITACION DOBLE"<<endl;
    cout<<"3 PARA HABITACION TRIPLE"<<endl;
    cin>>tipoHabitacion;
    ArchivoReservas archivoReservas;
    ArchivoHabitacion ArchivoHabitacion;
    int tamReservas=archivoReservas.getCantidad();
    int tamHabitacion=ArchivoHabitacion.getCantidad();
    Reservas *reservas=new Reservas[tamReservas];
    Habitacion *habitacion=new Habitacion[tamHabitacion];
    //Cargamos un contador para saber si no hubo ninguna habitacion que cumpliera con los requisitos, en ese caso devuelve false la funcion y buscamos opciones para el cliente
    int contador=0;



    //Cargamos reservas y habitaciones con vector dinamico
    for(int i=0; i<tamReservas; i++)
    {
        reservas[i]=archivoReservas.leer(i);
    }
    for (int i=0; i<tamHabitacion; i++)
    {
        habitacion[i]=ArchivoHabitacion.leer(i);
    }
    //Cargamos un booleano de habitaciones para poner en true las que estan ocupadas en la fecha dada
    bool habitacionDisponible;

    int i;
    //Buscamos si hay alguna habitacion disponible en cuanto a las fechas solicitadas
    for(i=0; i<tamHabitacion; i++)
    {
        habitacionDisponible=true;
        if (tipoHabitacion==habitacion[i].getTipo() && habitacion[i].getEstado()==true)
        {
            for(int j=0; j<tamReservas; j++)
            {

                if(reservas[j].getEstadoReserva()==true && reservas[j].getHabitacionReserva()==habitacion[i].getNumero())
                {
                    ///EVALUA SI HAY RESERVAS REALIZADAS EN LAS FECHAS SOLICITADAS POR CADA HABITACION. MUESTRA SI HAY ALGUNA DESOCUPADA EN ESAS FECHAS

                    if(reservas[j].getFechaIngresoReserva()>fIngresoR && (reservas[j].getFechaEgresoReserva()>fIngresoR==false) )
                    {
                        if(reservas[j].getFechaEgresoReserva()<fEgresoR||reservas[j].getFechaEgresoReserva()>fEgresoR)
                        {
                            habitacionDisponible=false;

                        }


                    }

                    if(reservas[j].getFechaIngresoReserva()<fIngresoR && (reservas[j].getFechaEgresoReserva()<fIngresoR==false)  )
                    {
                        if(reservas[j].getFechaEgresoReserva()>fIngresoR || reservas[j].getFechaEgresoReserva()>fEgresoR)
                        {
                            habitacionDisponible=false;

                        }

                    }





                    if(reservas[j].getFechaIngresoReserva()==fIngresoR || reservas[j].getFechaEgresoReserva()==fEgresoR)
                    {
                        habitacionDisponible=false;

                    }


                    if((reservas[j].getFechaIngresoReserva()>fIngresoR && reservas[j].getFechaEgresoReserva()>fEgresoR && reservas[j].getFechaEgresoReserva()<fIngresoR) ||
                            (reservas[j].getFechaIngresoReserva()<fIngresoR && reservas[j].getFechaEgresoReserva()<fEgresoR && reservas[j].getFechaEgresoReserva()<fIngresoR))
                    {
                        habitacionDisponible=true;

                    }



                }
            }

            //Mostramos la habitacion si no se encontro en el archio de reservas en las fechas solicitadas
            if(habitacionDisponible==true)
            {
                setColor(LIGHTGREEN);
                cout<<"\n----------------------------------"<<endl;
                cout<<"HABITACION #"<<habitacion[i].getNumero()<<endl;
                cout<<"-----------------------------------"<<endl;
                cout<<"LAS FECHAS NO COINCIDEN. SE PUEDE RESERVAR LA HABITACION."<<endl;
                vecHab[habitacion[i].getNumero()-1]=true;
                contador++;
                habitacion[i].mostrarHabitacion();
                cout<<endl;
                setColor(WHITE);
            }
            else
            {
                setColor(LIGHTRED);
                cout<<"\n----------------------------------"<<endl;
                cout<<"HABITACION #"<<habitacion[i].getNumero()<<endl;
                cout<<"----------------------------------"<<endl;
                cout<<"LAS FECHAS COINCIDEN. LA HABITACION NO SE PUEDE RESERVAR EN ESOS DIAS"<<endl<<endl;
                setColor(WHITE);
            }
        }

    }

    //Si el contador==0 significa que no hay ninguna habitación que estaba disponible entre esas dos fechas ingresadas
    if(contador==0)
    {
        cout<<"No hay habitaciones disponibles en el periodo solicitado"<<endl;
        delete [] reservas;
        delete [] habitacion;

        return false;
    }


    return true;

    delete [] reservas;
    delete [] habitacion;



}


//Si coinciden las fechas solicitadas con alguna habitacion disponible, procedemos a cargar la reserva
void Reservas::hacerReserva(bool vecHab[], Fecha fIngresoR, Fecha fEgresoR, Cliente cliente)
{
    //Cliente cliente;
    Reservas reservaAux;
    ArchivoReservas archivoReservas;
    ArchivoCliente archivoCliente;
    int nHabitacion;
    bool limite=false;
    ArchivoHabitacion archivoHabitacion;
    int cantHabitaciones=archivoHabitacion.getCantidad();

    ///Elegimos la habitacion para hacer la reserva

    int bandera2=0;
    cout<<"\nIngrese N° de habitacion a reservar "<<endl;


    while(bandera2==0)
    {
        cin>>nHabitacion;
        for(int i=0; i<cantHabitaciones; i++)
        {

            if(i==nHabitacion-1 && vecHab[i]==false && bandera2==0)
            {
                cout<<"La habitacion ingresada es incorrecta. Ingrese nuevamente: ";
                bandera2=0;
            }
            else
            {
                if(i==nHabitacion-1 && vecHab[i]==true)
                {
                    bandera2=1;

                }
            }

        }

    }

    if(strcmp(cliente.GetDni(), "0")==0)
    {

        //Cargamos el cliente --► PEDIMOS DNI PARA BUSCAR EN EL ARCHIVO SI YA EXISTE
        char dni[9];
        cout<<"Ingrese numero de DNI: "<<endl;
        cargarCadena(dni, 8);

        if(limiteReservas(fIngresoR, dni)==true)
        {
            cout<<"EL CLIENTE #"<<dni<<" SUPERO EL LIMITE DE 3 RESERVAS PARA LA MISMA FECHA DE INGRESO"<<endl<<endl;
            limite=true;
            return;
        }

        //Buscamos si el cliente ya figura en los archivos, para no pedirle todos los datos nuevamente.
        int pos=archivoCliente.buscar(dni);
        if(pos>=0)
        {
            cliente=archivoCliente.leer(pos);
            cliente.mostrarCliente();
        }
        else
        {
            cliente.cargarCliente(dni);
            //Guardamos el cliente en un archivo
            if(archivoCliente.guardar(cliente))
            {
                cout<<"Cliente guardado exitosamente."<<endl;
            }
            else
            {
                cout<<"No se pudo guardar el cliente."<<endl;
                return;
            }


        }
    }

    //Cargamos la reserva, le pasamos el Dni del cliente y la habitacion solicitada
    reservaAux.cargarReserva(cliente.GetDni(), nHabitacion, fIngresoR, fEgresoR);
    reservaAux.setNumeroReserva(reservaAux.incrementarNumeroReserva());
    if(archivoReservas.guardar(reservaAux))
    {
        cout<<"Reserva realizada exitosamente."<<endl;
    }
    else
    {
        cout<<"No se pudo realizar la reserva."<<endl;

    }

    if(limite==false)
    {
        if(limiteReservas(fIngresoR, cliente.GetDni())==true)
        {
            cout<<"EL CLIENTE #"<<cliente.GetDni()<<" SUPERO EL LIMITE DE 3 RESERVAS PARA LA MISMA FECHA DE INGRESO"<<endl<<endl;
            limite=true;
            return;
        }
        else
        {
            cout<<"EL CLIENTE #"<<cliente.GetDni()<<" PUEDE REALIZAR OTRA RESERVA"<<endl<<endl;
        }

        ///Preguntar si deseamos realizar la reserva. Si no no grabamos.--► ver si agregar opcion
        int opcion=-1;
        cout<<"Desea realizar otra reserva con el mismo DNI?"<<endl;
        cout<<"Presione 1 para confirmar, y 2 para volver al menu anterior."<<endl;
        cin>>opcion;

        while(opcion!=2 && limite==false)
        {

            switch (opcion)
            {
            case 1:
                reservaAux.reservar(cliente);
                break;

            case 2:
                return;
                break;

            default:
                cout<<"Opcion incorrecta. Vuelva a ingresar ua opcion valida (1 para realizar reserva y 2 para volver al menu anterior)"<<endl;
            }


            if(limiteReservas(fIngresoR, cliente.GetDni())==true)
            {
                cout<<"EL CLIENTE #"<<cliente.GetDni()<<" SUPERO EL LIMITE DE 3 RESERVAS PARA LA MISMA FECHA DE INGRESO"<<endl<<endl;
                limite=true;
                return;
            }
            else
            {
                cout<<"EL CLIENTE #"<<cliente.GetDni()<<" PUEDE REALIZAR OTRA RESERVA"<<endl<<endl;
            }

            ///Preguntar si deseamos realizar la reserva. Si no no grabamos.--► ver si agregar opcion
            int opcion=-1;
            cout<<"Desea realizar otra reserva con el mismo DNI?"<<endl;
            cout<<"Presione 1 para confirmar, y 2 para volver al menu anterior."<<endl;
            cin>>opcion;
        }
    }
    else
    {
        return;
    }
}


//Devuelve true si ya hay 3 reservas para el mismo dia para el mismo cliente
bool Reservas::limiteReservas(Fecha fIngresoR, const char* dni)
{
    ArchivoReservas archivoReservas;
    int cant=archivoReservas.getCantidad(), cont=0;
    Reservas *reservas=new Reservas[cant];

    for (int i=0; i<cant; i++)
    {
        reservas[i]=archivoReservas.leer(i);
    }

    for (int i=0; i<cant; i++)
    {
        if(strcmp(reservas[i].getDniCliente(),dni)==0 && reservas[i].getFechaIngresoReserva()==fIngresoR && reservas[i].getCancelar()==false)
        {
            cont++;

        }
    }

    if(cont>=3)
    {
        delete [] reservas;
        return true;
    }

    delete [] reservas;
    return false;
}



///Mostramos las habitaciones disponibles entre 2 fechas dadas, pudiendo ser del mismo mes o no. Mostramos los dias disponibles de c/ habitacion por el mes/ses ingresados.---► se podria agregar UN FILTRO SEGUN TIPO DE HABITACION. (1-SIMPLE, 2-DOBLE, 3-PREMIUM)
void Reservas::mostrarDisponibles(bool vecHab[], Fecha fIngresoR, Fecha fEgresoR)
{
    ArchivoReservas archivoReservas;
    ArchivoHabitacion archivoHabitacion;
    int tamReservas=archivoReservas.getCantidad();
    int tamHabitacion=archivoHabitacion.getCantidad();

    for(int i=0; i<tamHabitacion; i++)
    {
        vecHab[i]=false;
    }


    Reservas *reservas=new Reservas[tamReservas];
    Habitacion *habitacion=new Habitacion[tamHabitacion];

    //Cargamos reservas y habitaciones con vector dinamico
    for(int i=0; i<tamReservas; i++)
    {
        reservas[i]=archivoReservas.leer(i);
    }
    for (int i=0; i<tamHabitacion; i++)
    {
        habitacion[i]=archivoHabitacion.leer(i);
    }

    ///1° OPCION --► MISMO MES Y MISMO ANIO DE F. INGRESO Y F. SALIDA
    //Cargamos un booleano de dias en false para luego mostrar solo dias los que estan en false --► hab. sin ocupar dicho dia
    const int dias=31, meses=12;
    int opcion;
    ///3° OPCION y 4° OPCION --► Calculamos la cantidad de anios de diferencia para saber cuantos anios cargar y mostrar disponibiildad


    int cantAnios=fEgresoR.getAnio()-fIngresoR.getAnio()+1;
    if(cantAnios>1)
    {
        cout<<"\nNo se puede mostrar la disponibilidad de habitaciones del siguiente año, ingrese otra fecha."<<endl;
        Fecha fechaActual;
        fechaActual.AsignarFechaActual(fechaActual);
        bool validarFecha=false;
        int opcion;
        //Le pedimos al cliente la fecha de estadia ---► ver si pasar los datos de fecha como parametros
        cout<<"Ingrese una nueva fecha de ingreso de estadia "<<endl;
        fIngresoR.CargarFecha();
        cout<<"Ingrese una nueva fecha de egreso de estadia "<<endl;
        fEgresoR.CargarFecha();

        while(validarFecha!=true)
        {

            if((fIngresoR>fechaActual || fIngresoR==fechaActual) && fEgresoR>fIngresoR && fEgresoR>fechaActual)
            {
                validarFecha=true;
            }
            else
            {
                cout<<"Ingreso incorrecto. 1 Para volver a ingresar las fechas, 2 Para volver al menu anterior."<<endl;
                cin>>opcion;
                if(opcion==1)
                {
                    cout<<"Fecha de ingreso de estadia "<<endl;
                    fIngresoR.CargarFecha();
                    cout<<"Fecha de egreso de estadia "<<endl<<endl;
                    fEgresoR.CargarFecha();
                }
                else
                {
                    return;
                }
            }
        }

        this->buscarDisponibilidad(vecHab,fIngresoR, fEgresoR);
    }



    int anio;


    for(int i=0; i<tamHabitacion; i++)
    {
        bool vecDias[dias];
        bool matrizMesDias[meses][dias];
        ///Vector para OPCION 1 --► ver para meses como febrero como mostrarlo.--►reiniciamos en false
        for(int u=0;u<dias;u++){
            vecDias[u]= false;
        }

        ///Matriz para OPCION 2 --► ver para meses como febrero como mostrarlo.--►reiniciamos en false
        for(int u=0;u<meses;u++){

            for(int o=0;o<dias;o++){
                matrizMesDias[u][o]= false;

            }

        }



        for(int j=0; j<tamReservas; j++)
        {
            if(reservas[j].getEstadoReserva()==true && reservas[j].getHabitacionReserva()==habitacion[i].getNumero())
            {

                ///1° OPCION --► MISMO ANIO Y MISMO MES DE F. INGRESO Y F. SALIDA
                //Cargamos 1 vector booleano de dias en false para luego mostrar solo dias los que estan en false --► hab. sin ocupar dicho dia
                if(fIngresoR.getAnio()==fEgresoR.getAnio() &&  fIngresoR.getMes()==fEgresoR.getMes())
                {

                    cargarDiasOcupados(vecDias,dias, reservas[j].getFechaIngresoReserva(), reservas[j].getFechaEgresoReserva());
                    opcion=1;
                }

                ///2° OPCION --► MISMO ANIO Y DISTINTO MES DE F. INGRESO Y F. SALIDA
                //Cargamos una matriz booleanos de dias en false para luego mostrar solo dias los que estan en false --► hab. sin ocupar dicho dia
                if(fIngresoR.getAnio()==fEgresoR.getAnio() &&  fIngresoR.getMes()!=fEgresoR.getMes())
                {

                    cargarOcupacion2(matrizMesDias, meses, dias, reservas[j].getFechaIngresoReserva(), reservas[j].getFechaEgresoReserva());
                    opcion=2;
                }

            }
        }

        ///MOSTRAMOS HABITACION POR HABITACION SEGUN FECHAS DISPONIBLES DENTRO DEL RANGO DE LAS 2 FECHAS INDICADAS --► Acomodar por si se quiere ver otro mes, que vuelva a calcular entre otras dos fechas.
        ///BOOL QUE DEVUELVE TRUE SI ESTA DISPONIBLE
        bool habitacionDisponible=false;
        ///MOSTRAMOS HABITACION POR HABITACION SEGUN FECHAS DISPONIBLES DENTRO DEL RANGO DE LAS 2 FECHAS INDICADAS --► Acomodar por si se quiere ver otro mes, que vuelva a calcular entre otras dos fechas.
        if(opcion==1)
        {


            //CORROBORAMOS QUE LA HABITACION TENGA AL MENOS 1 DIA DISPONIBLE
            //PRIMERO DEBEMOS VER QUE MUESTRE SOLO LOS DIAS REALES (FEBRERO SOLO 28 DIAS POR EJEMPLO)
            cout<<"\nDIAS DISPONIBLES DE LA HABITACIÓN #"<<habitacion[i].getNumero()<<endl;
            int diasReales;
            int mesSolicitado=fIngresoR.getMes();
            if(mesSolicitado==4 || mesSolicitado==6 || mesSolicitado==9 || mesSolicitado==11)
            {
                diasReales=30;
            }
            else
            {
                if(mesSolicitado==1 || mesSolicitado==3 || mesSolicitado==5 || mesSolicitado==7 || mesSolicitado==8 || mesSolicitado==10 || mesSolicitado==12)
                {
                    diasReales=31;
                }
                if(mesSolicitado==2)
                {
                    ///VER SI ES ANIO BICIESTO
                    diasReales=28;
                }
            }


            for (int i=0; i<diasReales; i++)
            {
                if(vecDias[i]==false)
                {
                    habitacionDisponible=true;
                }
            }

            //MOSTRAMOS HABITACION
            if(habitacionDisponible==true)
            {
                vecHab[habitacion[i].getNumero()-1]=true;
                habitacion[i].mostrarHabitacion();
                cout<<"\n-------------------"<<endl;
                cout<<"MES #"<<mesSolicitado;
                cout<<"\n-------------------"<<endl;
                for (int i=0; i<diasReales; i++)
                {
                    if(vecDias[i]==false)
                    {
                        cout<<"\nDIA #"<<i+1;
                    }
                }
                cout<<endl;
            }



        }





        else if(opcion==2)
        {
            //MOSTRAR

            //CORROBORAMOS QUE LA HABITACION TENGA AL MENOS 1 DIA DISPONIBLE
            //PRIMERO DEBEMOS VER QUE MUESTRE SOLO LOS DIAS REALES (FEBRERO SOLO 28 DIAS POR EJEMPLO)
            int diasReales;
            for(int j=1; j<=meses; j++)
            {

                if(j==4 || j==6 || j==9 || j==11)
                {
                    diasReales=30;
                }
                else
                {
                    if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12)
                    {
                        diasReales=31;
                    }
                    if(j==2)
                    {
                        ///VER SI ES ANIO BICIESTO
                        diasReales=28;
                    }
                }

                for (int i=0; i<diasReales; i++)
                {
                    if(matrizMesDias[j-1][i]==false)
                    {
                        habitacionDisponible=true;
                    }
                }
            }

            //MOSTRAMOS HABITACION SI HAY AL MENOS UN DIA DISPONIBLE. SINO PASAMOS A LA OTRA HABITACION
            if(habitacionDisponible==true)
            {
                vecHab[habitacion[i].getNumero()-1]=true;
                habitacion[i].mostrarHabitacion();
                for(int j=1; j<=meses; j++)
                {

                    if(j==4 || j==6 || j==9 || j==11)
                    {
                        diasReales=30;
                    }
                    else
                    {
                        if(j==1 || j==3 || j==5 || j==7 || j==8 || j==10 || j==12)
                        {
                            diasReales=31;
                        }
                        if(j==2)
                        {
                            ///VER SI ES ANIO BICIESTO
                            diasReales=28;
                        }
                    }
                    cout<<"MES #"<<j<<endl;
                    for (int i=0; i<diasReales; i++)
                    {

                        if(matrizMesDias[j-1][i]==false)
                        {
                            cout<<"DIA "<<i+1<<endl;
                        }
                    }
                }
            }


        }

    }
}



///1° OPCION --► MISMO ANIO Y MISMO MES DE F. INGRESO Y F. SALIDA
///Carga el vector de dias para mostrar de cada habitacion los dias disponibles de cada mes. Si coincide con el indice, carga el dia como ocupado.
void Reservas::cargarDiasOcupados(bool vecDias[], int tam, Fecha fIngresoR, Fecha fEgresoR)
{
    if (fIngresoR.getAnio()!=fEgresoR.getAnio() && fIngresoR.getMes()==fEgresoR.getMes())
    {

        for(int i=0; i<tam; i++)
        {
            if(i+1 >= fIngresoR.getDia())
            {
                vecDias[i]=true;
            }
        }
    }

    else if( fIngresoR.getAnio()==fEgresoR.getAnio() && fIngresoR.getMes()!=fEgresoR.getMes()){

        for(int i=0; i<tam; i++)
        {
            if(i+1 >= fIngresoR.getDia())
            {
                vecDias[i]=true;
            }
        }
    }


    else if( fIngresoR.getAnio()==fEgresoR.getAnio() && fIngresoR.getMes()==fEgresoR.getMes()){

        for(int i=0; i<tam; i++)
        {
            if(i+1 >= fIngresoR.getDia()&& i+1 <= fEgresoR.getDia())
            {
                vecDias[i]=true;
            }
        }
    }




}


///2° OPCION --► MISMO ANIO Y DISTINTO MES DE F. INGRESO Y F. SALIDA
///Cargamos matriz para rellenar meses y dias ocupados (true)
void Reservas::cargarOcupacion2 (bool matrizMesDias[][31],int meses, int dias, Fecha fIngresoR, Fecha fEgresoR)
{


    for (int i=0; i<meses; i++)
    {
        if(i+1>= fIngresoR.getMes() && i+1<=fEgresoR.getMes())
        {

            for(int j=0; j<dias; j++)
            {
                if(j+1>= fIngresoR.getDia() && j+1 <=fEgresoR.getDia())
                {
                    matrizMesDias[i][j]=true;
                }
            }
        }
    }
}


//Calcular cantidad de dias entre 2 fechas dadas
//Si mandamos por parametro hace el calculo. Si no mandamos nada, nos pide los datos dentro.
int Reservas::calcularDias(int dI, int mI, int aI, int dE, int mE, int aE)
{

    int diaIngreso=dI;
    int mesIngreso=mI;
    int anioIngreso=aI;
    int diaEgreso=dE;
    int mesEgreso=mE;
    int anioEgreso=aE;

    if (dI ==0 && mI ==0 && aI==0)
    {
        cout<<"Ingrese dia de ingreso"<<endl;
        cin>>diaIngreso;

        cout<<"Ingrese mes de ingreso"<<endl;
        cin>>mesIngreso;
        mesIngreso-=1;

        cout<<"Ingrese anio de ingreso"<<endl;
        cin>>anioIngreso;

        cout<<"Ingrese dia de egreso"<<endl;
        cin>>diaEgreso;

        cout<<"Ingrese mes de egreso "<<endl;
        cin>>mesEgreso;
        mesEgreso-=1;

        cout<<"Ingrese anio de egreso"<<endl;
        cin>>anioEgreso;
        ///Poner un volver al menu principal por si se equivoca de anio.
    }

    anioIngreso-=1900;

    anioEgreso-=1900;


    tm a[6] = {0,0,0,diaIngreso,mesIngreso,anioIngreso}; /* June 24, 2004 */ //--► se debe mandar los 2 ultimos digitos del anio --► getanio -2000 --► se debe poner mes-1 en codigo --►si le mandamos 29/2/2022 no cuenta el dia 29, si no a partir del 1/3/2022 ok
    tm b[6]= {0,0,0,diaEgreso,mesEgreso,anioEgreso}; /* July 5, 2004 */
    time_t x = mktime(a);
    time_t y = mktime(b);
    int diferencia;
    if ( x != (time_t)(-1) && y != (time_t)(-1) )
    {
        diferencia = difftime(y, x) / (60 * 60 * 24);//usan double difference tambien
        //cout << ctime(&x);
        //cout << ctime(&y);
        cout << "Total dias = " << diferencia +1<< " dias" << endl;// --► se le manda +1 para incluir los dias de entrada y salida al calculo
    }

    return diferencia+1;

}



//Metodo para obtener el precio total segun 2 fechas dadas y un numero de habitacion
float Reservas::obtenerImporteReserva(Fecha fIngresoR, Fecha fEgresoR, int numHabitacion)
{
    Reservas reservas;
    int cantDias=reservas.calcularDias(fIngresoR.getDia(),fIngresoR.getMes(),fIngresoR.getAnio(), fEgresoR.getDia(),fEgresoR.getMes(),fEgresoR.getAnio());
    ArchivoHabitacion archivoHabitacion;
    int cantReg=archivoHabitacion.getCantidad();
    Habitacion *habitacion=new Habitacion[cantReg];
    float precioHabitacion;

    for (int i=0; i<cantReg; i++)
    {
        habitacion[i]=archivoHabitacion.leer(i);
    }

    for(int i=0; i<cantReg; i++)
    {
        if (habitacion[i].getNumero()==numHabitacion)
        {

            precioHabitacion=habitacion[i].getPrecio();
        }
    }

    float importeTotalReserva=precioHabitacion*(float)cantDias;
    return importeTotalReserva;

}


///Engloba todo lo que tiene que ver con las reservas del sub menu punto 1
void Reservas::reservar(Cliente cliente)
{
    Fecha fechaActual;
    fechaActual.AsignarFechaActual(fechaActual);
    Fecha fIngresoR;
    Fecha fEgresoR;
    bool validarFecha=false;
    int opcion;
    //Le pedimos al cliente la fecha de estadia ---► ver si pasar los datos de fecha como parametros
    cout<<"Fecha de ingreso de estadia "<<endl;
    fIngresoR.CargarFecha();
    cout<<"\nFecha de egreso de estadia "<<endl;
    fEgresoR.CargarFecha();

    while(validarFecha!=true)
    {
        if((fIngresoR>fechaActual || fIngresoR==fechaActual) && fEgresoR>fIngresoR && fEgresoR>fechaActual)
        {
            validarFecha=true;
        }
        else
        {
            cout<<"Ingreso incorrecto."<<endl;
            cout<<"1 Para volver a ingresar las fechas"<<endl;
            cout<<"2 Para volver al menu anterior ";
            cin>>opcion;
            if(opcion==1)
            {
                cout<<"Fecha de ingreso de estadia "<<endl;
                fIngresoR.CargarFecha();
                cout<<"Fecha de egreso de estadia "<<endl;
                fEgresoR.CargarFecha();
            }
            else
            {
                return;
            }
        }
    }

    ArchivoHabitacion archivohabitacion;
    int cant=archivohabitacion.getCantidad();
    bool *vecHab=new bool[cant];
    for(int i=0; i<cant; i++)
    {
        vecHab[i]=false;
    }
    Reservas reserva;
    if(reserva.buscarDisponibilidad(vecHab, fIngresoR,fEgresoR)==true)
    {
        ///PREGUNTAR SI HACER RESERVA O VOLVER AL MENU
        reserva.hacerReserva(vecHab,fIngresoR,fEgresoR, cliente);

    }
    else
    {
        mostrarDisponibles(vecHab,fIngresoR,fEgresoR);/// segun 2 fechas dadas que va a contemplar un plazo entre 2 meses o mas --► (ver si mandar fechas ingresadas al principio o pedir nuevamente)

        ///Si no gusta ninguna fecha, poner opcion para ingresar fechas nuevamente para buscar disponibilidad del punto anterior.

        //Le pedimos al cliente la fecha de estadia que quiere nuevamente (segun las opciones que muestra la pantalla)---► ver si pasar los datos de fecha como parametros
        cout<<"Fecha de ingreso de estadia "<<endl;
        fIngresoR.CargarFecha();
        cout<<"Fecha de egreso de estadia "<<endl;
        fEgresoR.CargarFecha();


        ///hacer reserva --► le mandamos fechas y dentro de esta funcion se carga lo demas (cliente, habitacion)
        reserva.hacerReserva(vecHab,fIngresoR,fEgresoR, cliente);
    }

    delete [] vecHab;
}

///Engloba todo lo que tiene que ver con la disponibilidad del sub menu punto 5
void Reservas::disponibilidad()
{

    ArchivoHabitacion archivoHabitacion;
    int cantHabitacion=archivoHabitacion.getCantidad();
    bool *vecHab=new bool[cantHabitacion];
    Reservas reserva;
    Fecha fIngresoR;
    Fecha fEgresoR;
    fIngresoR.CargarFecha();
    fEgresoR.CargarFecha();
    reserva.mostrarDisponibles(vecHab,fIngresoR, fEgresoR);
    cout<<endl;
    delete [] vecHab;
}



//CANCELAR RESERVA
void Reservas::cancelarReserva()
{
    ArchivoReservas archivoReservas;
    Reservas reserva;
    char dni[9];
    cout<<"Ingrese DNI: ";
    cargarCadena(dni,8);

    bool encontro=false;

    int cant=archivoReservas.getCantidad();
    Reservas *reservas=new Reservas[cant];

    for(int i=0; i<cant; i++)
    {
        reservas[i]=archivoReservas.leer(i);
    }

    int opcion=-1, opcion2=-1;
    cout<<"\n¿DESEA CANCELAR 1 O MAS RESERVAS?"<<endl;
    cout<<"PRESIONE 1 PARA VARIAS RESERVAS"<<endl;
    cout<<"PRESIONE 2 PARA UNA EN CONCRETO"<<endl;
    cout<<"PRESIONE 0 PARA SALIR"<<endl;

    while(opcion!=1 && opcion!=2 && opcion!=0)
    {
        cin>>opcion;
        cout<<endl;
        switch(opcion)
        {
        case 1:
        {
            for(int i=0; i<cant; i++)
            {

                if(strcmp(reservas[i].getDniCliente(), dni)==0)
                {
                    reservas[i].mostrarReserva();
                    cout<<"\nDESEA CANCELARLA?"<<endl;
                    cout<<"INGRESE 1 PARA CONFIRMAR"<<endl;
                    cout<<"INGRESE 2 PARA PASAR A LA SIGUIENTE RESERVA"<<endl;
                    cout<<"INGRESE 0 PARA SALIR";
                    while(opcion2!=1 && opcion2!=2 && opcion2!=0)
                    {
                        cin>>opcion2;
                        cout<<endl;
                        switch (opcion2)
                        {
                        case 1:
                            reservas[i].setCancelar(true);
                            reservas[i].setEstadoReserva(false);
                            if(archivoReservas.guardar(reservas[i], i))
                            {
                                cout<<"\nRESERVA CANCELADA."<<endl;
                            }
                            break;
                        case 2:
                            break;
                        case 0:
                            return;
                            break;
                        default:
                            cout<<"\nOPCION INCORRECTA."<<endl;
                            cout<<"INGRESE 1 PARA CONFIRMAR"<<endl;
                            cout<<"INGRESE 2 PARA PASAR A LA SIGUIENTE RESERVA";
                            break;
                        }

                    }


                }
                else
                {
                    cout<<"Datos incorrectos. Vuelva a ingresar los datos"<<endl;
                }

            }

        }
        break;
        case 2:
        {
            for(int i=0; i<cant; i++)
            {
                if(strcmp(reservas[i].getDniCliente(), dni)==0)
                {
                    reservas[i].mostrarReserva();
                }
            }
            int numReserva;
            cout<<"\nINGRESE NUMERO DE RESERVA A CANCELAR: ";
            cin>>numReserva;
            cout<<endl;

            for(int i=0; i<cant; i++)
            {
                if(strcmp(reservas[i].getDniCliente(), dni)==0 && reservas[i].getNumeroReserva()==numReserva)
                {
                    int opcion3=-1;
                    cout<<"\nSEGURO QUE DESEA CANCELAR LA RESERVA?"<<endl;
                    cout<<"INGRESE 1 PARA CONFIRMAR"<<endl;
                    cout<<"INGRESE 0 PARA VOLVER AL MENU ANTERIOR ";

                    while (opcion3!= 1 && opcion3!=0)
                    {
                        cin>>opcion3;
                        cout<<endl;

                        switch (opcion3)
                        {
                        case 1:
                        {
                            reservas[i].setEstadoReserva(false);
                            reservas[i].setCancelar(true);
                            archivoReservas.guardar(reservas[i], i);
                        }
                        break;
                        case 0:
                            return;
                            break;
                        default:
                            cout<<"\nOPCION INCORRECTA"<<endl;
                            cout<<"INGRESE 1 PARA CONFIRMAR"<<endl;
                            cout<<"INGRESE 0 PARA VOLVER AL MENU ANTERIOR ";
                            break;
                        }

                    }



                }
                else
                {
                    cout<<"Datos incorrectos. Vuelva a ingresar los datos"<<endl;
                }
            }



        }
        break;
        case 0:
            break;
        default:
            cout<<"\nOPCION INCORRECTA"<<endl;
            cout<<"PRESIONE 1 PARA VARIAS RESERVAS"<<endl;
            cout<<"PRESIONE 2 PARA UNA EN CONCRETO"<<endl;
            cout<<"PRESIONE 0 PARA SALIR ";
            break;

        }
    }


}



//CONSUTLAR RESERVAS DEL MENU OPCION 4
void Reservas::consultarReserva()
{
    ArchivoReservas archivoReservas;

    int tamReservas=archivoReservas.getCantidad();
    Reservas *reservas=new Reservas[tamReservas];

    for(int i=0; i<tamReservas; i++)
    {
        reservas[i]=archivoReservas.leer(i);
    }
    cout<<endl<<"\nPRESIONE 1 PARA CONSULTAR RESERVA POR DNI"<<endl;
    cout<<"PRESIONE 2 PARA CONSULTAR POR NUMERO DE RESERVA"<<endl;
    cout<<"PRESIONE 0 PARA SALIR ";
    int opcion=-1;

    while(opcion !=1 && opcion !=2 && opcion!=0)
    {
        cin>>opcion;
        cout<<endl;
        switch(opcion)
        {
        case 1:
        {
            char dni[9];
            bool bandera=false;
            cout<<endl<<"--------------------------"<<endl;
            cout<<endl<<"INGRESE DNI DE CLIENTE A CONSULTAR"<<endl;
            cargarCadena(dni,8);
            cout<<endl;

            for(int i=0; i<tamReservas; i++)
            {

                if(strcmp(reservas[i].getDniCliente(),dni)==0)
                {
                    reservas[i].mostrasTodasLasReservas();
                    cout<<"-------------------"<<endl;
                    bandera=true;
                }
            }
            if(bandera==false)
            {
                cout<<endl<<"NO HAY RESERVAS ACTIVAS PARA ESE CLIENTE"<<endl;
            }
        }
        break;
        case 2:
        {
            bool bandera=false;
            int numReserva;
            cout<<endl<<"--------------------------"<<endl;
            cout<<endl<<"INGRESE EL NUMERO DE RESERVA QUE DESEA CONSULTAR"<<endl;
            cin>>numReserva;
            cout<<endl;

            for(int i=0; i<tamReservas; i++)
            {

                if(reservas[i].getNumeroReserva()==numReserva)
                {
                    reservas[i].mostrasTodasLasReservas();
                    cout<<"-------------------"<<endl;
                    bandera=true;
                }
            }
            if(bandera==false)
            {
                cout<<endl<<"NO HAY RESERVAS CON ESE NUMERO DE RESERVA"<<endl;
            }
        }
        break;

        case 0:
            break;

        default:
            cout<<endl<<"\nINGRESO INCORRECTO"<<endl;
            cout<<"INGRESE 1 PARA BUSCAR POR DNI"<<endl;
            cout<<"INGRESE 2 PARA BUSCAR POR NUMERO DE RESERVA"<<endl;
            cout<<"INGRESE 0 PARA SALIR ";
            break;
        }
    }
}
