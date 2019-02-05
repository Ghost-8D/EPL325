/********************************************************
 * AVX2_char_count_std.c
 * Login to machine 103ws??.in.cs.ucy.ac.cy 
 * Compile using:
 * gcc -O3 -mavx2 AVX2_char_count_std.c -o AVX2_char_count_std.out
 * Author: Petros Panayi, PhD, CS, UCY, Jan. 2019
 ***************************************************************************
 * Reference: https://software.intel.com/sites/landingpage/IntrinsicsGuide/
 ***************************************************************************/

#include <immintrin.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "support.h"

#define ARRAY_SIZE_MB 1024*1024
#define COMPARE_VALUE 'a'		

void initData(char * vector, int size) {
	int i;
	srand (time(NULL));
	for (i = 0; i < size; i++){
		vector[i] = rand()%26+'a';
		//vector[i] = 'a';
	}
}

void printArray(char * charArray, int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%c", charArray[i]);
	printf("\n");
}

int char_count_serial(char * vector, int size, char c){
	int i, sum =0;
	for (i=0; i<size; i++)
			if (vector[i] == c) sum++;
	return sum;
}

int char_count_AVX2(char * vector, int size, char c){
	int sum =0;
	/*** ADD YOUR CODE HERE ***/
    
    
    
    
    
    
    
    
    
    
	return sum;
}

int main(int argc, char **argv) {
	unsigned long long int arraySize, sum, method = 0;
	if (argc == 3) {
		method = atoi(argv[1]);
		arraySize = atoi(argv[2])*ARRAY_SIZE_MB;
	} else {
		printf("Usage: ./a.out Method NumberOfCharsInMB\n");
		return 0;
	}
	 __attribute__ ((aligned (256))) char * charArray = (char *) malloc(sizeof(char) * arraySize);
	initData(charArray, arraySize);
	//printArray(charArray, arraySize);
	if (method == 0){
		//startTime(0);
		sum = char_count_serial(charArray, arraySize,COMPARE_VALUE);
		//stopTime(0); 
		printf("Serial Method[%d]:Found %d '%c'.\n",arraySize,sum,COMPARE_VALUE);
		// fprintf(stderr, is needed since time command prints on stderr
		// Collect the data by using ./runAll.sh 2> output.txt
		fprintf(stderr,"Serial Method[%d]:Found %d '%c'.\n",arraySize,sum,COMPARE_VALUE);
		//elapsedTime(0);
	}else if (method == 1){
		//startTime(0);
		sum = char_count_AVX2(charArray, arraySize,COMPARE_VALUE);
		//stopTime(0); 
		printf("AVX2 Method[%d]:Found %d '%c'.\n",arraySize,sum,COMPARE_VALUE);
		fprintf(stderr,"AVX2 Method[%d]:Found %d '%c'.\n",arraySize,sum,COMPARE_VALUE);
		//elapsedTime(0);
	}
  return 0;
}
