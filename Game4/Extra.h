#pragma once
#include "Figura.h"

class Extra :public Figura
{
private:
public:
	Extra(void);
	~Extra(void);

	void mostrarAmbulacia(Graphics^ graficador, Bitmap^ ambulancia);
	void mostrarPolicia(Graphics^ graficador, Bitmap^ policia);
	void MoverExtraAmbulancia(Direccion tecla);
	void MoverPolicia(Direccion tecla);
	
};

Extra::Extra()
{
	
	Random r;
	x = r.Next(50, 600);
	System::Threading::Thread::Sleep(80);
	y = r.Next(50, 60);
	System::Threading::Thread::Sleep(80);
	dx = 0; dy = 0;
	idx = idy = 0;
}



Extra::~Extra()
{
}

void Extra::mostrarAmbulacia(Graphics^ graficador, Bitmap^ ambulancia)
{
	//AMBULANCIA
	
		ancho = ambulancia->Width ;
		alto = ambulancia->Height / 4;

		Rectangle porcion = Rectangle(idx, idy * alto, ancho, alto);

		Rectangle aumento = Rectangle(x, y, ancho / 2, alto / 2);
		graficador->DrawImage(ambulancia, aumento, porcion, GraphicsUnit::Pixel);

}
void Extra::mostrarPolicia(Graphics^ graficador, Bitmap^ policia)
{
	//Policia
		ancho = policia->Width / 4;
		alto = policia->Height / 4;
		Rectangle porcion = Rectangle(idx * ancho, idy * alto, ancho, alto);
		Rectangle aumento = Rectangle(x, y, ancho ,  alto );
		graficador->DrawImage(policia, aumento, porcion, GraphicsUnit::Pixel);

		idx++;
		if (idx == 3)
			idx = 0;

}
//El movimiento de los adversarios sanos sera en linea recta
void Extra::MoverExtraAmbulancia(Direccion tecla)
{
	int velocidad = 5;
	switch (tecla)
	{
	case Arriba:
		dx = 0; dy = -velocidad;
		idy = 3;
		break;
	case Abajo:
		dx = 0; dy = velocidad;
		idy = 0;
		break;
	case Derecha:
		dx = velocidad; dy = 0;
		idy = 2;
		break;
	case Izquierda:
		dx = -velocidad; dy = 0;
		idy = 1;
		break;
	case Ninguno:
		dx = 0; dy = 0;
		break;
	}
	x += dx;
	y += dy;
}
void Extra::MoverPolicia(Direccion tecla)
{
	int velocidad=5;
	switch (tecla)
	{
	case Arriba:
		dx = 0; dy = -velocidad;
		idy = 3;
		break;
	case Abajo:
		dx = 0; dy = velocidad;
		idy =0 ;
		break;
	case Derecha:
		dx = velocidad; dy = 0;
		idy = 2;
		break;
	case Izquierda:
		dx = -velocidad; dy = 0;
		idy = 1;
		break;
	case Ninguno:
		dx = 0; dy = 0;
		break;
	}

	x += dx;
	y += dy;

}


