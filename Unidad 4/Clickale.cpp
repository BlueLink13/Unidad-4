#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace sf;

RenderWindow Crosshair(VideoMode(800, 600, 32), "Crosshair");

class Aliens
{
public:
	Aliens();
	bool IsClicked() {
		if (Alien.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y)) {

			return true;

		}
	}

	void DrawAlien() {
		Crosshair.draw(Alien);
	}


private:
	Texture ET;

	Sprite Alien;
};

Aliens::Aliens()
{
	ET.loadFromFile("et.png");

	Alien.setTexture(ET);

	Alien.setScale(0.030543677458766, 0.0308451573103023);

	Alien.setPosition((rand() % 780), (rand() % 580));
}

Texture Cruz;

Sprite Mira;

Event evt;

Text Puntaje, Ganar;

void CrosshairPosition(); //Mueve Mira en pantalla.

int puntos = 0;

int main() {

	srand(time(NULL));

	Cruz.loadFromFile("crosshair.png");

	Mira.setTexture(Cruz);

	Mira.setOrigin(64, 64);

	Aliens* Alienigena = new Aliens();

	Ganar.setString("Has Ganado!"); //prepara el mensaje de victoria

	Ganar.setCharacterSize(100);

	Ganar.setPosition(550, 350);

	String puntosText = std::to_string(puntos);


	Puntaje.setString("Puntaje: " + puntosText);


	while (Crosshair.isOpen()) {

		Crosshair.clear();

		Crosshair.draw(Puntaje);

		CrosshairPosition();

		Alienigena->DrawAlien();

		if (puntos < 5) //chequea condicion de victoria
		{

			while (Crosshair.pollEvent(evt))
			{
				switch (evt.type) {

				case Event::MouseButtonPressed:

					if (Alienigena->IsClicked() == true) //Si hay click en alien, aumenta puntaje y crea un alien nuevo
					{
						puntos++;

						puntosText = std::to_string(puntos);

						Puntaje.setString("Puntaje: " + puntosText);

						delete Alienigena;

						Aliens* Alienigena = new Aliens();

					}
					break;
				case Event::Closed:
					Crosshair.close();
				default:
					break;
				}
			}
		}
		else {

			Crosshair.draw(Ganar);

		}

		Crosshair.display();

	}

}


void CrosshairPosition()
{
	while (evt.MouseMoved == true)
	{
		Mira.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);

		Crosshair.draw(Mira);
	}
}

