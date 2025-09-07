
//Pranav Chainani
//Application 1
//June 7, 2023
//Implementing college student data set

#include "set.h"

//Creates data set with 3000 possible students
//O(1)
SET *createDataSet()
{
	SET *set = malloc(sizeof(SET));
	assert(set != NULL);
	
	set->count = 0;
	set->length = 3000;
	assert(set->info != NULL);

	return set;
}

//Destroys data set
//O(1)

void destroyDataSet(SET *set)
{
	assert(set != NULL);
	free(set);
	return;
}

//Searches for student using their age
//O(n)

int searchAge(SET *set, int age)
{
	assert(set != NULL);
	int i;

	printf("Searched Age: %d\n", age);

	for(i=0; i<1000; i++)
	{
		if(set->info[i].age == age)
		{
			printf("Found Student: Age: %d ID: %d\n", set->info[i].age, set->info[i].id);
			return 0;
		}
		
		
	}

	printf("No students with that age.");
	return 0;
}

//Inserts students into data set
//O(1)
void insert(SET *set, int age, int id, int i)
{
	assert(set != NULL);
	set->info[i].age = age;
	
	set->info[i].id = id;
	set->count++;

	return;
}

//Deletes students from data set
//O(n)
void deletion(SET *set, int age)
{
	assert(set != NULL);
	int i;
	printf("Deletion of Student Record\n");
	for(i = 0; i<set->length; i++)
	{
		if(set->info[i].age == age)
		{
			printf("Deleted Student Record: Age: %d ID: %d\n", set->info[i].age, set->info[i].id);
			set->info[i].age = '\0';
			set->info[i].id = '\0';
			
			set->count--;
			return;	
		}
	}
	
	printf("No students with that age.");

	return;
}

//Produces the max age gap
//O(1)

void maxAgeGap(int max, int min)
{
	int gap = max-min;
	printf("The max age gap is: %d\n", gap);
}
