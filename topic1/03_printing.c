#include <stdio.h>

int func(int x) {
	printf("hello world\n");
	return 1;
}

int main ( ) {
	int area = 25;
	int * pArea = &area;  
    long x =1000000000000;
	double y = 3.14159265358979323846;
	printf("x = %ld\n", x);
	printf("y = %.9f\n", y);
	printf("area = %d\n", area);
    printf("area = %d\n", *pArea);
	printf("pArea = %p\n", pArea);
    printf("pArea = %ld\n", (unsigned long)pArea);
}