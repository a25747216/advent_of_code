/* day1_2.c
 * same rules, but find out the position of the first character that causes
 * him to enter the basement
 */

#include <stdio.h>
#include <stdlib.h>
#define BASEMENT -1
int main(void) {
    int floor = 0;
    int cnt = 0;
    int ch;
    while (((ch = getchar()) != EOF) && (floor != BASEMENT)) {
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
	cnt++;
    }
    printf("The position is %d\n", cnt);

    return EXIT_SUCCESS;
}
