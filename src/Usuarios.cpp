#include "Usuarios.h"
#include <iostream>
#include "RegistroYLogin.h"

//SETS
void Usuarios::setAcceso(int s)
{
    _nivel_acceso=s;
}


void Usuarios::SetLegajo(const char* legajo)
{
    strcpy(_legajo,legajo);
}


//GETS
const char* Usuarios::GetLegajo()
{

    return _legajo;
}

int Usuarios::getAcceso()
{
    return _nivel_acceso;
}

const char* Usuarios::getContrasenia()
{
    return _contrasenia;
}

//METODOS
bool Usuarios::CrearUsuario()
{
    int nivel_acceso=-1;
    while(nivel_acceso < 0 || nivel_acceso > 2 )
    {
        cout<<endl<<"CREAR NUEVO USUARIO"<<endl;
        cout<<endl<<"1- ADMIN"<<endl;
        cout<<endl<<"2- EMPLEADO"<<endl;
        cout<<endl<<"0- VOLVER"<<endl<<endl;
        cin>>nivel_acceso;
        rlutil::cls();
        if (nivel_acceso==0)
        {
            return false;
        }
    }
    _nivel_acceso=nivel_acceso;
    cout<<endl<<"Fecha de registro: ";
    fecha_registro.AsignarFechaActual(fecha_registro);
    fecha_registro.MostrarFecha();
    cout<<"Legajo: "<<endl;
    cargarCadena(_legajo,8);
    Usuarios usuario;

    while(usuario.ChequearLegajo(_legajo)==false)
    {
        cout<<endl<<"INGRESE UN LEGAJO DIFERENTE O SALGA DEL REGISTRO"<<endl;
        int opcion;

        cout<<endl<<"PRESIONE 1 PARA INGRESAR UN LEGAJO DIFERENTE Y 2 PARA SALIR DE REGISTROS: ";
        cin>>opcion;
        cout<<endl;

        switch(opcion)
        {
        case 1:
            cout<<"Legajo: "<<endl;
            cargarCadena(_legajo,8);

            break;

        case 2:
            return false;
            break;
        default:
            "ESA OPCION NO EXISTE, INTENTE NUEVAMENTE: "
            ;

        }

    }
    Persona:
    CargarPersona();
    cout<<endl<<"Contraseña: ";
    cargarCadena(_contrasenia,50);
    cout<<endl;
    MostrarUsuario();
    return true;
}


void Usuarios::MostrarUsuario()
{
    cout<<endl<<endl<<"DATOS DEL USUARIO:"<<endl;
    cout<<"Legajo: "<<_legajo<<endl;
    MostrarPersona();
    //cout<<"Contraseña: "<<_contrasenia<<endl;
    cout<<"Nivel de acceso: "<<_nivel_acceso<<endl;
    cout<<"Fecha de registro: ";
    fecha_registro.MostrarFecha();
    cout<<"Estado: "<<getEstado()<<endl;
    cout<<endl;
}


//ARCHIVOS
void Usuarios::GuardarUsuario()
{
    FILE *usr;
    usr=fopen("usuarios.dat", "ab");
    if(usr==NULL)
    {
        cout<<endl<<"Error al Guardar Usuario"<<endl;
        fclose(usr);
        return;
    }
    fwrite(this,sizeof(Usuarios),1,usr);
    fclose(usr);
}


void Usuarios::ListaUsuarios()
{
    FILE *p;
    Usuarios aux;
    p=fopen("usuarios.dat", "rb");
    if(p==NULL)
    {
        cout<<endl<<"Error al Leer Lista de Usuarios"<<endl;
        return;
    }
    while(fread(&aux,sizeof(Usuarios),1,p )==1)
    {
        aux.MostrarUsuario();
        cout<<endl;
    }
    fclose(p);
}



bool Usuarios::BuscarUsuario(const char* legajo)
{
    FILE *p;
    p=fopen("usuarios.dat", "rb");
    if(p==NULL)
    {
        cout<<endl<<"Error al Buscar Usuario"<<endl;
        fclose(p);
        return false;
    }
    while(fread(this,sizeof(Usuarios),1,p )==1)
    {
        if(strcmp(legajo,this->GetLegajo())==0)
        {
            cout<<endl<<"Se encontró el LEGAJO: "<<GetLegajo();
            cout<<endl<<"Corresponde al Usuario: ";
            cout<<GetNombre()<<" "<<GetApellido()<<endl;
            cout<<"Nivel de acceso: ";
            if(getAcceso()==1)
            {
                cout<<"ADMIN"<<endl;
            }
            else
            {
                cout<<"EMPLEADO"<<endl;
            }

            fclose(p);
            return true;
        }
    }
    fclose(p);
    cout<<endl<<"No se encontró el LEGAJO!"<<endl;
    return false;
}



//VA A CONTAR CUANTOS USUARIOS HAY CARGADOS
int Usuarios::ContarCantidadArchivos()
{
    FILE* p = fopen("usuarios.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int cant = ftell(p) / sizeof(Usuarios);
    fclose(p);
    return cant;
}



//LEE TODOS LOS ARCHIVOS EXISTENTES A TRAVES DE UN VECTOR COMO PARAMETRO
bool Usuarios::leerTodos(Usuarios usuarios[], int cantidad) {
  FILE* p;
  p = fopen("usuarios.dat", "rb");
  if (p == NULL) {
    return false;
  }
  fread(usuarios, sizeof(Usuarios), cantidad, p);
  fclose(p);
  return true;
}






//VA A CREAR AL PRIMER ADMIN SI NO HAY USUARIOS CARGADOS
void Usuarios:: crearPrimerAdmin()
{
    cout<<endl<<"crear primer Admin del sistema: "<<endl;
    cout<<endl<<"Fecha de registro: ";
    fecha_registro.AsignarFechaActual(fecha_registro);
    fecha_registro.MostrarFecha();
    cout<<"Legajo: "<<endl;
    cargarCadena(_legajo,8);

    Persona:
    CargarPersona();
    cout<<endl<<"Contraseña: ";
    cargarCadena(_contrasenia,50);
    cout<<endl;
    _nivel_acceso=1;
    MostrarUsuario();
}


bool Usuarios:: ChequearLegajo(const char* legajo)
{
    FILE *p;
    p=fopen("usuarios.dat", "rb");
    if(p==NULL)
    {
        //cout<<endl<<"Error al Buscar Usuario"<<endl;
        fclose(p);
        return false;
    }
    while(fread(this,sizeof(Usuarios),1,p )==1)
    {
        if(strcmp(legajo,this->GetLegajo())==0)
        {
            cout<<endl<<"EL LEGAJO INGRESADO YA EXISTE"<<endl;

            return false;
        }
    }
    fclose(p);
    return true;
}



int Usuarios::leerUsuario(const char* legajo)
{
    int pos=0;
    FILE *p;
    p=fopen("usuarios.dat", "rb");
    if(p==NULL)
    {
        return -1;
    }
    while(fread(this,sizeof(Usuarios),1,p )==1)
    {
        if(strcmp(legajo,this->GetLegajo())==0)
        {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    cout<<endl<<"No se encontró el LEGAJO!"<<endl;
    return -1;
}


bool Usuarios::bajaOaltaLogica(int pos,bool estado)
{
    FILE *p=fopen("usuarios.dat","rb+");
    if(p==NULL)
    {
        return false;
    }
    fseek(p,pos*sizeof(Usuarios),SEEK_SET);
    this->setEstado(estado);
    if(fwrite(this,sizeof(Usuarios),1,p))
    {
        fclose(p);
        return true;
    }
    fclose(p);
    return false;
}


bool Usuarios::modificarUsuario()
{
    Usuarios usu;
    char pass[50];
    char legajo[9];
    cout<<"Para ingresar necesita privilegios de ADMIN"<<endl;
    cout<<"Legajo: ";
    cargarCadena(legajo,8);
    if(this->leerUsuario(legajo) == -1){
        return false;
    }
    cout<<"Contraseña:";
    cargarCadena(pass,49);
    if(this->getAcceso() ==2 )
    {
        cout<<"El usuario:"<<this->GetNombre()<<" ,no posee Nivel de Usuario: ADMIN"<<endl;
        cout<<"Necesita Permisos de ADMIN para Modificar"<<endl;
        return false;
    }
    else
    {
        if(!strcmp(pass,this->_contrasenia)==0){
            cout<<"La contraseña es incorrecta"<<endl;
            system("pause");
            system("cls");
            return false;
        }
        cout<<endl<<"Usuario ADMIN: "<<this->GetNombre()<<endl<<endl;

        char leg[9],c;
        cout<<"MODIFICAR/ELIMINAR USUARIOS"<<endl;
        cout<<"Ingrese Número de Legajo: ->";
        cargarCadena(leg,8);
        int pos=usu.leerUsuario(leg);
        if(pos >=0)
        {

            int op=-1;
            while(op !=0)
            {
                system("cls");
                usu.MostrarUsuario();
                cout<<endl;

                cout<<"ELIJA UN OPCIÓN"<<endl;
                cout<<"1. MODIFICAR USUARIO"<<endl;
                cout<<"2. ELIMINAR USUARIO"<<endl;
                cout<<"3. ALTA DE USUARIO"<<endl;
                cout<<"0. SALIR"<<endl;
                cin>>op;
                switch(op)
                {
                case 1:
                {
                    int op2=-1;

                    while (op2 !=0)
                    {
                        system("cls");
                        bool modificado=false;
                        cout<<"SELECCIONE DATOS A MODIFICAR: "<<endl;
                        cout<<"1. DATOS PERSONALES"<<endl;
                        cout<<"2. NIVEL DE ACCESO"<<endl;
                        cout<<"3. CONTRASEÑA"<<endl;
                        cout<<"0. SALIR"<<endl;
                        cin>>op2;
                        switch(op2)
                        {
                        case 1:
                            cout<<"Modificar Datos Personales:"<<endl;
                            usu.CargarPersona();
                            modificado=true;
                            op2=0;
                            break;
                        case 2:
                            cout<<"Ingrese Nivel de Acceso: 1 ADMIN o 2 EMPLEADO:"<<endl;
                            cin>>usu._nivel_acceso;
                            modificado=true;
                            op2=0;
                            break;
                        case 3:
                            cout<<"Ingrese Nueva Contraseña: ->";
                            cargarCadena(usu._contrasenia,49);
                            modificado=true;
                            op2=0;
                            break;
                        case 0:
                            break;
                        }
                        if(modificado)
                        {
                            char c;
                            cout<<"¿GUARDAR CAMBIOS? S/N ->";
                            cin>>c;
                            if(toupper(c)=='S')
                            {
                                FILE *p=fopen("usuarios.dat","rb+");
                                if(p==NULL)
                                {
                                    cout<<"Error al abrir el archivo"<<endl;
                                }
                                fseek(p,pos*sizeof(Usuarios),SEEK_SET);
                                fwrite(&usu,sizeof(Usuarios),1,p);
                                fclose(p);
                                cout<<"REGISTRO MODIFICADO"<<endl;

                            }
                            else if(toupper(c)=='N')
                            {
                                cout<<"NO SE GRABÓ"<<endl;
                            }
                            else
                            {
                                cout<<"Opción Incorrecta... No se grabó"<<endl;
                            }
                        }
                    }

                }
                system("pause");
                break;
                case 2:
                    cout<<"¿SEGURO QUE DESEA ELIMINAR EL USUARIO? S/N ->";
                    cin>>c;
                    if(toupper(c)=='S')
                    {
                        if(usu.bajaOaltaLogica(pos,false))
                        {
                            cout<<"Usuario eliminado con éxito"<<endl;
                        }
                        else
                        {
                            cout<<"No se puso eliminar el usuario"<<endl;
                        }
                    }
                    else
                    {
                        cout<<"NO SE ELIMINÓ EL USUARIO"<<endl;
                    }
                    system("pause");
                    break;
                case 3:
                    cout<<"¿DAR DE ALTA AL USUARIO? S/N ->";
                    cin>>c;
                    if(toupper(c)=='S')
                    {
                        if(usu.bajaOaltaLogica(pos,true))
                        {
                            cout<<"Se realizó el Alta con éxito"<<endl;
                        }
                        else
                        {
                            cout<<"No se puso dar de Alta al usuario"<<endl;
                        }
                    }
                    else
                    {
                        cout<<"ERROR EN ALTA DE USUARIO"<<endl;
                    }
                    system("pause");
                    break;
                case 0:
                    system("cls");
                    break;
                default:
                    cout<<"Opción Incorrecta, intente nuevamente..."<<endl;
                    system("pause");
                    system("cls");
                }
            }
        }
    }
}


//SOBRE ESCRIBIR  -  BACK UP
bool Usuarios::grabarBackUp(Usuarios usuarios[], int cantidad) {
  FILE* p;
  p = fopen("usuarios.dat", "wb");
  if (p == NULL) {
    return false;
  }
  fwrite(usuarios, sizeof(Usuarios), cantidad, p);
  fclose(p);
  return true;
}

