<<<<<<< HEAD
#ifndef MYGAME_H
#define MYGAME_H

#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include <vector>
#include <iostream>

class MyGame
{
public:
	MyGame();
	void play();
	
	void drawBoard(sf::RenderWindow &gameWindow);
	void drawSlot(sf::RenderWindow &gameWindow, int symbol, int x_pos, int y_pos);
	void drawWinScene(sf::RenderWindow &gameWindow, int side);
	bool isWinner(std::vector<std::vector<int>> &gameBoard, int side);
	bool handleClick(std::vector<std::vector<int>> &gameBoard, int side, int io, int jo);
	
	sf::RenderWindow gameWindow;
	std::vector<std::vector<int>> gameBoard;
	
};

=======
#ifndef MYGAME_H
#define MYGAME_H

#include "SFML\Graphics.hpp"
#include <vector>
#include <iostream>

class MyGame
{
public:
	MyGame();
	void play();
	
	void drawBoard(sf::RenderWindow &gameWindow);
	void drawSlot(sf::RenderWindow &gameWindow, int symbol, int x_pos, int y_pos);
	bool isWinner(std::vector<std::vector<int>> &gameBoard, int side);
	bool handleClick(std::vector<std::vector<int>> &gameBoard, int side, int io, int jo);
	
	sf::RenderWindow gameWindow;
	std::vector<std::vector<int>> gameBoard;
	
};

>>>>>>> e65176cca14b7f3f66c9f3343cd205515c779255
#endif