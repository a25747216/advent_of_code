/* day1_1.c
 */

/* start from floor 0, "(" go up, ")" go down. */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int floor = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
	switch (ch) {
	case '(':
	    floor++;
	    break;
	case ')':
	    floor--;
	    break;
	default:
	    break;
	}
    }
    printf("floor is %d\n", floor);

    return EXIT_SUCCESS;
}
