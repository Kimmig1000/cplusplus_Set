// Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../MySet/MySet.h"
#include <iostream>
#include "../MySet/OrderedSet.h"

int main() {
	Set s = Set::difference(Set({ 1,2,3 }), Set({ 2,3,4 }));
	s.print();
}

