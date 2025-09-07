
#include "list.h"


void userinfo()
{
        LIST p;
        printf("Enter Task: ");

        __fpurge(stdin);
        scanf("%[^'\n']", p.tasks);

        printf("Enter Priority: ");

        scanf("%d", &p.priority);
        if(check_duplicate(p.tasks)==1)
        {
                return;
        }

        printf("Enter hour: ");


        scanf("%d", &p.hours);

        if(p.hours < 0 || p.hours > 23)
        {
                printf("Invalid time");
                return;
        }

        printf("Enter minute: ");
        scanf("%d", &p.minutes);

        if(p.minutes < 0 || p.minutes > 59)
        {
                printf("Invalid time");
                return;
        }

        if(p.hours < 12)
        {
                printf("Enter budget: ");
                scanf("%2f", &p.info.budget);

        }

        if(p.hours>= 12 && p.hours <= 20)
        {
                printf("Enter location: ");
                scanf("%s", &p.info.location);

        }

        if(p.hours > 20)

        {
                printf("Enter end time:\n");
                printf("Hour:\n");

                scanf("%d", &p.info.endtime[0]);
                printf("Minute:\n");
                scanf("%d", &p.info.endtime[1]);

        }

        insert(p);
}


void insert(LIST node)
{


        LIST *p;
        LIST *q;
        LIST *z;




        q = (LIST *)malloc(sizeof(LIST));
        *q = node;



        z = p = heads[q->priority-1];;

        while(z != NULL)
        {
                if(z->hours > q->hours)
                {
                        break;
                }
                else if(z->hours == q->hours)
                {
                        if(z->minutes > q->minutes)
                        {
                                break;
                        }
                }
                p = z;

                z = z->next;
        }

        if(z==heads[q->priority-1])
        {
                q->next = heads[q->priority-1];
                heads[q->priority-1] = q;
        }
        else
        {
                q->next = z;
                p->next = q;


        }
        return;
}

int check_duplicate(char task[20])
{
        int i;
        for(i=0; i<3; i++)
        {
                LIST *q = heads[i];
                while(q != NULL)
                {
                        if(strcmp(task, q->tasks)==0)
                        {
                                printf("Task exists already!");
                                return 1;
                        }

                        else
                        {
                                return 0;
                        }

                        q = q->next;

                }

        }
                                                                                                                                                                                                                                       
}

void list()
{

        int i;
        int z;
        for(i=0; i<3; i++)
        {
                LIST *p = heads[i];
                while(p != NULL)
                {
                        printf("Priority: %d - %s, %d:%d, ", p->priority, p->tasks, p->hours, p->minutes);
                        if(p->hours < 12)
                        {
                                printf(" %.2f\n", p->info.budget);
                        }

                        if(p->hours>=12 && p->hours <=20)
                        {
                                printf("%s\n", p->info.location);
                        }
                        if(p->hours > 20)
                        {
                                for(z=0; z<2; z++)
                                {
                                        printf("%d: ", p->info.endtime[z]);
                                }
                        } 
                        p = p->next;
                }
        }
}


void listbytime()
{       
        LIST *p;
        
        
        int hour_search;
        int minute_search;
        int i;
        int z;
        printf("What hour would you like to search by? ");
        scanf("%d", &hour_search);

        for(i=0;i<3;i++)
        {
                p = heads[i];
                while(p != NULL)
                {
                        if(hour_search == p->hours)
                        {

                                printf("Priority: %d - %s, %d:%d ",p->priority,  p->tasks, p->hours, p->minutes);

                                if(p->hours < 12)
                                {
                                        printf("%.2f", p->info.budget);


                                }

                                if(p->hours>= 12 && p->hours <= 20)
                                {
                                        printf("%s", p->info.location);
                                }

                                if(p->hours > 20)
                                {
                                        for(z=0; z<2; z++)
                                        {
                                                printf("%d", p->info.endtime[z]);
                                        }
                                }
			}
			else    
                        {       
                                printf("No task with that time.");
                                return;
                        
                        
                        }
		}
	}
}       			

void delete()
{                         
	int i;
        LIST *p;
        LIST *q;
        LIST temp;
        printf("What task do you want to delete: ");
        scanf("%s", temp.tasks);
        int j;

        for(i=0; i<3; i++)
        {



                p = q = heads[i];


                        while(p != NULL)
                        {
                                if(strcmp(p->tasks, temp.tasks)==0)
                                {
                                        printf("%s has been deleted\n", temp.tasks);
                                        j = i;
                                        i = 3;
                                        break;
                                }
                                q = p;
                                p = p->next;
                        }

        }
        if(p==NULL)
        {
                return;
        }
        else if(p==heads[j])
        {
                heads[j] = heads[j]->next;
                free(p);

        }
        else
        {
                q->next = p->next;
                free(p);

        }
}

void deleteall2()
{
        int i;
        for (i=0; i<3; i++)
        {
                deleteall(heads[i]);
        }
}
void deleteall(LIST *p)
{

        if (p == NULL)
        {
                return;
        }
        else
        {
                deleteall(p->next);
                free(p);
        }

}
                                                                                                                                                                                                                   
               
                
                               
                                        
                                            
                                                      
                                                                      
                                                                                        
                                                                                                        
void listbackwards(LIST *p)
{

        if(p==NULL)
        {
                return;
        }
        else
        {
                listbackwards(p->next);
                printf("Priority: %d, Task:  %s, %d: %d ", p->priority, p->tasks, p->hours, p->minutes);


                if(p->hours < 12)
                {
                        printf("Budget: %.2f\n", p->info.budget);
                }
                else if(p->hours >= 12 && p->hours <= 20)
                {
                        printf("Location: %s\n", p->info.location);
                }
                else
                {
                        printf("Endtime: %d:%d\n", p->info.endtime[0], p->info.endtime[1]);


                }
        return;
        }
}

void listbackwards2()
{
        int i;
        for(i=0; i<3; i++)
        {
                listbackwards(heads[i]);
        }
}


                                                                                                                                                                                                                           
