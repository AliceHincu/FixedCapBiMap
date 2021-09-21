#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>

using namespace std;

FixedCapBiMap::FixedCapBiMap(int capacity) {
    if (capacity <= 0){
        throw exception();
    }
    this->capacity = capacity;
    this->nrPairs = 0;
    this->elements = new TElem[capacity];
} // Theta(1)

FixedCapBiMap::~FixedCapBiMap() {
	// ~ destructor
	delete[] this->elements;
} // Theta(1)


bool FixedCapBiMap::add(TKey c, TValue v){
    // if the array it's full
	if (this -> capacity == this -> nrPairs){
        throw exception();
    }

	// for a FixedCapBiMap, a key must have only 2 values. We count how many values has the key c.
	int index = 0;
	int count = 0;
	while (count < 2 && index < this->nrPairs){
	    if (this->elements[index].first == c){
	        count++;
	    }
	    index++;
	}

	// the key has already 2 associated values, we can't add anymore (since we must have maximum 2 values)
	if (count == 2){
	    return false;
	} else{ // "nrPairs" is also the first position that is not occupied (since we count from 0) so we use it as index
	    this->elements[this->nrPairs].first = c;
	    this->elements[this->nrPairs].second = v;
	    this->nrPairs++;
	    return true;
	}
}//best case: Theta(1)..Worst case:Theta(nrPairs)  => Total Complexity: O(nrPairs)


ValuePair FixedCapBiMap::search(TKey c) const{
    //return the pair of values associated with the keys
	ValuePair returnedValue;
	//we start with the assumption that the key is not in the container
	returnedValue.first = NULL_TVALUE;
	returnedValue.second = NULL_TVALUE;

	// stat looking for the values
	int count = 0;
	int index = 0;
    while(count < 2 && index < this->nrPairs){
        if (this->elements[index].first == c) { // we found the key
            if (count == 0){ // we found the first value
                returnedValue.first = this->elements[index].second;
            }
            else{ // we found the second value
                returnedValue.second = this->elements[index].second;
            }
            count++;
        }
        index++;
    }

	return returnedValue;
}//best case: Theta(1)..Worst case:Theta(nrPairs)  => Total Complexity: O(nrPairs)


bool FixedCapBiMap::remove(TKey c, TValue v){
    // check if the pair exists
	int index = 0;
	bool found = false;
	while(index < this->nrPairs && !found){
	    if(this->elements[index].first == c && this->elements[index].second == v){
	        found = true;
	    }
	    else{
	        index++;
	    }
	}

	// we didn't find it
    if (!found) return false;
    else{
        // take the last element and move it into this position (replace the removed pair with the last pai, since it isn't ordered
        this->elements[index] = this->elements[nrPairs-1];
        nrPairs--;
        return true;
    }
}//best case: Theta(1)..Worst case:Theta(nrPairs)  => Total Complexity: O(nrPairs)


int FixedCapBiMap::size() const {
    return this->nrPairs;
    //if we have an operation names "size()" we can't have a variable "this->size"
}//Theta(1)


bool FixedCapBiMap::isEmpty() const{
	if (this->nrPairs == 0) return true;
	else return false;
}//Theta(1)


bool FixedCapBiMap::isFull() const {
    if (this->nrPairs == this->capacity) return true;
    else return false;
}//Theta(1)


FixedCapBiMapIterator FixedCapBiMap::iterator() const {
	return FixedCapBiMapIterator(*this);
}//Theta(1)



