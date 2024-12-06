#include <raylib.h>
#include <entt/entt.hpp>

// A simple component for holding circle properties
struct Circle {
    Vector2 position;
    float radius;
    Color color;
};

int main() {
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    // Initialize Raylib window
    InitWindow(screenWidth, screenHeight, "Raylib + EnTT Example");

    // Create an EnTT registry
    entt::registry registry;

    // Create a few entities with Circle components
    for (int i = 0; i < 5; ++i) {
        // Create entity
        const auto entity = registry.create();

        // Assign a Circle component with random properties
        registry.emplace<Circle>(entity, Vector2{static_cast<float>(100 + i * 100), static_cast<float>(100 + i * 100)}, 50.0f + i * 20, RED);
    }

    // Set the frame rate
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        // (No dynamic updates for this simple example)

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Iterate over all entities with a Circle component and draw them
        registry.view<Circle>().each([](auto entity, const Circle& circle) {
            // Draw the circle using Raylib
            DrawCircleV(circle.position, circle.radius, circle.color);
        });

        EndDrawing();
    }

    // Close the window and OpenGL context
    CloseWindow();

    return 0;
}
