#include "ObjectsInHeap.h"
#include<iostream>

using namespace std;

int ObjectsInHeap::totalNumberOfObjects = 0;
int ObjectsInHeap::m_objectInHeap = 0;


ObjectsInHeap::ObjectsInHeap():
	nonStaticDataMember(0) {
	++totalNumberOfObjects;
	cout << "Ctor:-> No. Of Objects Created:-> " << totalNumberOfObjects << endl;
}

ObjectsInHeap::~ObjectsInHeap() {
	--totalNumberOfObjects;
	cout << "Dtor:-> No. Of Objects remaining:-> " << totalNumberOfObjects << endl;
}

ObjectsInHeap::ObjectsInHeap(const ObjectsInHeap& obj) :
	nonStaticDataMember(0) {
	cout << "Copy Ctor:-> " << endl;
}

void* ObjectsInHeap::operator new(size_t size) {
	++m_objectInHeap;
//	void* ptr = ::new ObjectsInHeap ( ); 
	void *ptr = malloc(size);
	cout << "New:-> No. Of Heap Objects:-> " << m_objectInHeap << endl;
	//return nullptr; / with this nullptr return, Ctor not called and Dtor not called and as memory not allocated and not deleted
	return ptr;
}

void ObjectsInHeap::operator delete(void* ptr) {
	--m_objectInHeap;
	free (ptr);

	cout << "delete:->  No. Of Heap Objects:-> " << m_objectInHeap << endl;
}

int ObjectsInHeap::getNumber() {
	m_objectInHeap = 99;
//	nonStaticDataMember = 100;
	return totalNumberOfObjects;
}

