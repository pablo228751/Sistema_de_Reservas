#include<iostream>
using namespace std;
#include "Informes.h"
#include "CrearMenu.h"


void Informes::consultasPorInformes()
{
    CrearMenu submenu;
    int opcion;
    opcion=submenu.menuConsultasInformes();

    switch(opcion){
    case 1:{
    this->recaudacionAnual();
    }
    break;
    case 2:{
    this->recaudacionAnualPorCliente();
    }
    break;
    case 3:{
    this->recaudacionAnualPorHabitacion();
    }
    break;
    case 0:
    break;
    }
}



void Informes::recaudacionAnual()
{
    const int tam=12;
    float vecMeses[tam]= {0}, total=0;
    bool facturo=false;
    Fecha fechaActual;
    fechaActual.AsignarFechaActual(fechaActual);

    ArchivoVentas archivoVentas;
    int cantVentas=archivoVentas.getCantidad();
    Ventas *ventas=new Ventas[cantVentas];
    if (ventas==NULL)
    {
        cout<<"NO HAY VENTAS REGISTRADAS. ";
        delete [] ventas;
        return;
    }
    for(int i=0; i<cantVentas; i++)
    {
        ventas[i]=archivoVentas.leer(i);
    }

    int anio;

    cout<<"INGRESE AÑO A INFORMAR: ";
    cin>>anio;


    for(int i=0; i<cantVentas; i++)
    {
        if(ventas[i].getFechaPago().getAnio()==anio)
        {
            vecMeses[ventas[i].getFechaPago().getMes()-1]+=ventas[i].getPagoTotal();
            total+=ventas[i].getPagoTotal();
            facturo=true;
        }
    }


    if (facturo==true)
    {
        cout<<"==========================="<<endl;
        cout<<"RECAUDACION ANUAL AÑO "<<anio<<endl;
        cout<<"==========================="<<endl;

        for(int i=0; i<tam; i++)
        {

            switch(i)
            {
            case 0:
            {
                cout<<"ENERO             "<<vecMeses[i]<<endl;
            }
            break;
            case 1:
            {
                cout<<"FEBRERO           "<<vecMeses[i]<<endl;
            }
            break;
            case 2:
            {
                cout<<"MARZO             "<<vecMeses[i]<<endl;
            }
            break;
            case 3:
            {
                cout<<"ABRIL             "<<vecMeses[i]<<endl;
            }
            break;
            case 4:
            {
                cout<<"MAYO              "<<vecMeses[i]<<endl;
            }
            break;
            case 5:
            {
                cout<<"JUNIO             "<<vecMeses[i]<<endl;
            }
            break;
            case 6:
            {
                cout<<"JULIO             "<<vecMeses[i]<<endl;
            }
            break;
            case 7:
            {
                cout<<"AGOSTO            "<<vecMeses[i]<<endl;
            }
            break;
            case 8:
            {
                cout<<"SEPTIEMBRE        "<<vecMeses[i]<<endl;
            }
            break;
            case 9:
            {
                cout<<"OCTUBRE           "<<vecMeses[i]<<endl;
            }
            break;
            case 10:
            {
                cout<<"NOVIEMBRE         "<<vecMeses[i]<<endl;
            }
            break;
            case 11:
            {
                cout<<"DICIEMBRE         "<<vecMeses[i]<<endl;
            }
            break;


            }

        }

        cout<<"\nTOTAL FACTURADO   "<<total<<endl;
        cout<<endl;
        return;
    }
    else
    {
        cout<<"NO HAY FACTURACION PARA EL AÑO INGRESADO. "<<endl;
        return;
    }

}


void Informes::recaudacionAnualPorCliente()
{
    ArchivoVentas archivoVentas;
    int cantVentas=archivoVentas.getCantidad();
    Ventas *ventas=new Ventas[cantVentas];
    if (ventas==NULL)
    {
        cout<<"NO HAY VENTAS REGISTRADAS. ";
        delete [] ventas;
        return;
    }

    ArchivoCliente archivoCliente;
    int cantCliente=archivoCliente.getCantidad();
    Cliente *clientes=new Cliente[cantCliente];

    bool facturo=false;
    float total, totalGeneral=0;

    for(int i=0; i<cantVentas; i++)
    {
        ventas[i]=archivoVentas.leer(i);
    }

    for(int i=0; i<cantCliente; i++)
    {
        clientes[i]=archivoCliente.leer(i);
    }

    int anio;
    cout<<"INGRESE AÑO A INFORMAR: ";
    cin>>anio;

    for(int i=0; i<cantVentas; i++)
    {
        if(ventas[i].getFechaPago().getAnio()==anio)
        {
            facturo=true;
        }
    }

    if(facturo==true)
    {
        cout<<"================================"<<endl;
        cout<<"RECAUDACION POR CLIENTE AÑO "<<anio<<endl;
        cout<<"================================"<<endl;

        for(int j=0; j<cantCliente; j++)
        {
            total=0;
            for(int i=0; i<cantVentas; i++)
            {
                if(ventas[i].getFechaPago().getAnio()==anio && strcmp(clientes[j].GetDni(), ventas[i].getDniCliente())==0)
                {
                    total+=ventas[i].getPagoTotal();
                    totalGeneral+=ventas[i].getPagoTotal();

                }
            }

            cout<<clientes[j].GetApellido()<<" "<<clientes[j].GetNombre()<<"  "<<total<<endl;
        }
        cout<<"\nTOTAL FACTURADO  "<<totalGeneral<<endl<<endl;
        return;
    }
    else
    {
        cout<<"NO HAY FACTURACION PARA EL AÑO INGRESADO. "<<endl;
        return;
    }

}


void Informes::recaudacionAnualPorHabitacion()
{
    int anio;
    cout<<"INGRESE AÑO A INFORMAR: ";
    cin>>anio;

    const int tam=3;
    float totalHabitacion[tam]= {0}, totalGeneral;
    ArchivoHabitacion archivoHabitacion;
    int cantHabitaciones=archivoHabitacion.getCantidad();
    Habitacion *habitacion=new Habitacion [cantHabitaciones];
    if (habitacion==NULL)
    {
        cout<<"NO HAY HABITACIONES CARGADAS."<<endl;
        return;
    }
    for(int i=0; i<cantHabitaciones; i++)
    {
        habitacion[i]=archivoHabitacion.leer(i);
    }


    ArchivoReservas archivoReservas;
    int cantReservas=archivoReservas.getCantidad();
    Reservas *reservas=new Reservas[cantReservas];
    if (reservas==NULL)
    {
        cout<<"NO HAY RESERVAS CARGADAS."<<endl;
        return;
    }
    for(int i=0; i<cantReservas; i++)
    {
        reservas[i]=archivoReservas.leer(i);
    }


    ArchivoVentas archivoVentas;
    int cantVentas=archivoVentas.getCantidad();
    Ventas *ventas=new Ventas[cantVentas];
    if (ventas==NULL)
    {
        cout<<"NO HAY VENTAS CARGADAS."<<endl;
        return;
    }
    for(int i=0; i<cantVentas; i++)
    {
        ventas[i]=archivoVentas.leer(i);
    }


    for(int i=0; i<cantHabitaciones; i++)
    {

        for(int j=0; j<cantVentas; j++)
        {

            if (ventas[j].getFechaPago().getAnio()== anio)
            {

                for(int k=0; k<cantReservas; k++)
                {

                    if(reservas[k].getHabitacionReserva()==habitacion[i].getNumero())
                    {
                        for(int l=0; l<3; l++)
                        {
                            if(reservas[k].getNumeroReserva()==ventas[j].getNumeroReserva(l) && ventas[j].getNumeroReserva(l)>0)
                            {
                                totalHabitacion[habitacion[i].getNumero()-1]+=reservas[k].getImporteReserva();
                                totalGeneral+=reservas[k].getImporteReserva();
                            }
                        }

                    }
                }
            }

        }


    }

    cout<<"==================================="<<endl;
    cout<<"RECAUDACION POR HABITACION AÑO "<<anio<<endl;
    cout<<"==================================="<<endl;

    for(int i=0; i<3; i++)
    {
        cout<<"HABITACION #"<<i+1<<"  "<<totalHabitacion[i]<<endl;
    }

    cout<<"\nTOTAL          "<<totalGeneral<<endl<<endl;

}

