#pragma once

#define NULL_TELEM -111111
typedef int TElem;
class SetIterator;

class Set {
	friend class SetIterator;

    private:
        int cp; // maximum capacity
        int n; // actual size of array
        TElem* e; // dynamic array of TElem elements
        int* link; // dynamic array for the links between elements
        int head; // index of the first element of the list
        int tail; // index of the last element of the list
        int firstEmpty; // index of first free space of the array

        void resize(); // resizes the dynamic arrays

    public:
        //implicit constructor
        Set();

        //adds an element to the set
		//returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
        bool add(TElem e);

        //removes an element from the set
		//returns true if e was removed, false otherwise
        bool remove(TElem e);

        //checks whether an element belongs to the set or not
        bool search(TElem elem) const;

        //returns the number of elements;
        int size() const;

        //check whether the set is empty or not;
        bool isEmpty() const;

        void empty();

        //return an iterator for the set
        SetIterator iterator() const;

        // destructor
        ~Set();

};





