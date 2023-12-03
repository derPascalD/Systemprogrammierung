#include "verwaltung.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

Node *mainList = NULL, *ifm_students = NULL, *students_sorted_by = NULL;
void addStudentMainList(Stdnt *student)
{
    Node *root;
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
                break;
            }
            else
            {
                mainList = mainList->next;
            }
        }
    }
}

void printList(Node *list)
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
            printf("prev-> %-15s | %-7s Node %d: %-16p |next-> %p\n", "/", list->stdnt->name, counter,(void *) list,(void *) list->next);
        }
        else if (list->next == NULL)
        {
            printf("prev-> %-15p | %-7s Node %d: %-16p |next-> %s\n",(void *) list->prev, list->stdnt->name, counter,(void *) list, "/");
        }
        else
        {
            printf("prev-> %-15p | %-7s Node %d: %-16p |next-> %p\n",(void *) list->prev, list->stdnt->name, counter,(void *) list,(void *) list->next);
        }

        list = list->next;
        counter++;
    }
    printf("\n");
}

void printNodeCount(Node *list){

    if(list == NULL){
        printf("Es sind noch keine Knoten vorhanden.\n");
        return;
    }
    Node *current = list;
    int counter = 0;
    
    while (current != NULL)
    {
        counter++;
        current = current->next;
    }
    printf("Die Liste hat aktuell %d Knoten.\n",counter);
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

                if (helpList == NULL)
                {
                    printf("Kein Speicher zugewiesen\n\n");
                    return;
                }
                
                helpList->next->stdnt = root->stdnt;
                helpList->next->next = NULL;
                helpList->next->prev = helpList;

                helpList = helpList->next;
            }
            counter++;
        }
        root = root->next;
    }

    printf("Die Länge der IFM Liste ist %d.\n\n",counter);
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

            if (students_sorted_by == NULL)
                {
                    printf("Kein Speicher zugewiesen\n\n");
                    return;
                }
            head = students_sorted_by;
            students_sorted_by->stdnt = studentList[i];
        }
        else
        {
            students_sorted_by->next = (Node *)malloc(sizeof(Node));

            if(students_sorted_by->next == NULL){
                printf("Kein Speicher zugewiesen\n\n");
                return;
            }

            students_sorted_by->next->stdnt = studentList[i];
            students_sorted_by->next->prev = students_sorted_by;
            students_sorted_by = students_sorted_by->next;
        }
    }
    students_sorted_by = head;
    printf("Die Länge der Students_sorted_by_Ects Liste ist %d.\n\n", counter);
}

/* Löscht einen Studenten aus der Main List und verknüpft sich mit dem anderen Knoten */
void removeStudent(Node *list, Stdnt *student, int modus) 
{   
    Node *current = list;
    while (current != NULL)
    {
        if (student == current->stdnt)
        {
            if (current->prev == NULL)
            {
                current->next->prev = NULL;
                
                if(mainList == list){
                   mainList = current->next;
                }else if(ifm_students == list){
                   ifm_students = current->next;
                }else if(students_sorted_by == list){
                    students_sorted_by = current->next;
                }

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
                free(current->stdnt);
            }
            else if (modus == 0)
            {
                current->stdnt = NULL;
            }
             
            free(current);
            current = NULL;
        
            return;
        }
        current = current->next;
    }
}

void memoryFreeIfmList(){
    if(ifm_students == NULL){
        printf("Hilfsliste ist leer!\n");
        return;
    }

    Node *next;
    int counter = 1;


    while (ifm_students->next != NULL)
    {
        next = ifm_students->next;
        removeStudent(ifm_students,ifm_students->stdnt,0);
        ifm_students = next;
        counter++;
    }
    ifm_students = NULL;

    printf("%d Knoten wurden entfernt und Speicher der IFM Hilfsliste wurde freigegben!\n", counter);
}

void memoryFreeSortedStdntByEcts(){
    if(students_sorted_by == NULL){
        printf("Hilfsliste ist leer!\n");
        return;
    }

    Node *next;
    int counter = 1;

    while (students_sorted_by->next != NULL)
    {
        next = students_sorted_by->next;
        removeStudent(students_sorted_by,students_sorted_by->stdnt,0);
        students_sorted_by = next;
        counter++;
    }
    students_sorted_by = NULL;
    printf("%d Knoten wurden entfernt und Speicher der Sortierten Hilfsliste wurde freigegben!\n", counter);
}

void memoryFreeMain()
{
    if(mainList == NULL){
        printf("Mainliste ist leer!\n");
        return;
    }

    Node *next;
    int counter = 1;


    while (mainList->next != NULL)
    {
        next = mainList->next;
        removeStudent(mainList,mainList->stdnt,1);
        mainList = next;
        counter++;
    }
    mainList = NULL;

    printf("%d Knoten wurden entfernt und Speicher der Mainliste wurde freigegben!\n", counter);

}

Node* getMainList(){
    if(mainList != NULL){
        return mainList;
    }else{
        return NULL;
    }
}

Node* getIfmList(){
    if(ifm_students != NULL){
        return ifm_students;
    }else{
        return NULL;
    }
}

Node* getSortedStdntByEcts(){
    if(students_sorted_by != NULL){
        return students_sorted_by;
    }else{
        return NULL;
    }
}

void setIfmList(Node* list){
    ifm_students = list;
}

void setSortedStdntByEcts(Node* list){
    students_sorted_by = list;
}