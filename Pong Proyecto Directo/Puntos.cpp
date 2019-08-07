#include "Puntos.hpp"
#include "config.hpp"
#include <sstream>

Puntos::Puntos()
{
	// los puntos = 0
	puntos_player = 0;
	puntos_ia = 0;
	// Cargo la fuente
	fuente.loadFromFile("Assets/Fonts/Sansation.ttf");
	// fuente cargada a los textos
	texto_player.setFont(fuente);
	texto_ia.setFont(fuente);
	// tamaño de letra de los textos
	texto_player.setCharacterSize(30);
	texto_ia.setCharacterSize(30);
	// color de los texto
	texto_player.setColor(sf::Color::Red);
	texto_ia.setColor(sf::Color::Blue);
	// Establezco la posicion en cada esquina
	texto_player.setPosition(20, 20);
	texto_ia.setPosition(ancho - 20 - texto_ia.getLocalBounds().width, 20);
}

void Puntos::addPointPlayer()
{
	puntos_player++;
}

void Puntos::addPointIA()
{
	puntos_ia++;
}

void Puntos::show(sf::RenderWindow& ventana)
{
	// Creo 2 streams para pasar de int a string
	std::stringstream ia;
	std::stringstream ju;
	// las cadenas desde los puntos
	ia << puntos_ia;
	ju << puntos_player;
	// las cadenas en los textos
	texto_ia.setString(ia.str());
	texto_player.setString(ju.str());

	// la posición del texto derecho para que se mantenga alineado
	texto_ia.setPosition(ancho - 20 - texto_ia.getLocalBounds().width, 20);

	// textos en la ventana
	ventana.draw(texto_player);
	ventana.draw(texto_ia);
}