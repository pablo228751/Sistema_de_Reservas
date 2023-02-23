#include "DiseniarMenu.h"

using namespace rlutil;
using namespace std;


int DiseniarMenu::Menu(string* nombresOpciones, int cantFilas,string descripcion, int distanciaMenu)
{
    ///VARIABLES
    int mayorSize=0,posCurX=posX-2,op=1,y=0, iniciar=2;
    string linea, lineaFin, lineaMed;
    bool color=true, dibujar=true;

    //CALCULAR EL STRING CON NOMBRE MAS LARGO para ADAPTAR EL TAMAÑO DEL mENU
    for(int i=0; i<cantFilas; i++)
    {
        if(nombresOpciones[i].size() > mayorSize)
        {
            mayorSize =nombresOpciones[i].size();
        }
    }
    ///SUMA 2 ESPACIOS DE MARGEN
    mayorSize += 4;

    ///RELLENA LA CADENA CON ESPACIOS PARA ADAPTARA AL tAMAÑO
    for(int i=0; i<cantFilas; i++)
    {
        calcular_espacios(nombresOpciones[i],mayorSize);
    }
    // OCULTAR CURSOR
    hidecursor();

    //CABECERA DEL MENU(FUERA DEL WHILE)
    calcularLinea(linea,mayorSize);
    //cls();
    posY = posY+1;
    locate(posX,posY);
    Fecha fecha;
    fecha.AsignarFechaActual(fecha);
    string fec="Fecha Actual: "+to_string(fecha.getDia())+"/"+to_string(fecha.getMes())+"/"+to_string(fecha.getAnio());
    calcular_espacios(fec,mayorSize+8);
    cout<<fec<<endl;
    posY = posY+2;
    locate(posX,posY);
    calcular_espacios(descripcion,mayorSize+6);
    cout<<descripcion<<endl;
    posY = posY+distanciaMenu;
    int posYbk=posY, posCurY=posY+1;




    locate(posX,posY);
    lineaFin="+---+"+linea+"+\n";
    lineaMed="|\n";
    cout<<endl;
    //cls();


    while(op != 0)
    {
        posY=posYbk;
        dibujarMenu(nombresOpciones,lineaFin,lineaMed,posX,posY,posCurY,cantFilas,color,y);
        int menuOpcion=posicionarCursor(posCurX,posCurY,y,iniciar,posX,cantFilas);
        if(menuOpcion >=0)
        {
            locate(posX+5,posY +2);
            cout<<endl;
            return menuOpcion;
        }
        resetearPosicionY(nombresOpciones,y,cantFilas,color,posX,posCurY,posY);
    }
}





//METODOS PRIVADOS

///FUNCION PARA COMPLETAR ESPACIOS VACIOS
void DiseniarMenu::calcular_espacios(string &palabra,int longitud)
{
    for(int i=0; i<longitud; i++)
    {
        if(palabra.size() < longitud)
        {
            palabra= " "+palabra;
        }
        if(palabra.size() < longitud)
        {
            palabra= palabra+" ";
        }
    }
}


///FUNCION PARA DIBUJAR UNA LINEA CON LA LONGITUD ESTABLECIDA (PARA EL MENÚ)
void DiseniarMenu::calcularLinea(string &cadena,int longitud,char c)
{
    for(int i=0; i<longitud; i++)
    {
        cadena += c;
    }
}



///DIBUJA EL MENÜ SEGUN LA CANTIDAD DE FILAS Y ALTERNA COLORES
void DiseniarMenu::dibujarMenu(string *nombresOpciones,string &lineaFin,string &lineaMed,int &posX, int &posY,int &posCurY,int &cantFilas,bool &color, int &y)
{
    for(int i=0; i<cantFilas; i++)
    {
        locate(posX,posY);
        posY++;
        string numM=to_string(i+1);
        ///Detectar ultima opcion del menu para designarle el num 0 (Cero) (Para volver,salir,regresar,etc)
        if(i+1==cantFilas){
                numM="0";

        }
        calcular_espacios(numM,3);
        cout<<lineaFin;
        if(i%2==0)
        {
            locate(posX,posY);
            posY++;
            cout<<"|";
            setColor(LIGHTCYAN);
            cout<<numM;
            setColor(WHITE);
            cout<<"|";
        }
        else
        {
            locate(posX,posY);
            posY++;
            cout<<"|";
            setColor(LIGHTMAGENTA);
            cout<<numM;
            setColor(WHITE);
            cout<<"|";
        }
        if (color==true && ((y-i)%2)==0 )
        {
            locate(posX+5,(posCurY)+y );
            setColor(LIGHTCYAN);
            //cout<<"valor i:"<<i<<" valor de Y:"<<y<<" valor de color: "<<color;
            cout<<nombresOpciones[y/2];
            setColor(WHITE);
        }
        else if(color==false && ((y-i)%2)!=0 )
        {
            locate(posX+5,(posCurY)+y );
            setColor(LIGHTMAGENTA);
            cout<<nombresOpciones[y/2];
            setColor(WHITE);
        }
        else
        {
            setColor(WHITE);
            cout<<nombresOpciones[i];
        }
        cout<<lineaMed;
        locate(posX,posY);
    }
    if(color==false)
    {
        color=true;
    }
    else
    {
        color=false;
    }
    cout<<lineaFin;
    locate(posX,posY);
}



/// CUANdO EL CURSOR SOBREPASA LA CANTIDAD DE FILAS, SE REINICIAN SUS VALORES
void DiseniarMenu::resetearPosicionY(string *nombresOpciones,int &y,int &cantFilas, bool &color,int &posX, int &posCurY,int &posY)
{
    //Validacion para que la posicion de Y no sobrepase las opciones
    if (y < 0)
    {
        //SI EL MENÜ ES PAR
        if((cantFilas%2)==0)
        {
            color=false;
        }
        else //SI ES IMPAR
        {
            locate(posX+5,posCurY );
            setColor(WHITE);
            cout<<nombresOpciones[0];
            if(color==true)
            {
                color=false;
            }
            else
            {
                color=true;
            }
        }
        y=(cantFilas*2)-2;
    }
    else if(y > (cantFilas*2)-1)
    {
        // SI EL MENU ES PAR
        if((cantFilas%2)==0)
        {
            color=true;
        }
        else //SI ES IMPAR
        {
            locate(posX+5,posY -1);
            setColor(WHITE);
            cout<<nombresOpciones[cantFilas-1];
            if(color==true)
            {
                color=false;
            }
            else
            {
                color=true;
            }
        }
        y=0;
    }
}



/// FUNciON QUE RETORNA LA OPCION DEL MENÚ SELECCIONADA POR EL USUARIO
int DiseniarMenu::posicionarCursor(int &posCurX,int &posCurY,int &y, int &iniciar, int &posX,int &cantFilas)
{
    //Posicion del cursor
    locate(posCurX,(posCurY)+y);
    cout<<"=>"<<endl;
    //Mover el cursor
    int tecla;
    if (iniciar>0)
    {
        if(iniciar==2)
        {
            tecla=15;
        }
        else
        {
            tecla=14;
        }
        iniciar--;
    }
    else
    {
        tecla= getkey();
    }
    switch(tecla)
    {
    case 14://UP
        locate(posCurX,(posCurY)+y );
        cout<<"  "<<endl;
        y -= 2;
        break;
    case 15://DOWN
        locate(posCurX,(posCurY)+y);
        cout<<"  "<<endl;
        y+=2;
        break;
    case 1: //ENTER
        locate(posCurX,(posCurY)+y);
        cout<<"  "<<endl;
        switch(y)
        {
        default:
            int elige=(y/2)+1;
            locate(posX,cantFilas+15);
            cout<<endl;
            ///Si es la ultima opcion (salir,volver,regresar,etc) setea en 0
            if (elige == cantFilas){
                elige=0;
            }
            return elige;
        }
    }
    return -1;
}

///SETEAR POSICIOÓN DEL MENÚ
void DiseniarMenu::setPosX(int x){posX=x;}
void DiseniarMenu::setPosY(int y){posY=y;}
