#include "player.h"

#include"console.h"
using namespace std;
//int point=0;
player::player()
{
    c=2;
    x=41;
    y=20;
    life = 4;
    color=114;
}

player::~player()
{
    //dtor
}
bool player::move(int a)
{
    switch(a)
    {
      case 1: x+=3;break;
      case 2: x-=3;break;
				}
}
void player::print()
{
    Objectcolor(color);
    gotoxy(x,y);
    cout<<char(24);
    gotoxy(x-1,y);
    cout<<char(24);
    gotoxy(x+1,y);
    cout<<char(24);
    gotoxy(x,y-1);
    cout<<char(24);

}

void player::delet()
{
    gotoxy(x,y);
    cout<<" ";
    gotoxy(x-1,y);
    cout<<" ";
    gotoxy(x+1,y);
    cout<<" ";
    gotoxy(x,y-1);
    cout<<" ";
}

void player::showPoints()
{
    gotoxy(47,2);
    Objectcolor(238);
    cout<<"BARRIER: "<<point;
}

void player::showLife()
{
    if(life<=4)
      {
        gotoxy(23,3);
        Objectcolor(237);
        cout<<"LIFE: ";
        if(life==4)cout<<"oooo";
        if(life==3)cout<<"ooo";
        if(life==2)cout<<"oo";
                        }
    else if(life>4)
    {
        Objectcolor(237);
        gotoxy(29,3);
        cout<<"    ";
        gotoxy(29,3);
        cout<<life<<"o";
                }

}
void player::kill()
{
    showLife();
    gotoxy(33+(life-4),3);
    if(life==3)cout<<" ";
    if(life==2)cout<<"  ";
    if(life==1)cout<<"   ";
    if(life==0)cout<<"    ";

}













