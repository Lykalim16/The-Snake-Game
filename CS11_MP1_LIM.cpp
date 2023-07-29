#include<graphics.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
//global variables//
int gd = DETECT, gm;
char arr[1250][1250];
int xbody[1250], ybody[1250];
int  r = 65, c = 65, food, p = 0, length = -1, exits = 0;
void display();
void movement();
void initFB(int diff);
void update();
void end();
void win();
void resetValues();
void portal();
void menu();
int main()
{
	initgraph(&gd,&gm,"C:\\TDM-GCC-32\\include");
	menu();
	closegraph();
	return 0;

}

void menu(){
    setbkcolor(CYAN);
	cleardevice();//main option
	settextstyle(3,HORIZ_DIR,2);
	outtextxy(200,100,"T  H  E   S  N  A  K  E   G  A  M  E ");
	outtextxy(240,130,"");
	outtextxy(240,160,"Choose an option");
	outtextxy(240,190,"(1) START GAME");
	outtextxy(240,220,"(2) INSTRUCTIONS");
	outtextxy(240,250,"(3) EXIT");
	char x = getch();
	cleardevice();

	if (x == '1')
	{
        settextstyle(3,HORIZ_DIR,2);
	    outtextxy(240,100,"ENTER LEVEL OF DIFFICULTY");
        outtextxy(240,130,"(1) EASY");
        outtextxy(240,160,"(2) DIFFICULT");
        char x = getch();
		if (x == '1')
		{
			initFB(x);
		}else if (x == '2') {
			initFB(x);
		}
		else{
            outtextxy(240,250,"Please enter a valid option\n");
            getch();
            menu();
		}
	}

	else if (x == '2')
	{
        outtextxy(220,50,"GAME INSTRUCTION");
        outtextxy(50,80,"There are two levels of difficulty in the game, the EASY mode");
        outtextxy(50,110,"and the DIFFICULT mode. In easy mode, the player will input foods");
        outtextxy(50,140,"strictly from 10 to 50 only. Foods will be represented by white");
        outtextxy(50,170,"blocks. In difficult mode, there will be additional black blocks in");
        outtextxy(50,200,"the board. When the snake's head collide with any part of itself, ");
        outtextxy(50,230,"the boarders or the black blocks, the game ends and you lose.");
        outtextxy(50,260,"After eating all the foods, a magic portal will appear");
        outtextxy(50,290,"and the whole snake needs to go in there to win the game.");
        outtextxy(50,360,"Press any key for the continuation");
        getch();
        cleardevice();
        outtextxy(50,260,"FOR THE SNAKE'S MOVEMENT: ");
        outtextxy(50,290,"Use the characters W, S, A, and D. W is used to");
        outtextxy(50,320,"make the snake go UP, S to move down, A to go to left,");
        outtextxy(50,350,"and D to go to right.");
        outtextxy(50,380,"HAPPY PLAYING!! :) ");
        outtextxy(50,410,"Press any key to proceed");
        getch();
        cleardevice();
        menu();
    }else if(x == '3')
	{
	    exit(0);
	}
        else
	{
	    outtextxy(240,160,"PLEASE ENTER A VALID OPTION :) ");
	    getch();
	    menu();
	}
}

void initFB(int x)
{
	int i, a, b;
	srand(time(NULL));
    cleardevice();
    outtextxy(110,160,"ENTER NUMBER OF FOODS TO BE EATEN (10 to 50):\n");
    char twodig=getch();
    char onedig=getch();
        food=(twodig-'0')*10+(onedig-'0');//im bento buti gumana
//        char pers[1]={};
//        char sec[1]={};
//        sprintf(pers,"%c",twodig);
//        sprintf(sec,"%c",onedig);
//        settextstyle(3,HORIZ_DIR,2);
//        setcolor(WHITE);
//        outtextxy(200,290,pers);
//        outtextxy(200,290,sec);

	if(food > 50 || food < 10)
	{
	    cleardevice();
	    outtextxy(240,160,"INVALID NUMBER. PLEASE ENTER AGAIN\n");
	    getch();
	    cleardevice();

        initFB(x);

	}

	cleardevice();
	for (a = 65; a <= 415; a=a+25)
	{
		for (b = 65; b <=415; b=b+25)
		{
			arr[a][b]= ' ';
		}
	}

	arr[65][65] = 'S';//ulo
	for (i = 0; i < food; i++)
	{
		a = (rand()%15)*25+65;
		b = (rand()%15)*25+65;
		while(arr[a][b] == '*'||(a==65&&b==65))
		{
			a = (rand()%15)*25+65;
            b = (rand()%15)*25+65;
		}
		arr[a][b] = '*';
        printf("%d %d\n", a, b);

	}

	if(x == '2'){
		for (i = 0; i < 10; i++)
		{
			a = (rand()%15)*25+65;
            b = (rand()%15)*25+65;
			while(arr[a][b] == '*' || arr[a][b]== 'B' || b % 2 == 0)
			{
				a = (rand()%15)*25+65;
                b = (rand()%15)*25+65;
			}
			arr[a][b] = 'B';

		}
	}

    display();
}

void display(){
	int a, b;
	for (a = 40; a <= 440; a=a+25)
	{
		for (b = 40; b <=440; b=b+25)
		{
			if(a == 40|| a == 440){
				if(b == 40 || b == 440) {setfillstyle(1,BLACK);
                    bar(a,b,a+25,b+25);
                    arr[a][b]='=';
				}
				else {setfillstyle(1,BLACK);
                    bar(a,b,a+25,b+25);
                    arr[a][b]='=';
                }
		}
		else if(b == 40 || b == 440) {setfillstyle(1,BLACK);
                    bar(a,b,a+25,b+25);
                    arr[a][b]='=';
                    }

	}
	}
	for (int c = 65; c <= 415; c=c+25)
	{
		for (int d = 65; d <=415; d=d+25)
		{
			if(arr[c][d]== ' '){
            setfillstyle(1,CYAN);
			bar(c,d,c+25,d+25);
			setcolor(BLACK);
			rectangle(c,d,c+25,d+25);
			}
			if(arr[c][d]== '*'){
            setfillstyle(1,WHITE);
			bar(c,d,c+25,d+25);
			}
			if(arr[c][d]== 'B'){
            setfillstyle(1,BLACK);
			bar(c,d,c+25,d+25);
			}
			if(arr[c][d]== 'S'){
            setcolor(WHITE);
			bar(c,d,c+25,d+25);
            setfillstyle(1,GREEN);
			bar(c,d,c+25,d+25);
			}
			if(arr[c][d] == 'P'){
            setfillstyle(1,RED);
			bar(c,d,c+25,d+25);

			}
		}
	}
    if(exits == length + 2){
        win();
    }

	 movement();
}

void movement(){
    int upd = 0;
    char m;
    if(upd == 0){
    update();
     upd = 1;
    }
    m=getch();


        if (m == 'D' || m == 'd'){
            //arr[r][c] = ' ';
            r=r+25;
            if(arr[r][c] == '*'){
                length++;
                xbody[length] = r;
                ybody[length] = c;
            }
            if(arr[r][c] == 'S') end();
            if(arr[r][c] == '=') end();
            if(arr[r][c] == 'B') end();
            if(arr[r][c] == 'P'){
                printf("length: %d\n\n", length);
                exits++;
                if(exits <= length + 1){
                    r = xbody[0];
                    c = ybody[0];
                }
                //length--;
            }

        } else if (m == 'S' || m == 's'){
            c=c+25;
            if(arr[r][c] == '*'){
                length++;
                xbody[length] = r;
                ybody[length] = c;
            }
            if(arr[r][c] == 'S') end();
            if(arr[r][c] == '=') end();
            if(arr[r][c] == 'B') end();
            if(arr[r][c] == 'P'){

                printf("length: %d\n\n", length);
                exits++;
                if(exits <= length + 1){
                r = xbody[0];
                c = ybody[0];
            }
                //length--;
            }

        } else if (m == 'A' || m == 'a'){
            r=r-25;
            if(arr[r][c] == '*'){
                length++;
                xbody[length] = r;
                ybody[length] = c;
            }
            if(arr[r][c] == 'S') end();
            if(arr[r][c] == '=') end();
            if(arr[r][c] == 'B') end();
            if(arr[r][c] == 'P'){
                printf("length: %d\n\n", length);
                exits++;
                if(exits <= length + 1){
                    r = xbody[0];
                    c = ybody[0];
                }
                //length--;
            }

        } else if (m == 'W'|| m== 'w'){
            c=c-25;
            if(arr[r][c] == '*'){
                length++;
                xbody[length] = r;
                ybody[length] = c;
            }
            if(arr[r][c] == 'S') end();
            if(arr[r][c] == '=') end();
            if(arr[r][c] == 'B') end();
            if(arr[r][c] == 'P'){
                printf("length: %d\n\n", length);
                exits++;
                if(exits <= length + 1){
                r = xbody[0];
                c = ybody[0];
                }

                //length--;
            }
        } else  if (m == 'Q' || m == 'q'){
            end();
        }
        else {
            display();
        }


    for(int i = 65; i <= 440; i+=25){
        for(int j = 65; j < 440; j+=25){
            if(arr[i][j] == 'S') arr[i][j] = ' ';
        }
    }

        if(exits < length + 2){
            arr[r][c] = 'S';
            for(int i = 0; i <= length; i++){
                arr[xbody[i]][ybody[i]] = 'S';
            }
        }
        if(length+1 == food && p == 0){
            portal();
        }

        display();

}

void update(){
    for(int i = length; i >= 0; i--){
        if(i == 0){
            xbody[i] = r;
            ybody[i] = c;
        }else{
            xbody[i] = xbody[i-1];
            ybody[i] = ybody[i-1];
        }
    }
}

void end (){
    char x;
    cleardevice();

    outtextxy(240,70,"Game Over!!");
    outtextxy(240,100,"Do you want to play again?");
    outtextxy(240,130,"(1) - Yes");
    outtextxy(240,160,"(2) - No");
    printf("Game Over!!\n");
    printf("Do you want to play again?\n");
    printf("(1) - Yes\n");
    printf("(2) - No\n");
    x = getch();
    if(x == '1'){

    resetValues();
       menu();
    }else if (x == '2'){
        exit(0);
    } else {
    printf("PLEASE PRESS A VALID OPTION\n");
    end();
    }
    //main();
}

void win (){
    cleardevice();

    outtextxy(180,160,"CONGRATULATIONS YOU WIN THE GAME");
    getch();
    resetValues();
    menu();
}

void resetValues(){
    length = -1;
    r = 65;
    c = 65;
    p = 0;
    exits = 0;
    for(int i = 0; i <  50; i++){
        xbody[i] = 0;
        ybody[i] = 0;
    }
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            arr[i][j] = ' ';
        }
    }
}

void portal(){
    int x, y, ck = 0;

		while(ck == 0)
		{
		    x = (rand()%15)*25+65;
            y = (rand()%15)*25+65;
            if((x == 65 ||x == 415) && y <= 415) ck = 1;
            else if((y == 65 || y == 415) && x<= 415) ck = 1;
            if(arr[x][y] == 'S' || arr[x][y] == 'B') ck = 0;
		}
		arr[x][y] = 'P';
		printf("\n\nPORTAL: %d %d\n", x, y);
		p = 1;
}
