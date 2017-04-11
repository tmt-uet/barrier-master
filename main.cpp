#include"player.h"
#include"Enemy.h"


   DWORD EventCount;
   DWORD readnum;
   INPUT_RECORD record;
   int numberE=4;

   int speed=100;
   bool conti=1;
   int countLoop=0;


class Heart{

		public:
	int x;
	int y;
	char iconHeart;
	bool isHeart;
	Heart(){
		y=2;
		randomx();
		iconHeart=char(169);
//		randomy();
		isHeart=false;
	}

	void move(){
		y++;
		if(y==23) { y=1;
		randomx();
		isHeart=false;
		iconHeart=char(169);
		}
	}
	void print(){
		Objectcolor(237);
		if(y>=2){
		gotoxy(x,y);
		cout<<" ";
		}

		move();

		if(y>=2){
		gotoxy(x,y);
		cout<<iconHeart;
		}
	}
	void activeHeart(){
		if(fmod(countLoop,150)==0){
			isHeart=true;
		}
		if(isHeart==true){
			print();
		}
	}
		void dieukieny(Enemy E1){
			if(fabs(x-E1.x)<=1&&y!=E1.y){
				y--;
			}
		}
		void delet(){

			gotoxy(x,y);
			iconHeart=' ';
		}
	private:
		void randomx(){
			int i = rand()%12+1;
			x=i+33;
			}

			};




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


class Background{
	public:
//		int color[4];
		void printBG(){
				BGcolor(116);
			for(int i= 0; i<=25;i++){

				gotoxy(0,i);
				cout<<"                                                                                ";
			}
			gotoxy(1,1);
		}

		void printBG2(){
			BGcolor(111);
			for(int i = 0; i<=23;i++){
			gotoxy(33,1+i);
			cout<<"|            |";
		}
		}
};
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

void GameOver(Background BG2)
{
	BG2.printBG();
	moveWord();
	Sleep(500);
	conti=false;
	}

int main(){

    Menu();
	player player1;
	Enemy enemy[numberE+1];
	Heart heart;
    srand(time(0));
    Background BG1;
	BG1.printBG();
	BG1.printBG2();
	player1.showPoints();
	player1.showLife();
	player1.print();
	while (conti)
        {
		countLoop++;
		Sleep(100-speed);
		for(int i= 1; i<=numberE;i++)
        {
            enemy[i].print();
            if ((enemy[i].x==player1.x||enemy[i].x==player1.x+1||enemy[i].x==player1.x-1)&&(enemy[i].y==player1.y))
            {
                player1.life--;
                player1.kill();
                Beep(700,250);
                player1.print();
			if (player1.life==0) GameOver(BG1);
		}




            if(enemy[i].y==22)
        {
                player1.point++;
                player1.showPoints();
		}
		}


		heart.activeHeart();

		if ((heart.x==player1.x||heart.x==player1.x+1||heart.x==player1.x-1)&&(heart.y==player1.y))
            {
			player1.life++;
			player1.showLife();
			heart.delet();
			player1.print();
		}
		else player1.print();

		turnUptheSpeed();
		if(player1.point>1&&(fmod(player1.point,100)==0)){
			int r=rand()%8+1;
			player1.color=r+71;
			Beep(800,200);
		}
		if(GetAsyncKeyState(VK_LEFT)!=0&&player1.x>36)
		{
			player1.delet();
            player1.move(2);
            player1.print();

		}
		if (GetAsyncKeyState(VK_RIGHT)!=0&&player1.x<44){
			player1.delet();
            player1.move(1);
            player1.print();

		}
	}


}





