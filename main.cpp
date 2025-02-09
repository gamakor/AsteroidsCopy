#include <cmath>
#include <iostream>
#include <raylib.h>

struct Player {
    Vector2 position;
    Vector2 speed;
    float acceleration;
    float maxAcceleration {50.f};
    float deceleration;
    bool isAccelerating = false;
    float rotation;
    float width;
    float height;
    Vector2 orgin;
    bool test1;


    Rectangle GetRectangle() {
        return Rectangle(position.x, position.y,width , height);
    }

    void Draw() {
        DrawRectanglePro(GetRectangle(),orgin,rotation,RED);
    }

};

int main() {

    InitWindow(800, 600, "Asteroids");
    SetTargetFPS(60);


    Player player
        {
            .position = Vector2(300,200 ),
            .speed = 10,
            .rotation = 0,
            .width = 20 ,
            .height = 20,
            .orgin = Vector2(10,10),

        };


    while (!WindowShouldClose()) {


        //Add in stats for player image

        if (IsKeyDown(KEY_A)) {
        player.rotation -= 200.f *GetFrameTime();
        }

        if (IsKeyDown(KEY_D)) {
            player.rotation +=  200.f *GetFrameTime();
        }

        player.speed.x = cosf(player.rotation*DEG2RAD) * 6.f;
        player.speed.y = sinf(player.rotation*DEG2RAD) * 6.f;

        if (IsKeyDown(KEY_W)) {
            // acceleration build up over time hitting a max cap accel
            player.isAccelerating = true;
            player.acceleration += 0.04f;
            if (player.acceleration>=player.maxAcceleration) {
                player.acceleration = player.maxAcceleration;
            }
        }else
            {player.isAccelerating = false;}
        player.position.x += (player.speed.x * player.acceleration) * GetFrameTime();
        player.position.y += (player.speed.y * player.acceleration) * GetFrameTime();

        // Add deceleraion rate when w key is not pressed stopping when it gets to 0
        if (!player.isAccelerating && player.acceleration >0) {
            player.acceleration -= 0.03f;

        }

        Player Wrapping around the screen.
        if (player.position.x >GetScreenWidth()) {
            player.position.x = player.position.x - GetScreenWidth();
        }
        if (player.position.x <0) {
            player.position.x = GetScreenWidth();
        }
        if (player.position.y >GetScreenHeight()) {
            player.position.y = player.position.y - GetScreenHeight();
        }
        if (player.position.y <0) {
            player.position.y = GetScreenHeight();
        }

        //Draw Images
        BeginDrawing();
        ClearBackground(BLACK);
        player.Draw();



        EndDrawing();
    }
    CloseWindow();



    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.