#include "raylib.h"

//Declare class Ball
class Ball {
private:
	Vector2 BallXY;
	Vector2 vectorSpeed;
	float radius;
	friend class Paddle;

public:
	Ball() {
		BallXY.x = GetScreenWidth() / 2.0f;
		BallXY.y = GetScreenHeight() / 2.0f;
		vectorSpeed.x = 300;
		vectorSpeed.y = 300;
		this->radius = 5;
	}

	Vector2 getBall();
	void motionBall();
	void reset();
	void Draw();
};