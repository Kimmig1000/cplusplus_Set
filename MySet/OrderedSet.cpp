#include "OrderedSet.h"
#include <algorithm>
//protected
OrderedSet::OrderedSet(size_t size) : Set(size), m_start(0) {}

void OrderedSet::sort() {
	int * beg = begin(); std::sort(beg, beg + m_size);
}

OrderedSet::OrderedSet() : Set(), m_start(0) {}

OrderedSet::~OrderedSet() {}

OrderedSet::OrderedSet(const Set& oSet) : Set(oSet), m_start(0) { sort(); }

OrderedSet::OrderedSet(std::initializer_list<int> l) : Set(l), m_start(0) { sort(); }

OrderedSet::OrderedSet(const int* cArray, size_t size, size_t start) : Set(cArray, size), m_start(start) { sort(); }

int * OrderedSet::begin() const {
	return Set::begin() + m_start;
}

OrderedSet OrderedSet::getSmaller(int x) const {
	OrderedSet oSet(m_size);
	int length = 0;
	int *cArray = begin();
	while (*cArray < x && length < m_size) {
		oSet[length] = *cArray;
		cArray++; length++;
	}
	oSet.m_size = length;
	return oSet;
}

OrderedSet OrderedSet::getLarger(int x) const {
	OrderedSet oSet(m_size);
	int length = 0, i = 0;
	int *cArray = begin();
	while (*cArray <= x && i < m_size) {
		i++; cArray++;
	}
	while (i < m_size) {
		oSet[length] = *cArray;
		length++; cArray++; i++;
	}

	oSet.m_size = length;
	return oSet;
}

Set OrderedSet::merge(const Set& set) const {
	const OrderedSet* oSet = dynamic_cast<const OrderedSet*>(&set);

	if (oSet != nullptr) { // if fails -> oSet is a Set (not an OrderedSet) 
		OrderedSet result(m_size + oSet->size());

		int* thisArray = begin();
		int* setArray = oSet->begin();
		size_t i = 0, j = 0;

		
		while (i < size() && j < oSet->size()) {

			int currentThisValue = *(thisArray + i);
			int currentSetValue = *(setArray + j);

			if (currentThisValue < currentSetValue) {
				if (currentThisValue == currentSetValue) {  //avoid duplicates
					i++;
				}
				else {
					result[result.m_size++] = currentThisValue;
					i++;
				}
			}
			else {
				if (currentSetValue == currentThisValue) {  //avoid duplicates
					j++;
				}
				else {
					result[result.m_size++] = currentSetValue;
					j++;
				}
			}
		}

		while (i < size()) {
			result[result.m_size++] = *(thisArray + i);
			i++;
		}
		while (j < oSet->size()) {
			result[result.m_size++] = *(setArray + j);
			j++;
		}

		return result;

	}
	else return Set::merge(set);


}

