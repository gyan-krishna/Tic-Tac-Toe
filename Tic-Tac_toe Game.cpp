#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int status();
void input();
void display();

char mat[3][3]={
		{'X','O','O'},
		{'X',' ','0'},
		{'O','X',' '},
	};
int currPlayer = 1;

//1. input procressing
//2. check if a player has won or not
//3. graphics 

int main()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
			mat[i][j] = ' ';
	}
	display();
	while(1)
	{
		input();
		display();
		int stat = status();
		if(stat == 1 || stat == 2)
		{
			system("cls");
			printf("congratulations player %d has won\n",stat);
			break;
		}
		if(stat == -1)
		{
			system("cls");
			printf("draw!\n");
			break;
		}
	}
	
	printf("game over");
	return 0;
}

//function to compute the present status of the board
// 1 - if player 1 has won
// 2 - if player 2 has won
// -1 - if there is a draw
// 0 - no outcome

int status()
{
	char comp[2]={'X','O'};
	for(int p = 0 ; p < 2 ; p++)
	{
		for(int i = 0 ; i < 3 ; i++)
		{
			//checking each row
			if(mat[i][0] == comp[p] && mat[i][1] == comp[p] && mat[i][2] == comp[p])
				return p + 1;
			//checking each col
			if(mat[0][i] == comp[p] && mat[1][i] == comp[p] && mat[2][i] == comp[p])
				return p + 1;			
		}
		//checking fro dia
		if(mat[0][0] == comp[p] && mat[1][1] == comp[p] && mat[2][2] == comp[p])
			return p + 1;
		if(mat[0][2] == comp[p] && mat[1][1] == comp[p] && mat[2][0] == comp[p])
			return p + 1;		
	}
	for(int i = 0 ; i < 2 ; i++)
	{
		for(int j = 0 ; j < 2 ; j++)
			if(mat[i][j] == ' ')
				return 0;
	}
	return -1;
}
//input procressing 
void input()
{
	int x,y;
	char ch = getch();
	if(ch >= '1' && ch <= '9')
	{
		switch(ch)
		{
			case '1':
				x = 0;
				y = 2;
				break;
			case '2':
				x = 1;
				y = 2;
				break;
			case '3':
				x = 2;
				y = 2;
				break;
			case '4':
				x = 0;
				y = 1;
				break;
			case '5':
				x = 1;
				y = 1;
				break;
			case '6':
				x = 2;
				y = 1;
				break;
			case '7':
				x = 0;
				y = 0;
				break;
			case '8':
				x = 1;
				y = 0;
				break;
			case '9':
				x = 2;
				y = 0;
				break;
		}
		
		if(mat[y][x] != ' ')
			return;
		if(currPlayer == 1)
		{
			mat[y][x] = 'X';
			currPlayer = 2;
		}
		else
		{
			mat[y][x] = 'O';
			currPlayer = 1;
		}
		//printf("%c -> %d %d",ch,y,x);
	}
}
// 196 - horizontal line
// 197 - cross
// 179 - vertical line
void display()
{
	int i,j;
	system("cls");
	printf("current player ::");
	
	if(currPlayer == 1)
		printf("X\n\n");
	else
		printf("O\n\n");

	printf("  %c %c %c %c %c\n",mat[0][0],179,mat[0][1],179,mat[0][2]);
	printf(" %c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,197,196,196,196,197,196,196,196);
	printf("  %c %c %c %c %c\n",mat[1][0],179,mat[1][1],179,mat[1][2]);
	printf(" %c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,197,196,196,196,197,196,196,196);
	printf("  %c %c %c %c %c\n",mat[2][0],179,mat[2][1],179,mat[2][2]);
}

