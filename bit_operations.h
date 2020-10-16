#include <stdio.h>

/*
Example for bit operations in C.
*/
bool bit_check_operation (int check, int bit) {
	if (bit == 0) return check == 0;
	bool bit_check = (1 << bit) == (check & (1 << bit));
	return bit_check;
}

int shift (int a) {
	bool check;
	printf("Before any shift %d\n", a);
	
	a |= (1 << 6); //Set a bit
	check = bit_check_operation(a, 6);
	printf("check bit %s \n", check ? "true" : "false");
	printf("After a |= (1 << 6); //Set a bit %d\n", a);
	
	a &= ~(1 << 6); //clear a bit
	check = bit_check_operation(a, 0);
	printf("check bit %s \n", check ? "true" : "false");
	printf("After a &= ~(1 << 6); //clear a bit %d\n", a);
    
	a ^= (1 << 4); //toggle bit
	check = bit_check_operation(a, 4);
	printf("check bit %s \n", check ? "true" : "false");
	printf("After a ^= (1 << 4); //toggle bit %d\n", a);
	
	a <<= 2; //left shift whold byte[]
	check = bit_check_operation(a, 6);
	printf("check bit %s \n", check ? "true" : "false");
	printf("After a <<= 2; //left shift whole byte[] %d\n", a);
	
	a >>= 2; //right shift whold byte[]
	check = bit_check_operation(a, 4);
	printf("check bit %s \n", check ? "true" : "false");
	printf("After a >>= 2; //right shift whole byte[] %d\n", a);
	
	return a;
}