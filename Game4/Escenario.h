#pragma once
#include "Figura.h"
class MAPA:public Figura
{
private:

public:
	MAPA();
	~MAPA();

	void mostrarMapa(Graphics^ grafico, Bitmap^ bitmap);

};

MAPA::MAPA()
{
	this->x = y = 0;
}

MAPA::~MAPA()
{
}
void MAPA::mostrarMapa(Graphics^ grafico, Bitmap^ bitmap)
{
	ancho = bitmap->Width;
	alto = bitmap->Height;

	Rectangle porcion = Rectangle(0, 0, ancho, alto);
	ancho = 700;
	alto = 500;
	Rectangle zoom = Rectangle(x, y,ancho ,alto);
	grafico->DrawImage(bitmap, zoom, porcion, GraphicsUnit::Pixel);
}


