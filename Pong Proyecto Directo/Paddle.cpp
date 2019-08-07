#include "Paddle.hpp"
#include "config.hpp"
#include "Bola.hpp"


Paddle::Paddle() : Sprite()
{
	//cargo la textura y se la pongo al sprite
	textura_palaH.loadFromFile("Assets/Media/tunelIzq");
	this->setTexture(textura_palaH);
	
	this->setPosition(0.f, alto/2.f);

	this->speed = 300.f; // defino la velocidad de la pala (eje y)
	this->setOrigin(9, 33); //defino el origen en el centro
}

void Paddle::updateHuman(Time& delta)
{
	// Obtenemos la posición superior e inferior
	float top = this->getGlobalBounds().top;
	float bottom = this->getGlobalBounds().top + this->getGlobalBounds().height;

	// Movemos la pala en función de las teclas pulsada
	// comprobando no salirnos de la pantalla
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && top > 0)
		this->move(0, -delta.asSeconds() * speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && bottom < alto)
		this->move(0, delta.asSeconds() * speed);
}

void Paddle::update_bot(Time& delta, Bola& bola) 
{
	if (bola.getSpeedX() >= 0 && bola.getPosition().x >= ancho / 2.0f)
	{
		if (this->getPosition().y < bola.getPosition().y)
			this->move(0, this->speed * delta.asSeconds());
		if (this->getPosition().y > bola.getPosition().y)
			this->move(0, -this->speed * delta.asSeconds());
	}
}