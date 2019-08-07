#pragma once
#ifndef Bola_hpp
#define Bola_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Bola : public Sprite
{
public:
	Bola();
	
	void update(Time& delta, FloatRect& p1, FloatRect& p2, Puntos& puntos);
	float getSpeedX() const;

private:
	Texture textura_bola;
	Vector2f speed;
	SoundBuffer buffer;
	Sound sound;
}; // clase Bola

#endif