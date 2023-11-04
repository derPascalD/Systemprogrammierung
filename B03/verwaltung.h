#ifndef VERWALTUNG_H
#define VERWALTUNG_H

typedef enum{
    IFM,
    BIO,
    MATHE,
    ENG,
    SOZIAL
}Modul;

typedef struct{
    char name[20];
    Modul enrolled;
    unsigned int cps;
}Stdnt;

typedef struct node{
    Stdnt *stdnt;
    struct node *prev;
    struct node *next;
}Node;

void addStudentMainList(Stdnt*);
void print(Node*);
void createIfmList(void);
void createSortedByEctsList(void);
void memoryFreeIFM(void);
void memoryFreeSortedStdntByEcts(void);
void memoryFreeMain(void);
void removeStudent(Stdnt*,int);

#endif