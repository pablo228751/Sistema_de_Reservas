#include "RegistroYLogin.h"
#include <conio.h>


//METODO PARA ACCEDER EL SISTEMA
bool RegistroYLogin:: login()
{
    int v=0;
    const int tamLegajo=9, tamPass=50;
    char legajo[tamLegajo];
    char contrasenia[tamPass];
    cout<<"Ingrese legajo de usuario: "<<endl;
    cargarCadena(legajo,9);
    cout<<"Ingrese contraseña: "<<endl;


    for (int i=0;i<tamPass;i++){
    v=getch();
    if (v>='a' && v<='z' || v>='A' && v<='Z' || v>='0' && v<='9' || v==' ' ){
    contrasenia[i]=v;
    cout<<"*";
    }
    if(v=='\r'){
        contrasenia[i]='\0';
        break;
        }
    }

    Usuarios usuarios;
    if(usuarios.BuscarUsuario(legajo))
    {
        if(strcmp(usuarios.getContrasenia(),contrasenia)==0)
        {
            usuarioLogueado=usuarios;
            return true;
        }
        else
        {
            cout<<"Contrasenia incorrecta"<<endl;
            return false;
        }
    }
    cout<<"No existe el usuario"<<endl;
    return false;

}




//METODO PARA REGISTRARSE
bool RegistroYLogin::registrarse()
{
    Usuarios usr;
    if(usr.CrearUsuario())
    {
        char confirma;
        while(true) ////VER
        {
            cout<<endl<<"¿GUARDAR USUARIO? S/N "<<endl;
            cin>>confirma;
            if(toupper(confirma) == 'S')
            {
                rlutil::cls();
                usr.GuardarUsuario();
                cout<<endl<<"SE GUARDÓ USUARIO"<<endl<<endl;
                Sleep(3000);
                rlutil::cls();
                break;
                return false;
            }
            if(toupper(confirma) == 'N')
            {
                rlutil::cls();
                cout<<endl<<"NO SE GUARDÓ"<<endl<<endl;
                Sleep(3000);
                rlutil::cls();
                break;
                return false;
            }
        }


    }

}


//METODO PARA LISTAR TODOS LOS USUARIOS
void RegistroYLogin:: listarUsuarios()
{
    Usuarios usr;
    usr.ListaUsuarios();
    system("pause");
    rlutil::cls();

}


//METODO PARA BUSCAR POR LEGAJO UN DETERMINADO USUARIO
void RegistroYLogin:: buscarPorLegajo()
{
    Usuarios usuarios;
    char legajo[9];
    rlutil::cls();
    //cin.ignore();
    cout<<endl<<"INGRESE LEGAJO PARA BUSCAR:";
    cargarCadena(legajo,9);
    //getline(cin,dni);
    usuarios.BuscarUsuario(legajo);
    //cout<<"CONTRASENIA: "<<usr.getContrasenia();

}



//METODO QUE VA A FILTRAR PARA QUE SOLO LOS USUARIOS ADMIN PUEDAN CREAR CUENTAS NUEVAS DE USUARIO
bool RegistroYLogin:: FiltroRegistro()
{
    Usuarios usuarios;
    RegistroYLogin registroYlogin;
    int cantidadUsuarios=usuarios.ContarCantidadArchivos();
    if(cantidadUsuarios==0)
    {
        cout<<endl<<"NP HAY USUARIOS CARGADOS "<<endl;
        usuarios.crearPrimerAdmin();
        usuarios.GuardarUsuario();
        return true;
    }
    else
    {
        char legajo[9];
        char contrasenia[50];
        cout<<"Ingrese legajo de usuario: "<<endl;
        cargarCadena(legajo,9);
        cout<<"Ingrese contraseña: "<<endl;
        cargarCadena(contrasenia,50);
        if(usuarios.BuscarUsuario(legajo))
        {
            if(strcmp(usuarios.getContrasenia(),contrasenia)==0)
            {
                if(usuarios.getAcceso()==1)
                {
                    if  (registroYlogin.registrarse()==true)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    cout<<endl<<"SOLO LOS USUARIOS ADMIN PUEDEN CREAR REGISTROS DE USUARIOS"<<endl;
                    return false;
                }
            }

            else
            {
                cout<<endl<<"CONTRASENIA INCORRECTA"<<endl;
                return false;
            }
        }
        cout<<"NO EXISTE EL USUARIO INGRESADO"<<endl;
        return false;
    }
}


