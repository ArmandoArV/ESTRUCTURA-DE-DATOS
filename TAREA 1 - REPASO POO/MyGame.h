class MyGame
{
    private:
        int MaxTurns;
        int numberOfPlayers;
        char option;
    public:
        MyGame();
        MyGame(int,int);
        ~MyGame();
        void startGame();
        void endGame(int);
};