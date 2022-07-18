#include "five.h"
#include <iostream>

Five::Five(int whiteX = 0, int whiteY = 0, int blackX = 0, int blackY = 0, int whiteSum = 0, int blackSum = 0) {
    m_iWhiteX = whiteX;
    m_iWhiteY = whiteY;
    m_iBlackX = blackX;
    m_iBlackY = blackY;
    m_iWhiteSum = whiteSum;
    m_iBlackSum = blackSum;

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++) {
            m_cQiPan[i][j] = '-';
        }
    }
}

Five::~Five() {

}

void Five::showQiPan() {
    for (int i = 0; i<= 9; i++) {
        std::cout << i << " ";
    }
    for (int i = 10; i<= 15; i++) {
        std::cout << i;
    }
    std::cout << std::endl;
    
    for (int i = 0; i < 15; i++) {
        std::cout << i+1 << " ";
        for (int j = 0; j < 15; j++) {
            std::cout << m_cQiPan[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

void Five::getWhitePoint() {
    std::cout << "请分别输入第" << m_iWhiteSum + 1 << "步白棋的横坐标和纵坐标" << std::endl;
    std::cin >> m_iWhiteX >> m_iWhiteY;
    if (!(m_iWhiteX >= 1 && m_iWhiteX <= 15 && m_iWhiteY >= 1 && m_iWhiteY <= 15)) {
        std::cout << "输入错误，请重新输入:" << std::endl;
        getWhitePoint();
    } else if (m_cQiPan[m_iWhiteX - 1][m_iWhiteY - 1] != '-') {
        std::cout << "该位置有棋子，请重新输入:" << std::endl;
        getWhitePoint();
    } else if (m_iWhiteSum >= (15 * 15)) {
        std::cout << "棋盘已满，平局。" << std::endl;
        exit(0);
    }else {
        m_cQiPan[m_iWhiteX - 1][m_iWhiteY - 1] = 'O';
        m_iWhiteSum++;
        
        showQiPan();
        if (isWhiteWin(m_iWhiteX - 1, m_iWhiteY - 1)) {
            std::cout << "恭喜！白棋赢了。" << std::endl;
            exit(0);
        }
    }
}

void Five::getBlackPoint() {
    std::cout << "请分别输入第" << m_iBlackSum + 1 << "步黑棋的横坐标和纵坐标" << std::endl;
    std::cin >> m_iBlackX >> m_iBlackY;
    if (!(m_iBlackX >= 1 && m_iBlackX <= 15 && m_iBlackY >= 1 && m_iBlackY <= 15)) {
        std::cout << "输入错误，请重新输入:" << std::endl;
        getBlackPoint();
    } else if (m_cQiPan[m_iBlackX - 1][m_iBlackY - 1] != '-') {
        std::cout << "该位置有棋子，请重新输入:" << std::endl;
        getBlackPoint();
    } else if (m_iBlackSum >= (15 * 15)) {
        std::cout << "棋盘已满，平局。" << std::endl;
        exit(0);
    }else {
        m_cQiPan[m_iBlackX - 1][m_iBlackY - 1] = 'X';
        m_iBlackSum++;

        showQiPan();
        if (isBlackWin(m_iBlackX - 1, m_iBlackY - 1)) {
            std::cout << "恭喜！黑棋赢了。" << std::endl;
            exit(0);
        }
    }
}

bool Five::isWhiteWin(int x, int y) {
    return isWin(x, y, 'O');
}

bool Five::isBlackWin(int x, int y) {
    return isWin(x, y, 'X');
}

bool Five::isWin(int x, int y, char flag) {
    int begin = 0;
    int end = 0;

    int begin1 = 0;
    int end1 = 0;

    // 判断行
    y - 4 > 0 ? begin = (y - 4) : begin = 0;
    y + 4 > 15 ? end = 14 : end = (y + 4);

    for (int j = begin; j + 4 <= end; j++) {
        if (m_cQiPan[x][j] == flag && m_cQiPan[x][j+1] == flag && 
            m_cQiPan[x][j+2] == flag && m_cQiPan[x][j+3] == flag &&
            m_cQiPan[x][j+4] == flag) {
                return true;
            }
    }

    // 判断列
    x - 4 > 0 ? begin = (x - 4) : begin = 0;
    x + 4 > 15 ? end = 14 : end = (x + 4);

    for (int i = begin; i + 4 <= end; i++) {
        if (m_cQiPan[i][y] == flag && m_cQiPan[i+1][y] == flag && 
            m_cQiPan[i+2][y] == flag && m_cQiPan[i+3][y] == flag &&
            m_cQiPan[i+4][y] == flag) {
                return true;
            }
    }

    // 判断左上右下对角线
    x - 4 > 0 ? begin = (x - 4) : begin = 0;
    x + 4 > 15 ? end = 14 : end = (x + 4);
    y - 4 > 0 ? begin1 = (y - 4) : begin1 = 0;
    y + 4 > 15 ? end1 = 14 : end1 = (y + 4);

    for (int i = begin, j = begin1; (i + 4 <= end) && (j + 4 <= end1); i++, j++) {
        if (m_cQiPan[i][j] == flag && m_cQiPan[i+1][j+1] == flag && 
            m_cQiPan[i+2][j+2] == flag && m_cQiPan[i+3][j+3] == flag &&
            m_cQiPan[i+4][j+4] == flag) {
                return true;
            }
    }

    // 判断左下右上对角线
    x - 4 > 0 ? begin = (x - 4) : begin = 0;
    x + 4 > 15 ? end = 14 : end = (x + 4);
    y - 4 > 0 ? end1 = (y - 4) : end1 = 0;
    y + 4 > 15 ? begin1 = 14 : begin1 = (y + 4);

    for (int i = begin, j = begin1; (i + 4 <= end) && (j - 4 >= end1); i++, j--) {
        if (m_cQiPan[i][j] == flag && m_cQiPan[i+1][j-1] == flag && 
            m_cQiPan[i+2][j-2] == flag && m_cQiPan[i+3][j-3] == flag &&
            m_cQiPan[i+4][j-4] == flag) {
                return true;
            }
    }

    return false;

}
