#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;


void main() {

	RenderWindow Resize(VideoMode(800, 600, 32), "Resize");

	Event evt;

	Vector2u Size;

	while (Resize.isOpen()) {

		while (Resize.pollEvent(evt))
		{
			Resize.clear();
			
			switch (evt.type)
			{
			case Event::Closed:
				Resize.close();
				break;

			case Event::Resized:

				if (Resize.getSize().x < 100)
				{
					Size.x = 100;

					Size.y = Resize.getSize().y;

					Resize.setSize(Size);

					break;
				}

				if (Resize.getSize().y < 100)
				{
					Size.y = 100;

					Size.x = Resize.getSize().x;

					Resize.setSize(Size);

					break;
				}

				if (Resize.getSize().x > 1000)
				{
					Size.x = 1000;

					Size.y = Resize.getSize().y;

					Resize.setSize(Size);

					break;
				}

				if (Resize.getSize().y > 1000)
				{
					Size.y = 1000;

					Size.x = Resize.getSize().x;

					Resize.setSize(Size);

					break;
				}
			default:
				break;
			}
		}
	}


	return;
}