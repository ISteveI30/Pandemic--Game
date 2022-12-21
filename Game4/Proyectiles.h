#pragma once
#include "Figura.h"
class Proyectil :public Figura
{
private:

public:
	Proyectil(int x, int y, int dx, int dy);
	~Proyectil();

	void MostrarBala(Graphics^ graficador, Bitmap^ bitmap);
	void MoverBala();
};

Proyectil::Proyectil(int x, int y, int dx, int dy)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
}

Proyectil::~Proyectil()
{

}
void Proyectil::MostrarBala(Graphics^ graficador, Bitmap^ bitmap)
{
	ancho = bitmap->Width;
	alto = bitmap->Height;

	//en el rectangilo se dibuja la porcion de la imagen que se desa usar
		//necesita 4 parametros x , y , alto, ancho
	Rectangle porcion = Rectangle(0, 0, ancho, alto);
	ancho = 15;
	alto = 15;
	//Agregamos un zoom para modificar el tamaño de la imagen
	Rectangle aumento = Rectangle(x, y, ancho, alto);
	graficador->DrawImage(bitmap, aumento, porcion, GraphicsUnit::Pixel);
}

void Proyectil::MoverBala()
{
	x += dx;
	y += dy;
}