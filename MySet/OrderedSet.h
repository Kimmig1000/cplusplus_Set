#pragma once
#include "MySet.h"

class OrderedSet : public Set{
protected:
	size_t m_start;

	OrderedSet(size_t size);

	void sort();

	// algorithm found on https://www.geeksforgeeks.org/merge-two-sorted-arrays/ -> adjusted it	
	Set merge(const Set& set) const override;

public:

	OrderedSet();

	virtual ~OrderedSet();
	// using flat copy
	OrderedSet(const Set& oSet);
	// accetps input like: Set s2({ 0,3,2,4 });
	OrderedSet(std::initializer_list<int> l);	
	
	OrderedSet(const int* cArray, size_t size, size_t start);

	int * begin() const override;


	OrderedSet getSmaller(int x) const;
	
	OrderedSet getLarger(int x) const;
	

};

