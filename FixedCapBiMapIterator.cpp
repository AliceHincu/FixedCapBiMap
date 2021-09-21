#include "FixedCapBiMap.h"
#include "FixedCapBiMapIterator.h"
#include <exception>
using namespace std;


FixedCapBiMapIterator::FixedCapBiMapIterator(const FixedCapBiMap& d) : map(d)
{
    this->current = 0;
}//Theta(1)


void FixedCapBiMapIterator::first() {
	this->current = 0;
}//Theta(1)


void FixedCapBiMapIterator::next() {
    if (!valid()) throw exception();
    else this->current++;
}//Theta(1)


TElem FixedCapBiMapIterator::getCurrent(){
    if (!valid()) throw exception();
    return this->map.elements[this->current];
}//Theta(1)


bool FixedCapBiMapIterator::valid() const {
	if (this->current < this->map.nrPairs) return true;
	return false;
}//Theta(1)



