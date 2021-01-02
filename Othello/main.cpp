#include <stdio.h>
#include <conio.h>

#include <windows.h>

int trueorfalse = 1;
int map[8][8] = {
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,2,1,0,0,0},
{0,0,0,1,2,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
};
int number = 0;
int giveup = 0;

void gotoxy(int x, int y);
int Checkdisk(int ax, int ay);
void Game(int ax, int ay, int diskcolor);
void DrawArraydisk(int diskcolor);
int Drawdisk(int ax, int ay, int x, int y);
void CheckdiskNumber();
void firstdisk();

int main()
{
	int i, j, e, o;
	int x, y;
	int u, r;
	int ax, ay;
	int blacknb = 0, whitenb = 0;
	char keycode;
	int diskcolor;

	gotoxy(10, 1);
	printf("* OTHELLO *");
	gotoxy(10, 3);

	for (j = 3; j <= 10; j++)
	{
		for (i = 10; i <= 25; i++)
		{
			gotoxy(i, j);
			printf(".");
		}
	}
	gotoxy(16, 7);
	x = 16;
	y = 7;
	ax = 3;
	ay = 4;
	firstdisk();
	gotoxy(12, 16);
	printf("BLACK TURN");
	gotoxy(16, 7);
	while (1)
	{
		for (e = 0; e < 8; e++)
		{
			for (o = 0; o < 8; o++)
			{
				if (map[e][o] == 1 || map[e][o] == 2)
					number++;
			}
		}

		if (number == 64)
		{
			CheckdiskNumber();
			system("pause>nul");
			return 0;
		}
		else
			number = 0;
		for (u = 0; u < 8; u++)
		{
			for (r = 0; r < 8; r++)
			{
				if (map[u][r] == 1)
					blacknb++;
				else if (map[u][r] == 2)
					whitenb++;
			}
		}
		if (blacknb == 0 || whitenb == 0)
		{
			gotoxy(12, 17);
			if (blacknb == 0)
				printf("WHITE WINS!");
			else if (whitenb == 0)
				printf("BLACK WINS!");
			system("pause>nul");
			return 0;
		}
		blacknb = 0;
		whitenb = 0;
		if (_kbhit())
		{
			keycode = _getch();
			if (keycode == 75)
			{
				gotoxy(x - 2, y);
				x = x - 2;
				ax = ax - 1;
			}
			if (keycode == 77)
			{
				gotoxy(x + 2, y);
				x = x + 2;
				ax = ax + 1;
			}
			if (keycode == 72)
			{
				gotoxy(x, y - 1);
				y = y - 1;
				ay = ay - 1;
			}
			if (keycode == 80)
			{
				gotoxy(x, y + 1);
				y = y + 1;
				ay = ay + 1;
			}
			if (x >= 26)
			{
				gotoxy(24, y);
				x = 24;
				ax = 7;
			}
			if (x <= 8)
			{
				gotoxy(10, y);
				x = 10;
				ax = 0;
			}
			if (y <= 3)
			{
				gotoxy(x, 3);
				y = 3;
				ay = 0;
			}
			if (y >= 10)
			{
				gotoxy(x, 10);
				y = 10;
				ay = 7;
			}
			if (keycode == 'z')
			{
				if (trueorfalse == 1)
				{
					trueorfalse = 0;
					gotoxy(12, 16);
					printf("WHITE TURN");
				}
				else if (trueorfalse == 0)
				{
					trueorfalse = 1;
					gotoxy(12, 16);
					printf("BLACK TURN");
				}
				giveup++;
				if (giveup == 4)
				{
					CheckdiskNumber();
					system("pause>nul");
					return 0;
				}
				gotoxy(x, y);
			}
			if (keycode == 13)
			{
				if (Checkdisk(ax, ay) == 0)
					diskcolor = Drawdisk(ax, ay, x, y);
				gotoxy(x, y);
			}
		}
	}
}
void Game(int ax, int ay, int diskcolor)
{
	int endx, endy;
	endx = 0;
	endy = 0;
	int i, j;
	int disktrue = 0;
	int tester[4] = { 0 };
	int tester2[4] = { 0 };
	int tester3[4] = { 0 };
	int tester4[4] = { 0 };
	int tester5[4] = { 0 };
	int PlusOneOrNot[4] = { 0 };
	int ArrayIndex = 0;
	int ere, dre;
	ere = 0;
	dre = 0;
	int g;
	if (map[ax + 1][ay] != diskcolor)
	{
		if (ax != 7)
		{
			if (map[ax + 1][ay] != 0)
			{
				for (j = ax + 1; j < 8; j++)
				{
					if (map[j][ay] == 0 || map[j][ay] > 2)
					{
						endx = ax;
						break;
					}
					if (map[j][ay] == diskcolor)
					{
						endx = j;
						break;
					}
				}
				for (i = ax + 1; i < endx + 1; i++)
				{
					if (map[i][ay] != diskcolor)
					{
						map[i][ay] = diskcolor;
						disktrue = 1;
					}
				}
			}
		}
	}
	if (map[ax - 1][ay] != diskcolor)
	{
		if (ax != 0)
		{
			if (map[ax - 1][ay] != 0)
			{
				for (j = ax - 1; j >= 0; j--)
				{
					if (map[j][ay] == 0)
					{
						endx = ax;
						break;
					}
					if (map[j][ay] == diskcolor)
					{
						endx = j;
						break;
					}
				}
				for (i = ax - 1; i > endx - 1; i--)
				{
					if (map[j][ay] != diskcolor)
						break;
					if (map[i][ay] != diskcolor)
					{
						map[i][ay] = diskcolor;
						disktrue = 1;
					}
				}
			}
		}
	}

	if (map[ax][ay - 1] != diskcolor)
	{
		if (ay != 0)
		{
			if (map[ax][ay - 1] != 0)
			{
				for (j = ay - 1; j >= 0; j--)
				{
					if (map[ax][j] == 0)
					{
						endy = ay;
						break;
					}
					if (map[ax][j] == diskcolor)
					{
						endy = j;
						break;
					}
				}
				for (i = ay - 1; i > endy - 1; i--)
				{
					if (map[ax][j] != diskcolor)
						break;
					if (map[ax][i] != diskcolor)
					{
						map[ax][i] = diskcolor;
						disktrue = 1;
					}
				}
			}
		}
	}
	if (map[ax][ay + 1] != diskcolor)
	{
		if (ay != 7)
		{
			if (map[ax][ay + 1] != 0)
			{
				for (j = ay + 1; j < 8; j++)
				{
					if (map[ax][j] == 0 || map[ax][j] > 2)
					{
						endy = ay;
						break;
					}
					if (map[ax][j] == diskcolor)
					{
						endy = j;
						break;
					}
				}
				for (i = ay + 1; i < endy + 1; i++)
				{
					if (map[ax][i] != diskcolor)
					{
						map[ax][i] = diskcolor;
						disktrue = 1;
					}
				}
			}
		}
	}
	if (map[ax - 1][ay - 1] != diskcolor)
	{
		if (ax != 0 && ay != 0)
		{
			if (map[ax - 1][ay - 1] != 0)
			{
				tester[0] = -1;
				tester2[0] = -1;
				tester3[0] = 0;
				tester4[0] = -2;
				tester5[0] = -1;
				PlusOneOrNot[0] = -1;
			}
		}
	} //test
	if (map[ax + 1][ay - 1] != diskcolor)
	{
		if (ax != 7 && ay != 0)
		{
			if (map[ax + 1][ay - 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = 1;
				tester2[ArrayIndex] = -1;
				tester3[ArrayIndex] = 0;
				tester4[ArrayIndex] = 2;
				tester5[ArrayIndex] = -1;
				PlusOneOrNot[ArrayIndex] = -1;
			}
		}
	}
	if (map[ax - 1][ay + 1] != diskcolor)
	{
		if (ax != 0 && ay != 7)
		{
			if (map[ax - 1][ay + 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = -1;
				tester2[ArrayIndex] = 1;
				tester3[ArrayIndex] = 7;
				tester4[ArrayIndex] = -2;
				tester5[ArrayIndex] = 1;
				PlusOneOrNot[ArrayIndex] = 1;
			}
		}
	}
	if (map[ax + 1][ay + 1] != diskcolor)
	{
		if (ax != 7 && ay != 7)
		{
			if (map[ax + 1][ay + 1] != 0)
			{
				if (tester[0] != 0)
					ArrayIndex++;
				tester[ArrayIndex] = 1;
				tester2[ArrayIndex] = 1;
				tester3[ArrayIndex] = 7;
				tester4[ArrayIndex] = 2;
				tester5[ArrayIndex] = 1;
				PlusOneOrNot[ArrayIndex] = 1;
			}
		}
	}
	if (tester[0] != 0)
	{
		for (g = 0; g <= ArrayIndex; g++)
		{
			if (map[ax + tester[g]][ay + tester2[g]] != diskcolor)
			{
				if (map[ax + tester[g]][ay + tester2[g]] != 0)
				{
					gotoxy(18, 18);
					ere = ax + tester[g];
					for (j = ay + tester2[g]; j != tester3[g]; j = j + PlusOneOrNot[g])
					{
						if (map[ere][j] == 0 || map[ere][j] > 2)
						{
							endy = ay;
							break;
						}
						if (map[ere][j] == diskcolor)
						{
							endx = ere;
							endy = j;
							break;
						}
						ere = ere + tester[g];
					}
					dre = ax + tester[g];
					for (i = ay + tester2[g]; i != j; i = i + PlusOneOrNot[g])
					{
						if (map[ere][j] != diskcolor)
							break;
						if (map[dre][i] != diskcolor)
						{
							map[dre][i] = diskcolor;
							disktrue = 1;
						}
						dre = dre + tester[g];
					}
				}
			}
			gotoxy(15, 21);
		}
	}
	if (disktrue == 0)
	{
		map[ax][ay] = 0;
	}
	else {
		if (trueorfalse == 0)
			trueorfalse = 1;
		else
			trueorfalse = 0;
		giveup = 0;
		gotoxy(12, 16);
		if (trueorfalse == 1)
			printf("BLACK TURN");
		else
			printf("WHITE TURN");
		DrawArraydisk(diskcolor);
	}
}
void DrawArraydisk(int diskcolor)
{
	int i, j;
	int x, y;
	x = 10;
	y = 3;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (map[j][i] == 1)
			{
				gotoxy(x, y);
				printf("b");
			}
			else if (map[j][i] == 2) {
				gotoxy(x, y);
				printf("w");
			}
			x += 2;
		}
		x = 10;
		y += 1;
	}
}
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
int Checkdisk(int ax, int ay)
{
	if (map[ax][ay] == 1 || map[ax][ay] == 2)
		return 1;
	else
		return 0;
}
int Drawdisk(int ax, int ay, int x, int y)
{
	int diskcolor;
	if (trueorfalse == 1)
	{
		map[ax][ay] = 1;
		diskcolor = 1;
	}
	else if (trueorfalse == 0)
	{
		map[ax][ay] = 2;
		diskcolor = 2;
	}
	Game(ax, ay, diskcolor);
	return diskcolor;
}
void firstdisk()
{
	printf("b");
	gotoxy(18, 7);
	printf("w");
	gotoxy(16, 6);
	printf("w");
	gotoxy(18, 6);
	printf("b");
	gotoxy(14, 7);
}
void CheckdiskNumber()
{
	int u, r;
	int blacknb = 0, whitenb = 0;

	for (u = 0; u < 8; u++)
	{
		for (r = 0; r < 8; r++)
		{
			if (map[u][r] == 1)
				blacknb++;
			else if (map[u][r] == 2)
				whitenb++;
		}
	}
	gotoxy(12, 17);
	if (blacknb > whitenb)
		printf("BLACK WINS!");
	else if (blacknb < whitenb)
		printf("WHITE WINS!");
	else if (blacknb == whitenb)
		printf("DRAW!");
}