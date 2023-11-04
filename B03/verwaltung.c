#include "verwaltung.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

Node *mainList = NULL, *ifm_students = NULL, *students_sorted_by = NULL;
void addStudentMainList(Stdnt *student)
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
    printf("Main Liste\n");
    print(mainList);
}

void print(Node *list)
{

    if (!list)
    {
        printf("Liste ist leer!\n\n");
        return;
    }
 
    int counter = 0;
    while (list != NULL)
    {
        
        if (list->prev == NULL)
        {
            printf("prev-> %-15s | %-7s Node %d: %-16p |next-> %p\n", "/", list->stdnt->name, counter, list, list->next);
        }
        else if (list->next == NULL)
        {
            printf("prev-> %-15p | %-7s Node %d: %-16p |next-> %s\n", list->prev, list->stdnt->name, counter, list, "/");
        }
        else
        {
            printf("prev-> %-15p | %-7s Node %d: %-16p |next-> %p\n", list->prev, list->stdnt->name, counter, list, list->next);
        }

        list = list->next;
        counter++;
    }
    printf("\n");
}

void createIfmList()
{
    ifm_students = NULL;
    if (mainList == NULL)
    {
        printf("Main List ist leer!\n\n");
        return;
    }

    int counter = 0;
    Node *root, *helpList;
    root = mainList;


    while (root != NULL)
    {

        if (root->stdnt->enrolled == IFM)
        {


           if (ifm_students == NULL)
            {
                ifm_students = (Node *)malloc(sizeof(Node));
                if (ifm_students == NULL)
                {
                    printf("Kein Speicher zugewiesen\n\n");
                    return;
                }

                ifm_students->stdnt = root->stdnt;
                ifm_students->next = NULL;
                ifm_students->prev = NULL;
                helpList = ifm_students;

            }
            else
            {
                helpList->next = (Node *)malloc(sizeof(Node));
                
                helpList->next->stdnt = root->stdnt;
                helpList->next->next = NULL;
                helpList->next->prev = helpList;

                helpList = helpList->next;
            }
            counter++;
        }
        root = root->next;
    }

    printf("Länge der IFM Liste ist %d.\n\n",counter);
    if (counter > 0)
    {
        printf("IFM Liste\n");
        print(ifm_students);
    }
}

void createSortedByEctsList()
{
    students_sorted_by = NULL;
    if (mainList == NULL)
    {
        printf("Main List ist leer!\n\n");
        return;
    }

    Node *tempNode, *head;
    tempNode = mainList;
    int counter = 0;
    while (tempNode != NULL)
    {
        tempNode = tempNode->next;
        counter++;
    }

    tempNode = mainList;

    Stdnt *studentList[counter];

    for (int i = 0; i < counter; i++)
    {
        studentList[i] = tempNode->stdnt;
        tempNode = tempNode->next;
    }

    Stdnt *tempStd;
    for (int i = 1; i < counter; i++)
    {
        for (int j = 0; j < counter - i; j++)
        {
            if (studentList[j]->cps > studentList[j + 1]->cps)
            {
                tempStd = studentList[j];
                studentList[j] = studentList[j + 1];
                studentList[j + 1] = tempStd;
            }
        }
    }

    for (int i = 0; i < counter; i++)
    {
        if (students_sorted_by == NULL)
        {
            students_sorted_by = (Node *)malloc(sizeof(Node));
            head = students_sorted_by;
            students_sorted_by->stdnt = studentList[i];
        }
        else
        {
            students_sorted_by->next = (Node *)malloc(sizeof(Node));

            students_sorted_by->next->stdnt = studentList[i];
            students_sorted_by->next->prev = students_sorted_by;
            students_sorted_by = students_sorted_by->next;
        }
    }
    printf("Die Länge der Students_sorted_by_Ects Liste ist %d.\n\n", counter);
    printf("\n");
    if (counter > 0)
    {
        students_sorted_by = head;
        printf("Students_sorted_by_Ects\n");
        print(students_sorted_by);
    }
}

/* Löscht einen Studenten aus der Main List und verknüpft sich mit dem anderen Knoten */
void removeStudent(Stdnt *student, int modus)
{
    Node *current = mainList;
    int counter = 0;
    while (current != NULL)
    {
        counter++;
        current = current->next;
    }

    printf("Die Länge beträgt vor dem Löschen %d.\n\n", counter);

    current = mainList;
    while (current != NULL)
    {
        if (student == current->stdnt)
        {
            if (current->prev == NULL)
            {
                current->next->prev = NULL;
                mainList = current->next;
                current->next = NULL;
                current->prev = NULL;
                
            }
            else if (current->next == NULL)
            {
                current->prev->next = NULL;
                current->prev = NULL;
                current->next = NULL;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                current->next = NULL;
                current->prev = NULL;
            }

            if (modus == 1)
            {
                current->stdnt = NULL;
            }
            else if (modus == 0)
            {
                current->stdnt = NULL;
            }

            free(current);
            current = NULL;

            current = mainList;
            counter = 0;
            while (current != NULL)
            {
                counter++;
                current = current->next;
            }
            printf("Die Länge beträgt nach dem Löschen %d.\n\n", counter);
            return;
        }
        current = current->next;
    }
}

void memoryFreeIFM()
{
    if(ifm_students == NULL){
        printf("Hilfsliste ist leer!\n");
        return;
    }

    Node *head, *prev;
    head = ifm_students;
    int counter = 0;
    while (ifm_students->next != NULL)
    {

        ifm_students = ifm_students->next;
    }

    while(ifm_students != NULL){

        prev = ifm_students->prev;

        free(ifm_students);
        ifm_students = NULL;

        ifm_students = prev;
        counter++;
        
    }
    printf("%d Knoten wurden entfernt und Speicher der Hilfsliste wurde freigegben!\n", counter);
 
}

void memoryFreeSortedStdntByEcts(){
    if(students_sorted_by == NULL){
        printf("Hilflsiste ist leer!\n");
        return;
    }

    Node *head, *prev;
    head = students_sorted_by;
    int counter = 0;
    while (students_sorted_by->next != NULL)
    {
  
        students_sorted_by = students_sorted_by->next;
    }

    while(students_sorted_by != NULL){

        
        prev = students_sorted_by->prev;

        free(students_sorted_by);
        students_sorted_by = NULL;

        students_sorted_by = prev;
        counter++;
        
    }
    printf("%d Knoten wurden entfernt und Speicher der Hilfsliste wurde freigegben!\n", counter);
 
}

void memoryFreeMain()
{
    if(mainList == NULL){
        printf("Mainliste ist leer!\n");
        return;
    }

    Node *head, *prev;
    head = mainList;
    int counter = 0;
    while (mainList->next != NULL)
    {

        mainList = mainList->next;
    }

    while(mainList != NULL){

        prev = mainList->prev;

        free(mainList);
        mainList = NULL;
   

        mainList = prev;
        counter++;
        
    }
    printf("%d Knoten wurden entfernt und Speicher der Mainliste wurde freigegben!\n", counter);

}

