#include <stdio.h>



// student structure
struct Student {
  char firstName[32];
  char lastName[32];
  int age;
  int studentID;
};


void printStudent(struct Student* student)
{
  printf("\n---- student ----\n");
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("  Age: %d\n", student->age);
  printf("  Student ID: %d\n", student->studentID);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for (int i = 0; i < num; i++) {
    printStudent(&students[i]);
  }
}


int main()
{

  // an array of students
  struct Student students[100];
  char input[256];
  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      printf("\nFirst Name:");
      fgets(input, 256, stdin);
      if (sscanf(input, "%s", students[numStudents].firstName) != 1) continue;

      printf("\nLast Name:");
      fgets(input, 256, stdin);
      if (sscanf(input, "%s", students[numStudents].lastName) != 1) continue;

      printf("\nAge:");
      fgets(input, 256, stdin);
      if (sscanf(input, "%d", &students[numStudents].age) != 1) continue;

      printf("\nStudentID:");
      fgets(input, 256, stdin);
      if (sscanf(input, "%d", &students[numStudents].studentID) != 1) continue;

      numStudents++;
    }
  }

  printf("\nGoodbye!\n");
}
