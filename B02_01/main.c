#include <stdio.h>
#include "string.h"

#define ANIMALCOUNT 10

typedef enum
{
    MAMMAL = 10,
    FISH = 4,
    BIRD = 1,
    AMPHIBIAN = 2,
    REPTILIES = 4
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

animal mammal, fish, amphibian, bird;

animal zoo[10];

int main()
{
    float durchschnitt;
    mammal.species = MAMMAL;
    mammal.food_weight = 20;
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
    printf("%.2f\n\n", durchschnitt);

    more_food();

    printf("%-15s| %-15s| %-15s| %-15s|\n", "Tier Name", "Spezies", "Alter", "Essens Gewicht");
    printf("-------------------------------------------------------------------\n");
    print_animal(zoo[0]);
    print_animal(zoo[1]);
    printf("\n");
    print_animal(zoo[4]);
    print_animal(zoo[5]);
    print_zoo();
    return 0;
}

/* Errechnet das Druchschnittsalter von allen Tieren im Zoo*/
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

/*Hier bekommen die Tiere mehr Futter zugeweisen*/
void more_food()
{
    int counter;

    while (zoo[counter].age > 0)
    {

        zoo[counter].food_weight += (zoo[counter].species * zoo[counter].food_weight) / 100;
        printf("%.2f\n", zoo[counter].food_weight);
        counter++;
    }
    printf("\n");
}

/*Hier werden vom übergebenen Tier die jeweiligen Inforamtionen in der Konsole ausgegeben*/
void print_animal(animal a)
{
    char name[10];
    if (a.species == MAMMAL)
    {
        strcpy(name, "Mammal");
    }
    else if (a.species == FISH)
    {
        strcpy(name, "Fish");
    }
    else if (a.species == BIRD)
    {
        strcpy(name, "Bird");
    }
    else if (a.species == AMPHIBIAN)
    {
        strcpy(name, "Amphibian");
    }
    else if (a.species == REPTILIES)
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
