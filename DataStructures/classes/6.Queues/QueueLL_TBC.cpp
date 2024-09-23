// Mutlu Mete
// Queue implementation using linked list, A dynamic data container
// CSCI 520

// FIFO structure

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html

using namespace std;

// A struct to keep items
struct item
{
    string data;
    item *next;
	item(string x, item* t) { // constructor
		data = x; next = t;
	}
};

typedef item * link;

// A class to represent Queue, where we enqueue and dequeue items.
// The items (strings) are not sorted in the list.
class Queue {
public:
    Queue();						// Construction
    bool enqueue(string str);		// Adds a new item to Queue
    bool dequeue ();				// remove the first item (the least recently added item)
    bool isEmpty ();				// check if we have any item added.
    void takeOut (string str);		// delete an arbitrar item in the queue, Not so common
    void ListAll();					// List all items of Queue, starting with the first ITEM
    bool has(string str);			// Check if Queue has this item
    string top();                   // Return (do not removed) the item on the end, the most recently 'enqueue'ed
    string bottom();                // Return the item at the bottom, the least recently 'enqueue'ed
    unsigned short getSize();		// How many items  he Queue has
private:
    link first;					// A pointer to show the first node, the one will be dequeued
    link last;                     // A pointer to show the last node
    unsigned short size;			// how many items Queue has
};

// Initialize the class
Queue::Queue() {
    size = 0;
    ?? = NULL;
    cout << "A queue was created...!" << endl ;
}
// How many items the Stack has
unsigned short Queue::getSize ()
{
    return size;
}

void Queue::takeOut(string str) {
    link back;
	link front;
	if (first == NULL) return ;
	first=last=first;

	if(first->data == str) // delete this
	{
		if (first == last) // there is only one item, which will be deleted
			first = last = NULL;
		else
			first = first->next;	// first of many items is being deleted
		delete front;
		size--;
		return ;
	}

	front = front->next;	// if reach this line, the first item of bag is not being deleted.

	while (front != NULL )
	{
		if (front->data == str)
		{
			back->next = front->next;	// a mid-item is being deleted. By-pass the (front)
			if (front == str) last = back; // the last item is being deleted
			delete front;
			size--;
			return ;
		}
		back = front ;
		front = front -> next;
    }
	return	; // if reach this line, item is not found in the list.
}

bool Queue::enqueue(string str) {			// Adds a new item to Queue

	link  NewItemPtr = new item(str, ??);//  dynamically create a new struct/item

    if ( NewItemPtr == NULL) return ??;  // not enought memory

    if ( first == NULL) {				// first item to be added
        first = last = NewItemPtr;
    } else {
        last->next = NewItemPtr;
        last = NewItemPtr;
    }
	size++;				//  update the size
    return true;	//  added.
}

bool Queue::dequeue () {			// remove the first item (the least recently added item)
    if ( first == NULL ) { 			// Check if there is an item in the queue
        return false;
    } else {
        link FirstItemPtr = first;
        first = first->next;
        delete FirstItemPtr;
        size--;				//  update the size
        return true;
    }
	// Question: What happens to "last" pointer if last item is dequeued.
}

bool Queue::isEmpty() {		// check if we have any item added.
    if (size == 0 ) return true;
    return false;

	 // alternatively if (! ?? )

}
void Queue::ListAll() {			// List all items of Queue, starting with the first ITEM
    link it = first;
	cout << size << ": ";
    while (it != NULL) {
        cout << it->data << "   ";
        it = it->next;
    }
    cout << endl;
}

bool Queue::has(string str) {		// Check if Queue has this item
    link it = first;
    for (int i=0; i < size; i++) {
        if (it->data == str) return true;
        it = it ->next;
    }
    return false;
}

string Queue::top() {   // Return the item on the end, the most recently 'enqueue'ed
    if (last == NULL)  return " ";
    return last->data;
}

string Queue::bottom() {   // Return the item on the end, the least recently 'enqueue'ed
    if (first == NULL)  return " ";
    return first->data;
}

int main(int argc, const char * argv[]) {

    Queue Q;
    string tempStr;
	char sel = ' ';
	while (sel != 'x')
	{
		cout << "(e)nQ, (d)eQ, (s)earch, (t)akeout (x)xit:   ";
		cin >> sel;
		switch(sel)
		{
			case 'e':
					cout << "\nString to be EnQueued:";
					cin >> tempStr;
					Q.enqueue(tempStr);
					Q.ListAll();
					break;
			case 'd':
					Q.dequeue();
					Q.ListAll();
					break;
			case 's':
					cout << "\nString to be searched: ";
				    cin >> tempStr;
					cout << Q.has(tempStr) << endl;
					break;
			case 't':
					cout << "\nString to be taken out: ";
				    cin >> tempStr;
					Q.takeOut(tempStr);
					Q.ListAll();
					break;
			default:
					break;
		}
	}

}
