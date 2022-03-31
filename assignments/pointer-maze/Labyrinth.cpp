#include "Labyrinth.h"
#include <iostream>
bool isPathToFreedom(MazeCell* start, const std::string& moves) {
   std::cout << moves << std::endl;
   int length = moves.length();
   
   MazeCell* current = start;
   int score = 0;
   for(int i = 0; i<length; i++) {
	if(moves[i] == 'N') {
		current = current->north;
	} else if(moves[i] == 'S') {
		current = current->south;

	} else if(moves[i] == 'W') {
		current = current->west;

	} else if(moves[i] == 'E') {
		current = current->east;
	}

	if(current == nullptr) {
		return false;
	}

	if(current->whatsHere == Item::SPELLBOOK || current->whatsHere == Item::POTION || current->whatsHere == Item::WAND) {
		score++;
	}
   }

  
  return score == 3; 
}


