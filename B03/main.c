#include <stdio.h>
#include "verwaltung.h"

int main()
{

    stdnt st1 = {"Pascal", "J", 50};
    stdnt st2 = {"Olli", "J", 60};
    stdnt st3 = {"Philip", "N", 60};  
    stdnt st4 = {"PascalS", "N", 60}; 
    addStudentMainList(st1);
    addStudentMainList(st2);
    addStudentMainList(st3);
    addStudentMainList(st4);
    printMainList();
 


}