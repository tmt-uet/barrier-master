#include"game.h"
using namespace std;
#define tmt 30;
void Menu(){
    Objectcolor(109);
    gotoxy(38,10);
    cout<<"PLAY";
    gotoxy(26,13);
    Objectcolor(110);
    cout<<"PLEASE PRESS ENTER TO PLAY GAME";
    gotoxy(29,19);
    cout<<"GAME BY TMT SOCIU STUDIO ^_^";
    int k;

    do
        {
        k=getch();
    }
    while(k!=13);
    Objectcolor(111);
    gotoxy(38,10);
    cout<<"PLAY";
    Beep(1444,200);
    }

int HoldkeyLoop(player player1){
 		int HoldKey;
       	GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE),&EventCount);
        while (EventCount > 0)
        {
            ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE),&record,1,&readnum);
            if (record.EventType == KEY_EVENT )
			{
				HoldKey = record.Event.KeyEvent.uChar.AsciiChar;
			}
			 GetNumberOfConsoleInputEvents(GetStdHandle(STD_INPUT_HANDLE),&EventCount);
        }
        if((player1.x==44&&HoldKey==100)||(player1.x==35&&HoldKey==97)) HoldKey=0;
        return HoldKey;
}

void turnUptheSpeed(){
	float k;
	if(speed<50)
	k+=0.1;
	else{
		k+=0.01;
	}

	speed=int(k);
	gotoxy(22,2);
	Objectcolor(241);
	cout<<"SPEED: +"<<speed+100;
}


void moveWord(){
	Objectcolor(240);
	for(int i= 10; i<=28; i++){
		gotoxy(9+i,12);
		cout<<"GAME";
		gotoxy(70-i,12);
		cout<<"OVER";

		Beep((41-i)*100,100);
		gotoxy(70-i-1,12);
		if(i<28)cout<<"      ";
		gotoxy(9+i,12);
		if (i<28)
		cout<<"    ";
	}
}





