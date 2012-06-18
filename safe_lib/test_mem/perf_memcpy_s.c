/*
 * perf_memcpy_s.c	
 */ 

#include <stdio.h>
#include <string.h>
#include <time.h>

#include "safe_types.h"
#include "safe_mem_lib.h"


#define LEN   ( 1024 * 10 )

uint8_t  mem1[LEN];
uint8_t  mem2[LEN];


static void timing_loop (uint32_t len, uint32_t loops)
{
    errno_t rc;
    uint32_t i;

    clock_t clock_start; 
    clock_t clock_end;

    clock_t sl_clock_diff;
    clock_t sd_clock_diff;

    double sl_clock_dur;
    double sd_clock_dur;


    for (i=0; i<LEN; i++) { mem1[i] = 33; }
    for (i=0; i<LEN; i++) { mem2[i] = 44; }

//    printf("\n Timing %d byte copy, %u loops \n", len, loops);

    /*
     * Safe C Lib Routine
     */ 
    clock_start = clock();
    for (i=0;i<loops; i++) {
       rc = memcpy_s(mem1, len, mem2, len);
    }
    clock_end = clock();

    /*
     * Note that background stuff continues to run, i.e. interrupts, so 
     * we need to compute average time per loop
     */ 
    sl_clock_diff = (clock_end - clock_start) / loops;



    /*
     * Standard C Routine
     */ 
    clock_start = clock();
    for (i=0;i<loops; i++) {
       memcpy(mem1, mem2, len);
    }
    clock_end = clock();

    /*
     * Note that background stuff continues to run, i.e. interrupts, so 
     * we need to compute average time per loop
     */ 
    sd_clock_diff = (clock_end - clock_start) / loops;


    /* convert to seconds */ 
    sl_clock_dur = ((double)(sl_clock_diff) / CLOCKS_PER_SEC);
    sd_clock_dur = ((double)(sd_clock_diff) / CLOCKS_PER_SEC);

    printf("%u  %u  memcpy_s %1.9f  memcpy %1.9f  diff %1.9f \n", 
           loops, 
           len,
           sl_clock_dur,  
           sd_clock_dur, 
           (sl_clock_dur - sd_clock_dur) );  

    return;
} 



int main()
{
    uint32_t loops;
    rsize_t len;

/*--------------------------------------------------*/
/*--------------------------------------------------*/

    printf("\n\n");

    loops = 400;

    len = 1024;
    timing_loop(len, loops);

    len = 1024 * 2;
    timing_loop(len, loops);

    len = 1024 * 3;
    timing_loop(len, loops);

    len = 1024 * 4;
    timing_loop(len, loops);

    len = 1024 * 5;
    timing_loop(len, loops);

    len = 1024 * 6;
    timing_loop(len, loops);

    len = 1024 * 7;
    timing_loop(len, loops);

    len = 1024 * 8;
    timing_loop(len, loops);

/*--------------------------------------------------*/

    printf("\n\n");

    loops = 600;

    len = 1024;
    timing_loop(len, loops);

    len = 1024 * 2;
    timing_loop(len, loops);

    len = 1024 * 3;
    timing_loop(len, loops);

    len = 1024 * 4;
    timing_loop(len, loops);

    len = 1024 * 5;
    timing_loop(len, loops);

    len = 1024 * 6;
    timing_loop(len, loops);

    len = 1024 * 7;
    timing_loop(len, loops);

    len = 1024 * 8;
    timing_loop(len, loops);

/*--------------------------------------------------*/

    printf("\n\n");

    loops = 800;

    len = 1024;
    timing_loop(len, loops);

    len = 1024 * 2;
    timing_loop(len, loops);

    len = 1024 * 3;
    timing_loop(len, loops);

    len = 1024 * 4;
    timing_loop(len, loops);

    len = 1024 * 5;
    timing_loop(len, loops);

    len = 1024 * 6;
    timing_loop(len, loops);

    len = 1024 * 7;
    timing_loop(len, loops);

    len = 1024 * 8;
    timing_loop(len, loops);

/*--------------------------------------------------*/
/*--------------------------------------------------*/

    return (0);
}

