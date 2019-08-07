#pragma once
#ifndef pong_hpp
#define pong_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bola.hpp"
#include "Paddle.hpp"

using namespace sf;

class Pong
{
public:
	Pong();
	
	void run();

private:
	RenderWindow ventana;
	Clock reloj;
	Time tiempo;

	Texture textura_fondo;
	Sprite fondo;
	//Sprite pad_player;
	//Sprite pad_ia;

	Music musica;

	Bola bola;

	Paddle pad_player;
	Paddle pad_ia;

}; // clase pong

#endif
