#include <stdio.h>
#include "zoo.h"
#include "string.h"

animal zoo[ANIMALCOUNT];

int main()
{
    animal mammal, fish, amphibian, bird;
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

    durchschnitt = calculate_average_age(zoo);
    printf("%.2f\n\n", durchschnitt);

    printf("%-15s| %-15s| %-15s| %-15s|\n", "Tier Name","Spezies","Alter", "Essens Gewicht");
    printf("-------------------------------------------------------------------\n");
    print_animal(zoo[0]);
    print_animal(zoo[1]);
    print_animal(zoo[2]);
    print_animal(zoo[4]);
    print_animal(zoo[3]);

    printf("\n");
    more_food(zoo);

    print_zoo(zoo);
    return 0;
}