#ifndef PLAYER_H
#define PLAYER_H
#include"console.h"

class player
{
    public:
        player();
        virtual ~player();
        int x;
        int y;
        int color;
        int life;
        int c;
       int point=0;
        bool move(int a);
        void print();
        void delet();
        void showPoints();
        void showLife();
        void kill();



        };

#endif // PLAYER_H
