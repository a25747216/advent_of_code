/* day3_2.c
 * Reads a bunchs of '^' 'v' '<' '>', and count every points have been passed, include origin.
 * Similar to first star, but now have a robo-santa, Santa go first, robo-santa go next.
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZES 1000

int main(void) {
    bool records[SIZES][SIZES];
    bool isSanta = true;
    size_t cnt = 0;
    int santar, robor, santac, roboc;
    int* rp;
    int* cp;
    int ch;
    
    /* initialize */
    for (santar = 0; santar < SIZES; santar++) {
	for (santac = 0; santac < SIZES; santac++) {
	    records[santar][santac] = false;
	}
    }
    
    santar = santac = roboc = robor = 500;
    records[santar][santac] = true;

    rp = &santar;
    cp = &santac;
    
    /* travres */
    while (((ch = getchar()) != EOF) && (*rp < SIZES && *rp >= 0) && (*cp < SIZES && *cp >= 0)) {
	if (isSanta) {
	    rp = &santar;
	    cp = &santac;
	    isSanta = false;
	} else {
	    rp = &robor;
	    cp = &roboc;
	    isSanta = true;
	}

	
	switch(ch) {
	case '^':
	    (*rp)--;
	    break;
	case '>':
	    (*cp)++;
	    break;
	case '<':
	    (*cp)--;
	    break;
	case 'v':
	    (*rp)++;
	    break;
	default:
	    break;
	}
	records[*rp][*cp] = true;
    }

    /* count */
    for (santar = 0; santar < SIZES; santar++) {
	for (santac = 0; santac < SIZES; santac++) {
	    if (records[santar][santac]) cnt++;
	}
    }

    printf("The total is %zd\n", cnt);

    return EXIT_SUCCESS;
}
