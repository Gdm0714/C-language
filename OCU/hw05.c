#include<stdio.h>
int reset(void);
int next(int);

int index = 1;

void main(void) {
	auto int index, jdex;
	index = reset();
	for (jdex = 1; jdex <= 3; jdex++) {
		printf(" % d \n", index, jdex, next(index));
	}
}
int reset(void) {
	return (index);
}

int next(int jdx) {
	jdx = ++index;
	return(jdx);
}