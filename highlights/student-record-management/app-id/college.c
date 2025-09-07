//Pranav Chainani
//June 7, 2023
//Application 2
//Implementation of main function

#include "set.h"

int main() 
{
	//creates data set of max 3000 students

	SET* set = createDataSet(3000);
	assert(set != NULL);
	srand(time(NULL));
	
	int i;
	int randAge, min, max; 
	randAge = min = max = (rand() % 13) + 18;
	int randID = (rand() % 2000 +1);
	int Next;
	insert(set, randAge, randID, 0);
	

	//generates 1000 students
	//O(n)
	for(i=1; i<1000; i++)
	{
		//random ID generator
		randID = (rand() % 2000 + 1);
		Next = set->info[i-1].id+((rand()%2000 +1));

			
		insert(set, randID, Next, i);

		
	
			
	
	}
		
	randID = (rand() % 2000 + 1) ;
	searchID(set, randID);
	deletion(set, randID);
	


	destroyDataSet(set);
}

	
