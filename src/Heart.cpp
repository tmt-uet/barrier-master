#include "Heart.h"

Heart::Heart()
{
    y=2;
    randomx();
    iconHeart=char(169);
//	randomy();
    isHeart=false;
}

void Heart::move()
{
		y++;
		if(y==23)
    {   y=1;
		randomx();
		isHeart=false;
		iconHeart=char(169);
		}
	}


void Heart::print()
{
		Objectcolor(237);
		if(y>=2)
    {
		gotoxy(x,y);
		cout<<" ";
		}

		move();

		if(y>=2)
    {
		gotoxy(x,y);
		cout<<iconHeart;
		}
	}

void Heart::activeHeart()
{
		if(fmod(countLoop,150)==0)
        {
			isHeart=true;
		}
		if(isHeart==true)
		{
			print();
		}
	}
void Heart::dieukieny(Enemy E1)
{
			if(fabs(x-E1.x)<=1&&y!=E1.y)
			{

				y--;
			}
		}

void Heart::delet()
{

			gotoxy(x,y);
			iconHeart=' ';
		}

void Heart::randomx()
{
			int i = rand()%12+1;
			x=i+33;

			}







