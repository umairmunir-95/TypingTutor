/*
									Typing Tutor !!
*/

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <time.h>
#include <conio.h>
#include <iomanip>
using namespace std;
int i=0,j=0,k=0;
char a;
class player
{												// Class Player
protected:
	char name[15];
	int lives;
public:
	player()
	{												// Player Constructor
		for(i=0;i<15;i++)
			name[i]='\0';
		lives=5;
	}
	void new_player()
	{										// New Player
		cout<<"\n\n\t\tEnter your name :\n\t\t\t";
		cin.ignore();
		gets_s(name);
	}
	int get_lives()
	{										// Return Lives
		return lives;
	}
	void set_lives(int d)
	{									// Lives Left
		lives--;
		if(lives==0)
			eog(d);
	}
	void eog(int d)
	{										// End of Game
		system("cls");
		cout<<"\n\n\t\t\t**************************\n";
		cout<<"\n\t\t\t*   Game Over !!         *\n\n";
		cout<<"\t\t\t*   Your Score is : "<<setw(3)<<d<<"  *"<<endl;
		cout<<"\n\t\t\t**************************\n";
		cout<<"\nPress any key to go back to main menu...\n";
		_getch();
	}
	char* get_name()
	{										// Get Name
		return name;
	}
};
class game:public player
{									// Class Game:Public Player
private:
	char alphabets[15];
	char characters[15];
	int level;
	int level_result;
	int points;
public:
	game()
	{													// Game Constructor
		for(i=0;i<15;i++)
		{
			alphabets[i]='\0';
			characters[i]='\0';
		}
		level=1;
		level_result=0;
		points=0;
		player();
	}
	int get_points()
	{										// Get points
		return points;
	}
	void start()
	{											// Start Function
		system("cls");
		cout<<"\n\n\t\t\tWelcome to Typing Tutor !!\n";
		cout<<"\n\n\t*************************";
		cout<<"\n\n\t*   1. Start Game       *\n";
		cout<<"\t*   2. Top Scorer       *\n";
		cout<<"\t*   3. All Scores       *\n";
		cout<<"\t*   4. Exit             *\n";
		cout<<"\n\t*************************";
		cout<<"\n\nEnter your choice...\n";
		a=_getch();
		switch(a)
		{
		case '1':
			system("cls");
			resetvalues();
			new_player();
			k=lessons();
			gamestart();
			break;
		case '2':
			topscorer();
			_getch();
			start();
			break;
		case '3':
			show();
			_getch();
			start();
			break;
		case '4':
			exit1();
			break;
		default:
			cout<<"Invalid Choice Entered!!\n";
			_getch();
			start();
		}
	}

	void topscorer()
	{										// Top Scorer
		system("cls");
		ifstream in;
		char d[15];
		for(i=0;i<15;i++)
			d[i]='\0';
		int p=0;
		cout<<"\n\n\t\t***********************\n";
		cout<<"\n\t\t*   Top Scorer...     *\n\n";
		in.open("record.txt",ios::in);
		while(!in.eof())
		{
			in>>name>>points;
			if(points>p)
			{
				strcpy_s(d,name);
				p=points;
			}
		}
		cout<<"\t\t*   "<<d<<"\t"<<setw(3)<<p<<"   *"<<endl;
		cout<<"\n\t\t***********************\n";
		cout<<"\nPress any key to go back to main menu...\n";
	}

	int lessons()
	{											// Lessons
		system("cls");
		cout<<"\n\t\t1. Lesson 1 (a)\n\n";
		cout<<"\t\t2. Lesson 2 (a/A)\n\n";
		cout<<"\t\t3. Lesson 3(a/A/1)\n\n";
		cout<<"Enter your choice...\n";
		int x=_getch();
		if(x==49)
			return 1;
		else if(x==50)
			return 2;
		else if(x==51)
			return 3;
		else
		{
			cout<<"Invalid no. entered...\n";
			x=lessons();
			return x;
		}
	}
	void exit1(){											// Exit Function
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t*****************************\n";
		cout<<"\t\t\t\t*       Developed By :      *\n";
		cout<<"\t\t\t\t*    Umair Munir Ahmad      *\n";
		cout<<"\t\t\t\t*       2012-CS-141         *\n";
		cout<<"\t\t\t\t*****************************\n\n";
		cout<<"Press any key to exit...\n";
		_getch();
		exit(0);
	}
	void resetvalues()
	{										// Reset Originals
		for(i=0;i<15;i++)
			name[i]='\0';
		lives=5;
		level=1;
		level_result=0;
		points=0;
	}
	void gamestart()
	{										// Game Start Function
		system("cls");
		cout<<get_name();
		cout<<"\tStage : "<<level_result;
		cout<<"\tScore : "<<points;
		cout<<"\tLives Left : "<<get_lives();
		cout<<"\tLevel : "<<level<<endl;
		generate_alphabets();
		show_alphabets();
		cin>>*this;
		result();
	}
	void show()
	{											// Show
		system("cls");
		cout<<"********\t\t**********\n";
		cout<<"* NAME *\t\t* SCORES *\n";
		cout<<"********\t\t**********\n\n";
		char s;
		ifstream in;
		in.open("record.txt",ios::in);
		s=in.get();
		while(s!=EOF)
		{
			cout<<s;
			s=in.get();
		}
		cout<<"\n\nDo you want to clear records (y/n)...\n";
		char c;
		c=_getch();
		if(c=='y' || c=='Y')
		{
			clr_records();
			show();
		}
		else
		{
			cout<<"\n\nPress any key to go back...\n";
			_getch();
			start();
		}
	}
	void clr_records()
	{										// Clear Records
		ofstream in;
		in.open("record.txt",ios::out);
	}
	void generate_alphabets()
	{								// Generate Alphabets
		int d;
		for(i=0;i<level+2;i++)
		{
			d=rand() % k;
			if(d==0)
				alphabets[i]=rand() % 26+97;
			else if(d==1)
				alphabets[i]=rand() % 26+65;
			else if(d==2)
				alphabets[i]=rand() % 10+48;
		}
	}

	void show_alphabets()
	{									// Show Alphabets
		cout<<"\n\t";
		for(i=0;i<level+2;i++)
			cout<<alphabets[i];
		cout<<endl;
	}
	void true_c()
	{											// True
		cout<<"Very Well...\n";
		points=points+level*5;
		level_result++;
		_getch();
	}
	void fileh()
	{											// File Handling
		ofstream o;
		o.open("record.txt",ios::app);
		o<<name<<"\t\t\t"<<points<<endl<<endl;
		o.close();
	}
	void false_c()
	{											// False
		cout<<"Wrong!!\n";
		_getch();
		set_lives(points);
		if(get_lives()==0)
		{
			fileh();
			start();
		}
	}
	void etime()
	{											// End of Time
		cout<<"Time consumed more than 5 seconds...\n";
		lives--;
		_getch();
	}
	void check()
	{											// Level Change
		if(level_result==10)
		{
			system("cls");
			cout<<"\t\tCongratulations !!\n";
			cout<<"\nLevel "<<level<<" cleared...\n\n";
			level++;
			level_result=level_result%10;
			cout<<"Entering Level "<<level<<"...\n";
			_getch();
		}
	}

	void result()
	{											// Result
		int c=0;
		for(i=0;i<level+2;i++)
		{
			if(alphabets[i]==characters[i])
				c++;
		}
		if(c==level+2)
			true_c();
		else
			false_c();
		check();
		gamestart();
	}
	friend istream& operator>>(istream &in,game &g);
};
istream& operator>>(istream &in,game &g)
{					// game::Operator >>
	time_t now=time(0);
	cout<<"\t";
	in>>g.characters;
	if(time(0)>now+5)
	{
		g.etime();
		g.gamestart();
	}
	return in;
}
int main()
{													// Main Function
	game g;
	g.start();
	system("pause");
	return 0;
}