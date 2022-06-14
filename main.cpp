#include <raylib.h>
#include <iostream>
#include <string.h>

#include "paddle.h"

//Global variable
const char* message = nullptr;
const char notification[] = "PRESS ENTER TO RESTART - PRESS ESC TO QUIT";

int main(int argc, char *argv) {
	//Initialize window and audio
	InitWindow(800,600,"Ping Pong");
	SetWindowState(FLAG_VSYNC_HINT);
	InitAudioDevice();

	//Declare class and struct 
	Ball ball;
	Paddle leftPaddle(50);
	Paddle rightPaddle(GetScreenWidth() - 50);
	Sound sound = LoadSound("C:/Users/Bao/source/repos/PingPong/PingPong/sound.mp3");
	
	while (!WindowShouldClose()) {
		//Motion of ball and paddle
		ball.motionBall();
		
		leftPaddle.motion();
		rightPaddle.motion();
		
		leftPaddle.checkcollision(ball, sound);
		rightPaddle.checkcollision(ball, sound);

		//Check win
		if (ball.getBall().x > GetScreenWidth())
			message = "RIGHT WIN";
		else if (ball.getBall().x < 0)
			message = "LEFT WIN";
		
		//Drawing ball and paddle
		BeginDrawing();
			ClearBackground(WHITE);
			leftPaddle.Draw();
			rightPaddle.Draw();
			ball.Draw();
			DrawFPS(10, 10);
			if (message != nullptr) {
				int textWidth = MeasureText(message, 50);
				DrawText(message, GetScreenWidth() / 2.0f - textWidth / 2.0, GetScreenHeight() / 2.0f - 30, 50, BLACK);
				int notiWidth = MeasureText(notification, 20);
				DrawText(notification, GetScreenWidth() / 2.0f - notiWidth / 2.0, GetScreenHeight() / 2.0f - 80, 20, BLACK);
			}
		EndDrawing();
		//Reset game
		if (message != nullptr) {
			if (IsKeyDown(KEY_ENTER)) {
				ball.reset();
				leftPaddle.reset(50);
				rightPaddle.reset(GetScreenWidth() - 50);
				message = nullptr;
				ClearBackground(WHITE);
			}
		}
	}
	//Close and deallocation
	CloseWindow();
	CloseAudioDevice();
	return 0;
}
