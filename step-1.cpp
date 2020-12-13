#include <iostream>

using namespace std;

int main() {
    string word;
    int n, pos = 0;
    char oper;
    cin >> word >> n >> oper;
    int size = (int)word.size();
    
    //음수일 때는 좌우 방향을 스위칭
    if(n < 0) {
        if(oper == 'L' || oper == 'l') oper = 'R';
        else if(oper == 'R' || oper == 'r') pos = oper = 'L';
    }
    
    for(int i=0; i<size; i++) {
        if(oper == 'L' || oper == 'l') pos = (n+i) % size;
        else if(oper == 'R' || oper == 'r') pos = (size-n+i) % size;
        cout << word[pos];
    }
    return 0;
}
