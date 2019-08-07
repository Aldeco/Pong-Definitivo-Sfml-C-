#pragma once
#ifndef Paddle_hpp
#define Paddle_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Bola;

class Paddle : public Sprite
{
public: 
	Paddle();

	void updateHuman(Time& delta);
	void update_bot(Time& delta, Bola& bola);

private:
	Texture textura_palaH;
	Texture textura_palaB;
	Sprite palaHumano;
	Sprite PalaBot;
	float speed;
}; //clase Paddle

#endif