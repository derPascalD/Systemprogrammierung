#include "verwaltung.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

Node *mainList, *ifm_students, *students_sorted_by;
void addStudentMainList(Stdnt student)
{
    Node *prev, *root;
    root = mainList;

    if (mainList == NULL)
    {
        mainList = (Node *)malloc(sizeof(Node));

        if (!mainList)
        {
            printf("Kein Speicher freigegeben\n\n");
            return;
        }
        mainList->stdnt = student;
    }
    else
    {
        while (mainList != NULL)
        {

            if (mainList->next == NULL)
            {
                mainList->next = (Node *)malloc(sizeof(Node));

                if (!mainList)
                {
                    printf("Kein Speicher zugewiesen\n\n");
                    return;
                }

                mainList->next->stdnt = student;
                mainList->next->prev = mainList;
                mainList = root;
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
    print(mainList);
}

void print(Node *list)
{
    if (!list)
    {
        printf("Main List ist leer!\n\n");
        return;
    }

    Node *root = list;
    int counter = 0;
    while (list != NULL)
    {
        printf("prev-> %-15p | Node %d: %-15p | next-> %-15p\n", list->prev, counter, list, list->next);
        list = list->next;
        counter++;
    }
    printf("\n");
}

void printIfmStudents()
{
    if (mainList == NULL)
    {
        printf("Main List ist leer!\n\n");
        return;
    }

    int counter = 0;
    Node *prev, *header, *root;
    root = mainList;

    while (mainList != NULL)
    {
        if (mainList->stdnt.enrolled == IFM)
        {
            if (mainList->prev == NULL)
            {
                ifm_students = (Node *)malloc(sizeof(Node));
                header = ifm_students;

                if (!ifm_students)
                {
                    printf("Kein Speicher zugewiesen\n\n");
                    return;
                }
                ifm_students->stdnt = mainList->stdnt;
            }
            else
            {
                ifm_students->next = (Node *)malloc(sizeof(Node));

                if (!ifm_students->next)
                {
                    printf("Kein Speicher zugewiesen\n\n");
                    return;
                }
                ifm_students->next->stdnt = mainList->stdnt;
                ifm_students->next->prev = ifm_students;
                ifm_students = ifm_students->next;
            }
            counter++;
        }
        mainList = mainList->next;
    }
    ifm_students = header;
    mainList = root;
    printf("Die Länge der IFM_Students Liste ist %d.\n\n", counter);
    print(ifm_students);
}

void printStudentsSortedByEcts()
{

    if (mainList == NULL)
    {
        printf("Main List ist leer!\n\n");
        return;
    }

    Node *tempNode = mainList;
    int counter = 0;
    while (tempNode != NULL)
    {
        tempNode = tempNode->next;
        counter++;
    }

    tempNode = mainList;
    
    Node *liste[counter];

    for (int i = 0; i < counter; i++)
    {
        liste[i] = tempNode;
        tempNode = tempNode->next;
    }

    

    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < counter-1; j++)
        {
            if(liste[j]->stdnt.cps > liste[j+1]->stdnt.cps){
                int cps = liste[j]->stdnt.cps;
                liste[j]->stdnt.cps = liste[j+1]->stdnt.cps;
                liste[j+1]->stdnt.cps = cps;
            }
        }
    }

    for (int i = 0; i < counter; i++)
    {
        printf("Name: %s ; Cps: %d\n",liste[i]->stdnt.name,liste[i]->stdnt.cps);
    }
    


    
}


void removeStudent(Stdnt student){

    Node *root = mainList;
    int counter = 0;
    while (mainList != NULL)
    {

        if(!strcmp(student.name,mainList->stdnt.name)){
            printf("Hat geklappt");
        }
        mainList = mainList->next;
        counter++;
    }
    mainList = root;
    printf("\n");
}
void speicherFreigeben()
{
    free(mainList);
    mainList = NULL;
}
