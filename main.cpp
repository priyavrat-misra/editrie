#include <SFML/Graphics.hpp>

int main() {
	char a[100]{0};
	sf::RenderWindow window(sf::VideoMode(720, 480), "editrie", sf::Style::Close);
	sf::Font font;
	font.loadFromFile("FreeMono.ttf");

	int i = 0;
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(24);

	window.clear();
	window.display();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::TextEntered:
					if (event.text.unicode == '\b')
						a[--i] = '\0';
					else if (event.text.unicode == '\r')
						a[i++] = '\n';
					else if (event.text.unicode < 128)
						a[i++] = event.text.unicode;	

					text.setString(a);
					window.clear();
					window.draw(text);
					window.display();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Left)
						i -= (bool) i;
					else if (event.key.code == sf::Keyboard::Right)
						++i;
			}
		}
	}
}
