/*ifoxpl3460 bubble-sort.cpp*/ 

// libs
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
// data for lines
struct data {
	int height, posx;
};
// n input, handling wrong inputs
int input (int* n) {
	bool flag = false;
	while (!flag) {
		std::cout << "Input n = ";
		std::cin >> *n;
		flag = std::cin.good ();
		// if there is any problem
		if (!flag) {
			system ("cls");
			std::cout << "\nn -> int\n\n";
			std::cin.clear ();
			std::cin.ignore ();
		}
		else {
			// 63 < n < 513
			if (*n > 63 && *n < 513 || *n == 1000) {
				return *n;
			}
			else {
				system ("cls");
				std::cout << "\n63 < n < 513\n\n";
				flag = false;
			}
		}
	}
}
// main () lol
int main () {
	// variables
	bool flag = false;
	int counter = 0;
	int randomh = 0;
	int	currenth = 0;
	int* n = new int (0);
	int	left;
	// rectangle shape for lines
	sf::RectangleShape* rectangle = new sf::RectangleShape;
	// random setup
	srand (time (NULL));
	// main loop
	while (!flag) {
		*n = input (n);
		// n = 1000 to exit program
		if (*n == 1000) {
			flag = true;
			continue;
		}
		// creates new window and event objects
		sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode (*n * 2, *n), "bubble-sort", sf::Style::Close);
		sf::Event* event = new sf::Event;
		// create n line data
		data* line = new data[*n];
		// setting left var
		left = *n;
		// setting random high for each line
		for (int i = 0; i < *n; i++) {
			randomh = 1 + rand () % (*n);
			line[i].posx = i;
			line[i].height = randomh;
		}
		// when window is opened loop
		while (window->isOpen ()) {
			while (window->pollEvent (*event)) {
				// closing program
				if (event->type == sf::Event::KeyPressed) {
					if (event->key.code == sf::Keyboard::Escape) window->close ();
				}
			}
			// bubble sort
			if (line[counter].height < line[counter + 1].height) {
				currenth = line[counter].height;
				line[counter].height = line[counter + 1].height;
				line[counter + 1].height = currenth;
			}
			// clearing window
			window->clear (sf::Color::Black);
			// visuals
			for (int i = 0; i < *n; i++) {
				rectangle->setFillColor (sf::Color::Green);
				rectangle->setPosition (line[i].posx + line[i - 1].posx + 1, *n);
				rectangle->setSize (sf::Vector2f (1, line[i].height));
				rectangle->setRotation (180);
				window->draw (*rectangle);
			}
			// rendering everything
			window->display ();
			// part of the sorting thing:
			counter++;
			if (counter >= left) {
				counter = 0;
				left--;
			}
			// closing when finished
			if (left == 0) {
				Sleep (5000);
				window->close ();
			}
		}
		// erasing memory
		delete[] line;
		delete window;
		delete event;
	}
	delete rectangle;
	return 0;
}