#include "Enemy.h"



void Enemy::randomx()
{
    int i= rand()%4+1;
    switch(i)
    {
        case 1: x=35;break;
        case 2: x=38;break;
        case 3: x=41; break;
        case 4: x=44;break;
			}
}
void Enemy::randomy()
{
    y=(rand()%20+1)-18;

}
Enemy::Enemy()
{
        y=2;
		randomx();
		randomy();
}


void Enemy::move()
{
    y++;
    if(y==24)
    {
        y=2;
		randomx();
		}

}

void Enemy::print()
{
    Objectcolor(249);
    if(y>=2)
        {
        gotoxy(x-1,y);
        cout<<"   ";
		}
    move();

    if(y>=2)
        {
		gotoxy(x,y);
		cout<<char(22);
		gotoxy(x-1,y);
		cout<<char(22);
		gotoxy(x+1,y);
		cout<<char(22);
		}
}


















