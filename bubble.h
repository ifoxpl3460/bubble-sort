#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
#include <iostream>

class bubble {
private:
	short n;
	short counter, randomh, currenth, left;
	struct data { int height, posx; };
	sf::RenderWindow* window;
	sf::Event* event;
	sf::RectangleShape* rectangle;
	data* line;
public:
	bubble ();
	void update ();
	void render ();
	void init ();	
	int input ();	
	void events ();
	void sort ();
	void cmemory ();
	
};