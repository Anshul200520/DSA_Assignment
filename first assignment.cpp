#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	
	int number;
	srand(time(NULL));
	
	number = rand()%10;
	printf("%d\n",number);
	return 0;  
}
