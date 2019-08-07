#pragma once
#ifndef Puntos_hpp
#define Puntos_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Puntos
{
public:
	Puntos();

	void show(RenderWindow& ventana);

	void addPointPlayer();
	void addPointIA();

private:
	Font fuente;
	Text texto_player;
	Text texto_ia;
	unsigned int puntos_player;
	unsigned int puntos_ia;
}; // class puntos

#endif // puntos_hpp