// Mutlu Mete
// Stack implementation using linked list, A dynamic data container
// CSCI 520


#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html

using namespace std;

// A struct to keep items
char PushArr[] = {'[', '{', '(', '<'};
char PopArr[] = {']', '}', ')', '>'};
struct node {
    char data;
    node *next;
    node(char x, node* t) {
        data = x;
        next = t;
    }
};

typedef node * nlink;

// A class to represent Stack, where we push and pop items.
// The items (strings) are not sorted in the list.
class Stack {
public:
    Stack();                        // Construction
    bool push (char str);            // Adds a new item to stack
    bool pop ();                    // remove the head guy (the most recently added item)
    bool isEmpty ();                // check if we have any item added.
    void ListAll();                    // List all items of stack.
    char has(char str);            // Check if stack has this item
    char top();                   // Return the item on the top, the most recently added
    unsigned short getSize();        // How many items  the stack has
    bool matchp(char first, char last);
private:
    nlink head;                        // A pointer to show the head node
    unsigned short size;            // how many items stack has
};

// Initialize the class
Stack::Stack() {
    size = 0;
    head = NULL;
    cout << "A stack was created...!" << endl ;
}
// How many items the Stack has
unsigned short Stack::getSize () {
    return size;
}

char Stack::top () {
    if (head == NULL) return 'N';
    return head ->data;
}

// add an item as the head one in the stack
bool Stack::push(char str) {
    nlink NewItemPtr = new node(str, head);    //  dynamically create a new struct/item
    if ( NewItemPtr == NULL) return false;  // not enought memory
    head = NewItemPtr;
    size++;
    return true;    // Yeah, added.
}

// remove the head one from the stack
bool Stack::pop() {
    if (head == NULL)
    {
        return false;
    }
    
    cout << head->data << endl;
    
    nlink RemovePtr = head;
    head = head->next;
    delete RemovePtr;
    size--;
    return true;    // Yeah, removed.
}

// List, print out, all items in the arrays
// make 5 coloumns
void Stack::ListAll() {
    nlink it = head;   // it means iterator, visit all items one by one.
    
    int i=0;
    while (it != NULL) {
        cout << it->data << " ";
        it = it->next;
        //if ( (i+1)%5 == 0) cout << endl;
        i++;
    }
    cout << endl;
}

// Check if the bag has item "str"

char Stack::has(char str) {
    nlink it = head;
    for (int i=0; i < size; i++) {
        if (it->data == str) return 'Y';
        it = it->next;
    }
    return 'N';
}
bool Stack::matchp(char first, char last) {
    
    if((first == '[' && last == ']') || (first == '{' && last == '}') ||
       (first == '(' && last == ')') || (first == '<' && last == '>'))
        return true;
    return false;
}

int main(int argc, const char * argv[]) {
    
    Stack Parenthesis_stack;
    string tempStr;
    cout << "Enter a String to check balanced or not ::: " << endl;
    cin >> tempStr;
    char inputStr[50];
    strcpy(inputStr, tempStr.c_str()); //Copy string to char array
    if(sizeof(tempStr) > 50 ) {
        cout << "Can not enter String more than 50 characters" << endl;
        exit(0);
    }
    for(char c : inputStr) {
        char *push_char = find(begin(PushArr), end(PushArr), c);
        char *pop_char = find(begin(PushArr), end(PushArr), c);
        cout << "push char " << *push_char;
        if(push_char != end(PushArr)) {
            Parenthesis_stack.push(c);
        }
        else if(pop_char != end(PopArr)) {
            if(Parenthesis_stack.isEmpty() || !Parenthesis_stack.matchp(Parenthesis_stack.top(), c)){
                cout << "No match of Parenthesis" << endl;
            }
            else
                Parenthesis_stack.pop();
        }
        
    }
    if(Parenthesis_stack.isEmpty())
        cout << "String is Validated as Balanced Parenthesis" << endl;
    else
        cout << "String is not balanced Parenthesis" << endl;
    /*while (sel != 'e') {
     cout << "p(u)sh, p(o)p, (s)earch, (t)op, (e)xit:   ";
     cin >> sel;
     switch (sel) {
     case 's' :
     cout << "\nString to be searched:";
     cin >> tempStr;
     cout << S.has(tempStr);
     break;
     
     case 'u' :
     cout << "\nString to be pushed:";
     cin >> tempStr;
     S.push(tempStr);
     S.ListAll();
     break;
     case 'o' :
     S.pop();
     S.ListAll();
     break;
     
     case 't' :
     cout << S.top() << endl;
     break;
     default:
     break;
     }
     }*/
}

