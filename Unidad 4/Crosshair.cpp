#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture Cruz;

Sprite Mira;

Event evt;

int main() {
	Cruz.loadFromFile("crosshair.png");

	Mira.setTexture(Cruz);

	Mira.setOrigin(64, 64);

	Mira.setPosition(150, 150);

	RenderWindow Crosshair(VideoMode(300, 300, 32), "Crosshair");

	while (Crosshair.isOpen()) {

		Crosshair.clear();

		Crosshair.draw(Mira);

		Crosshair.display();

		if (evt.Closed == true) {
			Crosshair.close();
		}

	}

	return 0;
}