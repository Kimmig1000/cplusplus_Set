#pragma once
#include <memory>
#include <initializer_list>
#include <fstream>

class Set {
protected:
	//-------------------------------
	// attributes of the set	
	std::shared_ptr<int[]> m_values;
	size_t m_size;
	//-------------------------------

	
	Set(size_t size);



	Set merge(const Set& set) const;

	Set difference(const Set& set) const;

	Set intersection(const Set& set) const;



	int *begin() const;

	int& operator[](size_t i) const;



public:

	// creates an empty array 
	Set();

	// using flat copy
	Set(const Set& s);

	// accetps input like: Set s2({ 0,3,2,4 });
	Set(std::initializer_list<int> l);

	// removes duplicates of the input Array
	Set(const int* cArray, size_t size);

	// nothing to delete, as we use shared_ptr
	~Set();

	//--------------------------------------------------------
	// set operations that call the protected set operations
	static Set merge(const Set& set1, const Set& set2) { return set1.merge(set2); }
	
	static Set difference(const Set& set1, const Set& set2) { return set2.difference(set1); }
	
	static Set intersection(const Set& set1, const Set& set2) { return set1.intersection(set2); }

	//--------------------------------------------------------
	
	
	bool contains(int value) const;

	bool containsAll(const Set& set) const;

	bool isEmpty() const;

	size_t size() const; 
	
	bool operator==(const Set& set) const { return containsAll(set) && set.containsAll(*this); }
	
	friend std::ostream& operator<<(std::ostream& os, const Set& s) {
		const int* const vptr = s.begin();
		os << "{";
		if (!s.isEmpty()) os << vptr[0];
		for (size_t i = 1; i < s.m_size; ++i) { os << ", " << vptr[i]; }
		os << "}";
	}

	void print();

};
