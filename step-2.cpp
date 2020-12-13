#include <iostream>

using namespace std;

void printCube(char cube[][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            cout << cube[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void leftShift(char cube[][3], int row) {
    int i;
    char tmp = cube[row][0]; //기억해둬야할 문자
    for(i=0; i<2; i++) {
        cube[row][i] = cube[row][i+1];
    }
    cube[row][2] = tmp;
}

void rightShift(char cube[][3], int row) {
    int i;
    char tmp = cube[row][2];
    for(i=2; i>=1; i--) {
        cube[row][i] = cube[row][i-1];
    }
    cube[row][0] = tmp;
}

void upShift(char cube[][3], int col) {
    int i;
    char tmp = cube[0][col];
    for(i=0; i<2; i++) {
        cube[i][col] = cube[i+1][col];
    }
    cube[2][col] = tmp;
}

void downShift(char cube[][3], int col) {
    int i;
    char tmp = cube[2][col];
    for(i=2; i>=1; i--) {
        cube[i][col] = cube[i-1][col];
    }
    cube[0][col] = tmp;
}

int main() {
    string word;
    int i;
    char cube[3][3] = {{'R', 'R', 'W'}, {'G', 'C', 'W'}, {'G', 'B', 'B'}};
    printCube(cube);
    
    while(true) {
        cout << "CUBE> ";
        string command;
        cin >> command;
        if(command == "Q") {
            cout << "Bye~" << '\n';
            return 0;
        }
        
        for(i=0; i<command.size(); i++) {
            if(command[i] == 'U' && command[i+1] == '\'') {
                rightShift(cube, 0);
                cout << command[i];
                continue;
            }
            else if(command[i] == 'U') leftShift(cube, 0);
            
            else if(command[i] == 'B' && command[i+1] == '\'') {
                rightShift(cube, 2);
                cout << command[i];
                continue;
            }
            else if(command[i] == 'B') leftShift(cube, 2);
            
            else if(command[i] == 'R' && command[i+1] == '\'') {
                downShift(cube, 2);
                cout << command[i];
                continue;
            }
            else if(command[i] == 'R') upShift(cube, 2);
            
            else if(command[i] == 'L' && command[i+1] == '\'') {
                downShift(cube, 0);
                cout << command[i];
                continue;
            }
            else if(command[i] == 'L') upShift(cube, 0);
            
            cout << command[i] << '\n';
            printCube(cube);
        }
    }
    return 0;
}
