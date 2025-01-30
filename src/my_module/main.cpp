/*
 * @author maishuji
 * This code is just a template to get you started.
 * You can delete it and start from scratch.
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>

#include "raylib/raylib.h"
#include "raylib/raymath.h"
#include "raylib/rlgl.h"
#include <kos.h>

KOS_INIT_FLAGS(INIT_DEFAULT);

int main(int argc, char **argv)
{
	maple_device_t *controller;
	cont_state_t *cont;

	InitWindow(640, 480, "Block stacking puzzle game in KOS!");
	Camera camera = {0};
	camera.position = (Vector3){4.0f, 4.0f, 4.0f}; // Camera position
	camera.target = (Vector3){0.0f, 0.0f, 0.0f};   // Look-at point
	camera.up = (Vector3){0.0f, 1.0f, 0.0f};	   // Camera up vector
	camera.fovy = 45.0f;						   // Field of view

	float rotationAngle = 0.0f; // Cube rotation angle

	SetTargetFPS(60);
	while (true)
	{
		rotationAngle += 1.0f; // Increment rotation angle
		if (rotationAngle >= 360.0f)
			rotationAngle -= 360.0f;
		controller = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);
		if (controller)
		{
			cont = (cont_state_t *)maple_dev_status(controller);
			if (cont->buttons & CONT_DPAD_UP)
			{
			}
			else if (cont->buttons & CONT_DPAD_DOWN)
			{
			}
			else if (cont->buttons & CONT_A)
			{
			}
			else if (cont->buttons & CONT_START)
			{
				break;
			}
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(camera);

		rlPushMatrix();
		rlRotatef(rotationAngle, 0.0f, 1.0f, 0.0f); // Rotate around the Y-axis
		DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, RED);
		DrawCubeWires((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, DARKGRAY);

		rlPopMatrix();

		EndMode3D();

		DrawText("Hello, World. Press START to break.\n", 10, 10, 20, RED);

		std::string text = "Rotation angle: ";
		text += std::to_string(rotationAngle);

		DrawText(text.c_str(), 10, 30, 20, RED);
		// DrawRectangle(165, 145, 310, 210, BLACK);
		DrawFPS(10, 50); // Draw FPS counter

		EndDrawing();
	}
}