# mazeGame
This project is the implementation of a mouse maze game where the goal is to get the mouse to the same room as the cheese by getting around the wall obstacles.
The maze.cpp file contains the same functions that are included in the TestGame repository. These functions work to initialize the maze, move the mouse based on user input, and check if the mouse is in the same room as the cheese. It also prints the maze for visuals. 
The maze.hpp file includes a RoomPair struct that is used to create and compare rooms. It also includes function prototypes.
Lastly, the game.cpp file runs the maze game. The game runs while the mouse and cheese are not in the same room and ends once the mouse reaches the cheese. There is an option to display the location of the mouse and cheese for debugging purposes as well.
