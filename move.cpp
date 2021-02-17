#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

bool running = true;
int x = 1;
int y = 1;
int width = 20;
int height = 10;

void Input(){
    if (_kbhit){
        switch (_getch()){
            case 'a':
                x -= 1;;
                break;
            case 's':
                y += 1;
                break;
            case 'd':
                x += 1;
                break;
            case 'w':
                y -= 1;
                break;
            case 'q':
                running = false;
        }
    }
}

string LeftXSpacing(){
    string str;
    for (int i = 1; i < x; i++){
        str += " ";
    }
    return str;
}

string RightXSpacing(){
    string str;
    for (int i = 0; i < (width - x) - 2; i ++){
        str += " ";
    }
    return str;
}

string Mid(){
    string str = "#";
    for (int i = 0; i < width -2; i++){
        str += " ";
    }
    return str + "#";
}

string TopAndBottom(){
    string str;
    for (int i = 0; i < width; i++){
        str += "#";
    }
    return str;
}

string TopYSpacing(){
    string str = Mid();
    for (int i = 0; i < y - 1; i ++){
        cout << str << endl;
    }
}

string BottomYSpacing(){
    string str = Mid();
    for (int i = 0; i < (height - y) - 2; i++){
        cout << str << endl;
    }
}

void Draw(){
    system("CLS");
    cout << TopAndBottom() << endl; //Top
    TopYSpacing();
    cout << "#" << LeftXSpacing() << "O" << RightXSpacing() << "#" << endl; // Line player is on
    BottomYSpacing();
    cout << TopAndBottom() << endl; //Bottom
}

int main(){
    cout << "O";
    while (running){
        if (x > width - 3){x = width - 3;}
        if (x < 2){x = 2;}
        if (y < 2){y = 2;}
        if (y > height - 3){y = height - 3;}
        Input();
        if (_kbhit){
            Draw();
        }
    }
}