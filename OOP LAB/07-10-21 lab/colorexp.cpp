#include <iostream>
#include <string>
using namespace std;

int main(int argc, char ** argv){
    cout << "\x1B[31m----------Student Details------------\033[0m\n";
    printf("\n");
    cout << "\x1B[31mTexting\033[0m\t\t";
    printf("\x1B[32mTexting\033[0m\t\t");
    printf("\x1B[33mTexting\033[0m\t\t");
    printf("\x1B[34mTexting\033[0m\t\t");
    printf("\x1B[35mTexting\033[0m\n");
    
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[37mTexting\033[0m\t\t");
    printf("\x1B[93mTexting\033[0m\n");
    
    printf("\033[3;42;30mTexting\033[0m\t\t");
    printf("\033[3;43;30mTexting\033[0m\t\t");
    printf("\033[3;44;30mTexting\033[0m\t\t");
    printf("\033[3;104;30mTexting\033[0m\t\t");
    printf("\033[3;100;30mTexting\033[0m\n");

    printf("\033[3;47;35mTexting\033[0m\t\t");
    printf("\033[2;47;35mTexting\033[0m\t\t");
    printf("\033[1;47;35mTexting\033[0m\t\t");
    printf("\t\t");
    printf("\n");

    return 0;
}

/* C++ program for the coloring the
// background and text with
// different color
#include <iostream>
  
// Header file to change color of
// text and background
#include <windows.h>
using namespace std;
  
// Driver Code
int main()
{
    // Color of the console
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
  
    // Print different colors from 1
    // to 50 on the output screen
    for (int P = 1; P < 50; P++) {
  
        // P is color code of the
        // corresponding color
        SetConsoleTextAttribute(
            console_color, P);
  
        // Print Statement
        cout << P << " Hello Geeks, "
             << "good night!!! \n";
    }
  
    return 0;
}
*/