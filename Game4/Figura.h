#pragma once
#include "conio.h"
//CLASE PADRE
enum Direccion { Arriba, Abajo, Derecha, Izquierda, Ninguno };
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System;
class Figura
{
protected:

	int x; int y;//coordenadas de posicion
	int dx; int dy;//desplazamiento
	int idx, idy;//me identifica la imagen que deseo dibujar(INDICE)
	int ancho, alto;//ancho y alto de la imagen
public:
	Figura();
	~Figura();

	virtual void mostrar(Graphics^ grafico, Bitmap^ bitmap);//Se coloca virtual cunado quieres hacer polimorfismo
	virtual void mover(Direccion tecla, Graphics^ grafico);

	//metodos de acceso
	void set_x(int _x);
	void set_y(int _y);
	void set_dx(int _dx);
	void set_dy(int _dy);
	void set_ancho(int _ancho);
	void set_alto(int _alto);
	void set_idx(int _idx);
	void set_idy(int _idy);


	int get_x();
	int get_y();
	int get_dx();
	int get_dy();
	int get_ancho();
	int get_alto();
	int get_idx();
	int get_idy();
};

Figura::Figura()
{
}

Figura::~Figura()
{
}

/////////////////////////////////getters
void Figura::set_x(int _x)
{
	this->x = _x;
}
void Figura::set_y(int _y)
{
	this->y = _y;
}
void Figura::set_dx(int _dx)
{
	this->dx = _dx;
}
void Figura::set_dy(int _dy)
{
	this->dy = _dy;
}
void Figura::set_ancho(int _ancho)
{
	this->ancho = _ancho;
}
void Figura::set_alto(int _alto)
{
	this->alto = _alto;
}
void Figura::set_idx(int _idx)
{
	this->idx = _idx;
}
void Figura::set_idy(int _idy)
{
	this->idy = _idy;
}
///////////////////////////////////setters
int Figura::get_x()
{
	return x;
}
int Figura::get_y()
{
	return y;
}
int Figura::get_dx()
{
	return dx;
}
int Figura::get_dy()
{
	return dy;
}
int Figura::get_ancho()
{
	return ancho;
}
int Figura::get_alto()
{
	return alto;
}
int Figura::get_idx()
{
	return idx;
}
int Figura::get_idy()
{
	return idy;
}


void Figura::mostrar(Graphics^ grafico, Bitmap^ bitmap)
{

}
void Figura::mover(Direccion tecla, Graphics^ grafico)
{

}