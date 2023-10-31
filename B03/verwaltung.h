#ifndef VERWALTUNG_H
#define VERWALTUNG_H


typedef struct{
    char name[20];
    char enrolled[2];
    int cps;
}stdnt;

struct node{
    stdnt stdnt;
    struct node *prev;
    struct node *next;
};


void addStudentMainList(stdnt);
void printMainList(void);
void printIfmStudents(void);
void printStudentsSortedByEcts(void);



#endif