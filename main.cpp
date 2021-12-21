#define n 256

// sfml lib
#include <SFML/Graphics.hpp>

// data for lines
struct data {
	int height; int posx;
} line[n];

int main () {

	// variables
	int j = 0;
	int randomh = 0, p = 1, m = 0, r = n;

	// sfml 
	sf::RenderWindow* win = new sf::RenderWindow (sf::VideoMode (512, 512), "bubble-sort", sf::Style::Close);
	sf::Event* evnt = new sf::Event;

	sf::RectangleShape* rectangle = new sf::RectangleShape;

	srand (time (NULL));

	// main loop
	while (win->isOpen ()) {
		while (win->pollEvent (*evnt)) {
			if (evnt->type == sf::Event::Closed) win->close ();
		}

		// setting random height and posx for every line
		if (p == 1) {
			for (int i = 0; i < n; i++) {
				randomh = 1 + rand () % (512);
				line[i].posx = i;
				line[i].height = randomh;
				if (i == n - 1) p = 2;
			}
		}

		// sort
		if (p == 2) {
			if (line[j].height < line[j + 1].height) {
				m = line[j].height;
				line[j].height = line[j + 1].height;
				line[j + 1].height = m;
			}
		}

		win->clear (sf::Color::Black);

		// visuals
		for (int i = 0; i < n; i++) {
			rectangle->setFillColor (sf::Color (0, 255, 100));
			if (i == j) rectangle->setFillColor (sf::Color (255, 0, 0));
			rectangle->setPosition (line[i].posx + line[i - 1].posx + 1, 512);
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
	delete rectangle;

	return 0;
}