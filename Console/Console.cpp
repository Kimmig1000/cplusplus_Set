// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../MySet/MySet.h"
#include <iostream>


int main() {
	/*
	Set s1;
	Set s11(s1);
	const int set2[] = { 1,2,3,1 };
	Set s2(set2, sizeof(set2) / sizeof(int));
	s2.print();
	Set s21(s2);
	Set s22 = s2;
	Set s4({ 5,4,3,2,1 });
	s4.print();
	*/
	Set s1({ 1,2,3 ,8,9});
	Set s2({ 0,3,2,4 });

	Set set3 = (Set::merge(s1, s2));
	set3.print();

	Set set4 = (Set::difference(s1, s2));
	set4.print();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
