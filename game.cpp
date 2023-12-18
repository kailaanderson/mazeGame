// Performs the maze game
// Kaila Anderson
// October 29, 2022

#include "maze.hpp"
#include <iostream>

using std::cin; using std::cout; using std::endl; 

int main() {

	RoomPair Maze[numWalls]; 
	build(Maze); 
	cout << "Before starting, would you like to display wall locations? (y = yes, n = no): " << endl; 
	char choice; 
	cin >> choice; 
	if (choice == 'y' || choice == 'Y') {
		cout << "These are the wall locations: " << endl; 
		printMaze(Maze); 
		cout << endl << "Let's Begin!" << endl; 
	}
	else if (choice == 'n' || choice == 'N') {
		cout << "Let's Begin!" << endl; 
	}

	Room MouseLocation = { 1, 'a' }; 
	Room CheeseLocation = { mazeSize- 1, 'a' + mazeSize - 1}; 

	while (matchRoom (MouseLocation, CheeseLocation) == false) {
		cout << "The mouse is in room "; 
		printRoom(MouseLocation); 
		cout << endl; 

		Room MyMove;
		MyMove = nextMove(MouseLocation); 
		RoomPair MoveMouse = { MyMove, MouseLocation };
		if (MyMove.x < 1 || MyMove.y < 'a') {
			cout << "wall" << endl; 
		}
		else if (MyMove.x > mazeSize || MyMove.y > 'a' + mazeSize - 1) {
			cout << "wall" << endl;
		}
		else if (checkMaze(Maze, MoveMouse) != -1) {
			cout << "Wall" << endl; 
		}
		else {
			MouseLocation = MyMove; 
		}
}
	cout << "The game has ended. Thank you for playing."; 
}