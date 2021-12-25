#include "bubble.h"

bubble::bubble () {
	n = 0;
	counter = 0;
	randomh = 0;
	currenth = 0;
	left = 0;
	event = new sf::Event;
	rectangle = new sf::RectangleShape;
	_ui = new ui;
}

// main

void bubble::update () {
	while (window->isOpen ()) {
		sortlines ();
		updateui ();
		render ();
		events ();
	}
}

int bubble::input () {
	std::cout << "Input\t";
	std::cin >> n;
	if (std::cin.fail () || !(n > 63 && n < 513 || n == 0)) {
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits <std::streamsize> ::max (), '\n');
		input ();
	}
	else {
		delete window;
		left = n;
		window = new sf::RenderWindow (sf::VideoMode (n * 2, n), "bubble-sort", sf::Style::Close);
		line = new data[n];
		return n;
	}
}

void bubble::init () {
	initui ();
	initlines ();
}

// engine

void bubble::render () {
	window->clear (sf::Color::Black);
	renderlines ();
	renderui ();
	window->display ();
}

void bubble::cmemory () {
	delete window;
	delete event;
	delete[] line;
	delete[] rectangle;
	delete _ui;
}

void bubble::events () {
	while (window->pollEvent (*event)) {
		switch (event->type) {
		case sf::Event::Closed:
			text.clear ();
			window->close ();
			break;
		}
	}
}

// lines

void bubble::sortlines () {
	if (left > 0) {
		if (line[counter].height < line[counter + 1].height) {
			currenth = line[counter].height;
			line[counter].height = line[counter + 1].height;
			line[counter + 1].height = currenth;
		}
	}
}

void bubble::initlines () {
	rectangle->setFillColor (sf::Color::Green);
	rectangle->setRotation (180);
	for (int i = 0; i < n; i++) {
		randomh = 1 + rand () % (n);
		line[i].posx = i;
		line[i].height = randomh;
	}
}

void bubble::renderlines () {
	for (int i = 0; i < n; i++) {
		rectangle->setPosition (line[i].posx + line[i - 1].posx + 1, n);
		rectangle->setSize (sf::Vector2f (1, line[i].height));
		window->draw (*rectangle);
	}
	if (counter >= left) {
		counter = 0;
		left--;
	}
	counter++;
}

// user interface

void bubble::updateui () {
	if (left >= 0) {
		text.at (1).setString ("left = " + std::to_string (left));
	}
}

void bubble::initui () {
	text.push_back (_ui->newtext ("n = " + std::to_string (n), 10, 0)); // 0
	text.push_back (_ui->newtext (&left, 10, 12)); // 1
	text.push_back (_ui->newtext ("input 0 to exit", 10, 24)); // 2
}

void bubble::renderui () {
	for (int i = 0; i < text.size (); i++) window->draw (text.at (i));
}