#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>



#define LIST struct list

extern pthread_mutex_t mutex;




typedef union info
{
        float budget;
        char location[20];
        int endtime[2];
} INFO;


struct list
{
        char tasks[20];
        int hours;
        int minutes;
        int priority;
        INFO info;
        LIST *next;
};
LIST *heads[3];






int main();
void userinfo(void);
void insert();
void list();
void listbytime(void);
void delete(void);
int check_duplicate(char *);
void deleteall();
void save_to_file(char *);
void read_file(char *);
void deleteall2();
void listbackwards();
void listbackwards2();
void *autosave(void *);
void binary();


