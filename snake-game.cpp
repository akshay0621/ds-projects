#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY;
enum eDirection{stop=0,UP,DOWN,LEFT,RIGHT};
eDirection dir;
int score=0;
int tailX[100],tailY[100],nTail;
void input(){
    //keyboard input
if(_kbhit()){

    switch(_getch()){
    case 'w':
        dir=UP;
        break;
        case 'a':
        dir=LEFT;
        break;
        case 'd':
        dir=RIGHT;
        break;
        case 's':
        dir=DOWN;
        break;
        default:
            break;
}
}
}
void Logic(){

//prevX,prevY -- first segment coordinates of tail
// x,y are the coordinates of head
int prevX=tailX[0];// tail coordinate
int prevY=tailY[0];
// head is already with one tail
tailX[0]=x; // tail pointing to head
tailY[0]=y;
for(int i=1;i<nTail;i++){
// prev2X,prev2Y -- last segment of tail cooedinates
int prev2X=tailX[i];
int prev2Y=tailY[i];
// snake last snake is pointed to first segment of tail coordinate which is in prevX,prevY
tailX[i]=prevX;
tailY[i]=prevY;
// prevX,prevY is updated from first segment to last segment of x

}

    //direction
switch(dir){
case UP:
    y--;
    break;
case DOWN:
    y++;
    break;
    case RIGHT:
    x++;
    break;
    case LEFT:
    x--;
    break;
    default:
        break;
}
// when snake touches border
if(x<0||x>width||y<0||y>height){
    gameOver=true;
}
// when snake head touches tail
for(int i=0;i<nTail;i++){
    if(x==tailX[i]&& y==tailY[i])
        gameOver=true;
}
//when snake eats fruit
if(x==fruitX&& y== fruitY){
    score++;
    nTail++;
    fruitX=rand()%width;
 fruitY=rand()%height;
}

}
//Initial setup of snake and fruit
void setup(){
gameOver=false;
dir=stop;
 x=width/2;
 y=height/2;
 fruitX=rand()%width;
 fruitY=rand()%height;

}
//display border snake and fruit
void draw(){
    system("CLS");
    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout << endl;
    //display border
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0||j==width-1){
                cout<<"#";
            }
            //display  snake
            else if(i==y && j==x){
              cout<<"O";
            }
            //display  fruit
            else if(i==fruitY && j==fruitX){
                cout<<"F";
            }
            else{
                    //Adding tail
                    bool print=false;
                    for(int k=0;k<nTail;k++){
                        if(i==tailY[k]&&j==tailX[k]){
                            cout<<"*";
            print=true;
                        }
                    }if(!print){
                cout << " ";
                    }
            }
        }
        cout << endl;
    }
// giving score
    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout << endl;
    cout<<"score"<<score<<endl;

}
int main(){
    setup();
    while(!gameOver){
        draw();
        input();
        Logic();
        Sleep(150);
    }
	return 0;
}
