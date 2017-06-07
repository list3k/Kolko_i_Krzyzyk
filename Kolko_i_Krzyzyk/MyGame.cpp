#include "MyGame.h"

MyGame::MyGame() :

	gameWindow(sf::VideoMode(600, 600, 32), "Kolko i Krzyzyk by Radek & Michal"),
	gameBoard{
		{ { 0,0,0 },
		{   0,0,0 },
		{   0,0,0 } }
					}

{
}

void MyGame::play()
{
	int turn = 1;
	bool win = false;

	//Main game loop
	while (gameWindow.isOpen()) {
		sf::Event event;

		while (gameWindow.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				gameWindow.close();
				break;
			}

			//Check click
			if (!win && event.type == sf::Event::MouseButtonPressed) {
				handleClick(gameBoard, turn, event.mouseButton.x, event.mouseButton.y);
				win = isWinner(gameBoard, turn);

				if (!win)
				{
					if (turn == 1)
					{
						turn = 2;
					}
					else
					{
						turn = 1;
					}
				}

			}
		}
		gameWindow.clear();

		//draw main window with lines
		drawBoard(gameWindow);

		//draw the slots
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				drawSlot(gameWindow, gameBoard[i][j], i, j);

		if (win) {
			drawWinScene(gameWindow, turn);
		}
		gameWindow.display();
	}
}

void MyGame::drawBoard(sf::RenderWindow &gameWindow) 
{
	//clear the window to black
	gameWindow.clear(sf::Color::Black);

	//draw horizontal lines
	sf::RectangleShape line1(sf::Vector2f(560, 2));
	line1.setFillColor(sf::Color::White);
	line1.setPosition(20, 200);

	sf::RectangleShape line2 = line1;
	line2.setPosition(20, 400);

	//draw vertical lines;
	sf::RectangleShape line3(sf::Vector2f(2, 560));
	line3.setFillColor(sf::Color::White);
	line3.setPosition(200, 20);

	sf::RectangleShape line4 = line3;
	line4.setPosition(400, 20);

	//draw to the window
	gameWindow.draw(line1);
	gameWindow.draw(line2);
	gameWindow.draw(line3);
	gameWindow.draw(line4);
}

void MyGame::drawSlot(sf::RenderWindow &gameWindow, int symbol, int x_pos, int y_pos) 
{
	if (symbol == 1)      //O
	{
		sf::CircleShape shape(60); // use this to change radius !!! setPosition must be also changed if radius was changed !!!
		shape.setFillColor(sf::Color::Transparent);
		shape.setOutlineThickness(5);
		shape.setOutlineColor(sf::Color::White);
		shape.setPosition(35 + (205 * x_pos), 35 + (205 * y_pos));

		gameWindow.draw(shape);
	}
	else if (symbol == 2) //X
	{
		//the \ cross
		sf::RectangleShape cross1(sf::Vector2f(200, 5));
		cross1.setPosition(25 + (210 * x_pos), 20 + (210 * y_pos));
		cross1.rotate(45);
		cross1.setFillColor(sf::Color::White);

		//the / cross
		sf::RectangleShape cross2(sf::Vector2f(200, 5));
		cross2.setPosition(25 + (210 * x_pos), 165 + (205 * y_pos));
		cross2.rotate(-45);
		cross2.setFillColor(sf::Color::White);

		gameWindow.draw(cross1);
		gameWindow.draw(cross2);
	}

}

void MyGame::drawWinScene(sf::RenderWindow &gameWindow, int side)
{
	sf::Text winText;
	sf::Font winFont;
	if (!winFont.loadFromFile("Xeron.ttf"))
	{
		std::cerr << ".Error while loading font" << std::endl;
		exit;
	} 
	winText.setFont(winFont);
	winText.setCharacterSize(50);
	winText.setColor(sf::Color::Red);
	winText.setPosition(40, 250);

	if (side == 1) {
		winText.setString("Player O wins!");
		
	}
	else if (side == 2) {
		winText.setString("Player X wins!");
	}
	else if (side == 0) {
		winText.setString("It's a DRAW!");
	}
	gameWindow.draw(winText);	
}

bool MyGame::isWinner(std::vector<std::vector<int>> &gameBoard, int side)
{
	int count;

	//check horizontally
	for (int i = 0; i < 3; ++i)
	{
		count = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (gameBoard[i][j] == side)
				++count;
		}

		if (count == 3)
		{
			return true;
			
		}
	}

	//check vertically
	for (int j = 0; j < 3; ++j)
	{
		count = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (gameBoard[i][j] == side)
				++count;
		}

		if (count == 3)
		{
			return true;
		}
	}

	//check diagonally
	count = 0;
	for (int i = 0, j = 0; i < 3; ++i, ++j)
	{
		if (gameBoard[i][j] == side)
			++count;
	}

	if (count == 3)
	{
		return true;
	}

	count = 0;
	for (int i = 0, j = 2; i < 3; ++i, --j)
	{
		if (gameBoard[i][j] == side)
			++count;
	}

	if (count == 3)
	{
		return true;
	}

	return false;

}

bool MyGame::handleClick(std::vector<std::vector<int>> &gameBoard, int side, int x_axis, int y_axis)
{
	int i, j;

	//searching for clicked element and getting is into table array - e.g. clicked middle = board[1][1]

	//checking clicked square - horizontally
	if (x_axis < 200) 
	{
		i = 0; // clicked left
	}
	else if (x_axis < 400)
	{
		i = 1; // clicked middle
	}
	else
	{
		i = 2; // clicked right
	}

	//checking clicked square - vertically
	if (y_axis < 200)
	{
		j = 0; // clicked top
	}
	else if (y_axis < 400)
	{
		j = 1; // clicked middle
	}
	else
	{
		j = 2; // clicked bottom
	}

	if (gameBoard[i][j] == 0)   //if the slot is empty
	{
		gameBoard[i][j] = side;
		return true;
	}

	return false;
}