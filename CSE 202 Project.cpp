#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include<string.h>
#include <windows.h>
using namespace std;
char letter[10][10];
int grid[10][10],assignment_integer=100;
class game
{
	public:
	void line(int n,char c);
    void surface();
    void score(char name1[],char name2[],int p1, int p2);
    void dice(int &score);
    void board_letters();
    void board_numbers();
};

class game1:public game
{
	public:
	void display()
{
int player1=0,player2=0,PreviousPosition,exit;
char player1name[80],player2name[80];
system("cls");
srand((unsigned)time(NULL));
line(80,'#');
cout<<"\n\n\t\t\t\tWELCOME TO\n\n";
cout<<"\n\n\t\t\tSNAKE AND LADDER GAME\n\n";
cout<<"\n\n\t\t\tMADE BY DEVESH CHAUDHARY\n\n";
line(80,'#');
cout<<"\n\n\t\t\tPress any key to continue...";
getch();
system("cls");

line(80,'=');
cout<<"\n\n\t\tENTER THE NAMES\n\n";
line(80,'=');
cout<<"\n\n\nEnter Name of player 1 :";
gets(player1name);
cout<<"\n\nEnter Name of player 2 :";
gets(player2name);
 do{
                if (strcmp(player2name,player1name)==0)
                {
                    cout<<"Both the players cannot have the same name."<<endl<<"Enter you name again player 2 :";
                    cin>>player2name;
                }
                else
                    exit=0;
          }while(exit!=0);
  system("cls");        

    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<"                                   INSTRUCTIONS                                 ";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\t\tWelcome to Snakes and Ladders. The rules"<<endl;
    cout<<"\t\tare simple. You will be presented with a board"<<endl;
    cout<<"\t\twith numbers upto 100. After entering the player names"<<endl;
    cout<<"\t\tthe dice will be rolled and the players while evading the"<<endl;
    cout<<"\t\tsnakes (green) and climbing the ladders(yellow) and"<<endl;
    cout<<"\t\tattempt to be the first one to reach 100."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t- Devesh Chaudhary"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    system("pause");

while(player1<100 && player2<100)
{
surface();
score(player1name,player2name,player1,player2);
cout<<"\n\n--->" <<player1name<<" It's your Turn >> Press any key to play ";
getch();
PreviousPosition=player1;
dice(player1);
if(player1<PreviousPosition)
cout<<"\n\aOops!! Snake found !! You are at postion "<<player1<<"\n";
else if(player1>PreviousPosition+6)
cout<<"\nGreat!! you got a ladder !! You are at position "<<player1;
cout<<"\n\n--->"<<player2name<<" Now it's your Turn >> Press any key to play ";
getch();
PreviousPosition=player2;
dice(player2);
if(player2<PreviousPosition)
cout<<"\n\n\aOops!! Snake found !! You are at position "<<player2<<"\n";
else if(player2>PreviousPosition+6)
cout<<"\n\nGreat!! you got a ladder !! You are at position "<<player2<<"\n";
getch();
}
system("cls");
cout<<"\n\n";
line(80,'+');
cout<<"\n\n\t\t\t\tRESULT\n\n";
line(80,'+');
cout<<endl;
score(player1name,player2name,player1,player2);
cout<<"\n\n\n";
if(player1>=player2)
cout<<"Congretulation "<<player1name<<" !! You are the winner of the game\n\n";
else
cout<<"Congretulation "<<player2name<<" !! You are the winner of the game\n\n";
line(80,'+');

	ofstream fout("PlayerNames.txt",ios::app);
if(fout.is_open())
{
		fout<<"# This match held between  "<<player1name<<"  and  "<<player2name<<"\n";
		if(player1>=player2)
		fout<<"   Winner of this game was :"<<player1name<<"\n";
		else
		fout<<"   Winner of this game was :"<<player2name<<"\n";
		fout.close();
}
else
{
	cout<<"Players name can't be submitted successfully please try once again!!!";
}
}
};

void game::line(int n,char ch)
{
for(int i=0;i<n;i++)
cout<<ch;
}

 void game::board_numbers()
{
    for (int i=0;i<10;++i)
    {
        for (int j=0;j<10;++j)
            {
                grid[i][j]=assignment_integer;
                assignment_integer--;
            }
    }
}

void game::board_letters()
{
    letter[0][2]='S';
    letter[0][5]='S';
    letter[0][8]='S';
    letter[1][7]='S';
    letter[2][7]='S';
    letter[3][1]='S';
    letter[3][6]='S';
    letter[4][1]='S';
    letter[4][5]='S';
    letter[4][8]='S';
    letter[5][2]='S';
    letter[5][4]='S';
    letter[5][6]='S';
    letter[9][7]='L';
    letter[7][9]='L';
    letter[5][7]='L';
    letter[5][0]='L';
    letter[3][8]='L';
    letter[3][3]='L';
    letter[2][0]='L';
}

void game::surface()
{
system("cls");
cout<<"\t\t\t Snakes & Ladders"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    for (int i=0;i<10;++i)                                                                          
    {                                                                                                
        cout<<"\n\n";                                                                                  
        for (int j=0;j<10;++j)                                                                         
            {
                if (isalpha(letter[i][j]))
                {
                      {
                          SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );//For remaining space
                          cout<<"     ";
                          if(letter[i][j]=='S')
                          {
                               SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xA1 );//For Snake color green
                               cout<<letter[i][j];
                          }
                          else
                          {
                             SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xE4 );//For ladder color yellow
                             cout<<letter[i][j];
                          }
                    }
                }
                else
                {
                    SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );//To give background color black for all
                    if (grid[i][j]<10)
                      cout<<" ";
                     cout<<"    "<<grid[i][j];
                    if (i==1&&j==9)
                        cout<<"\t"<<"INFORMATION:";
                    if (i==2&&j==9)
						cout<<"\t"<<"YELLOW = Ladder";
					if(i==3&&j==9)
						cout<<"\t"<<"GREEN = Snake";
                }
            }
    }
cout<<"\n\n";
line(80,'-');
cout<<"\tSNAKE AT POSITION                               LADDER AT POSITION\n";
line(80,'-');
cout<<"\n\tFrom 98 to 28  \t\t\t\t\tFrom 8 to 26\n\tFrom 95 to 24  \t\t\t\t\tFrom 21 to 82\n\tFrom 92 to 51  \t\t\t\t\tFrom 43 to 77\n\tFrom 83 to 19  \t\t\t\t\tFrom 50 to 91\n\tFrom 73 to 1  \t\t\t\t\tFrom 62 to 96\n\tFrom 69 to 33  \t\t\t\t\tFrom 66 to 87\n\tFrom 64 to 36  \t\t\t\t\tFrom 80 to 100\n\tFrom 59 to 17\n\tFrom 55 to 7\n\tFrom 52 to 11\n\tFrom 48 to 9\n\tFrom 46 to 5\n\tFrom 44 to 22\n\n";
};

void game::score(char name1[],char name2[],int p1, int p2)
{
line(80,'~');
cout<<"\n\t\t\t*****|STATUS OF THE GAME|*****\n";
line(80,'~');
if(p1>100)
p1=100;
if(p2>100)
p2=100;
cout<<"\n\t--->"<<name1<<" is at position "<<p1<<endl;
cout<<"\n\t--->"<<name2<<" is at position "<<p2<<endl;
line(80,'_');
}

void game::dice(int &score)
{
int dice;
dice=(rand()%6)+1;
cout<<"\nYou got "<<dice<<" Point !!\n ";
if(dice==1)
{
cout<<"\t\t _______\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|_______|\n";}
if(dice==2)
{
cout<<"\t\t _______\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|_______|\n";}
if(dice==3)
{
cout<<"\t\t _______\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|_______|\n";}
if(dice==4)
{
cout<<"\t\t _______\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|_______|\n";}
if(dice==5)
{
cout<<"\t\t _______\n";
cout<<"\t\t|       |\n";
cout<<"\t\t|   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|_______|\n";}
if(dice==6)
{
cout<<"\t\t _______\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|       |\n";
cout<<"\t\t| ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<"   ";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x4F );
cout<<"O";
SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
cout<<" |\n";
cout<<"\t\t|_______|\n";
}
score=score+dice;
cout<<"Now you are at position "<<score;
switch(score)
{
case 98 :score=28;
break;
case 95 :score=24;
break;
case 92 :score=51;
break;
case 83 :score=19;
break;
case 73 :score=1;
break;
case 69 :score=33;
break;
case 64 :score=36;
break;
case 59 :score=17;
break;
case 55 :score=7;
break;
case 52 :score=11;
break;
case 48 :score=9;
break;
case 46 :score=5;
break;
case 44 :score=22;
break;
case 8 :score=26;
break;
case 21 :score=82;
break;
case 43 :score=77;
break;
case 50 :score=91;
break;
case 54 :score=93;
break;
case 62 :score=96;
break;
case 66 :score=87;
break;
case 80 :score=100;
}
}

int main()
{
	game1 *g1=new game1;
    g1->board_numbers();
    g1->board_letters();
    g1->display();
    delete g1;
    getch();
}
