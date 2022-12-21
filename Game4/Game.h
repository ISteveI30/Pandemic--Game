#pragma once
#include "Instrucciones.h"
#include "Nivel.h"

namespace Game4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(void)
		{
			InitializeComponent();
		
			
			vidas=0;
			tiempo=0;
			dificultad=0;

			graficador = this->CreateGraphics();
			objNivel = new Nivel();

			player = gcnew Bitmap("imagenes/jugador.png");
			balajugador = gcnew Bitmap("imagenes/carta.png");
			balaEnemigo = gcnew Bitmap("imagenes/piedra.png");

			mapa = gcnew Bitmap("imagenes/parque.png");
			mapa2 = gcnew Bitmap("imagenes/mapa.png");
			mapa3 = gcnew Bitmap("imagenes/mapa3.png");

			sano = gcnew Bitmap("imagenes/saludable.png");//Sano
			verde = gcnew Bitmap("imagenes/verde.png");
			asintomatico = gcnew Bitmap("imagenes/asintomatico.png");//Enfermo
			rojo = gcnew Bitmap("imagenes/rojo2.png");
			///////////////////////////////EXTRAS
            ambulancia = gcnew Bitmap("imagenes/carro.png");//ambulancia
			policia = gcnew Bitmap("imagenes/policia.png");
			/////////////////////////////ESPECIAL
			zombies = gcnew Bitmap("imagenes/zombie.png");
			bala = gcnew Bitmap("imagenes/bala.png");
			militar = gcnew Bitmap("imagenes/soldado.png");
		}

	protected:
		
		~Game()
		{
			if (components)
			{
				delete components;


				delete buffer;
				delete bc;
				delete graficador;

			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:

		//variables que guardan los valores del formulario
		int vidas;//se guardan las vidas para el segundo nivel
		int tiempo;//se guardan las vidas para le segundo nivel
		int dificultad;
		//variables para modificar los datos
		int segundos=590;
		int contador;//me idica cada cuanto tiempo disparan los enemigos

		int contadorPolicia;

		/////randoms para la ambulancia y policia
		int a,p;
		Random r;
		//jugador 
		Bitmap^ player;
		Bitmap^ balajugador;
		//enemigo
		Bitmap^ sano;
		Bitmap^ verde;
		Bitmap^ asintomatico;
		Bitmap^ rojo;
		Bitmap^ balaEnemigo;

		//escenario
		Bitmap^ mapa;
		Bitmap^ mapa2;
		Bitmap^ mapa3;
		//Extras
		Bitmap^ ambulancia;
		Bitmap^ policia;
		Bitmap^ bala;
		//especial
		Bitmap^ zombies;
		Bitmap^ militar;
		//Declaracion del  objeto principal
		Nivel* objNivel;
		//declaracion del lienzo(canvas)
		Graphics^ graficador;
		//Declarando buffer
		BufferedGraphicsContext^ bc;
		BufferedGraphics^ buffer;
		////////////////informacion
		String^ info = "QUEDATE EN CASA";
		String^ info2 = "LAVATE LAS MANOS";
		int mensaje = -1;

	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Button^ btnInfo;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnGame;
	private: System::Windows::Forms::ComboBox^ cboxDificultad;


	private: System::Windows::Forms::TextBox^ txtVidas;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider2;
	private: System::Windows::Forms::ErrorProvider^ errorProvider3;
	private: System::Windows::Forms::Timer^ timer2;
private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::TextBox^ txtTiempo;


		  

#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnInfo = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnGame = (gcnew System::Windows::Forms::Button());
			this->cboxDificultad = (gcnew System::Windows::Forms::ComboBox());
			this->txtVidas = (gcnew System::Windows::Forms::TextBox());
			this->txtTiempo = (gcnew System::Windows::Forms::TextBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider3 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider3))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Game::timer1_Tick);
			// 
			// btnStart
			// 
			this->btnStart->BackColor = System::Drawing::Color::DarkOrchid;
			this->btnStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStart->ForeColor = System::Drawing::Color::White;
			this->btnStart->Location = System::Drawing::Point(58, 238);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(108, 35);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = false;
			this->btnStart->Click += gcnew System::EventHandler(this, &Game::btnStart_Click);
			// 
			// btnInfo
			// 
			this->btnInfo->BackColor = System::Drawing::Color::DarkOrchid;
			this->btnInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInfo->ForeColor = System::Drawing::Color::White;
			this->btnInfo->Location = System::Drawing::Point(278, 238);
			this->btnInfo->Name = L"btnInfo";
			this->btnInfo->Size = System::Drawing::Size(153, 35);
			this->btnInfo->TabIndex = 1;
			this->btnInfo->Text = L"Instrucciones";
			this->btnInfo->UseVisualStyleBackColor = false;
			this->btnInfo->Click += gcnew System::EventHandler(this, &Game::btnInfo_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 298);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(499, 1);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(268, 298);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 3;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::DeepPink;
			this->label1->Location = System::Drawing::Point(90, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(341, 31);
			this->label1->TabIndex = 4;
			this->label1->Text = L"QUARANTINE-GAME";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::SlateGray;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(546, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"CONFIGURACIONES";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::MediumPurple;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(515, 92);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"VIDAS";
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::MediumPurple;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(515, 139);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 33);
			this->label4->TabIndex = 7;
			this->label4->Text = L" TIEMPO  (minutos)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::MediumPurple;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(515, 202);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(105, 20);
			this->label5->TabIndex = 8;
			this->label5->Text = L"DIFICULTAD";
			// 
			// btnGame
			// 
			this->btnGame->BackColor = System::Drawing::Color::DarkOrchid;
			this->btnGame->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGame->Location = System::Drawing::Point(602, 250);
			this->btnGame->Name = L"btnGame";
			this->btnGame->Size = System::Drawing::Size(75, 23);
			this->btnGame->TabIndex = 9;
			this->btnGame->Text = L"JUGAR";
			this->btnGame->UseVisualStyleBackColor = false;
			this->btnGame->Click += gcnew System::EventHandler(this, &Game::btnGame_Click);
			// 
			// cboxDificultad
			// 
			this->cboxDificultad->FormattingEnabled = true;
			this->cboxDificultad->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Principiante", L"Avanzado" });
			this->cboxDificultad->Location = System::Drawing::Point(625, 197);
			this->cboxDificultad->Name = L"cboxDificultad";
			this->cboxDificultad->Size = System::Drawing::Size(133, 21);
			this->cboxDificultad->TabIndex = 10;
			// 
			// txtVidas
			// 
			this->txtVidas->Location = System::Drawing::Point(609, 92);
			this->txtVidas->Name = L"txtVidas";
			this->txtVidas->Size = System::Drawing::Size(133, 20);
			this->txtVidas->TabIndex = 11;
			// 
			// txtTiempo
			// 
			this->txtTiempo->Location = System::Drawing::Point(609, 139);
			this->txtTiempo->Name = L"txtTiempo";
			this->txtTiempo->Size = System::Drawing::Size(133, 20);
			this->txtTiempo->TabIndex = 12;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// errorProvider2
			// 
			this->errorProvider2->ContainerControl = this;
			// 
			// errorProvider3
			// 
			this->errorProvider3->ContainerControl = this;
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Game::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &Game::timer3_Tick);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 297);
			this->Controls->Add(this->txtTiempo);
			this->Controls->Add(this->txtVidas);
			this->Controls->Add(this->cboxDificultad);
			this->Controls->Add(this->btnGame);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btnInfo);
			this->Controls->Add(this->btnStart);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyDown);
			this->Resize += gcnew System::EventHandler(this, &Game::Game_Resize);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void IniciarPartida()
		{
			if (txtTiempo->Text==""||txtVidas->Text=="")
			{
				errorProvider1->SetError(txtTiempo,"Definir tiempo");
				errorProvider2->SetError(txtVidas,"Definir Vidas");
			}
			else
			{
			    tiempo = Int32::Parse(txtTiempo->Text);
				vidas = Int32::Parse(txtVidas->Text);
				dificultad = cboxDificultad->SelectedIndex;
				objNivel->set_puntaje(0);
				objNivel->set_cambiarMundo(0);
				if (dificultad==-1)
				{
					errorProvider3->SetError(cboxDificultad,"Seleccionar Dificultad");
				}
				else
				{
					
					objNivel->set_tiempo(tiempo);
					objNivel->set_vidas(vidas);
					objNivel->set_dificultad(dificultad);
					objNivel->set_Nivel(1);
					a = r.Next(50,80);
					p = r.Next(50,80);
					delete pictureBox1;
					delete pictureBox2;
					delete label1;
					delete label2;
					delete label3;
					delete label4;
					delete label5;
					delete txtTiempo;
					delete txtVidas;
					delete cboxDificultad;
					delete btnGame;
					delete btnStart;
					delete btnInfo;
					this->Width = 700;
					this->Height = 500;
					this->CenterToScreen();
					this->BackColor = System::Drawing::Color::DarkGreen;
					MessageBox::Show("Bienvenido a MIRAFLORES, en este lugar las personas son medianamente responsables. Envia mensajes de advertencia a los ciudadanos ");
					timer1->Enabled = true;
					this->Text = "";
				}				
			}		
		}

		void colisiones_Vidas()
		{
			
			if (objNivel->ColisionesCambiarColor())
			{
				
				objNivel->set_puntaje(objNivel->get_puntaje() + 10);
				objNivel->set_cambiarMundo(objNivel->get_cambiarMundo() + 1);
				mensaje++;
			}
			if (objNivel->ColisonesJugador())
			{
				objNivel->set_vidas(objNivel->get_vidas()-1);
			}
			if (objNivel->ColisonesJugador_Enemigo())
			{
				objNivel->set_vidas(objNivel->get_vidas() - 1);
			}
			objNivel->ColisionPolicia();
			objNivel->ColisionAmbulancia();
		}
		void colisioneszombies()
		{
			
			if (objNivel->colisionesZombies())
			{
				objNivel->set_puntaje(objNivel->get_puntaje() + 10);
			}
			
			if (objNivel->Colision_Jugador_Zombie())
			{
				objNivel->set_vidas(objNivel->get_vidas() - 1);
			}
		}

		void calcularTiempo()
		{
			segundos--;
			if (segundos/10==0)
			{
				tiempo--;
				objNivel->set_tiempo(tiempo); 
				segundos = 590;
			}
			if (objNivel->get_tiempo()==0)
			{
				segundos = 0;
			}
		}
		void PasarNivel()
		{
			
			this->BackColor = System::Drawing::Color::DarkRed;
			timer1->Enabled = false;
			MessageBox::Show("Bienvenido a CALLAO, en este lugar las personas no son responsables. Envia mensajes de advertencia a los ciudadanos irresponsables");
			timer2->Enabled = true;
			this->Text = "";
			mensaje = -1;
			a = r.Next(50, 80);
			p = r.Next(50, 80);
			objNivel->set_vidas(vidas);
			objNivel->set_tiempo(tiempo);
			objNivel->set_puntaje(0);
			objNivel->set_cambiarMundo(0);
     	}
		void PasarNive2()
		{

			timer2->Enabled = false;
			this->BackColor = System::Drawing::Color::Black;
			MessageBox::Show("Han transcurrido 7 años, el virus ha mutado en las personas irresponsables convirtiendolas en Zombies, ¡SOBREVIVE! ¡ANIQUILALOS!");
			timer3->Enabled = true;
			this->Text = "";
			objNivel->set_vidas(vidas);
			objNivel->set_tiempo(tiempo);
			objNivel->set_puntaje(0);
			objNivel->set_cambiarMundo(0);
		}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		bc = BufferedGraphicsManager::Current;
		buffer = bc->Allocate(graficador, this->ClientRectangle);
		//buffer->Graphics->Clear(Color::Black);
		objNivel->Mapa(buffer->Graphics, mapa);
		objNivel->MostrarEnemigos(buffer->Graphics, sano, asintomatico, verde, rojo);
		objNivel->MostrarPersonajes(buffer->Graphics, player);
		objNivel->BalasJugador(buffer->Graphics, balajugador);
		objNivel->MoverEnemigos(buffer->Graphics);
		p--;
		if (p==0)
		{
            objNivel->Policia(buffer->Graphics, policia);
		    p ++;
		}
		a--;
		if (a==0)
		{
		    objNivel->Ambulancia(buffer->Graphics, ambulancia);
			a++;
		}
		if (objNivel->get_dificultad() == 1)
		{
			objNivel->MostrarBalasEnemigo(buffer->Graphics, balaEnemigo);
			objNivel->MoverBalasEnemigo();

			contador++;
			if (contador == 30)
			{
				objNivel->AgregarBalasEnemigo();
				contador = 0;
			}

		}
		colisiones_Vidas();
		calcularTiempo();
		if (mensaje%2==0)
		{
		    this->Text ="ADVERTENCIA : "+ info;
		}
		if (mensaje % 2 != 0)
		{
			this->Text = "ADVERTENCIA : " + info2;
		}
		objNivel->mostrarDatos(buffer->Graphics, objNivel->get_vidas(), objNivel->get_tiempo(), segundos/10, 
		objNivel->get_puntaje(),objNivel->get_cambiarMundo(), objNivel->get_cantidadIncialEnmigos());

		buffer->Render(graficador);
		if (objNivel->get_cambiarMundo() == objNivel->get_cantidadIncialEnmigos() /2)
		{
			PasarNivel();
		}
		if (objNivel->get_vidas()==0)
		{
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
		}
		if (objNivel->get_tiempo() == 0)
		{
			timer1->Enabled = false;
			MessageBox::Show("Perdiste");
		}
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		bc = BufferedGraphicsManager::Current;
		buffer = bc->Allocate(graficador, this->ClientRectangle);
		//buffer->Graphics->Clear(Color::White);
		objNivel->Mapa(buffer->Graphics, mapa2);
		objNivel->MostrarEnemigos(buffer->Graphics, sano, asintomatico, verde, rojo);
		objNivel->MostrarPersonajes(buffer->Graphics, player);
		objNivel->BalasJugador(buffer->Graphics, balajugador);
		objNivel->MoverEnemigos(buffer->Graphics);
		p--;
		if (p == 0)
		{
			objNivel->Policia(buffer->Graphics, policia);
			p++;
		}
		a--;
		if (a == 0)
		{
			objNivel->Ambulancia(buffer->Graphics, ambulancia);
			a++;
		}
		if (objNivel->get_dificultad() == 1)
		{
			objNivel->MostrarBalasEnemigo(buffer->Graphics, balaEnemigo);
			objNivel->MoverBalasEnemigo();

			contador++;
			if (contador == 30)
			{
				objNivel->AgregarBalasEnemigo();
				contador = 0;
			}
		}
		colisiones_Vidas();
		calcularTiempo();
		if (mensaje % 2 == 0)
		{
			this->Text = "ADVERTENCIA : " + info;
		}
		if (mensaje % 2 != 0)
		{
			this->Text = "ADVERTENCIA : " + info2;
		}
		objNivel->mostrarDatos(buffer->Graphics,objNivel->get_vidas(),objNivel->get_tiempo(),segundos/10,
		objNivel->get_puntaje(),objNivel->get_cambiarMundo(), objNivel->get_cantidadIncialEnmigos());

		buffer->Render(graficador);
		if (objNivel->get_cambiarMundo() == objNivel->get_cantidadIncialEnmigos()/2)
		{
			PasarNive2();
		}
		if (objNivel->get_vidas() == 0)
		{
			timer2->Enabled = false;
			MessageBox::Show("Perdiste");
		}
		if (objNivel->get_tiempo()==0)
		{
			timer2->Enabled = false;
			MessageBox::Show("Perdiste");	
		}
    }
    private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		bc = BufferedGraphicsManager::Current;
		buffer = bc->Allocate(graficador, this->ClientRectangle);
		//buffer->Graphics->Clear(Color::Black);
		objNivel->Mapa(buffer->Graphics, mapa3);
		objNivel->MostrarZombies(buffer->Graphics,zombies);
		objNivel->MostrarPersonajes(buffer->Graphics, militar);
		objNivel->BalasJugador(buffer->Graphics, bala);
		objNivel->MoverZombies(buffer->Graphics);
		calcularTiempo();
		colisioneszombies();
		objNivel->mostrarDatosEspecial(buffer->Graphics, objNivel->get_vidas(), objNivel->get_tiempo(), segundos / 10,
			objNivel->get_puntaje());
		buffer->Render(graficador);
		if (objNivel->get_Zombies() == 0)
		{
			timer3->Enabled = false;
			MessageBox::Show("¡GANASTE! Esto podria pasar, así que quedate en casa");
			this->Close();
		}
		if (objNivel->get_vidas()==0)
		{
			timer3->Enabled = false;
			MessageBox::Show("Esto podria pasar¡Quedate en casa!");
		}
		if (objNivel->get_tiempo() == 0)
		{
			timer3->Enabled = false;
			MessageBox::Show("Se acabo el tiempo. Perdiste");

		}
    }
	private: System::Void Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		objNivel->MoverJugador(e->KeyCode, graficador);
		if (e->KeyCode == Keys::Space)
		{
			objNivel->Disparar();
		}
    }
	private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Width = 787;
	}
    private: System::Void btnInfo_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Game4::Instrucciones ^Info= gcnew Instrucciones();
		Info->ShowDialog();
    }
    private: System::Void Game_Resize(System::Object^ sender, System::EventArgs^ e)
    {
		graficador = this->CreateGraphics();
    }
    private: System::Void btnGame_Click(System::Object^ sender, System::EventArgs^ e)
	{
		IniciarPartida();
    }
    private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e)
	{
		
    }
   
};
}
