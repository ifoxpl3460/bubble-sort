/*ifoxpl3460 bubble-sort.cpp*/
#include "bubble.h"

int main () {
	srand (time (NULL));
	bubble* _bubble = new bubble;
	while (_bubble->input () != 0) {		
		_bubble->init ();
		_bubble->update ();
	}	
	_bubble->cmemory ();
	system ("pause");
	return 0;
}