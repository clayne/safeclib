/*------------------------------------------------------------------
 * test_gmtime_s
 *
 *------------------------------------------------------------------
 */

#include "test_private.h"
#include "safe_lib.h"

int test_gmtime_s (void)
{
    int errs = 0;
    time_t timer;
    struct tm tm;
    struct tm *tmptr;

    timer = time(NULL);
    
/*--------------------------------------------------*/

    tmptr = gmtime_s(&timer, NULL);
    ERRNO(ESNULLP);
    PTRNULL(tmptr);

    tmptr = gmtime_s(NULL, &tm);
    ERRNO(ESNULLP);
    PTRNULL(tmptr);

/*--------------------------------------------------*/

    timer = 0;
    tmptr = gmtime_s(&timer, &tm);
    ERRNO(0);
    PTRNN(tmptr);

    timer = -1;
    tmptr = gmtime_s(&timer, &tm);
    ERRNO(EOVERFLOW);
    PTRNULL(tmptr);

    {
        struct tm *tm = gmtime(&timer);
        memset(tm, 0, sizeof(struct tm));
        tm->tm_year = 10000;
        timer = mktime(tm);
        debug_printf("year 10000 = %ld\n", timer);
        timer++;
    }

    /* eg. 313392063599L */
    tmptr = gmtime_s(&timer, &tm);
    ERRNO(EOVERFLOW);
    PTRNULL(tmptr);

/*--------------------------------------------------*/
    
    return (errs);
}

#ifndef __KERNEL__
/* simple hack to get this to work for both userspace and Linux kernel,
   until a better solution can be created. */
int main (void)
{
    return (test_gmtime_s());
}
#endif