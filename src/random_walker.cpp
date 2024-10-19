#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>

class Walker{

private:
        int x,y;
        const int width = 600;
        const int height = 800;

public:
        void Newgame() {
            x = width/2;
            y = height/2;
        }

        Walker(int width,int height){
            x = width/2;
            y = height/2;
        }

        void render(){
            DrawPixel(x, y, WHITE);
        }

        void step(){
            int choice = GetRandomValue(0,3);
            
            if(choice == 0){
                x++;
            }
            else if (choice == 1){
                x--;
            }
            else if (choice == 2){
                y++;
            }
            else{
                y--;
            }
        }

        void keycheck(){
            if(IsKeyPressed(KEY_R)) {
            Newgame();
            render();
            step();
            }
        }
        
};


int main(void){
    const int width = 800;
    const int height = 600;
    InitWindow(width, height, "Random walker :D");
    SetTargetFPS(60);
    
    Walker w(width,height);

    w.keycheck();
    
    int i = 1;
    while(!WindowShouldClose()){
        w.step();
        BeginDrawing();
        w.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;

   
}
