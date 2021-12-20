#define n 256
#include <SFML/Graphics.hpp>

struct data {
	int height;
	int posx;
} line[n];

int main () {

	int j = 0;
	int randomh = 0, part = 1, m = 0, r = n;

	sf::RenderWindow* win = new sf::RenderWindow (sf::VideoMode (256, 256), "bubble-sort");
	sf::Event* evnt = new sf::Event;

	sf::RectangleShape* rectangle = new sf::RectangleShape (sf::Vector2f (4, 178));
	rectangle->setFillColor (sf::Color (235, 149, 13));

	srand (time (NULL));

	while (win->isOpen ()) {
		while (win->pollEvent (*evnt)) {
			if (evnt->type == sf::Event::Closed) win->close ();
		}

		if (part == 1) {
			for (int i = 0; i < n; i++) {
				randomh = 1 + rand () % (256);
				line[i].posx = i;
				line[i].height = randomh;
				if (i == n - 1) { part = 2; };
			}
		}

		if (part == 2) {
			if (line[j].height < line[j + 1].height) {
				m = line[j].height;
				line[j].height = line[j + 1].height;
				line[j + 1].height = m;
			}
		}

		win->clear (sf::Color::Black);

		for (int i = 0; i < n; i++) {
			rectangle->setFillColor (sf::Color (0, 255, 100));
			if (i == j) {
				rectangle->setFillColor (sf::Color (255, 0, 0));
			}
			rectangle->setPosition (line[i].posx, 256);
			rectangle->setSize (sf::Vector2f (1, line[i].height));
			rectangle->setRotation (180);
			win->draw (*rectangle);
		}

		win->display ();

		j++;

		if (j >= r) {
			j = 0;
			r--;
		}
	}

	delete win;
	delete evnt;

	return 0;

}