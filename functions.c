#include "require.h"

void drawStuff(struct coords* data,const int flood){

    int Y_MAX = 64; /* hardcoded columns that exist on my terminal */
    int p_y;

    /* Get the last point of the line and set p_y to its position, this is what removes characters with spaces */

    if(data->y < data->l){
         p_y = (Y_MAX - (data->l - data->y));  /* two bits are stuck on the terminal for some reason */
     }else{p_y = data->y - data->l - 1;}
    
    /*---------------------------------------------------------------------------------------------------------*/

     /* A hard coded mess to remove the last two digit bug */
    
        mvdelch(Y_MAX - 4, data->x);
    
    /*---------------------------------------------------------------------------------------------------------*/

    /* Draw ones and zeros */
    
        move(data->y,data->x);
        printw("%d",data->z);
        mvdelch(p_y, data->x);
   
    /*---------------------*/


    /* Incrementation */
        if(flood){

            data->y++;
            data->x += (data->x > 100) ? 1 : 0; 
            data->z = randomRange(0,1);
        }else{
            data->y++;
            data->z = randomRange(0,1);
        }
    /*----------------*/


    if(data->y > Y_MAX){data->y = 0;}
    
}

int nsleep(long miliseconds){
   struct timespec req, rem;

   if(miliseconds > 999)
   {   
        req.tv_sec = (int)(miliseconds / 1000);                            
        req.tv_nsec = (miliseconds - ((long)req.tv_sec * 1000)) * 1000000; 
   }   
   else
   {   
        req.tv_sec = 0;                         
        req.tv_nsec = miliseconds * 1000000;   
   }   

   return nanosleep(&req , &rem);
}

int randomRange(const int MIN, const int MAX){

    return rand() % (MAX + 1 - MIN) + MIN;

}

void populate_array(struct coords* data,const int length, const int debug){
    int i;
    struct coords TEMPSTRUCT = {0,0,0,0};

    for(i = 0; i < length; i++){
        TEMPSTRUCT.x = randomRange(5,248);
        TEMPSTRUCT.y = randomRange(5,62);
        TEMPSTRUCT.l = randomRange(1,5);

        data[i] = TEMPSTRUCT;
    }
    if(debug){

        for(i = 0; i < length; i++){
            printw("%d\n",data[i].x);
        }
    }

    



}


