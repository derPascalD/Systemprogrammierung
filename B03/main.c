#include <stdio.h>
#include "verwaltung.h"

int main()
{

  Stdnt st1 = {"Pascal", IFM, 45};
  Stdnt st2 = {"Olli", ENG, 60};
  Stdnt st3 = {"Philip", MATHE, 10};
  Stdnt st4 = {"PascalS", IFM, 30};

  printIfmStudents();
  addStudentMainList(&st1);
  addStudentMainList(&st2);
  addStudentMainList(&st3);
  addStudentMainList(&st4);
  printMainList();
  printIfmStudents();
  printMainList();
  printStudentsSortedByEcts();
  /* removeStudent(st2);*/
}