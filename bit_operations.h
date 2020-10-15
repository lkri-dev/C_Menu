#include <stdio.h>

/*
Example for bit operations in C.
*/

int shift (int a) {
	printf("Before any shift %d\n", a);
	a |= (1 << 6); //Set a bit
	//printf("%u ",num&maxPow ? 1 : 0);
	printf("After a |= (1 << 6); //Set a bit %d\n", a);
	a &= ~(1 << 6); //clear a bit
	printf("After a &= ~(1 << 6); //clear a bit %d\n", a);
    a ^= (1 << 4); //toggle bit
	printf("After a ^= (1 << 4); //toggle bit %d\n", a);
	a <<= 2; //left shift whold byte[]
	printf("After a <<= 2; //left shift whole byte[] %d\n", a);
	a >>= 2; //right shift whold byte[]
	printf("After a >>= 2; //right shift whole byte[] %d\n", a);
	return a;
}