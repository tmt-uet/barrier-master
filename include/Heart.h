#ifndef HEART_H
#define HEART_H
#include"console.h"
#include"Enemy.h"

class Heart
{
    public:
        Heart();
        int x,y,countLoop=0;;

        char iconHeart;
        bool isHeart;
        void move();
        void print();
        void activeHeart();
        void dieukieny(Enemy E1);
        void delet();
        void randomx(){



        void randomx();
};

#endif // HEART_H
