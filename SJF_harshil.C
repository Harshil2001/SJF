#include <stdio.h>
#include <stdlib.h>
struct Process
{
  int at;
  int bt;
  struct Process *next;
  struct Process *prev;
};
struct Process *Header =NULL;
struct Process *temp =NULL;
struct Process *t1 =NULL;
struct Process *s =NULL;
void insert(void);
void display(void);
void runproc(void);
long time=0;
int main()
{
    int ch;
    while (1)
    {
        printf("1.Add process   2.Run existing processes   3.Display existing process   4.Exit \n");
        printf("Enter ur choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: insert();
                    break;
            case 2: runproc();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
        }
    }
	return 0;
}
void insert()
{
    struct Process* new_node =(struct Process*) malloc(sizeof(struct Process));
    printf("Enter arival time and burst time: ");
    scanf("%d %d",&new_node->at,&new_node->bt);
    if(Header->next == NULL)
    {
        Header->next=new_node;
        new_node->next=NULL;
        new_node->prev=Header;
        return;
    }
    temp=Header->next;
    while(temp!=NULL)
    {
        if(new_node->at > temp->at)
        {
            t1=temp;
            temp=temp->next;
        }
        else
        {
            new_node->next=temp;
            new_node->prev=t1;
            temp->prev=new_node;
            t1->next=new_node;
            return;
        }
    }
    new_node->next=NULL;
    new_node->prev=t1;
    t1->next=new_node;
    return;
}
void runproc()
{
    temp=Header->next;
    s=temp;
    if(time==0)
    {
        time += temp->bt + temp->at;
        t1=temp->next;
        Header->next=t1;
        t1->prev=Header;
        free(temp);
        return;
    }
    while(temp->at <= time)
    {
        if(s->bt > temp->bt)
            s=temp;
    }
    t1=s->next;
    temp=s->prev;
    time += s->bt;
    t1->prev=temp;
    temp->next=t1;
    free(s);
    return;
}
void display()
{
    temp=Header;
    printf("completion time is: %long\n",time);
    while(temp!=NULL)
    {
        printf("%d %d \n",temp->at,temp->bt);
    }
}
