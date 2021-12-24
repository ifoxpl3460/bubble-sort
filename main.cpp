/*ifoxpl3460 bubble-sort.cpp*/
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
struct data { int height, posx; };
int input (int* n) {
	std::cout << "Input n = ";
	std::cin >> *n;
	if (std::cin.fail () || !(*n > 63 && *n < 513)) {
		std::cin.clear ();
		std::cin.ignore (std::numeric_limits <std::streamsize> ::max (), '\n');
		input (n);
	}
	else return *n;
}
int main () {
	srand (time (NULL));
	short counter = 0, randomh = 0, currenth = 0, left = 0;
	int* n = new int;
	*n = input (n);
	left = *n;
	data* line = new data[*n];
	sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode (*n * 2, *n), "bubble-sort", sf::Style::Close);
	sf::RectangleShape* rectangle = new sf::RectangleShape ();
	rectangle->setFillColor (sf::Color::Green);
	rectangle->setRotation (180);	
	for (int i = 0; i < *n; i++) {
		randomh = 1 + rand () % (*n);
		line[i].posx = i;
		line[i].height = randomh;
	}
	while (window->isOpen ()) {
		if (line[counter].height < line[counter + 1].height) {
			currenth = line[counter].height;
			line[counter].height = line[counter + 1].height;
			line[counter + 1].height = currenth;
		}
		window->clear (sf::Color::Black);
		for (int i = 0; i < *n; i++) {
			rectangle->setPosition (line[i].posx + line[i - 1].posx + 1, *n);
			rectangle->setSize (sf::Vector2f (1, line[i].height));
			window->draw (*rectangle);
		}
		window->display ();
		counter++;
		if (counter >= left) {
			counter = 0;
			left--;
		}
		if (left == 0) {
			Sleep (2500);
			window->close ();
		}
		
	}
	delete [] line, window, rectangle; // idk if it works
	system ("pause");
	return 0;
}