#pragma once
#include "Figura.h"

class Especial:public Figura
{
private:
public:
	Especial();
	~Especial();
	void MostrarZombie(Graphics^ graficador, Bitmap^ bitmap);
	void MoverZombie(Graphics^ mapa, int _x, int _y);
};

Especial::Especial()
{
	Random r;
	x = r.Next(30, 600);
	System::Threading::Thread::Sleep(90);
	y = r.Next(10, 400);
	System::Threading::Thread::Sleep(90);
	dx = 0; dy = 0;
	idx = idy = 0;
	
	
}

Especial::~Especial()
{
}

void Especial::MostrarZombie(Graphics^ graficador, Bitmap^ bitmap)
{
	//aqui se optiene las dimensiones de la imagen
	ancho = bitmap->Width / 3;
	alto = bitmap->Height / 4;
	//en el rectangilo se dibuja la porcion de la imagen que se desa usar
		//necesita 4 parametros x , y , alto, ancho
	Rectangle porcion = Rectangle(idx * ancho, idy * alto, ancho, alto);
	ancho = 45; alto = 45;
	//Agregamos un zoom para modificar el tamaño de la imagen
	Rectangle aumento = Rectangle(x, y, ancho, alto);
	graficador->DrawImage(bitmap, aumento, porcion, GraphicsUnit::Pixel);

	idx++;
	if (idx > 2)
		idx = 0;


}

void Especial::MoverZombie(Graphics^ mapa,int _x,int _y)
{
	int velocidad = 3;
	
	if (x> _x)//IZQUIERDA
	{
		dx = -velocidad; dy = 0;
		idy = 1;
	}
	if (x< _x)//DERECHA
	{
		dx = velocidad; dy = 0;
		idy = 2;
	}
	if (y > _y)//ARRIBA
	{
		dx = 0; dy = -velocidad;
		idy = 3;
	}
	if (y < _y)//ABAJO
	{
		dx = 0; dy = velocidad;
		idy = 0;
	}
		
	x += dx;
	y += dy;
}