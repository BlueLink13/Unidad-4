#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture Rojo, Azul;

Sprite SplatRojo, SplatAzul;

Event evt;

RenderWindow Splat(VideoMode(800, 600, 32), "Splat");

void main() {
	Rojo.loadFromFile("rcircle.png");

	Azul.loadFromFile("rcircleb.png");

	SplatRojo.setTexture(Rojo);

	SplatRojo.setScale(0.4, 0.4);

	SplatRojo.setOrigin(51, 51);

	SplatAzul.setTexture(Azul);

	SplatAzul.setScale(0.6, 0.6);

	SplatAzul.setOrigin(76, 76);

	while (Splat.isOpen())
	{

		while (Splat.pollEvent(evt)) {
			switch (evt.type)
			{

			case Event::MouseButtonReleased:
				if (Mouse::Left == true) {
					SplatRojo.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);

					Splat.draw(SplatRojo);
				}

				if (Mouse::Right == true) {
					SplatAzul.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);

					Splat.draw(SplatAzul);
				}
				break;
			case Event::Closed:
				Splat.close();
			default:
				break;
			}

		}

		Splat.display();
	}
}
