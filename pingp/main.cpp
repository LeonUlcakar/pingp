/*
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

enum eDir {
	STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall
{
private:
	int x{};
	int y{};

	int ogX{};
	int ogY{};
	eDir direction{};

public:
	cBall(int posX, int posY) {
		ogX = posX;
		ogY = posY;
		direction = STOP;
	}
	void Reset()
	{
		x = ogX;
		y = ogY;
		direction = STOP;
	}
	void changeDirection(eDir d)
	{
		direction = d;
	}
	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getDirection()
	{
		return direction;
	}
	void Move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--;
			y--;
			break;
		case DOWNLEFT:
			x--;
			y++;
			break;
		case UPRIGHT:
			x++;
			y--;
			break;
		case DOWNRIGHT:
			x++;
			y++;
			break;
		}
	}
	friend ostream& operator<<(ostream& o, cBall c)
	{
		o << "Ball [" << c.x << ", " << c.y << "][" << c.direction << "]" << endl;
		return o;
	}
};

class cPaddle
{
private:
	int x;
	int y;
	int ogX{};
	int ogY{};

public:
	cPaddle()
	{
		x = y = 0;
	}
	cPaddle(int posX, int posY) : cPaddle()
	{
		ogX = posX;
		ogY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = ogX; y = ogY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }

	friend ostream& operator<<(ostream& o, cPaddle c)
	{
		o << "Paddle [" << c.x << ", " << c.y << "]" << endl;
		return o;
	}

};

class cGameManager
{
private:
	int width;
	int height;
	int score1;
	int score2;
	char up1;
	char up2;
	char down1;
	char down2;
	bool quit;
	cBall* ball;
	cPaddle* player1;
	cPaddle* player2;
public:
	cGameManager(int w, int h)
	{
		srand(time(NULL));
		quit = FALSE;
		up1 = 'w';
		up2 = 'i';
		down1 = 's';
		down2 = 'k';
		score1 = score2 = 0;
		width = w;
		height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w-2, h / 2 - 3);
	}
	~cGameManager()
	{
		delete ball, player1, player2;
	};
	void ScoreUp(cPaddle* player)
	{
		if (player == player1)
			score1++;
		else if (player == player2)
		{
			score2++;
		}
		ball->Reset();
		player1->Reset();
		player2->Reset();

	};
};

int main() 
{
	cPaddle p1(0, 0);
	cPaddle p2(10, 0);
	std::cout << p1 << endl;
	std::cout << p2 << endl;
	p1.moveUp();
	p2.moveDown();
	std::cout << p1 << endl;
	std::cout << p2 << endl;



	return 0;
}

*/
#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
using namespace std;

enum eDir {
	STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6
};

class cBall
{
private:
	int x{};
	int y{};

	int ogX{};
	int ogY{};
	eDir direction{};

public:
	cBall(int posX, int posY) {
		ogX = posX;
		ogY = posY;
		direction = STOP;
	}
	void Reset()
	{
		x = ogX;
		y = ogY;
		direction = STOP;
	}
	void changeDirection(eDir d)
	{
		direction = d;
	}
	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getDirection()
	{
		return direction;
	}
	void Move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--;
			y--;
			break;
		case DOWNLEFT:
			x--;
			y++;
			break;
		case UPRIGHT:
			x++;
			y--;
			break;
		case DOWNRIGHT:
			x++;
			y++;
			break;
		}
	}
	friend ostream& operator<<(ostream& o, cBall c)
	{
		o << "Ball [" << c.x << ", " << c.y << "][" << c.direction << "]" << endl;
		return o;
	}
};

class cPaddle
{
private:
	int x;
	int y;
	int ogX{};
	int ogY{};

public:
	cPaddle()
	{
		x = y = 0;
	}
	cPaddle(int posX, int posY) : cPaddle()
	{
		ogX = posX;
		ogY = posY;
		x = posX;
		y = posY;
	}
	inline void Reset() { x = ogX; y = ogY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }

	friend ostream& operator<<(ostream& o, cPaddle c)
	{
		o << "Paddle [" << c.x << ", " << c.y << "]" << endl;
		return o;
	}

};

class cGameManager
{
private:
	int width;
	int height;
	int score1;
	int score2;
	char up1;
	char up2;
	char down1;
	char down2;
	bool quit;
	cBall* ball;
	cPaddle* player1;
	cPaddle* player2;
public:
	cGameManager(int w, int h)
	{
		srand(time(NULL));
		quit = FALSE;
		up1 = 'w';
		up2 = 'i';
		down1 = 's';
		down2 = 'k';
		score1 = score2 = 0;
		width = w;
		height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w - 2, h / 2 - 3);
	}
	~cGameManager()
	{
		delete ball, player1, player2;
	};
	void ScoreUp(cPaddle* player)
	{
		if (player == player1)
			score1++;
		else if (player == player2)
		{
			score2++;
		}
		ball->Reset();
		player1->Reset();
		player2->Reset();

	};
	void Draw()
	{
		system("cls");
		for (int i = 0; i < width + 2; i++)
		{
			std::cout << "\xB2";
		}

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ballx = ball->getX();
				int bally = ball->getY();
				int player1x = player1->getX();
				int player1y = player1->getY();
				int player2x = player2->getX();
				int player2y = player2->getY();

				if (j == 0)
				{
					std::cout << "\xB2";
				}

				if (ballx == j && bally == i)
				{
					std::cout << "O";
				}
				else if (player1x == j && player1y == i)
				{
					std::cout << "\xDB";
				}
				else if (player2x == j && player2y == i)
				{
					std::cout << "\xDB";
				}

				else if (player1x == j && player1y + 1 == i)
				{
					std::cout << "\xDB";
				}
				else if (player1x == j && player1y + 2 == i)
				{
					std::cout << "\xDB";
				}
				else if (player1x == j && player1y + 3 == i)
				{
					std::cout << "\xDB";
				}

				else if (player2x == j && player2y + 1 == i)
				{
					std::cout << "\xDB";
				}
				else if (player2x == j && player2y + 2 == i)
				{
					std::cout << "\xDB";
				}
				else if (player2x == j && player2y + 3 == i)
				{
					std::cout << "\xDB";
				}

				else
				{
					std::cout << " ";
				}

				if (j == width - 1)
				{
					std::cout << "\xB2";
				}
			}
			std::cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
		{
			std::cout << "\xB2";
		}
	}
	void Input()
	{
		ball->Move();
		int ballx = ball->getX();
		int bally = ball->getY();
		int player1x = player1->getX();
		int player1y = player1->getY();
		int player2x = player2->getX();
		int player2y = player2->getY();

		if (_kbhit)
		{
			char current = _getch();
			if (current == up1)
			{
				if (player1y > 0)
				{
					player1->moveUp();
				}
			}

			if (current == up2)
			{
				if (player2y > 0)
				{
					player2->moveUp();
				}
			}
			if (current == down1)
			{
				if (player1y + 4 < height)
				{
					player1->moveDown();
				}
			}
			if (current == down2)
			{
				if (player2y + 4 < height)
				{
					player2->moveDown();
				}
			}

			if (ball->getDirection() == STOP)
			{
				ball->randomDirection();
			}

			if (current == 'q')
			{
				quit = true;
			}
		}
	}
};

int main()
{
	cGameManager c(40, 20);
	c.Draw();




	return 0;
}
