#include "verwaltung.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

Node *mainList, *ifm_students, *students_sorted_by;
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

    Node *root = list;
    int counter = 0;
    while (list != NULL)
    {
        if (list->prev == NULL)
        {
            printf("prev-> %-15s | %-7s Node %d: %-16p |next-> %p\n", "/", list->stdnt->name, counter, list->stdnt, list->next->stdnt);
        }
        else if (list->next == NULL)
        {
            printf("prev-> %-15p | %-7s Node %d: %-16p |next-> %s\n", list->prev->stdnt, list->stdnt->name, counter, list->stdnt, "/");
        }
        else
        {
            printf("prev-> %-15p | %-7s Node %d: %-16p |next-> %p\n", list->prev->stdnt, list->stdnt->name, counter, list->stdnt, list->next->stdnt);
        }

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
    Node *header, *root;
    root = mainList;

    while (mainList != NULL)
    {

        if (mainList->stdnt->enrolled == IFM)
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
    mainList = root;
    printf("Die Länge der IFM_Students Liste ist %d.\n\n", counter);

    if (counter > 0)
    {
        ifm_students = header;
        printf("IFM Liste\n");
        print(ifm_students);
    }
}

void printStudentsSortedByEcts()
{

    if (mainList == NULL)
    {
        printf("Main List ist leer!\n\n");
        return;
    }

    Node *tempNode, *header;
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
            header = students_sorted_by;
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
        students_sorted_by = header;
        printf("Students_sorted_by_Ects\n");
        print(students_sorted_by);
    }
}

void removeStudent(Stdnt *student)
{

    Node *root = mainList;
    int counter = 0;
    while (mainList != NULL)
    {

        if (!strcmp(student->name, mainList->stdnt->name))
        {
            printf("Hat geklappt");
        }
        mainList = mainList->next;
        counter++;
    }
    mainList = root;
    printf("\n");
}
void speicherFreigebenMain()
{
    free(mainList);
    mainList = NULL;
}
