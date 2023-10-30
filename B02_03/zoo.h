#ifndef ZOO_H
#define ZOO_H

#define ANIMALCOUNT 10

typedef enum {
    MAMMAL = 10,
    FISH = 4,
    BIRD = 1,
    AMPHIBIAN = 2,
    REPTILIES = 4
} viech;

typedef struct {
    viech species;
    char name[10];
    unsigned int age;
    float food_weight;
} animal;


float calculate_average_age(animal zoo[]);

void more_food(animal zoo[]);

void print_zoo(animal zoo[]);

void print_animal(animal);

#endif

