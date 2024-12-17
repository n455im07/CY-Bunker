#include <stdio.h>
#include <unistd.h>

void slowPrint(char* words,int speed){
	while(*words){
		putchar(*words);
		fflush(stdout);
		usleep(speed);
		words++;
	}
	putchar('\n');
}