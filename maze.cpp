// For function definitions
// Kaila Anderson
// October 24, 2022


#include "maze.hpp"
#include <iostream> 

using std::cin; using std::cout; using std::endl; 

void clearWalls(RoomPair room[]) {
	for (int i = 0; i < numWalls; ++i) {
		room[i].one = { -1, '*' };
		room[i].two = { -1, '*' };
	}

}

const RoomPair pickWall() {
	RoomPair room;
	int row = rand() % mazeSize + 1;
	room.one.x = row;
	int column = rand() % mazeSize + 1;
	char vertical = 'a';
	switch (column) {
	case 1:
		vertical = room.one.y = vertical;
		break;
	case 2:
		vertical = room.one.y = ++vertical;
		break;
	case 3:
		vertical = room.one.y = vertical + 2;
		break;
	case 4:
		vertical = room.one.y = vertical + 3;
		break;
	}

	bool selectedOrNot = false;
	while (selectedOrNot == false) {
		int direction = rand() % 3 + 1;
		switch (direction) {
		case 1:
			// up
			if (row > 1 && row <= mazeSize) {
				room.two = { --row, room.one.y };
				selectedOrNot = true;
			}
			break;
		case 2:
			// down
			if (row >= 1 && row < mazeSize) {
				room.two = { ++row, room.one.y };
				selectedOrNot = true;
			}
			break;
		case 3:
			// right
			if (column >= 1 && column < mazeSize) {
				room.two = { row, ++vertical };
				selectedOrNot = true;
			}
			break;
		case 4:
			// left
			if (column > 1 && column <= mazeSize) {
				room.two = { row, --vertical };
				selectedOrNot = true;
			}
			break;
		}
	}
	return room;
}

bool matchRoom(const Room& one, const Room& two) {
	Room first = one;
	Room second = two;

	if (first.x == second.x &&
		first.y == second.y) return true;
	else
		return false;
}

bool matchPair(const RoomPair& one, const RoomPair& two) {
	RoomPair first = one;
	RoomPair second = two;
	
	if (matchRoom(first.one, second.one) || matchRoom(first.one, second.two)) {
		if (matchRoom(first.two, second.one) || matchRoom(first.two, second.two)) {
			return true;
		}
	}
	else return false;
}

int checkMaze(const RoomPair check[], const RoomPair& pair) {
	int i = 0;
	for (i = 0; i < numWalls; ++i) {
		if (matchPair(check[i], pair)) {
			return i;
		}
		else {
			if (i == numWalls-1) { return -1; }
			continue;
		}
	}

}

void build(RoomPair walls[]) {
	int wallsBuilt = 0;
	while (wallsBuilt < numWalls) {
		RoomPair pair = pickWall();
		if (checkMaze(walls, pair) == -1) {
			walls[wallsBuilt] = pair;
			++wallsBuilt;
		}
	}
}

void printRoom(const Room& room) {
	cout << room.x << room.y << endl;
}

void printPair(const RoomPair& pair) {
	cout << pair.one.x << pair.one.y << "|"
		<< pair.two.x << pair.two.y << endl;
}

void printMaze(const RoomPair maze[]) {
	for (int wall = 0; wall < numWalls; ++wall) {
		
		printPair(maze[wall]);
	
	}
}

const Room nextMove(const Room& currentRoom) {
	cout << "Insert a character to make your next move!" << endl << "u for up, d for down, l for left, r for right, and q to quit" << endl;
	char move;
	cin >> move;
	char ycoord = currentRoom.y;
	Room newRoom;
	switch (move) {
	case 'u':
		newRoom = { currentRoom.x - 1, currentRoom.y };
		break;
	case 'd':
		newRoom = { currentRoom.x + 1, currentRoom.y };
		break;
	case 'l':
		newRoom = { currentRoom.x, ycoord - 1 };
		break;
	case 'r':
		newRoom = { currentRoom.x, ycoord + 1 };
		break;
	case 'q':
		cout << "The game has ended. Thank you for playing!"; 
		exit(0);
		break;
	}
	return newRoom;
}