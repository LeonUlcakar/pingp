#include <iostream>
using namespace std;

enum eDir {
	STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class cBall
{
private:
	int x;
	int y;

	int ogX;
	int ogY;
	eDir direction;

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
		o << "Ball [" << c.x << "<" << c.y << "][" << c.direction << "]" << endl;
		return o;
	}
};

int main() 
{
	cBall c(0, 0);
	std::cout << c << endl;
	c.randomDirection();
	std::cout << c << endl;
	c.Move();
	std::cout << c << endl;
	c.randomDirection();
	c.Move();
	std::cout << c << endl;

	return 0;
}