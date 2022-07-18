class Five {
    public:
        Five(int whiteX, int whiteY, int blackX, int blackY, int whiteSum, int blackSum);
        ~Five();

        void getWhitePoint();   // 白子出子及计数
        void getBlackPoint();   // 黑子出子及计数
        void showQiPan();       // 绘制棋盘

    private:
        char m_cQiPan[15][15];   // 棋盘大小
        int m_iWhiteX, m_iWhiteY, m_iBlackX, m_iBlackY, m_iWhiteSum, m_iBlackSum;
        bool isWhiteWin(int x, int y);
        bool isBlackWin(int x, int y);
        bool isWin(int x, int y, char flag);

};