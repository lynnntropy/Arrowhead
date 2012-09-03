#include <stdio.h>
#include <ncurses.h>

int getInput(void);
void drawPlayer(int x, int y, char sprite);

int main()
{
	initscr();
	raw();
	noecho();
	cbreak();
	
	int game_loop;
	game_loop = 1;
	
	int x;
	int y;
	int direction;
	
	x = 0;
	y = 0;
	direction = 5;
	
	drawPlayer(0, 0, '>');
	
	while(game_loop)
	{
		direction = getInput();
		
		switch(direction)
		{
			case 6:
				x++;
				drawPlayer(x, y, '>');
				break;
			case 4:
				x = x - 1;
				drawPlayer(x, y, '<');
				break;
			case 8:
				y = y - 1;
				drawPlayer(x, y, '^');
				break;
			case 2:
				y++;
				drawPlayer(x, y, 'V');
				break;
			case 5:
				break;
		}
		
		direction = 5;
	}
	
	return 0;
}
	
void drawPlayer(int x, int y, char sprite)
{
	int maxx;
	int maxy;
	
	getmaxyx(stdscr, maxy, maxx);
	
	if (x >= 0 && y >= 0 && x <= maxx && y <= maxy)
	{
		erase();
		mvprintw(y, x, "%c", sprite);
	}
	else if (y < 0)
	{
		y = 1;
		erase();
		mvprintw(y, x, "%c", sprite);
	}
	else if (x < 0)
	{
		x = 1;
		erase();
		mvprintw(y, x, "%c", sprite);
	}
	else if (y > maxy)
	{
		y = maxy - 1;
		erase();
		mvprintw(y, x, "%c", sprite);
	}
	else if (x > maxx)
	{
		x = maxx - 1;
		erase();
		mvprintw(y, x, "%c", sprite);
	}
}

int getInput()
{
	char input;
	input = getch();
	
	switch(input)
	{
		case 'w':
			return 8;
			break;
		case 's':
			return 2;
			break;
		case 'a':
			return 4;
			break;
		case 'd':
			return 6;
			break;
	}
	
		
}
