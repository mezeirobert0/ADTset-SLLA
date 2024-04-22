#include "Set.h"
#include "SetITerator.h"
#include <stack>

Set::Set() {
	// Initializing capacity
	cp = 5;

	// Allocating space dynamically for cp elements of type TElem
	e = new TElem[cp];

	link = new int[cp];

	// Initializing size
	n = 0;
	
	// the list is empty
	head = -1;
	tail = -1;
	firstEmpty = 0;

	// All elements in the array point to nothing
	for (int i = 0; i < cp - 1; i++)
		link[i] = i + 1;
	
	link[cp - 1] = -1;
}

void Set::resize()
{
	//New array of double the capacity of the initial one
	TElem* eNew = new TElem[2 * cp];
	int* linkNew = new int[2 * cp];

	//We copy all the elements from the old array into the new one
	for (int i = 0; i < n; i++)
	{
		eNew[i] = e[i];
		linkNew[i] = link[i];
	}

	firstEmpty = n;

	//Doubling the capacity
	cp *= 2;

	for (int i = n; i < cp - 1; i++)
		linkNew[i] = i + 1;

	linkNew[cp - 1] = -1;

	//Freeing the memory occupied by the initial arrays
	delete[] e;
	delete[] link;

	//Now e and link will refer to the newly created arrays
	e = eNew;
	link = linkNew;
}

bool Set::add(TElem elem) {
	if (n == 0)
	{
		head = tail = firstEmpty;
		e[head] = elem;
		firstEmpty = link[firstEmpty];
		link[tail] = -1;
		n = 1;

		return true;
	}

	if (n == cp)
		resize();
	
	// we search if the element already exists
	if (search(elem))
		return false;

	link[tail] = firstEmpty;
	tail = firstEmpty;
	e[tail] = elem;
	firstEmpty = link[firstEmpty];
	link[tail] = -1;

	n++;

	return true;
}

bool Set::remove(TElem elem) {
	if (!search(elem))
		return false;

	if (e[head] == elem)
	{	
		int oldHead = head;
		int newHead = link[head];

		link[oldHead] = firstEmpty;
		firstEmpty = oldHead;

		head = newHead;

		n--;

		return true;
	}

	SetIterator it = iterator();

	int prev = it.current;
	it.next();
	while (it.getCurrent() != elem) {
		prev = it.current;
		it.next();
	}

	link[prev] = link[it.current];

	// adding an empty element to the list
	link[it.current] = firstEmpty;
	firstEmpty = it.current;

	if (it.current == tail)
		tail = prev;

	//Decremented the size
	n--;

	return true;
}

bool Set::search(TElem elem) const {
	SetIterator it = iterator();

	while (it.valid()) {
		if (it.getCurrent() == elem)
			return true;

		it.next();
	}

	return false;
}

void Set::empty() {
	// delete all elements
	
	std::stack<int> values;
	SetIterator it = iterator();

	while (it.valid()) {
		values.push(it.getCurrent());
		it.next();
	}

	while (!values.empty()) {
		remove(values.top());
		values.pop();
	}
}

int Set::size() const {
	return n;
}


bool Set::isEmpty() const {
	return n == 0;
}


Set::~Set() {
	delete[] e;
	delete[] link;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}
