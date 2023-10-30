#ifndef VERWALTUNG_H
#define VERWALTUNG_H


typedef struct{
    char name[20];
    char enrolled[5];
    int cps;
}stdnt;

struct node{
    stdnt stdnt;
    struct node *prev;
    struct node *next;
};

void addStudent(stdnt);
void printStudents(struct node);



#endif