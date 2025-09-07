
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void save_to_file(char *name)
{       
        FILE *outfp;
        LIST *p;
        int i;
	outfp = fopen(name, "w");
        if((outfp = fopen(name, "w")) == NULL)
        {       
                printf("Cannot open\n");
        }
        
        for(i=0; i<3; i++)
        {       
                p = heads[i];
                while(p != NULL)
                {       
                        fprintf(outfp, "%s ", p->tasks);
                        fprintf(outfp, "%d ", p->priority);
                        
                        fprintf(outfp, "%d:%02d ", p->hours, p->minutes);
                        if(p->hours < 12)
                        {       
                                fprintf(outfp, "%.2f\n", p->info.budget);
                        }
                        if(p->hours >= 12 && p->hours <= 20)
                        {       
                                fprintf(outfp, "%s\n", p->info.location);
                        }
                        if(p->hours > 20)
                        {       
                                fprintf(outfp, "%d:%02d\n", p->info.endtime[0], p->info.endtime[1]);
                        } 
                        p = p->next;
                }
        
	}
	fclose(outfp);
	return;
}
void read_file(char *name)
{
        FILE *fp;
        char c;
        LIST temp;


        fp = fopen(name, "r");
        if(fp == NULL)
        {
                printf("Cannot open\n");
                return;
        }

        while(fscanf(fp, "%s", temp.tasks) == 1)
        {

                fscanf(fp, "%d", &temp.priority);
                fscanf(fp, "%d", &temp.hours);
                fscanf(fp, "%c", &c);
                fscanf(fp, "%d", &temp.minutes);
                if(temp.hours < 12)
                {
                        fscanf(fp, "%f", &temp.info.budget);
                }
                else if(temp.hours >= 12 && temp.hours <= 20)
                {
                        fscanf(fp, "%s", temp.info.location);
                }
                else
                {
                        fscanf(fp, "%d", &temp.info.endtime[0]);
                        fscanf(fp, "%c", &c);
                        fscanf(fp, "%d", &temp.info.endtime[1]);
                }

        	insert(temp);
        }
                                                                                                                                                                                                                     

	fclose(fp);
}

void *autosave(void *arg)
{
	char *filename = (char*)arg;
	FILE *fp;
	LIST *p;
	int i;
	while (1)
	{
		printf("test");		
		pthread_mutex_lock(&mutex);
		fp = fopen(filename, "wb");
		for(i=0; i<3; i++)
		{
			p = heads[i];
			while(p != NULL)
			{
				fwrite(p, sizeof(LIST), 1, fp);
				p = p->next;
			}	 	
		}
		fclose(fp);
		pthread_mutex_unlock(&mutex);
		sleep(5);
		
	}
}

void binary(char *arg)
{
	
        FILE *fp;
        LIST p;
        int i;
        fp = fopen(arg, "rb");
	
	while(0 < fread(&p, sizeof(LIST), 1, fp))
	{
		printf("%s ", p.tasks);
        	printf("%d ", p.priority);

        	printf("%d:%02d ", p.hours, p.minutes);
                if(p.hours < 12)
                {
                	printf("%.2f\n", p.info.budget);
                }
                if(p.hours >= 12 && p.hours <= 20)
                {
                	printf("%s\n", p.info.location);
                }
                if(p.hours > 20)
                {
                	printf("%d:%02d\n", p.info.endtime[0], p.info.endtime[1]);
                }
               
        }

        
        fclose(fp);
        return;
}
	
	












                                                                                                                                                                                                                                      
