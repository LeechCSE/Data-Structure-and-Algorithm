#include <iostream>
#include <vector>
#include <queue>

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

using namespace std;

struct Opcode{
   int time;
   char direction;
};

struct Position{
   int y, x;
};

int main(){
   // init
   int n, k;
   cin >> n >> k;
   vector<vector<bool>> apple(n, vector<bool>(n, false));
   vector<vector<bool>> snake(n, vector<bool>(n, false));
   for (int i = 0; i < k; i++){
      int ay, ax;
      cin >> ay >> ax;
      apple[ay - 1][ax - 1] = true;
   }
   int l;
   cin >> l;
   queue<Opcode> opcodes;
   for (int i = 0; i < l; i++){
      int t;
      char d;
      cin >> t >> d;
      opcodes.emplace(Opcode{t, d});
   }
   // driver
   int cur_sec = 0;
   Position head = {0, 0};
   Position tail = {0, 0};
   int head_dir = RIGHT;
   snake[0][0] = true;
   queue<Position> trace;
   
   while (true){
      // direction change
      if (!opcodes.empty()){
         if (cur_sec == opcodes.front().time){
            switch (opcodes.front().direction){
               case 'L': // left 90 degrees
                  if (head_dir == RIGHT)
                     head_dir = UP;
                  else
                     head_dir--;
               break;
               case 'D': // right 90 degrees
                  if (head_dir == UP)
                     head_dir = RIGHT;
                  else
                     head_dir++;
               break;
            }
            opcodes.pop();
         }
      }
      // second increment
      cur_sec++;
      // step 1: move head first
      switch (head_dir){
         case RIGHT:
            head.x++;
         break;
         case DOWN:
            head.y++;
         break;
         case LEFT:
            head.x--;
         break;
         case UP:
            head.y--;
         break;
      }
      // end-game check
      if (!(0 <= head.y && head.y < n
         && 0 <= head.x && head.x < n))
         break;
      if (snake[head.y][head.x]) 
         break;
      snake[head.y][head.x] = true;
      trace.emplace(head);
      // step 2: apple check
      if (apple[head.y][head.x])
         apple[head.y][head.x] = false;
      else{
         snake[tail.y][tail.x] = false;
         tail = trace.front();
         trace.pop();
      }
   }
   
   cout << cur_sec << endl;
   
   return 0;
}