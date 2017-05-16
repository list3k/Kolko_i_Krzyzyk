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

#endif