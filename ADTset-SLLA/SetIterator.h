#pragma once
#include "Set.h"

class SetIterator
{
	friend class Set;

private:
	const Set& set;
	SetIterator(const Set&);
	
	int current; // index to the current element

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
};


