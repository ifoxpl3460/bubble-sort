#include "ui.h"

ui::ui () {
	font.loadFromFile ("C:/Windows/Fonts/arial.ttf");
}

sf::Text ui::newtext (int * a, int w, int h) {
	init (std::to_string(*a), &w, &h);
	return *text;
}

sf::Text ui::newtext (std::string * s, int w, int h) {
	
	init (*s, &w, &h);
	return *text;
}

sf::Text ui::newtext (std::string s, int w, int h) {		
	init (s, &w, &h);
	return *text;
}

void ui::init (std::string s, int * w, int * h){
	text = new sf::Text;
	
	text->setFont (font);
	text->setString (s);
	text->setString (s);
	text->setPosition (*w, *h);
	text->setPosition (*w, *h);
	text->setCharacterSize (12);
	text->setOutlineThickness (1);
	text->setOutlineColor (sf::Color::Black);
}