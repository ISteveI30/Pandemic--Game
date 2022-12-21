#pragma once
#include "Player.h"
#include "Enemigo.h"
#include "Extra.h"
#include "Escenario.h"
#include "Especial.h"
class Nivel
{
protected:
	//////////////////////////////////MAPA/////////////////
	MAPA* objMapa;
	//////////Jugador
	Player* objplayer;
	
	//////////////////////////////////Enemigos/////////////
	Enemigo** arreglo;
	int cantidad;//CANTIDAD DEL ARREGLO
	int numero;//NUMERO DE ANEMIGOS QUE SE GENERARA
	int CantidadEnemigo1;//DIVISION EQUITATIVA
	int CantidadEnemigo2;
	//////////////////////////////////BALAS ENEMIGO///////
	//Atribitos de los proyectiles del enemigo
	Proyectil** BalasEnemigo;
	int cantidadBalas;
	int velocidad = 8;//velocidad de la bala enemiga
	/////////////////////////////////Extras///////////////
	Extra* objExtra;//policia
	Extra* objExtra2;//ambulancia
	////////////////////////////////JUEGO/////////////////
	int vidas;
	int tiempo;
	int dificultad;
	int puntaje;
	int nivel;
	int cambiar;
	////////////////////////////FUNCIONALIDAD ESPECIAL///////////////
	Especial** arregloZombies;
	int CantidadInfectados;
	int Z;
public:
	Nivel(void);
	~Nivel(void);
	/////////////////////////////////Jugador/////////////////////////////////
	void MoverJugador(Keys tecla, Graphics^ graficador);
	void MostrarPersonajes(Graphics^ graficador, Bitmap^ jugador);
	void BalasJugador(Graphics^ graficador, Bitmap^ bitmap);
	void Disparar();
	bool ColisonesJugador();
	bool ColisonesJugador_Enemigo();
	bool ColisionesCambiarColor();
	
	/////////////////////////////////Enemigos////////////////////////////////

	void AgregarEnemigos(int TipoEnemigo, int n);
	void MostrarEnemigos(Graphics^ graficador, Bitmap^ Sano, Bitmap^ Asintomatico, Bitmap^ verde, Bitmap^ rojo);
	void MoverEnemigos(Graphics^ mapa);
	void EliminarEnemigo(int n);
	//setter y getters del arreglo Enmigos
	int get_cantidadEnemigos();
	Enemigo* get_Enemigo(int pos);

	//////////////////////////////////BALAS ENEMIGO//////////////////////
	//metodos de los proyeciles del enemigo
	void AgregarBalasEnemigo();
	void MostrarBalasEnemigo(Graphics^ graficador, Bitmap^ bitmap);
	void MoverBalasEnemigo();
	void EliminarBalaEnemigo(int n);
	int get_cantidadBalasEnemigo();
	Proyectil* get_balaEnemigo(int pos);

	//////////////////////////////////Extras////////////
	void PoliciaSeguir();
	void Policia(Graphics^ graficador, Bitmap^ policia);

	void ColisionPolicia();
	void ColisionAmbulancia();

	void AmbulanciaSeguir();
	void Ambulancia(Graphics^ graficador, Bitmap^ ambulancia);

	/////////////////////////////ESCENARIO///////////////
	void Mapa(Graphics ^graficador,Bitmap^mapa);
	
	////////////////////////////////JUEGO CONFIGURACIONES/////////////////
	int get_vidas();
	int get_tiempo();
	int get_dificultad();
	int get_puntaje();
	int get_Nivel();
	int get_cambiarMundo();
	int get_cantidadIncialEnmigos();


	void set_vidas(int _vidas);
	void set_tiempo(int _tiempo);
	void set_dificultad(int _dificultad);
	void set_puntaje(int _puntaje);
	void set_Nivel(int _nivel);
	void set_cambiarMundo(int _cambiar);

	void mostrarDatos(Graphics^ graficador, int vidas, int minutos, int segundos,int puntajes, int mensajes, int enemigos);
	void mostrarDatosEspecial(Graphics^ graficador, int vidas, int minutos, int segundos, int puntajes);
	////////////////////////////////FUNCIONALIDAD ESPECIAL/////////////////////////////////
	void AgregarZombie(int n);
	void EliminarZombies(int n);
	void MostrarZombies(Graphics^ graficador, Bitmap^ zombie);
	void MoverZombies(Graphics^ graficador);
	bool colisionesZombies();
	bool Colision_Jugador_Zombie();
	int get_Zombies();
};

Nivel::Nivel(void)
{
	objplayer = new Player();
	objMapa = new MAPA();
	objExtra = new Extra();//policia
	objExtra2 = new Extra();//ambulancia
	Random r;
	cantidad = 0;
	arreglo = NULL;
	cantidadBalas = 0;
	BalasEnemigo = NULL;
	arregloZombies = NULL;
	CantidadInfectados = 0;

	numero = r.Next(5, 11);//Se genera una cantidad aleatoria de enemigos  4<numero<11 
	if (numero % 2 == 0)
	{
		CantidadEnemigo1 = numero / 2;//se indica la cantidad de enemigos que se mostrara
		CantidadEnemigo2 = numero / 2;

		//1= indica el tipo de enemigo que se mostrara (SANO)
		//2= indica el tipo de enemigo que se mostrara (ASINTOMATICO)
		AgregarEnemigos(1, CantidadEnemigo1);//sanos,verdes
		AgregarEnemigos(2, CantidadEnemigo2);//asintomaticos,rojos


	}
	if (numero % 2 != 0)
	{
		CantidadEnemigo1 = numero / 2;
		CantidadEnemigo2 = (numero / 2) + 1;


		AgregarEnemigos(1, CantidadEnemigo1);
		AgregarEnemigos(2, CantidadEnemigo2);
	}
	Random g;
	Z = g.Next(10,20);
	AgregarZombie(Z);


}

Nivel::~Nivel(void)
{
	for (int i = 0; i < cantidad; i++)
	{
		delete arreglo[i];
	}
}
///////////////////////////////////////////////////JUGADOR///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Nivel::MoverJugador(Keys tecla, Graphics^ graficador)
{
	if (tecla == Keys::Up)
	{
		objplayer->mover(Direccion::Arriba, graficador);
	}
	if (tecla == Keys::Down)
	{
		objplayer->mover(Direccion::Abajo, graficador);
	}
	if (tecla == Keys::Left)
	{
		objplayer->mover(Direccion::Izquierda, graficador);
	}
	if (tecla == Keys::Right)
	{
		objplayer->mover(Direccion::Derecha, graficador);
	}
}
void Nivel::MostrarPersonajes(Graphics^ graficador, Bitmap^ jugador)
{
	//MostrarEnemigos(graficador);
	objplayer->mostrar(graficador, jugador);
}
void Nivel::BalasJugador(Graphics^ graficador, Bitmap^ bitmap)
{
	objplayer->MoverBalasJugador();
	objplayer->MostrarBalasJugador(graficador, bitmap);
}
void Nivel::Disparar()
{
	objplayer->AgregarBalasJugador();
}

bool Nivel::ColisionesCambiarColor()
{
	
	Rectangle enemigos;
	Rectangle balas;
	Proyectil* proyectil;
	bool point=false;
inicio:
	for (int i = 0; i < objplayer->get_cantidadBalas(); i++)//recorre el arreglo de balas
	{
		proyectil = objplayer->get_bala(i);

		balas = Rectangle(proyectil->get_x(), proyectil->get_y(), proyectil->get_ancho(), proyectil->get_alto());
		for (int j = 0; j < cantidad; j++)//recorre el arreglo de enemigos
		{
			enemigos = Rectangle(arreglo[j]->get_x(), arreglo[j]->get_y(), arreglo[j]->get_ancho(), arreglo[j]->get_alto());
			if (balas.IntersectsWith(enemigos))
			{
				if (arreglo[j]->get_id() == 1 || arreglo[j]->get_id() == 3)
				{
					arreglo[j]->set_ID(3);//aqui llamo al identificador del enemigo y el asgino nuevo valor que se vera reflejado en el metodo mostrar
					objplayer->EliminarBala(i);
					point= true;
					goto inicio;
				}
				if (arreglo[j]->get_id() == 2 || arreglo[j]->get_id() == 4)
				{
					
					arreglo[j]->set_ID(4);
					objplayer->EliminarBala(i);
					point = true;
					goto inicio;
				}


			}
		}
	}
	return point;
}
bool Nivel::ColisonesJugador()
{
	
	Rectangle balas;
		
	Rectangle jugador=Rectangle(objplayer->get_x(), objplayer->get_y(), objplayer->get_ancho(), objplayer->get_alto());
		for (int i = 0; i < cantidadBalas; i++)//recorre el arreglo de enemigos
		{
			balas = Rectangle(BalasEnemigo[i]->get_x(), BalasEnemigo[i]->get_y(), BalasEnemigo[i]->get_ancho(), BalasEnemigo[i]->get_alto());
			if (jugador.IntersectsWith(balas))
			{
				objplayer->set_x(350);
				objplayer->set_y(420);
				return true;
			}
		}
		return false;
}
bool Nivel::ColisonesJugador_Enemigo()
{
	Rectangle enemigos;

	Rectangle jugador = Rectangle(objplayer->get_x(), objplayer->get_y(), objplayer->get_ancho(), objplayer->get_alto());
	for (int i = 0; i < cantidad; i++)//recorre el arreglo de enemigos
	{
		enemigos = Rectangle(arreglo[i]->get_x(), arreglo[i]->get_y(), arreglo[i]->get_ancho(), arreglo[i]->get_alto());
		if (jugador.IntersectsWith(enemigos))
		{
			objplayer->set_x(350);
			objplayer->set_y(420);
			return true;
		}
	}
	return false;
}

///////////////////////////////////////////////////ENEMIGOD///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Nivel::AgregarEnemigos(int TipoEnemigo, int numero)
{

	for (int i = 0; i < numero; i++)
	{
		Enemigo** aux = new Enemigo * [cantidad + 1];
		for (int i = 0; i < cantidad; i++)
		{
			aux[i] = arreglo[i];
		}
		aux[cantidad] = new Enemigo(TipoEnemigo);
		cantidad++;
		if (arreglo != NULL)
			delete arreglo;
		arreglo = aux;
	}
}
void Nivel::MostrarEnemigos(Graphics^ graficador, Bitmap^ Sano, Bitmap^ Asintomatico, Bitmap^ verde, Bitmap^ rojo)
{
	for (int i = 0; i < cantidad; i++)
	{
		arreglo[i]->mostrar(graficador, Sano, Asintomatico, verde, rojo);
	}
}
void Nivel::MoverEnemigos(Graphics^ mapa)
{
	for (int i = 0; i < cantidad; i++)
	{
		arreglo[i]->MoverEnemigoSano(mapa);
		arreglo[i]->MoverEnemigoAsintomatico(mapa);
	}
}
void Nivel::EliminarEnemigo(int n)//eliminar enemigos rojos
{
	
	Enemigo** aux = new Enemigo * [cantidad - 1];
	delete arreglo[n];
	for (int i = 0; i < n; i++)
	{
		aux[i] = arreglo[i];
	}
	for (int i = n; i < cantidad - 1; i++)
	{
		aux[i] = arreglo[i + 1];
	}
	cantidad--;
	arreglo = aux;
}

void Nivel::AgregarBalasEnemigo()
{
	for (int j = 0; j < cantidad; j++)
	{
	    Proyectil** aux = new Proyectil * [cantidadBalas + 1];
	    int dx, dy = 0;
	    for (int i = 0; i < cantidadBalas; i++)
	    {
	    	aux[i] = BalasEnemigo[i];
	    }
	    switch (arreglo[j]->get_Direccion())
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
	    
	    aux[cantidadBalas] = new Proyectil(arreglo[j]->get_x() + (arreglo[j]->get_ancho() / 4), arreglo[j]->get_y() + (arreglo[j]->get_alto() / 4), dx, dy);
	    cantidadBalas++;
	    if (BalasEnemigo != NULL)
	    	delete BalasEnemigo;
	    
	    BalasEnemigo = aux;
    }
}
void Nivel::MostrarBalasEnemigo(Graphics^ graficador, Bitmap^ bitmap)
{
	for (int i = 0; i < cantidadBalas; i++)
	{
		BalasEnemigo[i]->MostrarBala(graficador, bitmap);
	}
}
void Nivel::MoverBalasEnemigo()
{
	for (int i = 0; i < cantidadBalas; i++)
	{
		BalasEnemigo[i]->MoverBala();
	}
}
void Nivel::EliminarBalaEnemigo(int n)
{
	Proyectil** aux = new Proyectil * [cantidadBalas - 1];
	delete BalasEnemigo[n];
	for (int i = 0; i < n; i++)
	{
		aux[i] = BalasEnemigo[i];
	}
	for (int j = n; j < cantidadBalas - 1; j++)
	{
		aux[j] = BalasEnemigo[j + 1];
	}
	cantidadBalas--;
	BalasEnemigo = aux;
}


int Nivel::get_cantidadBalasEnemigo()
{
	return cantidadBalas;
}
int Nivel::get_cantidadEnemigos()
{
	return cantidad;
}
Proyectil* Nivel::get_balaEnemigo(int pos)
{
	return BalasEnemigo[pos];
}
Enemigo* Nivel::get_Enemigo(int pos)
{
	return arreglo[pos];
}
////////////////////////////////////////////EXTRAS///////////////////////////////////////////////////////////
void Nivel::PoliciaSeguir()
{
	bool atrapado=false;
	for (int i = 0; i < cantidad;i++ )
	{
		
		if (arreglo[i]->get_id()==3)
		{
			if (objExtra->get_x() > arreglo[i]->get_x())
			{
				objExtra->MoverPolicia(Direccion::Izquierda);
			}
			if (objExtra->get_x() < arreglo[i]->get_x())
			{
				objExtra->MoverPolicia(Direccion::Derecha);
			}
			if (objExtra->get_y() > arreglo[i]->get_y())
			{
				objExtra->MoverPolicia(Direccion::Arriba);
			}
			if (objExtra->get_y() < arreglo[i]->get_y())
			{
				objExtra->MoverPolicia(Direccion::Abajo);
			}
			
		}
		
	}

}
void Nivel::ColisionPolicia()
{

	Rectangle enemigos;
	inicio:
	
	Rectangle policia = Rectangle(objExtra->get_x(), objExtra->get_y(), objExtra->get_ancho(), objExtra->get_alto());
	for (int i = 0; i < cantidad; i++)//recorre el arreglo de balas
	{
		enemigos = Rectangle(arreglo[i]->get_x(), arreglo[i]->get_y(), arreglo[i]->get_ancho(), arreglo[i]->get_alto());
		if (policia.IntersectsWith(enemigos))
		{
			if (arreglo[i]->get_id()==3)
			{
				EliminarEnemigo(i--);
			
				goto inicio;
			}
		}
	}
	
}
void Nivel::ColisionAmbulancia()
{
	Rectangle enemigos;
inicio:

	Rectangle policia = Rectangle(objExtra2->get_x(), objExtra2->get_y(), objExtra2->get_ancho(), objExtra2->get_alto());
	for (int i = 0; i < cantidad; i++)//recorre el arreglo de balas
	{
		enemigos = Rectangle(arreglo[i]->get_x(), arreglo[i]->get_y(), arreglo[i]->get_ancho(), arreglo[i]->get_alto());
		if (policia.IntersectsWith(enemigos))
		{
			if (arreglo[i]->get_id() == 4)
			{
				EliminarEnemigo(i--);

				goto inicio;
			}
		}
	}

}

void Nivel::Policia(Graphics^ graficador, Bitmap^ policia)
{
	
	PoliciaSeguir();
	objExtra->mostrarPolicia(graficador, policia);

}
void Nivel::AmbulanciaSeguir()
{
	for (int i = 0; i < cantidad; i++)
	{

		if (arreglo[i]->get_id() == 4)
		{
			if (objExtra2->get_x() > arreglo[i]->get_x())
			{
				objExtra2->MoverExtraAmbulancia(Direccion::Izquierda);
			}
			if (objExtra2->get_x() < arreglo[i]->get_x())
			{
				objExtra2->MoverExtraAmbulancia(Direccion::Derecha);
			}
			if (objExtra->get_y() > arreglo[i]->get_y())
			{
				objExtra2->MoverExtraAmbulancia(Direccion::Arriba);
			}
			if (objExtra2->get_y() < arreglo[i]->get_y())
			{
				objExtra2->MoverExtraAmbulancia(Direccion::Abajo);
			}

		}
	}
}
void Nivel::Ambulancia(Graphics^ graficador, Bitmap^ ambulancia)
{
	AmbulanciaSeguir();
	objExtra2->mostrarAmbulacia(graficador,ambulancia);
}

void Nivel::mostrarDatos(Graphics^ graficador, int vidas,int minutos,int segundos,int puntajes,int mensajes,int enemigos)
{
	graficador->DrawString("VIDAS : " + vidas.ToString(), gcnew Font("Terminator Two", 16), Brushes::Black,10, 15);
	graficador->DrawString("TIEMPO : " + minutos.ToString()+":"+segundos.ToString()
	, gcnew Font("Terminator Two", 16), Brushes::Black, 150, 15);
	graficador->DrawString("PUNTAJES : " + puntajes.ToString(), gcnew Font("Terminator Two", 16), Brushes::Black, 350, 15);
	graficador->DrawString("MENSAJES : " + mensajes.ToString(), gcnew Font("Terminator Two", 16), Brushes::Black, 10, 40);
	graficador->DrawString("ENEMIGOS : " + enemigos.ToString(), gcnew Font("Terminator Two", 16), Brushes::Black, 350, 40);
}
void Nivel::mostrarDatosEspecial(Graphics^ graficador, int vidas, int minutos, int segundos, int puntajes)
{
	graficador->DrawString("VIDAS : " + vidas.ToString(), gcnew Font("Terminator Two", 16), Brushes::White, 10, 15);
	graficador->DrawString("TIEMPO : " + minutos.ToString() + ":" + segundos.ToString()
		, gcnew Font("Terminator Two", 16), Brushes::White, 150, 15);
	graficador->DrawString("PUNTAJES : " + puntajes.ToString(), gcnew Font("Terminator Two", 16), Brushes::White, 350, 15);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////ESPECIAL///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Nivel::AgregarZombie(int n)
{
	for (int j = 0; j < n; j++)
	{
		Especial** aux = new Especial * [CantidadInfectados + 1];
		for (int i = 0; i < CantidadInfectados; i++)
		{
			aux[i] = arregloZombies[i];
		}
		aux[CantidadInfectados] = new Especial();
		CantidadInfectados++;
		if (arregloZombies != NULL)
			delete arregloZombies;
		arregloZombies = aux;
	}
}
void Nivel::EliminarZombies(int n)
{

	Especial** aux = new Especial * [CantidadInfectados - 1];
	delete arregloZombies[n];
	for (int i = 0; i < n; i++)
	{
		aux[i] = arregloZombies[i];
	}
	for (int i = n; i < CantidadInfectados - 1; i++)
	{
		aux[i] = arregloZombies[i + 1];
	}
	CantidadInfectados--;
	arregloZombies = aux;
}
void Nivel::MostrarZombies(Graphics^ graficador, Bitmap^ zombie)
{
	for (int i = 0; i < CantidadInfectados; i++)
	{
		arregloZombies[i]->MostrarZombie(graficador,zombie);
	}
}
void Nivel::MoverZombies(Graphics^ graficador)
{
	for (int i = 0; i < CantidadInfectados; i++)
	{
		arregloZombies[i]->MoverZombie(graficador,objplayer->get_x(),objplayer->get_y());
	}
}
bool Nivel::colisionesZombies()
{
	Rectangle zombies;
	Rectangle balas;
	Proyectil* proyectil;
	bool point = false;
inicio:
	for (int i = 0; i < objplayer->get_cantidadBalas(); i++)//recorre el arreglo de balas
	{
		proyectil = objplayer->get_bala(i);

		balas = Rectangle(proyectil->get_x(), proyectil->get_y(), proyectil->get_ancho(), proyectil->get_alto());
		for (int j = 0; j < CantidadInfectados; j++)//recorre el arreglo de enemigos
		{
			zombies = Rectangle(arregloZombies[j]->get_x(), arregloZombies[j]->get_y(), arregloZombies[j]->get_ancho(),
			arregloZombies[j]->get_alto());
			if (balas.IntersectsWith(zombies))
			{
				EliminarZombies(j);
				objplayer->EliminarBala(i);
				point = true;
				goto inicio;
			}
		}
	}
	return point;
}
bool Nivel::Colision_Jugador_Zombie()
{
	Rectangle zombies;

	Rectangle jugador = Rectangle(objplayer->get_x(), objplayer->get_y(), objplayer->get_ancho(), objplayer->get_alto());
	for (int i = 0; i < CantidadInfectados; i++)//recorre el arreglo de enemigos
	{
		zombies = Rectangle(arregloZombies[i]->get_x(), arregloZombies[i]->get_y(), arregloZombies[i]->get_ancho(),
		arregloZombies[i]->get_alto());
		if (jugador.IntersectsWith(zombies))
		{
			objplayer->set_x(350);
			objplayer->set_y(420);
			return true;
		}
	}
	return false;
}
int Nivel::get_Zombies()
{
	return CantidadInfectados;
}
int Nivel:: get_cantidadIncialEnmigos() 
{ return numero; }
///////////////////////////////JUEGO//////////////////////////////////

void Nivel::Mapa(Graphics^ graficador, Bitmap^ mapa)
{

	objMapa->mostrarMapa(graficador,mapa);
}
int Nivel::get_vidas()
{
	return vidas;
}
int Nivel::get_tiempo()
{
	return tiempo;
}
int Nivel::get_dificultad()
{
	return dificultad;
}
int Nivel::get_puntaje()
{
	return puntaje;
}
int Nivel::get_Nivel()
{
	return nivel;
}
int Nivel::get_cambiarMundo()
{
	return cambiar;
}
void Nivel::set_vidas(int _vidas)
{
	this->vidas = _vidas;
}
void Nivel::set_tiempo(int _tiempo)
{
	this->tiempo = _tiempo;
}
void Nivel::set_dificultad(int _dificultad)
{
	this->dificultad = _dificultad;
}
void Nivel::set_puntaje(int _puntaje)
{
	this->puntaje = _puntaje;
}
void Nivel::set_Nivel(int _nivel)
{
	this->nivel = _nivel;
}
void Nivel::set_cambiarMundo(int _cambiar)
{
	this->cambiar = _cambiar;
}

