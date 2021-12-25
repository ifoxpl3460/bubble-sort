#pragma once
#include <iostream>
#include "ui.h"

class bubble {
private:
	int n; // number of numbers to sort
	int counter, randomh, currenth, left; // other variables
	struct data { int height, posx; }; // struct data
	sf::RenderWindow* window; // sfml window
	sf::Event* event; // event obj
	sf::RectangleShape* rectangle; // rectangle for drawing lines
	data* line; // data for lines
	std::vector<sf::Text> text; // text vector
	ui * _ui; // user interface obj

public:
	bubble (); // constructor

	// main

	void update (); // updating everything
	int input (); // get input from user	
	void init (); // initialization

	// engine

	void render (); // rendering 
	void events (); // handling events
	void cmemory (); // clearing memory\

	// lines
	void renderlines (); // rendering lines
	void initlines (); //initialization lines
	void sortlines (); // bubble sort lines
	
	// user interface

	void updateui (); // updating ui
	void initui (); // initialization ui
	void renderui (); // displaying ui
};