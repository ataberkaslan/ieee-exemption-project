#include "Application.h"

#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

std::vector<std::unique_ptr<Circle>> Application::circles;

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
    for(auto& circle : Application::circles)
    {
        DrawCircle(circle->centerX, circle->centerY, circle->radius, circle->color);
    }
    EndDrawing();
}

void Application::AddCircle(Color color, float radius, int centerX, int centerY, float angularVelocity, float rodLength) {
    Application::circles.push_back(std::make_unique<Circle>(color, radius, centerX, centerY, angularVelocity, rodLength));
}