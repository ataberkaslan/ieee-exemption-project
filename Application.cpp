#include "Application.h"

#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

LinkedList<std::shared_ptr<Circle>> Application::circles;

int Application::Start() {
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(60);
    // Head Node
    Application::AddCircle(BROWN, 20.f, 0, 0);

    Application::AddCircle(BLUE, rand() % 70 + 5, rand() % 30, rand() % 100 + 25, PI);
    Application::AddCircle(RED, rand() % 70 + 5, rand() % 30, rand() % 100 + 25, PI);
    Application::AddCircle(GREEN, rand() % 70 + 5, rand() % 30, rand() % 100 + 25, PI);

    while (!WindowShouldClose()) {
        Application::Draw();
    }
    CloseWindow();
    return 0;
}

void Application::Draw() {
    int drawX = WIDTH / 2, drawY = HEIGHT / 2;
    int prevX = 0, prevY = 0;
    bool firstNode = true;
    BeginDrawing();
    ClearBackground(GRAY);
    for(std::shared_ptr<Circle>& circle : Application::circles)
    {
        drawX += circle->rodLength * cos(circle->angle);
        drawY += circle->rodLength * sin(circle->angle);
        
        DrawCircle(drawX, drawY, circle->radius, circle->color);
        if (!firstNode) {
            DrawLine(prevX, prevY, drawX, drawY, BLACK);
        }
        firstNode = false;
        prevX = drawX, prevY = drawY;
        circle->update(5);
    }
    EndDrawing();
}

void Application::AddCircle(Color color, float radius, float angularVelocity, float rodLength, float angle) {
    Application::circles.append(std::make_shared<Circle>(color, radius, angularVelocity, rodLength, angle));
}