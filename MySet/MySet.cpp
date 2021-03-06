// MySet.cpp 
#include "MySet.h"


//-------------------------------------------------------
// Constructor implementations

Set::Set(size_t size) : m_values(new int[size]), m_size(0) {
	std::cout << "private-ctor " << std::endl;
}

Set::Set() {
	m_size = 0;
	std::cout << "default constructor called" << std::endl;
}


Set::Set(const Set& set) :m_size(set.size()), m_values(set.m_values) {

	std::cout << "copy constructor with flat copy called" << std::endl;
}

Set::Set(const int* cArray, size_t size) : m_values(new int[size]), m_size(size) {
	size_t sizeCounter = 0;
	for (size_t i = 0; i < size; i++) {
		if (!contains(*(cArray + i))) {
			m_values[i] = *(cArray + i);
			sizeCounter++;
		}
	}
	m_size = sizeCounter; // take the size without duplicates

	std::cout << "type conversion constructor called" << std::endl;
}

Set::Set(std::initializer_list<int> l) : m_values(new int[l.size()]), m_size(l.size()) {
	size_t it = 0;
	for (int i : l) {
		if (!contains(i)) {
			m_values[it] = i;
			it++;
		}
	}
	m_size = it; // take the size without duplicates

	std::cout << "initializer list constructor called" << std::endl;
}

Set::~Set() {
	std::cout << "destructor called" << std::endl;
}

// End of constructor implementations
//------------------------------------------------




//-------------------------------------------------
//  Set operations

Set Set::merge(const Set& set) const {
	Set result(size() + set.size());
	std::memcpy(result.begin(), begin(), size() * sizeof(int));
	result.m_size = size();

	for (size_t i = 0; i < set.size(); ++i) {
		if (!contains(set[i])) result[result.m_size++] = set[i];
	}
	return result;
}

Set Set::difference(const Set& set) const {
	Set result(size() + set.size());

	size_t length = 0;

	for (size_t i = 0; i < set.size(); ++i) {
		if (!contains(set[i])) {
			result[length] = set[i];
			length++;
		}
	}
	result.m_size = length;
	return result;
}

Set Set::intersection(const Set& set)const {
	Set result(size() + set.size());

	size_t length = 0;

	for (size_t i = 0; i < set.size(); ++i) {
		if (contains(set[i])) {
			result[length] = set[i];
			length++;
		}
	}
	result.m_size = length;
	return result;
}

//MOVE

Set Set::difference(Set&& set) const {
	if (set.m_values.use_count() == 1) {

		size_t length = 0;
		std::cout << "using move" << std::endl;
		

		for (size_t i = 0; i < set.size(); ++i) {
			if (!contains(set[i])) {
				set.begin()[length] = set[i];
				length++;
			}
		}
		set.m_size = length;
		return set;
	}
	else {
		return difference(set);
	}

}

Set Set::intersection(Set&& set) const {
	if (set.m_values.use_count() == 1) {
		size_t length = 0;
		std::cout << "using move" << std::endl;
		

		for (size_t i = 0; i < set.size(); ++i) {
			if (contains(set[i])) {
				set.begin()[length] = set[i];
				length++;
			}
		}
		set.m_size = length;
		return set;

	}
	else {
		return intersection(set);
	}
}



// End of set operations
//------------------------------------------------




//-------------------------------------------------
//  Helper methods

bool Set::contains(int value) const {
	for (size_t i = 0; i < size(); i++) {
		if (m_values[i] == value) return true;
	}
	return false;
}

bool Set::containsAll(const Set& set) const {
	for (size_t i = 0; i < set.size(); i++) {
		if (!contains(set.m_values[i])) {
			return false;
		}
	}
	return true;
}

size_t Set::size() const {
	return m_size;
}

bool Set::isEmpty() const {
	return size() == 0;
}

int* Set::begin() const {
	if (m_values == nullptr) {
		return nullptr;
	}
	else {
		return m_values.get();
	}
}



int& Set::operator[](size_t i) const {
	return *(begin() + i);
}




void Set::print() {
	for (size_t i = 0; i < size(); i++)
	{
		std::cout << m_values[i] << " ";
	}
	std::cout << std::endl;
}

// End of helper methods
//------------------------------------------------

