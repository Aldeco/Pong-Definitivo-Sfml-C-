#pragma once
#ifndef pong_hpp
#define pong_hpp
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

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

	Music musica;

}; // clase pong

#endif
