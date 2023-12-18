
#include <cstdlib>
#include <ctime>

#ifndef MAZE_HPP
#define MAZE_HPP
const int mazeSize = 4; // maze is mazeSize * mazeSize
const int numWalls = 8;  // number of internal walls

struct Room {
    int x;  // 1 through mazeSize
    char y; // 'a' through mazeSize
};

const Room startRoom = { 1, 'a' };
const Room cheeseRoom = { mazeSize, 'a' + mazeSize - 1 };

// internal wall or next move
struct RoomPair {
    Room one;
    Room two;
};

// initialization functions
//
void clearWalls(RoomPair[]);
const RoomPair pickWall();
bool matchRoom(const Room&, const Room&);
bool matchPair(const RoomPair&, const RoomPair&);
int checkMaze(const RoomPair[], const RoomPair&);
void build(RoomPair[]);

// display functions
//
void printRoom(const Room&);
void printPair(const RoomPair&);
void printMaze(const RoomPair[]);

// game functions
//
const Room nextMove(const Room& currentRoom);


#endif
