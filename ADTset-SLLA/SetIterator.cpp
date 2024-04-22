#include "SetIterator.h"
#include "Set.h"
#include <stdexcept>


SetIterator::SetIterator(const Set& m) : set(m)
{
	current = set.head;
}


void SetIterator::first() {
	current = set.head;
}


void SetIterator::next() {
	if (!valid())
		throw std::out_of_range("Iterator is out of range");

	current = set.link[current];
}


TElem SetIterator::getCurrent()
{
	if (!valid())
		throw std::out_of_range("Iterator is out of range");

	return set.e[current];
}

bool SetIterator::valid() const {
	return (current != -1);
}



