#include "bubble.h"

bubble::bubble () {
	n = 0;
	counter = 0;
	randomh = 0;
	currenth = 0;
	left = 0;
}

// main

void bubble::update () {
	while (window->isOpen ()) {
		updateui ();		
		sortlines ();
		events ();
		render ();
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
		line = new data[n];
		window = new sf::RenderWindow (sf::VideoMode (n * 2, n), "bubble-sort", sf::Style::Close);		
		return n;
	}
}

void bubble::init () {	
	initlines ();
	initui ();	
}

// engine

void bubble::render () {
	window->clear (sf::Color::Black);
	renderlines ();
	renderui ();
	window->display ();
}

void bubble::events () {
	while (window->pollEvent (event)) {
		if (event.type == sf::Event::Closed) {
			window->close ();
			left = 0;
			text.clear ();
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
	rectangle.setFillColor (sf::Color::Green);
	rectangle.setRotation (180);
	for (int i = 0; i < n; i++) {
		randomh = 1 + rand () % (n);
		line[i].posx = i;
		line[i].height = randomh;
	}
}

void bubble::renderlines () {
	for (int i = 0; i < n; i++) {
		rectangle.setPosition (line[i].posx + line[i - 1].posx + 1, n);
		rectangle.setSize (sf::Vector2f (1, line[i].height));
		window->draw (rectangle);
	}
	if (counter >= left) {
		counter = 0;
		left--;
	}
	counter++;
}

// user interface

void bubble::updateui () {
	if (left > -1 && window->isOpen()) {
		text.at (0).setString ("n = " + std::to_string (n));
		text.at (1).setString ("left = " + std::to_string (left));
	}
}

void bubble::initui () {
	text.push_back (_ui.newtext ("n = " + std::to_string (n), 10, 0)); // 0
	text.push_back (_ui.newtext (&left, 10, 12)); // 1
	text.push_back (_ui.newtext ("input 0 to exit", 10, 24)); // 2
}

void bubble::renderui () {
	for (int i = 0; i < text.size (); i++) window->draw (text.at (i));
}