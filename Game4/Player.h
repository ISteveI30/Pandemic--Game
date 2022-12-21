#pragma once
#include "Figura.h"
#include "Proyectiles.h"
class Player :public Figura
{
private:
	Proyectil** arregloBala;
	Direccion tecla;
	int velocidad = 15;// velocidad de la bala

	int cantidad;
public:
	Player();
	~Player();
	//metodos del jugador
	void mostrar(Graphics^ graficador, Bitmap^ bitmap);
	void mover(Direccion tecla, Graphics^ grafico);
	//metodos de las balas del jugador
	void AgregarBalasJugador();
	void MostrarBalasJugador(Graphics^ graficador, Bitmap^ bitmap);
	void MoverBalasJugador();
	void EliminarBala(int n);

	int get_cantidadBalas();
	Proyectil* get_bala(int pos);

};

Player::Player()
{
	x = 350; y = 420;
	dx = 0; dy = 0;
	tecla = Direccion::Abajo;
	idx = idy = 0;
	arregloBala = NULL;
	cantidad = 0;
}

Player::~Player()
{
}
void Player::mostrar(Graphics^ graficador, Bitmap^ bitmap)
{
	//aqui se optiene las dimensiones de la imagen
	ancho = bitmap->Width / 3;
	alto = bitmap->Height / 4;
	//en el rectangilo se dibuja la porcion de la imagen que se desa usar
		//necesita 4 parametros x , y , alto, ancho
	Rectangle porcion = Rectangle(idx * ancho, idy * alto, ancho, alto);
	ancho = 34; alto = 40;
	//Agregamos un zoom para modificar el tamaño de la imagen
	Rectangle aumento = Rectangle(x, y, ancho, alto);
	graficador->DrawImage(bitmap, aumento, porcion, GraphicsUnit::Pixel);

	idx++;
	if (idx  >2)
		idx = 0;


}
void Player::mover(Direccion tecla, Graphics^ grafico)
{
	int velocidad = 3;
	switch (tecla)
	{
	case Arriba:
	{
		if (y + dy < 1) { dx = 0; dy = 0; }
		else
		{
			dx = 0; dy = -velocidad;
			this->tecla = Direccion::Arriba;
		}
		idy = 3;

		break;
	}
	case Abajo:
	{
		if (y + dy + alto > grafico->VisibleClipBounds.Height) { dx = 0; dy = 0; }
		else
		{
			dx = 0; dy = velocidad;
			this->tecla = Direccion::Abajo;
		}
		idy = 0;

		break;
	}
	case Derecha:
	{
		if (x + dx + ancho > grafico->VisibleClipBounds.Width)
		{
			dx = 0; dy = 0;
		}
		else
		{
			dx = velocidad; dy = 0;
			this->tecla = Direccion::Derecha;
		}
		idy = 2;

		break;
	}
	case Izquierda:
	{
		if (x + dx < 1) { dx = 0; dy = 0; }
		else
		{
			dx = -velocidad; dy = 0;
			this->tecla = Direccion::Izquierda;
		}
		idy = 1;

		break;
	}
	case Ninguno:
	{
		dx = 0; dy = 0; break;
	}

	}
	x += dx;
	y += dy;
}
////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////Arreglo BALAS//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
void Player::AgregarBalasJugador()
{
	Proyectil** aux = new Proyectil * [cantidad + 1];
	for (int i = 0; i < cantidad; i++)
	{
		aux[i] = arregloBala[i];
	}
	switch (tecla)
	{

	case Direccion::Arriba:
		dx = 0; dy = -velocidad;
		break;
	case Direccion::Abajo:
		dx = 0; dy = velocidad;
		break;
	case Direccion::Derecha:
		dx = velocidad; dy = 0;
		break;
	case Direccion::Izquierda:
		dx = -velocidad; dy = 0;
		break;
	}

	aux[cantidad] = new Proyectil(x + (ancho / 3), y + alto / 2, dx, dy);
	cantidad++;
	if (arregloBala != NULL)
		delete arregloBala;

	arregloBala = aux;
}
void Player::MostrarBalasJugador(Graphics^ graficador, Bitmap^ bitmap)
{
	for (int i = 0; i < cantidad; i++)
	{
		arregloBala[i]->MostrarBala(graficador, bitmap);
	}
}
void Player::MoverBalasJugador()
{
	for (int i = 0; i < cantidad; i++)
	{
		arregloBala[i]->MoverBala();
	}
}
void Player::EliminarBala(int n)
{
	Proyectil** aux = new Proyectil * [cantidad - 1];
	delete arregloBala[n];
	for (int i = 0; i < n; i++)
	{
		aux[i] = arregloBala[i];
	}
	for (int j = n; j < cantidad - 1; j++)
	{
		aux[j] = arregloBala[j + 1];
	}
	cantidad--;
	arregloBala = aux;
}
int Player::get_cantidadBalas()
{
	return cantidad;
}
Proyectil* Player::get_bala(int pos)
{
	return arregloBala[pos];
}