#include <stdio.h>
#include "string.h"
#include "zoo.h"


float calculate_average_age(animal zoo[]) {
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

void more_food(animal zoo[]) {
    int counter;
    while (zoo[counter].age > 0)
    {

        zoo[counter].food_weight += (zoo[counter].species * zoo[counter].food_weight) / 100;
        printf("%.2f\n", zoo[counter].food_weight);
        counter++;
    }
    printf("\n");
}

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
        printf("Die Index Stelle hat kein Tier\n\n");
        return;
    }

    printf("%-15s| %-15s| %-15d| %-15.2f|\n", a.name,name,a.age,a.food_weight);
}

void print_zoo(animal zoo[]){
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











