#include "raylib.h"
#include "transform2d.h"
int main()
{
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	transform2d base;
	base.localPos = { 100, 100 };

	transform2d turret;
	turret.setParent(&base);
	Rectangle baseRec{base.localPos.x, base.localPos.y, 100.0f, 150.0f };
	vec2 worldPosT = turret.worldPosition();
	//float worldRotT = turret.localRot;
	vec2 worldScale = base.worldScale();
	Rectangle turretRec{ worldPosT.x, worldPosT.y, 50.0f, 75.0f };
	baseRec.height = baseRec.height * worldScale.x;
	float oHeight = baseRec.height;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		worldPosT = (turret.worldPosition());
		ClearBackground(RAYWHITE);
		if (IsKeyDown(KEY_DOWN))
		{
			base.translate({ 100 * GetFrameTime() , 100 * GetFrameTime() });
		}
		baseRec.x = base.localPos.x;
		baseRec.y = base.localPos.y;
		turretRec.x = worldPosT.x;
		turretRec.y = worldPosT.y;
		//std::cout << worldPosT.x << std::endl;
		if (IsKeyDown(KEY_RIGHT))
		{
			base.rotate(10);
			turret.localRot = base.localRot;
		}

		if (IsKeyDown(KEY_LEFT))
		{
			turret.rotate(10);
			//worldRotT = turret.worldRotation();
		}

		if (IsKeyPressed(KEY_E))
		{
			worldScale.x += 1;
			baseRec.height = oHeight * worldScale.x;
			std::cout << worldScale.x << std::endl;
		}
		if (IsKeyPressed(KEY_R))
		{
			worldScale.x -= 1;
			baseRec.height = oHeight * worldScale.x;
			std::cout << worldScale.x << std::endl;
		}
		DrawRectanglePro(baseRec, { baseRec.width / 2, baseRec.height / 2 }, base.localRot, BLUE);
		DrawRectanglePro(turretRec, { turretRec.width / 2, turretRec.height / 2 }, turret.localRot, RED);

		EndDrawing();
	}
	CloseWindow();
}