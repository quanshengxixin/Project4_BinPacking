#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MIN 50
#define ENTRIES 1000

typedef int data_type;

/* generate a random floating point number from min to max */
data_type randfrom() 
{
    data_type range = (MAX - MIN); 
    data_type div = RAND_MAX / range;
    return MIN + (rand() / div);
}

int main(void){
	
	FILE *fp = fopen("bins.txt", "w");
	int i;
	for(i=0;i<ENTRIES;i++){
		fprintf(fp, "%d\n", randfrom());
	}
	
	return 0;
}
