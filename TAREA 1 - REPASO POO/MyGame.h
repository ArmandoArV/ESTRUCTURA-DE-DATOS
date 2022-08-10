class MyGame
{
    private:
        int MaxTurns;
        int numberOfPlayers;
        char option;
    public:
        MyGame();
        MyGame(int,int,char);
        ~MyGame();
        int getMaxTurns();
        int getNumberOfPlayers();
        char getOption();
        void setMaxTurns(int);
        void setNumberOfPlayers(int);
        void setOption(char);
        
        void startGame();
        void endGame(int);
};