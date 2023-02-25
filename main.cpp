#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include<unistd.h>
#include<cstdlib>
#include<windows.h>
int tailX[100],tailY[100];
int ntail=10;

using namespace std;
class SnakeGame
{
	int x,y,Foodx,Foody;
	int width=60;
	int height=30;
	enum Direction{Stop=0,Left,Right,Up,Down};
	Direction dir;

  public:
  	int score;
  	int over;
  	void set_value();
  	void design();
  	void GameOver();
  	void input();
  	void control();
  	void Score();
  	void length();
};

int highscore=0;

void SnakeGame::set_value()   //Yash Salunke
{
    over=0;     //decides gameover condition
    dir=Stop;
    x=width/2;  //setting initial values for snake heaed
    y=height/2;
    Foodx=rand()%width;    //setting random values for food
    Foody=rand()%height;
    score=0;
    ntail=0;
}

void SnakeGame::design()
{
   // system("cls");
    cout<<"\t\t\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t\t\t\t\t\t |  C L A S S I C   S N A K E   G A M E  |\n";
    cout<<"\t\t\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"\t\t\t\t\t\t\t\t";
   for(int i=0;i<width;i++)
   {
   	    if(i==0)                      cout<<"|";
        if(i<=width-2)                cout<<"=";  //printing top border
        if(i==width-1)                cout<<"|";
   }
        cout<<endl;

    for(int i=0;i<height;i++)
       {
           cout<<"\t\t\t\t\t\t\t\t";
           for(int j=0;j<width;j++)
             {
                    if(j==0)                      cout<<"|";
                    if(j==width-1)                cout<<"|";
                    else if(i==height-1)          cout<<"=";
                    else if(i==y&&j==x)           cout<<"$";

                    else if(i==Foody && j==Foodx) cout<<"O";
                    else
                    {
                       bool print=false;
				for(int k=0;k<ntail;k++)
				{
					if(tailX[k]==j&& tailY[k]==i)
					{
						cout<<"o";
						print=true;
					}
				}
				if(!print)
				{
					cout<<" ";
				}
                    }
             }
             cout<<endl;
       }
       cout<<"\t\t\t\t\t\t\t\t"<<"|                       Score = "<<score<<"                           |"<<endl;
       cout<<"\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void SnakeGame::GameOver()  //gameover design scren
{
	int choice,c;
    cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t    |  C L A S S I C   S N A K E   G A M E  |\n";
    cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t\t |      G A M E ~ O V E R    |"<<endl;
    cout<<"\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t\t Your Score ::"<<score<<endl<<endl;
    cout<<"\t\t\t\t\t High Score :: "<<highscore<<endl<<endl;
	cout<<"\t\t\t\t\t Press any key countinue.........\n";
	getch();
}

void SnakeGame::input()  //Pranav Patil
{
    char c;
    if(_kbhit())   //condition true on keypress
    {
        c=_getch();
        if((c=='a'||c=='A')&&dir!=Right)      dir=Left;
        else if((c=='d'||c=='D')&&dir!=Left)  dir=Right;
        else if((c=='w'||c=='W')&&dir!=Down)  dir=Up;
        else if((c=='s'||c=='S')&&dir!=Up)    dir=Down;
        else if(c==' ')                       dir=Stop;
    }
}

void SnakeGame :: length(){
	int prevX = tailX [0];
    int prevY = tailY [0];
    int prev2X, prev2Y;
    tailX[0] = x;  //headvalues inserted
    tailY[0] = y;
    for(int i = 1;i < ntail ; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y ;
    }
}

void SnakeGame::Score()
{
    if(x==Foodx&&y==Foody)
    {
        score+=10;
        Foodx=rand()%width-1;
        Foody=rand()%height-1;
        ntail ++;
    }
}

void SnakeGame::control()  //Adityaraj Patil
{


    switch(dir)
    {
        case Up:
            if(y==0)      over=1;
            else y--;
            break;

        case Down:
            if(y==height) over=1;
            else y++;
            break;

        case Left:
            if(x==0)      over=1;
            else x--;
            break;

        case Right:
            if(x==width)  over=1;
            else x++;
            break;
    }


}

int main()  //Karteek Patil
{
	SnakeGame obj;
    int choice,c;
    flag:
    do
    {
        cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t\t\t\t    |  C L A S S I C   S N A K E   G A M E  |\n";
        cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    	cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t *******************************\n";
        cout<<"\t\t\t\t\t *\t   1.Easy              *"<<endl;
        cout<<"\t\t\t\t\t *\t   2.Medium            *"<<endl;
        cout<<"\t\t\t\t\t *\t   3.Hard              *"<<endl;
        cout<<"\t\t\t\t\t *******************************\n";
        cout<<"\t\t\t\t\t Enter your choice:";
        cin>>c;
    system("cls");
    obj.set_value();
    while(!obj.over)
   {
        obj.design();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
        obj.input();   //direction
        obj.length();
        obj.control(); //co-ordinates
        obj.Score();
        if(c==1)      _sleep(250);   //introducing
        else if(c==2) _sleep(150);
        else if(c==3) _sleep(60);
   }
    highscore=highscore>obj.score?highscore:obj.score;

    system("cls");
    obj.GameOver();
    system("cls");
    int choice,c;
    cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t    |  C L A S S I C   S N A K E   G A M E  |\n";
    cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t *******************************\n";
    cout<<"\t\t\t\t\t *          1.Restart          *"<<endl;
    cout<<"\t\t\t\t\t *          2.Quit             *"<<endl;
    cout<<"\t\t\t\t\t *******************************\n";
    cout<<"\t\t\t\t\t Enter your choice:";
    cin>>choice;

        switch(choice)
        {
            case 1:
               system("cls");
               goto flag;
                break;
            case 2:
                return 0;
                break;
            default:
                return 0;
        }
  }
        while(choice==1);
}

