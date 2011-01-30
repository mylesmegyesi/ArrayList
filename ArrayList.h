/**
 * @ArrayList.h
 * @author  Myles Megyesi <myles.megyesi@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * Copyright (c) 2010, Myles Megyesi
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * My name may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Myles Megyesi BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_
#include <exception>
using namespace std;

template<class Object>
class ArrayList {
	public:
		/**
		 * Default Contructor
		 *
		 * @throws MemoryFailureException upon memory allocation failure.
		 */
		ArrayList();
		
		/**
		 * Constructs an empty list with the specified initial capacity.
		 *
		 * @param size The initial capacity of the list.
		 * @throws MemoryFailureException upon memory allocation failure.
		 */
		ArrayList(unsigned int size);
		
		/**
		 * Constructs an ArrayList containing the elements of the specified ArrayList.
		 * The ArrayList instance has an initial capacity of 110% the size of the specified collection.
		 * 
		 * @param a The ArrayList whose elements are to be placed into this ArrayList.
		 * @throws MemoryFailureException upon memory allocation failure.
		 */
		ArrayList(const ArrayList<Object> &a);
	
		/**
		 * Destructor
		 */
		~ArrayList();
	
		/**
		 * Constructs an ArrayList containing the elements of the specified ArrayList.
		 * The ArrayList instance has an initial capacity of 110% the size of the specified collection.
		 *
		 * @param a The ArrayList whose elements are to be placed into this ArrayList.
		 * @returns A reference to a newly allocated ArrayList.
		 */
		ArrayList& operator = (const ArrayList<Object> &a);
	
		/**
		 * Compares the specified ArrayList with this ArrayList for equality.
		 * Returns true if and only if both ArrayLists have the same size, 
		 * and all corresponding pairs of elements in the two lists are equal.
		 * Uses the == operator of the Object Class.
		 *
		 * @param a the ArrayList to be compared for equality with this ArrayList.
		 * @returns A boolean, specifying equality of the given ArrayList to this ArrayList.
		 * @throws MemoryFailureException upon memory allocation failure.
		 */
		bool operator == (const ArrayList<Object> &a);
		
		/**
		 * Compares the specified ArrayList with this ArrayList for equality.
		 * Returns false if ArrayLists have different size, 
		 * or any of the corresponding pairs of elements in the two lists are not equal.
		 *
		 * @param a the ArrayList to be compared for inequality with this ArrayList.
		 * @returns A boolean, specifying inequality of the given ArrayList to this ArrayList.
		 */
		bool operator != (const ArrayList<Object> &a);
		
		/**
		 * Creates a new ArrayList comprised of all of the elements in this ArrayList and the specified ArrayList.
		 * The items in the this ArrayList will be in front of the newly created ArrayList.
		 * 
		 * @param a The elements to combine with this ArrayList.
		 * @returns A pointer to a newly created ArrayList.
		 */
		ArrayList<Object>* operator + (const ArrayList<Object> &a);
		
		/**
		 * Appends all of the elements in the specified ArrayList to the end of this ArrayList.
		 *
		 * @param a The elements to be inserted into this ArrayList.
		 * @throws MemoryFailureException upon memory allocation failure.
		 */
		void operator += (const ArrayList<Object> &a);
		
		/**
		 * Creates a new ArrayList comprised of all of the elements in this ArrayList with elements in the
		 * specified ArrayList removed.
		 * 
		 * @param a The elements to remove from the new ArrayList.
		 * @returns A pointer to a newly created ArrayList.
		 * @throws MemoryFailureException upon memory allocation failure.
		 */
		ArrayList<Object>* operator - (const ArrayList<Object> &a);
		
		/**
		 * Removes all of the elements in the specified ArrayList from this ArrayList.
		 *
		 * @param a The elements to be inserted into this ArrayList.
		 */
		void operator -= (const ArrayList<Object> &a);
		
		/**
		 * Returns the element at the specified position in this list.
		 *
		 * @param index The index of element to return.
		 * @returns The element at the specified index.
		 * @throws MemoryFailureException upon memory allocation failure.
		 */
		Object& operator [] (unsigned int index);
		
		/**
		 * Inserts the specified element at the specified position in this list.
		 * Shifts the element currently at that position (if any) and any subsequent elements to the right
		 * (adds one to their indices).
		 * 
		 * @param index The index at which the specified element is to be inserted.
		 * @param item The element to be inserted.
		 * @throws BadAccessException if the specified index is out of bounds (is allowed to be equal to the current size).
		 */
		void add(unsigned int index, const Object &item);
		
		/**
		 * Searches for all occurences of the given element, testing for equality using the == operator.
		 *
		 * @param item The element to search for.
		 * @returns A pointer to a newly created ArrayList of integers. Each entry contains the index of a found element.
		 * @throws MemoryFailureException upon memory allocation failure.
		 * @throws BadAccessException if the specified index is out of bounds.
		 */
		ArrayList<int>* allIndicesOf(const Object &item);
		
		/**
		 * Appends the specified element to the end of this ArrayList.
		 *
		 * @param item The element to be appended.
		 */
		void append(const Object &item);
		
		/**
		 * Appends all the elements of the specified ArrayList to the end of this ArrayList.
		 *
		 * @param items The ArrayList of elements to be appended.
		 */
		void appendAll(const ArrayList<Object> &items);
		
		/**
		 * Searches to find if this ArrayList contains the specified element.
		 *
		 * @param item The element whose presence in this ArrayList is to be tested.
		 */
		bool contains(const Object &item);
		
		/**
		 * Searches to find if this ArrayList contains all of the elemesnts in the specified ArrayList.
		 *
		 * @param item The element whose presence in this ArrayList is to be tested.
		 */
		bool containsAll(const ArrayList<Object> &a);
		
		/**
		 * Increases the capacity of this ArrayList instance, if necessary,
		 * to ensure that it can hold at least the number of elements specified by the minimum capacity argument.
		 *
		 * @param minCapacity The desired minimum capacity.
		 * @throws MemoryFailureException upon memory allocation failure.
		 */
		void ensureCapacity(int minCapacity);
		
		/**
		 * Compares the specified ArrayList with this ArrayList for equality.
		 * Returns true if and only if both ArrayLists have the same size, 
		 * and all corresponding pairs of elements in the two lists are equal.
		 * Uses the == operator of the Object Class.
		 *
		 * @param a the ArrayList to be compared for equality with this ArrayList.
		 * @returns A boolean, specifying equality of the given ArrayList to this ArrayList.
		 */
		bool equals(const ArrayList<Object> &a);
		
		/**
		 * Returns the index in this ArrayList of the first occurrence of the specified element,
		 * or -1 if this ArrayList does not contain this element.
		 *
		 * @param item The element to search for.
		 * @returns The index in this ArrayList of the first occurrence of the specified element,
		 * or -1 if this ArrayList does not contain this element.
		 */
		int firstIndexOf(const Object &item);
		
		/**
		 * Returns the element at the specified position in this list.
		 *
		 * @param index The index of element to return.
		 * @returns The element at the specified index.
		 * @throws BadAccessException if the specified index is out of bounds.
		 */
		Object& get(unsigned int index);
		
		/**
		 * Returns all the elements of the of the matching indices of the specified ArrayList of integers.
		 *
		 * @param a An ArrayList of integers specifying indices to return.
		 * @returns The elements at the specified indices.
		 * @throws MemoryFailureException upon memory allocation failure.
		 * @throws BadAccessException if the specified index is out of bounds.
		 */
		ArrayList* getAll(const ArrayList<int> &a);
		
		/**
		 * Tests if this list has no elements.
		 *
		 * @returns A boolean representing whether the ArrayList is empty.
		 */
		bool isEmpty();
		
		/**
		 * Returns the index in this ArrayList of the last occurrence of the specified element,
		 * or -1 if this ArrayList does not contain this element.
		 *
		 * @param item The element to search for.
		 * @returns The index in this ArrayList of the last occurrence of the specified element,
		 * or -1 if this ArrayList does not contain this element.
		 */
		int lastIndexOf(const Object &item);
		
		/**
		 * Prepends the specified element to the front of this ArrayList.
		 *
		 * @param item The element to be prepended.
		 */
		void prepend(const Object &item);
		
		/**
		 * Prepends all the elements of the specified ArrayList to the front of this ArrayList.
		 *
		 * @param items The ArrayList of elements to be prepended.
		 */
		void prependAll(const ArrayList<Object> &items);
		
		/**
		 * Removes the element at the specified position in this ArrayList.
		 * Shifts any subsequent elements to the left (subtracts one from their indices).
		 *
		 * @param index The index of the element to removed.
		 * @throws BadAccessException if the specified index is out of bounds.
		 */
		void remove(unsigned int index); 
	
		/**
		 * Removes every occurence of the specified element.
		 * Shifts any subsequent elements to the left (subtracts one from their indices).
		 *
		 * @param index The element to removed.
		 */
		void removeAll(const Object &item);
		
		/**
		 * Removes all elements in the specified ArrayList.
		 * Shifts any subsequent elements to the left (subtracts one from their indices).
		 *
		 * @param items The ArrayList of elements to be prepended.
		 */
		void removeAll(const ArrayList<Object> &items);
		
		/**
		 * Removes the first occurence of the specified element.
		 * Shifts any subsequent elements to the left (subtracts one from their indices).
		 *
		 * @param index The element to removed.
		 */
		void removeFirst(const Object &item);
		
		/**
		 * Removes the last occurence of the specified element.
		 * Shifts any subsequent elements to the left (subtracts one from their indices).
		 *
		 * @param index The element to removed.
		 */
		void removeLast(const Object &item);
		void reverse();
		
		/**
		 * Replaces the element at the specified position in this ArrayList with the specified element.
		 *
		 * @param index The index of element to replace.
		 * @param item The element to be stored at the specified position.
		 * @throws BadAccessException if the specified index is out of bounds.
		 */
		void set(unsigned int index, const Object &item);
		
		/**
		 * Returns the number of elements in this ArrayList.
		 *
		 * @returns The number of elements in this list.
		 */
		int size();
		
		/**
		 * Returns a view of the portion of this list between fromIndex, inclusive, and toIndex, exclusive.
		 * (If fromIndex and toIndex are equal, the returned list is empty.)
		 *
		 * @param fromIndex The low endpoint (inclusive) of the subList.
		 * @param toIndex The high endpoint (exclusive) of the subList.
		 * @returns A pointer to a newly created ArrayList with the elements of the specified range.
		 * @throws MemoryFailureException upon memory allocation failure.
		 * @throws BadAccessException if the specified indices is out of bounds.
		 */
		ArrayList<Object>* subList(unsigned int fromIndex, unsigned int toIndex);
		
		/**
		 * Resizes the internal array to be the size of the number of elements.
		 */
		void trimToSize();
	
	private:
		Object* array;
		unsigned int _size;
		unsigned int memsize; 
		const static int basesize = 16;
		
		void copy(const ArrayList<Object> &a);
		void doublesize();
		void halfsize();
};

class BadAccessException: public exception {
	public:
		virtual const char* what() const throw(){
			return "Attempting to subscript array element that doesn't exist";
		}
} badaccess;

class MemoryFailureException: public exception {
	public:
		virtual const char* what() const throw(){
			return "Memory Allocation Failed";
		}
} memfail;

// Public methods 
template <class Object>
ArrayList<Object>::ArrayList() {
    array = new Object[basesize];
    if (array == NULL){
		throw memfail;
	}
	_size = 0;
	memsize = basesize;
}

template <class Object>
ArrayList<Object>::ArrayList(unsigned int size) {
	if (size == 0) {
		array = NULL;
	}
	else {
		array = new Object[size];
		if (array == NULL){
			throw memfail;
		}
	}
	_size = 0;
	memsize = size;
}

template <class Object>
ArrayList<Object>::ArrayList(const ArrayList<Object> &a) {
	copy(a);
}

template <class Object>
ArrayList<Object>::~ArrayList() {
    if (array){
    	delete [] array;
    	array = NULL;
    }
}


template <class Object>
ArrayList<Object>& ArrayList<Object>::operator = (const ArrayList<Object> &a) {
	if (this != &a) {
		delete [] array;
		copy(a);
	}
	return *this;
}

template <class Object>
bool ArrayList<Object>::operator == (const ArrayList<Object> &a) {
	return equals(a);
}

template <class Object>
bool ArrayList<Object>::operator != (const ArrayList<Object> &a) {
	return !equals(a);
}

template <class Object>
ArrayList<Object>* ArrayList<Object>::operator + (const ArrayList<Object> &a) {
	ArrayList<Object>* temp = new ArrayList<Object>(*this);
	if (temp == NULL) {
		throw memfail;
	}
	temp->appendAll(a);
	return temp;
}

template <class Object>
void ArrayList<Object>::operator += (const ArrayList<Object> &a) {
	appendAll(a);
}

template <class Object>
ArrayList<Object>* ArrayList<Object>::operator - (const ArrayList<Object> &a) {
	ArrayList<Object>* temp = new ArrayList<Object>(*this);
	if (temp == NULL) {
		throw memfail;
	}
	temp->removeAll(a);
	return temp;
}

template <class Object>
void ArrayList<Object>::operator -= (const ArrayList<Object> &a) {
	removeAll(a);
}


template <class Object>
Object& ArrayList<Object>::operator [] (unsigned int index) {
	return get(index); 
}

template <class Object>
void ArrayList<Object>::add(unsigned int index, const Object &item) {
	if (index > _size) {
		throw badaccess;
	}	
	if ((_size+1) > memsize) {
		doublesize();
    }
	for(int i=_size; i>index; i--) {
		array[i] = array[i-1];
	}
	array[index] = item;
	_size++;
}

template <class Object>
ArrayList<int>* ArrayList<Object>::allIndicesOf(const Object &item) {
	ArrayList<int>* temp = new ArrayList();
	for(int i=0; i<_size; i++) {
		if (array[i] == item) {
			temp->append(i);
		}
	}
	return temp;
}

template <class Object>
void ArrayList<Object>::append(const Object &item) {	
	if ((_size+1) > memsize) {
		doublesize();
    }
	array[_size] = item;
	_size++;
}

template <class Object>
void ArrayList<Object>::appendAll(const ArrayList<Object> &items){
	for(int i=0; i<items._size; i++) {
		append(items.array[i]);
	}
}

template <class Object>
bool ArrayList<Object>::contains(const Object &item) {
	for(int i=0; i<_size; i++) {
		if (array[i] == item) {
			return true;
		}
	}
	return false;
}

template <class Object>
bool ArrayList<Object>::containsAll(const ArrayList<Object> &a){
	for(int i=0; i<a._size; i++) {
		if (!contains(a.array[i])) {
			return false;
		}
	}
	return true;
}

template <class Object>
void ArrayList<Object>::ensureCapacity(int minCapacity){
	if (memsize >= minCapacity) {
		return;
	}
	Object* temp = new Object[minCapacity];
	if (temp == NULL) {
		throw memfail;
	}
	for(int i=0; i<_size; i++) {
		temp[i] = array[i];
	}
	delete [] array;
	array = temp;
	memsize = minCapacity;
}

template <class Object>
bool ArrayList<Object>::equals(const ArrayList<Object> &a) {
	if (_size != a._size) {
		return false;
	}
	for (int i=0; i<_size; i++) {
		if (array[i] != a.array[i]) {
			return false;
		}
	}
	return true;
}

template <class Object>
int ArrayList<Object>::firstIndexOf(const Object &item) {
	for (int i=0; i<_size; i++) {
		if (array[i] == item) {
			return i;
		}
	}
	return -1;
}

template <class Object>
Object& ArrayList<Object>::get(unsigned int index) {
	if (index > (_size-1)) {
		throw badaccess;
	}
    return array[index]; 
}

template <class Object>
ArrayList<Object>* ArrayList<Object>::getAll(const ArrayList<int> &a){
	ArrayList<Object>* temp = new ArrayList();
	if (temp == NULL) {
		throw memfail;
	}
	for(int i=0; i<a._size; i++){
		temp->append(array[a.array[i]]);
	}
	return temp;
}

template <class Object>
bool ArrayList<Object>::isEmpty() {
	if (_size == 0) {
		return true;
	}
	return false;
}

template <class Object>
int ArrayList<Object>::lastIndexOf(const Object &item) {
	for (int i=_size-1; i>=0; i++) {
		if (array[i] == item) {
			return i;
		}
	}
	return -1;
}

template <class Object>
void ArrayList<Object>::prepend(const Object &item) {
	add(0, item);
}

template <class Object>
void ArrayList<Object>::prependAll(const ArrayList<Object> &items) {
	for(int i=items._size-1; i>=0; i--) {
		add(0, items.array[i]);
	}
}

template <class Object>
int ArrayList<Object>::size() {
	return _size;
}

template <class Object>
void ArrayList<Object>::remove(unsigned int index) {
	if (index > (_size-1)){
		throw badaccess;
	}
	for(unsigned int i=index; i<_size-1; i++) {
		array[i] = array[i+1];
	}
	_size--;
	if (_size <= (memsize/4) && memsize > basesize) {
		halfsize();
	}
}

template <class Object>
void ArrayList<Object>::removeAll(const Object &item) {
	for(int i=_size-1; i>=0; i--) {
		if (array[i] == item) {
			remove(i);
		}
	}
}

template <class Object>
void ArrayList<Object>::removeAll(const ArrayList<Object> &items) {
	for(int i=0; i<items._size; i++) {
		removeAll(items.array[i]);
	}
}

template <class Object>
void ArrayList<Object>::removeFirst(const Object &item) {
	for(int i=0; i<_size; i++) {
		if (array[i] == item) {
			remove(i);
			return;
		}
	}
}

template <class Object>
void ArrayList<Object>::removeLast(const Object &item) {
	for(int i=_size-1; i>=0; i++) {
		if (array[i] == item) {
			remove(i);
			return;
		}
	}
}

template <class Object>
void ArrayList<Object>::reverse() {
	Object* temp = new Object[memsize];
	if (temp == NULL) {
		throw memfail;
	}
	for(int i=_size-1; i>=0; i--) {
		temp[_size-1-i] = array[i];
	}
	delete [] array;
	array = temp;
}

template <class Object>
void ArrayList<Object>::set(unsigned int index, const Object &item) {
	if (index > _size) {
		throw badaccess;
	}
	array[index] = item;
}

template <class Object>
ArrayList<Object>* ArrayList<Object>::subList(unsigned int fromIndex, unsigned int toIndex) {
	ArrayList<Object>* temp = new ArrayList();
	if (temp == NULL) {
		throw memfail;
	}
	if (toIndex >= _size || fromIndex >= _size) {
		throw badaccess;
	}
	if (fromIndex >= toIndex) {
		return temp;
	}
	for(int i=fromIndex; i<toIndex; i++) {
		temp->append(array[i]);
	}
	return temp;
}

template <class Object>
void ArrayList<Object>::trimToSize() {
	if (_size == memsize) {
		return;
	}
	Object* temp = new Object[_size];
	if (temp == NULL) {
		throw memfail;
	}
	for(int i=0; i<_size; i++) {
		temp[i] = array[i];
	}
	delete [] array;
	array = temp;
	memsize = _size;
}

// Private methods

template <class Object>
void ArrayList<Object>::copy(const ArrayList<Object> &a) {
	array = new Object[a.memsize];
	if (array == NULL) {
		throw memfail;
	}
	for (int i=0; i<a._size; i++) {
		array[i] = a.array[i];
	}
    memsize = a.memsize;
    _size = a._size;
}

template <class Object>
void ArrayList<Object>::doublesize() {
	Object* temp = NULL;
	int new_size;
	if (memsize == 0) {
		temp = new Object[basesize];
		new_size = 1;
	}
	else {
		temp = new Object[memsize*2];
		new_size = memsize*2;
	}
	if (temp == NULL) {
		throw memfail;
	}
	for(int i=0; i<_size; i++) {
		temp[i] = array[i];
	}
	delete [] array;
	array = temp;
	memsize = new_size;
}

template <class Object>
void ArrayList<Object>::halfsize() {
	int resize = memsize/2;
	if (memsize < (basesize*2)) {
		resize = basesize;
	}	
	Object* temp = new Object[resize];
	if (temp == NULL) {
		throw memfail;
	}
	for(int i=0; i<_size; i++) {
		temp[i] = array[i];
	}
	delete [] array;
	array = temp;
	memsize = resize;
}

#endif