//Pranav Chainani
//Application 1
//June 7, 2023
//Initializing functions and structs


#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define maxcapacity 3000

typedef struct info{
	int age;
	int id;
} INFO;

typedef struct set{
	int length;
	int count;
	INFO info[maxcapacity];
} SET;


SET *createDataSet();

void destroyDataSet(SET *set);

int searchAge(SET *set, int age);

void insert(SET *set, int age, int id, int i);

void deletion(SET *set, int i);

void maxAgeGap(int max, int min);


