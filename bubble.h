#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class bubble {
private:
	int n; // number of numbers to sort
	short counter, randomh, currenth, left;
	struct data { int height, posx; };
	sf::RenderWindow* window; // sfml window
	sf::Event* event; // event obj
	sf::RectangleShape* rectangle; // rectangle for drawing lines
	data* line; // data for lines
public:
	bubble (); // constructor
	void update (); // updating everything
	void render (); // rendering lines
	void init (); // initialization
	int input (); // get input from user
	void events (); // handling events
	void sort (); // bubble sort
	void cmemory (); // clearing memory
};