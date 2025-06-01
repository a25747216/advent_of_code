/* day2_2.c
 * Give length l, width w and height h. What's wrapping paper need.
 * How to calculate wrapping paper?
 * similar to first star
 * (l * w * h) + 2 * (smallest(l, w, h) + the second smallest(l, w, h))
 */

#include <stdio.h>
#include <stdlib.h>

unsigned int calculate(int length, int width, int height);
unsigned int small(int length, int width, int height);

int main(void) {
    int l, w, h;
    unsigned int sum = 0;
    while (scanf("%dx%dx%d", &l, &w, &h) != EOF) {
	sum += calculate(l, w, h);
    }

    printf("Totally need %u feet\n", sum);

    return EXIT_SUCCESS;
}


unsigned int calculate(int length, int width, int height) {
    unsigned int sum = 0;
    
    sum += (length * width * height);
    sum += small(length, width, height);

    return sum;
}

unsigned int small(int length, int width, int height) {
    int s1, s2;
    unsigned int sum = 0;

    if (length <= width && length < height) {
	s1 = length;
	s2 = (width < height) ? width : height;
    } else if (width <= length && width <= height) {
	s1 = width;
	s2 = (length < height) ? length : height;
    } else {
	s1 = height;
	s2 = (length < width) ? length : width;
    }

    return 2 * (s1 + s2);
}
