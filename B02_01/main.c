#include <stdio.h>
#include "string.h"

#define ANIMALCOUNT 10

typedef enum
{
    MAMMAL = 10,
    FISH = 4,
    BIRD = 1,
    AMPHIBIAN = 2,
    REPTILIES = 0
} viech;

typedef struct
{
    viech species;
    char name[10];
    unsigned int age;
    float food_weight;
} animal;

float calculate_average_age(void);
void more_food(void);
void print_animal(animal);
void print_zoo(void);

animal zoo[10];

int main()
{
    animal mammal, fish, amphibian, bird;
    float durchschnitt;

    mammal.species = MAMMAL;
    mammal.food_weight = 25;
    strcpy(mammal.name, "Hase");
    mammal.age = 5;

    fish.species = FISH;
    fish.food_weight = 20;
    strcpy(fish.name, "Karpfen");
    fish.age = 2;

    amphibian.species = AMPHIBIAN;
    amphibian.food_weight = 30;
    strcpy(amphibian.name, "Froesche");
    amphibian.age = 3;

    bird.species = BIRD;
    bird.food_weight = 40;
    strcpy(bird.name, "Taube");
    bird.age = 4;

    zoo[0] = mammal;
    zoo[1] = fish;
    zoo[2] = amphibian;
    zoo[3] = bird;

    durchschnitt = calculate_average_age();
    printf("Durchschnitt: %.2f\n\n", durchschnitt);



    printf("%-15s| %-15s| %-15s| %-15s|\n", "Tier Name", "Spezies", "Alter", "Essens Gewicht");
    printf("-------------------------------------------------------------------\n");
    print_animal(zoo[0]);
    print_animal(zoo[1]);
    printf("\n");
    print_animal(zoo[4]);
    print_animal(zoo[5]);

    more_food();

    print_zoo();
    return 0;
}

/* Errechnet das Durchschnittsalter von allen Tieren im Zoo*/
float calculate_average_age()
{
    float summeAlter = 0;
    int anzahlTiere = 0;
    int i;
    for (i = 0; i < ANIMALCOUNT; i++)
    {

        if (zoo[i].age > 0)
        {
            anzahlTiere++;
            summeAlter += zoo[i].age;
        }
    }

    return summeAlter / anzahlTiere;
}

/*Hier bekommen die Tiere mehr Futter zugewiesen*/
void more_food()
{
    int counter = 0;
    while (counter < ANIMALCOUNT)
    {

        zoo[counter].food_weight += (zoo[counter].species * zoo[counter].food_weight) / 100;
        counter++;
    }
    printf("\n");
}

/*Hier werden vom übergebenen Tier die jeweiligen Informationen in der Konsole ausgegeben*/
void print_animal(animal a)
{
    char name[10];
    if (a.species == MAMMAL && a.age != 0)
    {
        strcpy(name, "Mammal");
    }
    else if (a.species == FISH && a.age != 0)
    {
        strcpy(name, "Fish");
    }
    else if (a.species == BIRD && a.age != 0)
    {
        strcpy(name, "Bird");
    }
    else if (a.species == AMPHIBIAN && a.age != 0)
    {
        strcpy(name, "Amphibian");
    }
    else if (a.species == REPTILIES && a.age != 0)
    {
        strcpy(name, "Reptilies");
    }
    else
    {
        printf("Die Index Stelle hat kein Tier\n\n");
        return;
    }

    printf("%-15s| %-15s| %-15d| %-15.2f|\n", a.name, name, a.age, a.food_weight);
}

/*Hier werden von allen Tieren im Zoo, die jeweiligen Informationen ausgegeben*/
void print_zoo()
{
    int i;
    printf("%-15s| %-15s| %-15s| %-15s|\n", "Tier Name", "Spezies", "Alter", "Essens Gewicht");
    printf("-------------------------------------------------------------------\n");
    for (i = 0; i < ANIMALCOUNT; i++)
    {

        if (zoo[i].age > 0)
        {
            print_animal(zoo[i]);
        }
    }
    printf("\n");
}
