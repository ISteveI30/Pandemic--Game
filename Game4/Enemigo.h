#pragma once
#include "Figura.h"
#include "Proyectiles.h"
class Enemigo :public Figura
{
private:
	int id;//me indica que tipo de enemigo se va a imprimir
	int DireccionInicial;
	Direccion tecla;//capta la direccion del enemigo para indicar el sentido del disparo

public:
	Enemigo(void);
	Enemigo(int _identificador);
	~Enemigo(void);
	//metodos del los enemigos
	void mostrar(Graphics^ graficador, Bitmap^ Sano, Bitmap^ Asintomatico, Bitmap^ verde, Bitmap^ rojo);
	void MoverEnemigoSano(Graphics^ mapa);
	void MoverEnemigoAsintomatico(Graphics^ mapa);
	int get_id();
	void set_ID(int ID);
	Direccion get_Direccion();
	

};
Enemigo::Enemigo() {}

Enemigo::Enemigo(int _identificador)
{
	/*this->*/id = _identificador;
	Random r;
	x = r.Next(30, 600);
	System::Threading::Thread::Sleep(80);
	y = r.Next(10, 370);
	System::Threading::Thread::Sleep(80);
	dx = 0; dy = 0;
	idx = idy = 0;
	DireccionInicial = 1;
}



Enemigo::~Enemigo()
{
}

void Enemigo::mostrar(Graphics^ graficador, Bitmap^ Sano, Bitmap^ Asintomatico, Bitmap^ verde, Bitmap^ rojo)
{
	if (id == 1)//SANO
	{

		ancho = Sano->Width / 3;
		alto = Sano->Height / 4;

		Rectangle porcion = Rectangle(idx * ancho, idy * alto, ancho, alto);
		ancho = 40; alto = 40;
		Rectangle aumento = Rectangle(x, y, ancho, alto);
		Sano->MakeTransparent(Sano->GetPixel(0, 0));
		graficador->DrawImage(Sano, aumento, porcion, GraphicsUnit::Pixel);
		
	}
	if (id == 2)//ASINTOMATICO
	{
		
		ancho = Asintomatico->Width / 3;
		alto = Asintomatico->Height / 4;
		Rectangle porcion = Rectangle(idx * ancho, idy * alto, ancho, alto);
		ancho = 40; alto = 40;
		Rectangle aumento = Rectangle(x, y, ancho, alto);
		graficador->DrawImage(Asintomatico, aumento, porcion, GraphicsUnit::Pixel);
	}
	if (id == 3)//Verde
	{
		
		ancho = verde->Width / 3;
		alto = verde->Height / 4;
		Rectangle porcion = Rectangle(idx * ancho, idy * alto, ancho, alto);
		ancho = 40; alto = 40;
		Rectangle aumento = Rectangle(x, y, ancho, alto);
		graficador->DrawImage(verde, aumento, porcion, GraphicsUnit::Pixel);
	}
	if (id == 4)//ROJO
	{
		
		ancho = rojo->Width / 3;
		alto = rojo->Height / 4;
		Rectangle porcion = Rectangle(idx * ancho, idy * alto, ancho, alto);
		ancho = 40; alto = 40;
		Rectangle aumento = Rectangle(x, y, ancho, alto);
		graficador->DrawImage(rojo, aumento, porcion, GraphicsUnit::Pixel);
	}
	idx++;
	if (idx > 2)
		idx = 0;

}

//El movimiento de los adversarios sanos sera en linea recta
void Enemigo::MoverEnemigoSano(Graphics^ mapa)
{
	int velocidad = 3;

	if (id == 1 || id == 3)
	{
		//Derecha
		if (DireccionInicial == 1)
		{
			dx = velocidad; dy = 0;
			idy = 2;
			this->tecla = Direccion::Derecha;
			if (x + dx + ancho / 2 > mapa->VisibleClipBounds.Width)//Izquierda
			{
				DireccionInicial = 2;
			}
		}
		//IZQUIERDA
		else if (DireccionInicial == 2)
		{
			dx = -velocidad; dy = 0;
			idy = 1;
			this->tecla = Direccion::Izquierda;
			if (x + dx < 0)//derecha
			{
				DireccionInicial = 1;
			}
		}
		x += dx;
		//y += dy;
	}
}
//El movimiento de los adversarios sera de forma aleatoria 
void Enemigo::MoverEnemigoAsintomatico(Graphics^ mapa)
{
	int velocidad = 4;
	if (id == 2 || id == 4)
	{
		//ABAJO
		if (DireccionInicial == 1)
		{
			dy = velocidad; dx = 0;
			idy = 0;
			this->tecla = Direccion::Abajo;
			if (y + alto / 2 + dy > mapa->VisibleClipBounds.Height-80)//ARRIBA
			{
				DireccionInicial = 2;
			}
		}
		//ARRIBA
		else if (DireccionInicial == 2)
		{
			dy = -velocidad; dx = 0;
			idy = 3;
			this->tecla = Direccion::Arriba;
			if (y + dy < 0)//ABAJO
			{
				DireccionInicial = 1;
			}
		}
		//x += dx;
		y += dy;
	}
}

int Enemigo::get_id() //me dice que tipo de enemigo es
{
	return id;
}
void Enemigo::set_ID(int ID)
{
	this->id = ID;
}
Direccion Enemigo::get_Direccion()
{
	return tecla;
}
