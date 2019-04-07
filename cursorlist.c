#include <stdio.h>
#include <conio.h>
#define SIZE 10

typedef int List;

typedef struct{
	char course[8];
	char fname[10];
	int year;
}studrec;

typedef struct{
	studrec rec;
	int link;
}studType;

typedef struct{
	int avail;
	studType stud[SIZE];
}vheap;

typedef struct{
	vheap *vptr;
	int count;
	int elem;
}cursorlist;


