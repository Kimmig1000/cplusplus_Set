// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../MySet/MySet.h"
#include <iostream>
#include "../MySet/OrderedSet.h"


int main() {
	/*
	Set s = Set::difference(Set({ 1,2,3 }), Set({ 2,3,4 }));
	s.print();
	
	Set s1({ 1,2,3 });
	Set s2({ 3,2,4 });
	Set s3 = Set::intersection(Set(s1), Set(s2));
	s3.print();
	*/

	OrderedSet s1({ 3,2,1,1,2 });
	OrderedSet s2({ 3,2,4 });
	
	OrderedSet s3 = Set::merge(s1,s2);
	s3.print();
	/*
	Set s1({ 1,2,3 ,8,9 });
	Set s2({ 0,3,2,4 });

	Set set3 = (Set::merge(s1, s2));
	set3.print();

	Set set4 = (Set::difference(s1, s2));
	set4.print();
	*/
	return 0;
}

