#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture Amarillo, Rojo;

Sprite Cuadrado, Circulo;

void main(){

	Amarillo.loadFromFile("cuad_yellow.png");

	Rojo.loadFromFile("rcircleg.png");

	Cuadrado.setTexture(Amarillo);

	Circulo.setTexture(Rojo);

	Cuadrado.setScale(0.0390625, 0.0390625);

	Circulo.setScale(0.15625, 0.15625);

	bool cuadOcirc = false;

	RenderWindow Atrapado(VideoMode(800, 600, 30), "Atrapado");

	while (Atrapado.isOpen())
	{
		Event evt;

		while (Atrapado.pollEvent(evt)) {

			Atrapado.clear();

			switch (evt.type)
			{

			case Event::KeyPressed:

				if (evt.key.code == Keyboard::Right && (Cuadrado.getPosition().x < 780))
				{
					Cuadrado.setPosition((Cuadrado.getPosition().x + 5), Cuadrado.getPosition().y);
				}

				if (evt.key.code == Keyboard::Right && (Cuadrado.getPosition().x > 0))
				{
					Cuadrado.setPosition((Cuadrado.getPosition().x - 5), Cuadrado.getPosition().y);
				}

				if (evt.key.code == Keyboard::Right && (Cuadrado.getPosition().y < 580))
				{
					Cuadrado.setPosition(Cuadrado.getPosition().x, (Cuadrado.getPosition().y + 5));
				}

				if (evt.key.code == Keyboard::Right && (Cuadrado.getPosition().y > 0))
				{
					Cuadrado.setPosition(Cuadrado.getPosition().x, (Cuadrado.getPosition().y - 5));
				}

				if (evt.key.code == Keyboard::Space)
				{
					if (cuadOcirc == true) 
					{
						cuadOcirc = false;
					}
					else
					{
						cuadOcirc = true;
					};
				}

				Circulo.getPosition(Cuadrado.getPosition().x, Cuadrado.getPosition().y);

				break;

			case Event::Closed:
				Atrapado.close();
				break;

			default:
				break;
			}
		}

		if (cuadOcirc == true)
		{
			Atrapado.draw(Cuadrado);
		}
		else if (cuadOcirc == false)
		{
			Atrapado.draw(Circulo);

		}

		Atrapado.display();

	}

}