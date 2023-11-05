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
void printList(Node*);
void printNodeCount(Node*);
void createIfmList(void);
void createSortedByEctsList(void);
void memoryFreeIfmList();
void memoryFreeSortedStdntByEcts();
void memoryFreeMain(void);
void removeStudent(Node*,Stdnt*,int);
Node* getMainList(void);
Node* getIfmList(void);
Node* getSortedStdntByEcts(void);
void setIfmList(Node*);
void setSortedStdntByEcts(Node*);

#endif