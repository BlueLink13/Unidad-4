#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;


Texture textura;

Sprite Circulo1, Circulo2, Circulo3, Circulo4;

Event evt;

void moverCirculos();

int main() {


	textura.loadFromFile("rcircle.png");

	Circulo1.setTexture(textura);

	Circulo1.setOrigin(64, 64);

	Circulo2.setOrigin(64, 64);

	Circulo3.setOrigin(64, 64);

	Circulo4.setOrigin(64, 64);

	Circulo2.setTexture(textura);

	Circulo3.setTexture(textura);

	Circulo4.setTexture(textura);

	RenderWindow Sniper(VideoMode(800, 600, 32), "Sniper");

	Circulo2.setPosition(0, 472);

	Circulo3.setPosition(672, 0);

	Circulo4.setPosition(672, 472);

	while (Sniper.isOpen()) {

		Sniper.clear();

		while (Sniper.pollEvent(evt)) {
			switch (evt.type)
			{
			case Event::MouseButtonPressed: 
				 
				moverCirculos(); 
				break;

			case Event::Closed:

				Sniper.close();
				break;
			default:
				break;
			}
		}

		Sniper.clear();

		Sniper.draw(Circulo1);

		Sniper.draw(Circulo2);

		Sniper.draw(Circulo3);

		Sniper.draw(Circulo4);

		Sniper.display();
	}
}

void moverCirculos() {

	FloatRect Colision;

	Vector2i MousePos = Mouse::getPosition();

	Colision = Circulo1.getGlobalBounds();
	if (Colision.contains(MousePos.x, MousePos.y)) {

		Circulo1.setPosition(MousePos.x, MousePos.y);

	}
	Colision = Circulo2.getGlobalBounds();
	if (Colision.contains(MousePos.x, MousePos.y)) {

		Circulo2.setPosition(MousePos.x, MousePos.y);

	}
	Colision = Circulo3.getGlobalBounds();
	if (Colision.contains(MousePos.x, MousePos.y)) {

		Circulo3.setPosition(MousePos.x, MousePos.y);

	}
	Colision = Circulo4.getGlobalBounds();
	if (Colision.contains(MousePos.x, MousePos.y)) {

		Circulo4.setPosition(MousePos.x, MousePos.y);

	}
};