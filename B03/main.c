#include <stdio.h>
#include "verwaltung.h"

int main()
{
  Stdnt st1 = {"Pascal", IFM, 45};
  Stdnt st2 = {"Olli", IFM, 60};
  Stdnt st3 = {"Philip", BIO, 10};
  Stdnt st4 = {"PascalS", IFM, 30};
  printNodeCount(getMainList());
  addStudentMainList(&st1);
  addStudentMainList(&st2);
  addStudentMainList(&st3);
  addStudentMainList(&st4);
  printNodeCount(getMainList());
  printf("Main Liste\n");
  printList(getMainList());

  printNodeCount(getIfmList());
  createIfmList();
  printNodeCount(getIfmList());
  printf("IFM Liste\n");
  printList(getIfmList());

  printNodeCount(getSortedStdntByEcts());
  createSortedByEctsList();
  printNodeCount(getSortedStdntByEcts());
  printf("Sortierte Liste\n");
  printList(getSortedStdntByEcts());

  printNodeCount(getMainList());
  removeStudent(getMainList(), &st2, 1);
  printNodeCount(getMainList());

  printf("Nach dem Löschen anzeigen\n");

  printf("Main Liste\n");
  printList(getMainList());

  printf("Ifm Liste\n");
  printList(getIfmList());

  printf("Sortierte Liste\n");
  printList(getSortedStdntByEcts());

  printf("Nach dem Löschen erstellen\n");
  createIfmList();
  printf("IFM Liste\n");
  printList(getIfmList());

  createSortedByEctsList();
  printf("Sortierte Liste\n");
  printList(getSortedStdntByEcts());

  printf("Speicher freigeben\n");
  memoryFreeIfmList();
  memoryFreeSortedStdntByEcts();
  memoryFreeMain();

  printf("Sortierte Liste\n");
  printList(getSortedStdntByEcts());

  printf("IFM Liste\n");
  printList(getIfmList());

  printf("Main Liste\n");
  printList(getMainList());

  return 0;
}