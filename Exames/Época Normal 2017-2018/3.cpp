﻿#include <iostream>
#include <new>

using namespace std;

float average(const int grades[], int numStudents) { //Exercise 3.a1)
	float sum = 0;

	for (int i = 0; i < numStudents; i++)
		sum += grades[i];

	return sum / numStudents;
}

void readGrades(int grades[], int numStudents);

void showAverage() { //Exercise 3.a2)
	int numStudents;

	cin >> numStudents;

	int *grades = new int[numStudents];

	readGrades(grades, numStudents);

	cout << average(grades, numStudents);
}

struct Position {
	int lin, col;
};