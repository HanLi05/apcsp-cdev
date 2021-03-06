//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args

//Student* st = (Student*)malloc((strlen(fname)+strlen(lname))*sizeof(char)+2*sizeof(int));
  Student* st = (Student*)malloc(sizeof(Student));
  st->firstName = (char*)malloc(strlen(fname)*sizeof(char));
  st->lastName = (char*)malloc(strlen(lname)*sizeof(char));
  strcpy(st->firstName, fname);
  strcpy(st->lastName, lname);
  st->age = age;
  st->id = id;
  students[numStudents++] = st;
}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
  for (int i = 0; i < numStudents; i++) {
    deleteStudent(students[i]);
    students[i] = 0;
  }
  numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 
  FILE* fp;

  fp = fopen("studentdata.txt", "w");
  if (fp) {
    for (int i = 0; i < numStudents; i++) {
      char* firstName = (char*) malloc(strlen(students[i]->firstName)*sizeof(char));
      char* lastName = (char*) malloc(strlen(students[i]->lastName)*sizeof(char));
      char strAge[10];
      char strId[50];
      strcpy(firstName, students[i]->firstName);
      strcpy(lastName, students[i]->lastName);
      sprintf(strAge, "%d", students[i]->age);
      sprintf(strId, "%ld", students[i]->id);
      encrypt(firstName, &key, 1);
      encrypt(lastName, &key, 1);
      encrypt(strAge, &key, 1);
      encrypt(strId, &key, 1);
      printf("saving: %s %s %s %s\n", firstName, lastName, strAge, strId);
      fprintf(fp, "%s %s %s %s\n", firstName, lastName, strAge, strId);
    }
    fclose(fp);
    printf("saved %d students\n", numStudents);
  }
}


void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  FILE *fp;

  fp = fopen("studentdata.txt", "r");
  if (fp) {
    deleteStudents();
    while (1) {
      char fname[100], lname[100], strAge[10], strId[50];
      unsigned int age;
      long int id;
      char *ptr;
      if (fscanf(fp, "%s %s %s %s\n", fname, lname, strAge, strId) == 4) {
        decrypt(fname, &key, 1);
        decrypt(lname, &key, 1);
        decrypt(strAge, &key, 1);
        decrypt(strId, &key, 1);
        age = atoi(strAge);
        id = strtol(strId, &ptr, 10);
        createStudent(fname, lname, age, id);
      }
      else
        break;
    }
    fclose(fp);
  }
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




