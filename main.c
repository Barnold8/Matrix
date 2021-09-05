#include "require.h"
#include "functions.h"
#include <signal.h>

int main(void) {

	/* Variable space to init and declare values if needed */
		struct coords coordsARR[101];
	    int running,i,TIMEMAX;
		clock_t start, end;
		double program_seconds;
		start = clock();
		running = 1;
		TIMEMAX = 100;
		srand(time(NULL));
	
	/* ------------ */
    

	initscr();

	/* Populate array with coord structs */
		populate_array(coordsARR,100,0);
		
	/* ------------ */
	

	move(0,0);
	


	while(running){
	
		/* Time management so the code doesnt go too fast. sorry C im slowing you down */
			end = clock();
			program_seconds = ((double)(end-start) / CLOCKS_PER_SEC) * 500; /* BUG: time isnt accurate for some reason :/ I suppose its a good measurment of some time to end the program after a while*/
			if(program_seconds > TIMEMAX){running = 0;}


		/* ------------ */

		/* The part that actually does the matrix stuff */

			
			if(program_seconds < TIMEMAX - 30){
				for(i = 0; i < 25;++i){
					drawStuff(&coordsARR[i],0);
				}
			}
			else{
				for(i = 0; i < 100;++i){
					drawStuff(&coordsARR[i],1);
				}
			}

		/* --------------------------------- */
		
			nsleep(80);


			refresh();
		/*clear();*/

		
    	

		/* */
	}

	endwin();
	
 
    return EXIT_SUCCESS;
}



/* temp comments 
		
		drawStuff(&data);
		printw("%f",seconds);
		struct coords data = {0,5,0,4};


TODO: SORT A TIME SYSTEM OUT SO THE BINARY STUFF CAN BE PRINTED AT A NICE TIME. Also continue NCURSES tutorial -DONE
TODO: MAKE A SYSTEM TO HAVE TRAILING ONES AND ZEROS AND HAVE IT SO IT DOESNT FILL THE WHOLE SCREEN - DONE


*/
