#include <iostream>

using namespace std;

char cube[6][3][3] =
{ {{'B','B','B'},{'B','B','B'},{'B','B','B'}},
    {{'W','W','W'},{'W','W','W'},{'W','W','W'}},
    {{'O','O','O'},{'O','O','O'},{'O','O','O'}},
    {{'G','G','G'},{'G','G','G'},{'G','G','G'}},
    {{'Y','Y','Y'},{'Y','Y','Y'},{'Y','Y','Y'}},
    {{'R','R','R'},{'R','R','R'},{'R','R','R'}} };

void printLine(int i, int k) {
    int j;
    for(j=0; j<3; j++) {
        cout << cube[k][i][j] << ' ';
    }
    cout << "     ";
}

void printCube() {
    int i, j;
    for(i=0; i<3; i++) {
        cout << "                ";
        for(j=0; j<3; j++) {
            cout << cube[0][i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (i=0; i<3; i++) {
        printLine(i, 1);
        printLine(i, 2);
        printLine(i, 3);
        printLine(i, 4);
        cout << '\n';
    }
    cout << '\n';
    for (i=0; i<3; i++) {
        cout << "                ";
        for (int j = 0; j < 3; j++)
        cout << cube[5][i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    string word;
    int i;
    
    while(true) {
        cout << "CUBE> ";
        string command;
        cin >> command;
        if(command == "Q") {
            cout << "Bye~" << '\n';
            return 0;
        }
        
        for(i=0; i<command.size(); i++) {
            if(command[i] == 'F' && command[i+1] == '\'') {
                cout << command[i];
                continue;
            }
            else if(command[i] == 'F') {}
            else if(command[i] == 'R' && command[i+1] == '\'') {
                cout << command[i];
                continue;
            }
            else if(command[i] == 'R') {}
            else if(command[i] == 'U' && command[i+1] == '\'') {
                cout << command[i];
                continue;
            }
            else if(command[i] == 'U') {}
            else if(command[i] == 'B' && command[i+1] == '\'') {
                cout << command[i];
                continue;
            }
            else if(command[i] == 'B') {}
            else if(command[i] == 'L' && command[i+1] == '\'') {
                cout << command[i];
                continue;
            }
            else if(command[i] == 'L') {}
            else if(command[i] == 'D' && command[i+1] == '\'') {
                cout << command[i];
                continue;
            }
            else if(command[i] == 'D') {}
            cout << command[i] << '\n';
            printCube();
        }
    }
    return 0;
}
