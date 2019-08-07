#include "config.hpp"
#include "Pong.hpp"

Pong::Pong()
{
	// primero creo la ventana con los valores que tengo que config.hpp
	ventana.create(VideoMode(ancho,alto, bpp), "Pong definitivo", Style::Close);
	ventana.setVerticalSyncEnabled(true); // 60 fps

	textura_fondo.loadFromFile("Assets/Media/cuadricula.png"); //cargo la textura del fondo desde un archivo
	fondo.setTexture(textura_fondo); // asigno a la textura fondo, al sprite fondo

	// Se ajusta las posiciones de cada pala
	pad_player.setPosition(40, alto / 2);
	pad_ia.setPosition(ancho - 40, alto / 2);
	
	musica.openFromFile("Assets/Music/musica_fondo.ogg"); //se carga la musica de fondo
	musica.setLoop(true);
	musica.play();

}

void Pong::run()
{
	// game loop mientras la ventana este abierta
	while (ventana.isOpen())
	{
		tiempo = reloj.restart(); // reinicio el reloj almacenando el tiempo pasado;

		Event evento; //creo un objeto evento
		while (ventana.pollEvent(evento)) //proceso la pila de eventos
		{
			if (evento.type == Event::Closed) // si el evento es de tipo closed, cierro la ventana
			{
				ventana.close();
			}
		}
		// actualizo los elementos del juego
		pad_player.updateHuman(tiempo);
		pad_ia.update_bot(tiempo, bola);
		bola.update(tiempo, pad_player.getGlobalBounds(), pad_ia.getGlobalBounds(), puntos);

		//ventana.clear(Color::Transparent);

		ventana.draw(fondo); // dibujo el elemento del juego
		ventana.draw(bola);
		ventana.draw(pad_player);
		ventana.draw(pad_ia);
		puntos.show(ventana);
		ventana.display();  //actualizo la ventana

	}

}