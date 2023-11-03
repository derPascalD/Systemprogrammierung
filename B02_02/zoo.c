#include <stdio.h>
#include "string.h"
#include "zoo.h"

 static animal zoo[ANIMALCOUNT] = {
    {MAMMAL, "Hase",5, 20},
    {FISH, "Karpfen", 2, 25},
    {AMPHIBIAN, "Froesche", 3, 30},
    {BIRD, "Taube",4, 40}
};

/* Errechnet das Durchschnittsalter von allen Tieren im Zoo*/
float calculate_average_age() {
    float summeAlter = 0;
    int anzahlTiere = 0;
    int i;
    for (i = 0; i < ANIMALCOUNT; i++) {

        if (zoo[i].age > 0) {
            anzahlTiere++;
            summeAlter += zoo[i].age;
        }
    }
    return summeAlter / anzahlTiere;
}

/*Hier bekommen die Tiere mehr Futter zugewiesen*/
void more_food() {
    int counter = 0;
    while (counter < ANIMALCOUNT)
    {
        zoo[counter].food_weight += (zoo[counter].species * zoo[counter].food_weight) / 100;
        printf("%.2f\n", zoo[counter].food_weight);
        counter++;
    }
    printf("\n");
}

/*Hier werden vom übergebenen Tier die jeweiligen Informationen in der Konsole ausgegeben*/
void print_animal(animal a) {
    char name[10];
    if(a.species == MAMMAL){
        strcpy(name,"Mammal");
    }else if(a.species == FISH){
        strcpy(name,"Fish");
    }else if(a.species == BIRD){
        strcpy(name,"Bird");
    }else if(a.species == AMPHIBIAN){
        strcpy(name,"Amphibian");
    }else if(a.species == REPTILIES){
        strcpy(name,"Reptilies");
    }else{
        printf("Die Index Stelle hat kein Tier\n");
        return;
    }
    printf("%-15s| %-15s| %-15d| %-15.2f|\n", a.name,name,a.age,a.food_weight);
}

/*Hier werden von allen Tieren im Zoo, die jeweiligen Informationen ausgegeben*/
void print_zoo(){
    int i;
    printf("%-15s| %-15s| %-15s| %-15s|\n", "Tier Name","Spezies","Alter", "Essens Gewicht");
    printf("-------------------------------------------------------------------\n");
    for (i = 0; i < ANIMALCOUNT; i++) {

        if (zoo[i].age > 0) {
            print_animal(zoo[i]);
        }
    }
    printf("\n");
}

void setAnnimalinZoo(animal a, int pos){
   zoo[pos] = a;

}

animal getAnimalinZoo(int pos){
    return zoo[pos];
}












