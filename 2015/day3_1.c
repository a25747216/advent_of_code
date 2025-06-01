/* day3_1.c
 * Reads a bunchs of '^' 'v' '<' '>', and count every points have been passed, include origin.
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZES 1000

int main(void) {
    bool records[SIZES][SIZES];
    size_t cnt = 0;
    int r, c;
    int ch;
    
    /* initialize */
    for (r = 0; r < SIZES; r++) {
	for (c = 0; c < SIZES; c++) {
	    records[r][c] = false;
	}
    }

    r = c = 500;
    records[r][c] = true;

    /* travres */
    while (((ch = getchar()) != EOF) && (r < SIZES && r >= 0) && (c < SIZES && c >= 0)) {
	switch(ch) {
	case '^':
	    r--;
	    break;
	case '>':
	    c++;
	    break;
	case '<':
	    c--;
	    break;
	case 'v':
	    r++;
	    break;
	default:
	    break;
	}
	records[r][c] = true;
    }

    /* count */
    for (r = 0; r < SIZES; r++) {
	for (c = 0; c < SIZES; c++) {
	    if (records[r][c]) cnt++;
	}
    }

    printf("The total is %zd\n", cnt);

    return EXIT_SUCCESS;
}
