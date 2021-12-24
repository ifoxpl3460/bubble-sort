#include "bubble.h"

bubble::bubble () {
	n = 0;
	counter = 0;
	randomh = 0;
	currenth = 0;
	left = 0;
	event = new sf::Event;
	rectangle = new sf::RectangleShape;
}

void bubble::update () {
	while (window->isOpen ()) {
		sort ();
		render ();
		events ();
	}
}

int bubble::input () {
	std::cout << "Input\t";
	std::cin >> n;
	if (std::cin.fail () || !(n > 63 && n < 513 || n == 0) ) {
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits <std::streamsize> ::max (), '\n');
		input ();
	}
	else {
		left = n;
		window = new sf::RenderWindow (sf::VideoMode (n * 2, n), "bubble-sort");
		line = new data[n];
		return n;
	}
}

void bubble::init () {
	rectangle->setFillColor (sf::Color::Green);
	rectangle->setRotation (180);
	for (int i = 0; i < n; i++) {
		randomh = 1 + rand () % (n);
		line[i].posx = i;
		line[i].height = randomh;
	}
}

void bubble::render () {			
	window->clear (sf::Color::Black);
	for (int i = 0; i < n; i++) {
		rectangle->setPosition (line[i].posx + line[i - 1].posx + 1, n);
		rectangle->setSize (sf::Vector2f (1, line[i].height));
		window->draw (*rectangle);
	}
	window->display ();
	counter++;
	if (counter >= left) {
		counter = 0;
		left--;
	}
}

void bubble::sort () {	
	if (left > 0) {	
		if (line[counter].height < line[counter + 1].height) {
			currenth = line[counter].height;
			line[counter].height = line[counter + 1].height;
			line[counter + 1].height = currenth;
		}
	}	
}

void bubble::cmemory () {
	delete window;
	delete event;
	delete[] line;
	delete rectangle;
}

void bubble::events () {
	while (window->pollEvent (*event)) {
		switch (event->type) {
		case sf::Event::Closed:
			window->close ();
			break;
		}
	}
}