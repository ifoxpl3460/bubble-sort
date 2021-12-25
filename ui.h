#pragma once
#include <SFML/Graphics.hpp>

class ui {
private:
	sf::Text* text;
	sf::Font font;
public:
	ui ();
	sf::Text newtext (int*, int, int);
	sf::Text newtext (std::string*, int, int);
	sf::Text newtext (std::string, int, int);
	void init (std::string, int*, int*);
};