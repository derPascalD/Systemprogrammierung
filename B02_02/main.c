#include <stdio.h>
#include "zoo.h"
#include "string.h"

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

    durchschnitt = calculate_average_age(zoo);
    printf("%.2f\n\n", durchschnitt);

    print_animal(zoo[0]);
    print_animal(zoo[1]);
    print_animal(zoo[2]);
    print_animal(zoo[3]);

    more_food(zoo);
    print_zoo(zoo);
    return 0;
}