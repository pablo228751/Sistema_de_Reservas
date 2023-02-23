#include "CrearMenu.h"


int CrearMenu::menuInicio()
{
    system("cls");
    DiseniarMenu inicio;
    std::string descripcion="MENÚ PRINCIPAL";
    const int cant=6;
    std::string nomMenu[cant]= {"Ingresar al Programa",
                                 "Registrarse",
                                 "Ver Usuarios",
                                 "Buscar Usuario",
                                 "Info de la Cátedra",
                                 "SALIR"};

    return (inicio.Menu(nomMenu,cant,descripcion,2));
    }

int CrearMenu::menuUsuario(Usuarios &usuarioLogueado)
{
    system("cls");
    int posX=10, posY=6;
    rlutil::locate(posX,posY++);
    cout<<"LEGAJO: "<<usuarioLogueado.GetLegajo()<<endl;
    rlutil::locate(posX,posY++);
    cout<<"Usuario: "<<usuarioLogueado.GetNombre()<<" "<<usuarioLogueado.GetApellido()<<endl;
    rlutil::locate(posX,posY);
    cout<<"Nivel de acceso: ";
    if(usuarioLogueado.getAcceso()==1){
            cout<<"ADMIN"<<endl;
    }else{
        cout<<"EMPLEADO"<<endl;
        }
    DiseniarMenu usu;
    std::string descripcion="MENÚ USUARIO";
    const int cant=15;
    std::string nomMenu[cant]= {"Realizar reserva",
                                "Check in",
                                "Check out",
                                "Cancelar reserva",
                                "Consultar reserva",
                                "Disponibilidad",
                                "Listados",
                                "Consultas por listado",
                                "Informes",
                                "Modificaciones",
                                "Crear habitacion",
                                "Ingreso de cliente",
                                "Realizar copia de seguridad",
                                "Restaurar copia de seguridad",
                                "Volver al menu anterior"
                                };
    return (usu.Menu(nomMenu,cant,descripcion,6));

}

int CrearMenu::nivelUsuario()
{
    DiseniarMenu usu;
    std::string descripcion="NIVEL DE USUARIO";
    const int cant=3;
    std::string nomMenu[cant]= {"ADMIN","EMPLEADO","VOLVER"};
    return (usu.Menu(nomMenu,cant,descripcion,3));

}


int CrearMenu::menuConsultasListados(){
    system("cls");
    DiseniarMenu inicio;
    std::string descripcion="CONSULTAS POR LISTADO";
    const int cant=4;
    std::string nomMenu[cant]= { "Consultar por cliente",
                                 "Consultar por ventas",
                                 "Consultar por habitacion",
                                 "Para volver al menu anterior"
                                 };

    return (inicio.Menu(nomMenu,cant,descripcion,2));
}


int CrearMenu::menuConsultasInformes(){
    system("cls");
    DiseniarMenu inicio;
    std::string descripcion="LISTADO DE INFORMES";
    const int cant=4;
    std::string nomMenu[cant]= { "Recaudacion anual general",
                                 "Recaudacion anual por cliente",
                                 "Recaudacion anual por habitacion",
                                 "Para volver al menu anterior"
                                 };

    return (inicio.Menu(nomMenu,cant,descripcion,2));
}



void CrearMenu::integrantes()
{
    setlocale(LC_CTYPE, "Spanish");
    string integrantes[]= {"Lara Campos, Brian Esteban - Profesor","Gonzalez, Juan Agustín - Jefe de trabajos prácticos","Ávila Rotela, Catalina - Ayudante de trabajos prácticos","Pablo Gabriel Felice || Legajo: 26283"};
    string espacio="                                                      ";
    char salir;
    system("cls");
    cout<<endl<<endl;
    cout<<".";
    Beep(440,500);
    Sleep(7);
    cout<<" .";
    Beep(440,500);
    Sleep(7);
    cout<<"  .";
    Beep(440,500);
    Sleep(7);
    cout<<"   .";
    Beep(349,350);
    Sleep(5);
    cout<<"    .";
    Beep(523,150);
    Sleep(5);
    cout<<"     .";
    Beep(440,500);
    Sleep(40);
    cout<<"      .";
    Beep(349,350);
    cout<<"       .";
    Beep(523,150);
    cout<<"        .";
    Beep(440,1000);
    cout<<endl<<espacio<<"* Tecnicatura en Programación UTN - Laboratorio de Computación II *"<<endl<<endl;
    Beep(659,500);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout<<endl<<espacio<<"                  - INTEGRANTES DE LA CÁTEDRA -"<<endl<<endl;
    rlutil::setColor(rlutil::WHITE);
    Beep(659,500);
    cout<<endl<<espacio<<integrantes[0]<<endl<<endl;
    Beep(659,500);
    cout<<endl<<espacio<<integrantes[1]<<endl<<endl;
    Beep(698,350);
    Sleep(10);
    cout<<endl<<espacio<<integrantes[2]<<endl<<endl;
    Beep(523,150);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout<<endl<<espacio<<"                           - ESTUDIANTE -"<<endl<<endl;
    rlutil::setColor(rlutil::WHITE);
    Beep(415,500);
    Sleep(30);
    Beep(349,350);
    Beep(523,150);
    cout<<endl<<espacio<<integrantes[3]<<endl<<endl;
    Beep(440,1000);
    Sleep(4000);
}


