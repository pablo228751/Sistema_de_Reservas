#ifndef DISENIARMENU_H
#define DISENIARMENU_H
#include <locale.h>
#include <string>
#include <stdlib.h>
#include "rlutil.h"
#include "Fecha.h"


class DiseniarMenu
{
private:
    int posX=8, posY=1;
    void calcularLinea(std::string &cadena,int longitud,char c='-');
    void calcular_espacios(std::string &palabra,int longitud);
    void dibujarMenu(std::string *nombresOpciones,std::string &lineaFin,std::string &lineaMed,int &posX, int &posY,int &posCurY,int &cantFilas,bool &color, int &y);
    void resetearPosicionY(std::string *nombresOpciones,int &y,int &cantFilas, bool &color,int &posX, int &posCurY,int &posY);
    int posicionarCursor(int &posCurX,int &posCurY,int &y, int &iniciar, int &posX,int &cantFilas);

public:
    int Menu(std::string* nombresOpciones, int cantFilas,std::string descripcion,int distanciaMenu);
    void setPosX(int x);
    void setPosY(int y);


};

#endif // DISENIARMENU_H
