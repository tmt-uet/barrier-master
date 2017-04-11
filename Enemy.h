#ifndef ENEMY_H
#define ENEMY_H
#include"console.h"

class Enemy
{
    public:
        Enemy();
        void move();
        void print();
        int x;
        int y;
    private:
        void randomx();
        void randomy();
};

#endif // ENEMY_H
