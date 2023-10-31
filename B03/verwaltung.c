#include "verwaltung.h"
#include <stdio.h>
#include <stdlib.h>

struct node *mainList, *ifm_students, *students_sorted_by;
struct node *root, *prev;

void addStudentMainList(stdnt student)
{
    if (mainList == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->stdnt = student;
        mainList = newNode;
        root = newNode;
    }
    else
    {

        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->stdnt = student;
        mainList = root;

        while (mainList != NULL)
        {
            prev = mainList;

            if (mainList->next == NULL)
            {
                newNode->prev = prev;
                mainList->next = newNode;
                return;
            }
            else
            {
                
                mainList = mainList->next;
            }
        }
    }
}

void printMainList()
{
    int counter = 0;

    mainList = root;
    while (mainList != NULL)
    {
        printf("prev-> %-10d | Node %d: %-10d | next-> %-10d\n",mainList->prev,counter,mainList,mainList->next);
        mainList = mainList->next;
        counter++;
    }
}
