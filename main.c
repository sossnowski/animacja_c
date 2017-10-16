#include <ncurses.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>


int kolumny = 0;
int rzedy = 0;
char tekst[] = "Krzysztof Brzoska";
char kometa[]="XXX";
char kometa2[]="XXX";
char kometa3[]="XXX";


int main()
{
    initscr(); 
    getmaxyx( stdscr, rzedy, kolumny );
	
	double x, y;
	int t=0;
	time_t tt;
		
		
		
	int zarodek= time(&tt);
	srand(zarodek);

	for (t=8;t<100000;t++){
		getmaxyx( stdscr, rzedy, kolumny );
		x= 0.2*t*sin(t);
		y= 0.2*t*cos(t);

		int a = x;
		int b = y;
		int a1, b1;

		if (t%2==0){
			a1 = rand()%rzedy-2;	
			b1 = rand()%kolumny-1;}

		if (a== rzedy/2-2){
			t=8;
		}else if (b== kolumny/2-2){
			t=8;
		}
	
		start_color();
		init_pair(1, COLOR_RED, COLOR_GREEN);
		attrset(COLOR_PAIR(1));

    	mvwaddstr(stdscr, rzedy / 2+a,( kolumny / 2 ) -( sizeof( tekst ) / 2 )+b, tekst ); 
		mvwaddstr(stdscr,a1, b1-1, kometa ); 
		mvwaddstr(stdscr, a1-1, b1-1, kometa2 );
		mvwaddstr(stdscr, a1+1, b1-1, kometa3 );
	
		int roznica_a=abs((rzedy / 2)+a-a1);
		int roznica_b=abs(( kolumny / 2 )+b-b1);
	
	
		if ((roznica_a==0 && roznica_b<6) || (roznica_a==1 && roznica_b<6)){

			wrefresh(stdscr);
			usleep(900000);
			wclear(stdscr);
			mvwaddstr(stdscr,rzedy/2, kolumny/2-3, "koniec" );
			getch(); 
    		endwin(); 
			return 0;}
	

		wrefresh(stdscr);
		usleep(200000);
		wclear(stdscr);
		}	
    

   	 return 0;
}
