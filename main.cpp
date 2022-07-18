#include <iostream>
#include "five.h"

using namespace std;

int main(int, char**) {
    // cout << "Hello, world!\n";
    Five five(0, 0, 0, 0, 0, 0);
    five.showQiPan();
    cout << "O表示白棋，X表示黑棋" << endl;
    while (true) {
        five.getWhitePoint();
        five.getBlackPoint();
    }
}
