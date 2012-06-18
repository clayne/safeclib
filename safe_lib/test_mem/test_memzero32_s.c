/*------------------------------------------------------------------
 * test_memzero32_s
 *
 *
 *=
 *------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

#include "../include/safe_mem_lib.h"

#define debug_printf printf

#define LEN   ( 512 )



int main()
{
    errno_t rc;
    uint32_t i;
    uint32_t len; 

    uint32_t mem1[LEN];

/*--------------------------------------------------*/

    rc = memzero32_s(NULL, LEN);
    if (rc != ESNULLP) {
        debug_printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__, rc);
    }

/*--------------------------------------------------*/

    rc = memzero32_s(mem1, 0);
    if (rc != ESZEROL) {
        debug_printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__, rc);
    }

/*--------------------------------------------------*/

    rc = memzero32_s(mem1, RSIZE_MAX_MEM32+1);
    if (rc != ESLEMAX) {
        debug_printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__, rc);
    }

/*--------------------------------------------------*/

    for (i=0; i<LEN; i++) { mem1[i] = 33; }

    len = 1;
    rc = memzero32_s(mem1, len);
    if (rc != EOK) {
        debug_printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__, rc);
    }

    /* verify mem1 was zeroed */
    for (i=0; i<len; i++) {
        if (mem1[i] != 0) {
            printf("%d - %d m1=%d \n",
                 __LINE__, i, mem1[i]);
        }
    }

/*--------------------------------------------------*/

    for (i=0; i<LEN; i++) { mem1[i] = 33; }

    len = 2;
    rc = memzero32_s(mem1, len);
    if (rc != EOK) {
        debug_printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__, rc);
    }

    /* verify mem1 was zeroed */
    for (i=0; i<len; i++) {
        if (mem1[i] != 0) {
            printf("%d - %d m1=%d \n",
                 __LINE__, i, mem1[i]);
        }
    }

/*--------------------------------------------------*/

    for (i=0; i<LEN; i++) { mem1[i] = 33; }

    len = 3;
    rc = memzero32_s(mem1, len);
    if (rc != EOK) {
        debug_printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__, rc);
    }

    /* verify mem1 was zeroed */
    for (i=0; i<len; i++) {
        if (mem1[i] != 0) {
            printf("%d - %d m1=%d \n",
                 __LINE__, i, mem1[i]);
        }
    }

/*--------------------------------------------------*/

    for (i=0; i<LEN; i++) { mem1[i] = 33; }

    len = LEN;
    rc = memzero32_s(mem1, len);
    if (rc != EOK) {
        debug_printf("%s %u   Error rc=%u \n",
                     __FUNCTION__, __LINE__, rc);
    }

    /* verify mem1 was zeroed */
    for (i=0; i<len; i++) {
        if (mem1[i] != 0) {
            printf("%d - %d m1=%d \n",
                 __LINE__, i, mem1[i] );
        }
    }

/*--------------------------------------------------*/
/*--------------------------------------------------*/

    return (0);
}

