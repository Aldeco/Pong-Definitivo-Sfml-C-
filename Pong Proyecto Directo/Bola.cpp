#include "Bola.hpp"
#include "config.hpp"

Bola::Bola() : Sprite()
{
	textura_bola.loadFromFile("Assets/Media/MushroomBall.png"); // cargo la textura de la bola
	this->setTexture(textura_bola);

	this->buffer.loadFromFile("Assets/Music/sonido_bola.wav"); // establezco el sonido
	this->sound.setBuffer(buffer);

	// Establezco el origen de la bola en su centro
	this->setOrigin(this->getLocalBounds().width / 2.0f, this->getLocalBounds().height / 2.0f);
	// Establezco la posici�n de la bola en el centro de la ventana
	this->setPosition(ancho / 2.0f, alto / 2.0f);

	// Definino la velocidad
	this->speed.x = 300.0f;
	this->speed.y = 300.0f;
}

void Bola::update(sf::Time& delta, sf::FloatRect& p1, sf::FloatRect& p2, Puntos& puntos)
{
	// Obtenemos los cuatro laterales de la bola
	float left = this->getPosition().x - this->getOrigin().x;
	float right = this->getPosition().x + this->getOrigin().x;
	float top = this->getPosition().y - this->getOrigin().y;
	float bottom = this->getPosition().y + this->getOrigin().y;

	// Comprobamos si choca contra las paredes
	if (left <= 0 && speed.x < 0)
	{
		this->speed.x *= -1;
		this->sound.play();
		puntos.addPointIA();
	}
	if (right >= ancho && speed.x > 0)
	{
		this->speed.x *= -1;
		this->sound.play();
		puntos.addPointPlayer();
	}
	if ((top <= 0 && speed.y < 0) || (bottom >= alto && speed.y > 0))
	{
		this->speed.y *= -1;
		this->sound.play();
	}
	// Por �ltimo comprobamos si ha chocado contra las palas
	if (this->getGlobalBounds().intersects(p1) || this->getGlobalBounds().intersects(p2))
	{
		this->speed.x *= -1;
		this->sound.play();
	}
	// Movemos la bola multiplicando la velocidad por el tiempo pasado
	this->move(delta.asSeconds() * this->speed.x, delta.asSeconds() * this->speed.y);
}

float Bola::getSpeedX() const
{
	return speed.x;
}