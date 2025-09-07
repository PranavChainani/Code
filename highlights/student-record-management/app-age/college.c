//Pranav Chainani
//Application 1
//June 7, 2023
//Implementing main function


#include "set.h"

int main() 
{
	//creates data set of max 3000 students

	SET* set = createDataSet();
	assert(set != NULL);
	srand(time(NULL));
	
	int i;
	 
	int max = 0;
	int min = 999999;
	
	int randAge = (rand()%13) +18;

	
	int randID = (rand() % 2000) +1;
	int Next;
	
	insert(set, randAge, randID, 0);
	

	//generates 1000 students
	//O(n)
	for(i=1; i<1000; i++)
	{
		//random age generator
		randAge = (rand()%13) +18;		
		Next = set->info[i-1].id+((rand()%2000) +1);

		if(randAge > max)
		{
			max = randAge;
		}
		if(randAge < min)
		{
			min = randAge;
		}
		
		insert(set, randAge, Next, i);

		
	
			
	
	}
	
	 	
	printf("%d\n", max);


	
	randAge = (rand()%13) +18;
	searchAge(set, randAge);
	deletion(set, randAge);
	maxAgeGap(max, min);	

	destroyDataSet(set);
	
	return 0;
}

	
