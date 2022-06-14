#include "ball.h"


Vector2 Ball::getBall() {
	return this->BallXY;
}

void Ball::motionBall() {
	BallXY.x += vectorSpeed.x * GetFrameTime();
	BallXY.y += vectorSpeed.y * GetFrameTime();
	if (BallXY.y < 0) {
		BallXY.y = 0;
		vectorSpeed.y *= -1;
	}
	else if (BallXY.y > GetScreenHeight()) {
		BallXY.y = GetScreenHeight();
		vectorSpeed.y *= -1;
	}
}

void Ball::Draw() {
	DrawCircleV(BallXY, radius, BLACK);
}

void Ball::reset() {
	BallXY.x = GetScreenWidth() / 2.0f;
	BallXY.y = GetScreenHeight() / 2.0f;
	vectorSpeed.x = 300;
	vectorSpeed.y = 300;
	this->radius = 5;
}