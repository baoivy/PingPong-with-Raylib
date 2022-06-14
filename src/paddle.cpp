#include "paddle.h"

Vector2 Paddle::getPaddleXY() {
	return this->paddleXY;
}

void Paddle::motion() {
	if (IsKeyDown(KEY_UP)) {
		paddleXY.y -= speed * GetFrameTime();
	}
	else if (IsKeyDown(KEY_DOWN)) {
		paddleXY.y += speed * GetFrameTime();
	}

	if (paddleXY.y > GetScreenHeight() - height / 2.0 - 1) {
		paddleXY.y = GetScreenHeight() - height / 2.0 - 1;
	}
	else if (paddleXY.y < height / 2.0 - 1) {
		paddleXY.y = height / 2.0 - 1;
	}
}

Rectangle Paddle::getRect() {
	return Rectangle{ paddleXY.x - width / 2, paddleXY.y - height / 2, 10, 100 };
}

void Paddle::Draw() {
	DrawRectangleRec(getRect(),BLACK);
}

void Paddle::checkcollision(Ball& ball, Sound sound) {
	if (CheckCollisionCircleRec(ball.BallXY, ball.radius, getRect())) {
		if (ball.vectorSpeed.x < 0) {
			ball.vectorSpeed.x *= -1.1f;
			ball.vectorSpeed.y = (ball.BallXY.y - paddleXY.y) / (height / 2) * ball.vectorSpeed.x;
			PlaySound(sound);
		}
		else if (ball.vectorSpeed.x > 0) {
			ball.vectorSpeed.x *= -1.f;
			ball.vectorSpeed.y = (ball.BallXY.y - paddleXY.y) / (height / 2) * -ball.vectorSpeed.x;
			PlaySound(sound);
		}
	}
}

void Paddle::reset(int x) {
	this->paddleXY.x = x;
	paddleXY.y = GetScreenHeight() / 2;
	this->width = 10;
	this->height = 100;
	this->speed = 500;
}