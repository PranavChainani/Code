//Lab 10
//Pranav Chainani
//Tuesday 2:15 PM
#include "list.h"

LIST *heads[3] = {NULL, NULL, NULL};



pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main (int argc, char *argv[])
{
        int option;
        if(argc==1)
        {
                printf("The name of the file is missing!\n");
                return 1;
        }

        read_file(argv[1]);
	
	
	pthread_mutex_init(&mutex, NULL);
	pthread_t thread;
	pthread_create(&thread, NULL, autosave, argv[1]);

	
        while (1)
        {
                printf ("enter option:\n1 to insert\n2 to list\n3 to list by times\n4 to delete a task\n5 to list backwards\n6 to show autosave\n0 to quit\n");
                scanf("%d", &option);
                switch (option)
                {
                        case 1:
                               pthread_mutex_lock(&mutex);
				userinfo();
				pthread_mutex_unlock(&mutex);
                                break;

                        case 2:
                              
				list();
                               
				break;

                        case 3:
                                
				listbytime();
                                
				break;
                        case 4:
				pthread_mutex_lock(&mutex);

                                delete();
				pthread_mutex_unlock(&mutex);
                                break;
                        case 5:
                                pthread_mutex_lock(&mutex);

				listbackwards2();
				pthread_mutex_unlock(&mutex);
				break;
                        case 6:
				pthread_mutex_lock(&mutex);
				binary(argv[1]);
				pthread_mutex_unlock(&mutex);
				break;
			case 0:
				pthread_mutex_lock(&mutex);
                                save_to_file(argv[1]);
                                
				deleteall2();
                                pthread_mutex_unlock(&mutex);

                                return 0;

                }

        }




}



