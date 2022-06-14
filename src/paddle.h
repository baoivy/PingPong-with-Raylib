#include <raylib.h>

#include "ball.h"

//Declare class Paddle
class Paddle{
private:
	Vector2 paddleXY;
	float speed;
	float width, height;

public:
	Paddle(int x) {
		this->paddleXY.x = x;
		paddleXY.y = GetScreenHeight() / 2;
		this->width = 10;
		this->height = 100;
		this->speed = 500;
	}
	Vector2 getPaddleXY();
	Rectangle getRect();
	void Draw();
	void checkcollision(Ball& , Sound);
	void reset(int x);
	void motion();
};