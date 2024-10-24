#include "Application.h"

#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

LinkedList<std::shared_ptr<Circle>> Application::circles;

int Application::Start() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(60);
    Application::AddCircle(BROWN, 20.f, 590, 390);
    while (!WindowShouldClose()) {
        Application::Draw();
    }
    CloseWindow();
    return 0;
}

void Application::Draw() {
    BeginDrawing();
    ClearBackground(GRAY);
    for(std::shared_ptr<Circle>& circle : Application::circles)
    {
        DrawCircle(circle->centerX, circle->centerY, circle->radius, circle->color);
    }
    EndDrawing();
}

void Application::AddCircle(Color color, float radius, int centerX, int centerY, float angularVelocity, float rodLength) {
    Application::circles.append(std::make_shared<Circle>(color, radius, centerX, centerY, angularVelocity, rodLength));
}