//
//  main.cpp
//  Queues
//
//  Created by Shruthi Pavan on 2/6/19.
//  Copyright © 2019 Shruthi Pavan. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

int CAPACITY = 1000;
const char stringarr[] = "abcdefghijklmnopqrstuvwxyz";
const string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const string states[] = {"Dallas, TX", "Miami, FL", "Albany, NY", "Chicago, IL", "minneapolis, MN", "Commerce, TX"};
struct Customer {
    string name;
    unsigned short int ID;
    string DOB;
    string address;
    Customer *next;
    Customer(string n ,unsigned short int id, string dob, string addr) {
        name = n ;
        ID = id;
        DOB = dob;
        address = addr;
    }
    
};

typedef Customer *link;

class CustomerBag {
public:
    CustomerBag();
    bool add();                         //Adds a single customer
    link add (Customer *cust);          // Adds a new customer to bag
    bool has (unsigned short int ID);   // Check the bag with given ID
    bool remove();                      //Remove Last Customer
    bool remove(unsigned short int ID); //Remove Customer with ID
    bool removeAll();                   //Removes entire bag
    void ListCustInfo(string addr);     // Lists all the customer details for addr
    int totalCust();                    // Total No. Og Customers in bag
    void ListCustomers();
    void ListCustomers(string address);
    unsigned short int getCapacity ();  // get the capacity of the Bag.
    unsigned short getSize();           // How many customers are in the Bag
    
private:
    link first;                         // A pointer to show the first node
    link last;                          // A pointer to show the last node
    unsigned short int size;            // how many items Bag has
};

unsigned short int CustomerBag::getCapacity() { //Customer Bag's Capacity
    return CAPACITY;
}

unsigned short CustomerBag::getSize() {  //How many customers are in Bag
    return size;
}

CustomerBag::CustomerBag() //constructor
{
    size = 0;
    first = last = NULL;
    cout << "Customer Bag with " <<  getCapacity()  << " is created...!" << endl ;
}

link CustomerBag::add(Customer *cust) {
    link newCustomer = cust;
    if(newCustomer == NULL) {
        cout << "No Customer data" <<endl;
        return newCustomer;
    }
    if(first == NULL) first=newCustomer;
    else last->next = newCustomer;
    
    last = newCustomer;
    size++;
    return newCustomer;
}

bool CustomerBag::remove(unsigned short id) {
    link back;
    link front;
    if (first == NULL) return false;
    back=front=first;
    
    if(first->ID == id)
    {
        if (first == last)
            first = last = NULL;
        else
            first = first->next;
        delete front;
        size--;
        return true;
    }
    
    front = front->next;
    while (front != NULL)
    {
        if (front->ID == id)
        {
            back->next = front->next;
            if (front == last) last = back;
            free(front);
            size--;
            return true;
        }
        back = front ;
        front = front -> next;
    }
    return false;
}

bool CustomerBag::remove() {
    cout<<"removing....."<< endl;
    link front , back;
    front = back = first;
    if (front == NULL) return false;
    if(front->next ==  NULL ) {
        delete front;
        front = back = NULL;
        cout << "Deleted Customer Whose ID is : " << front->ID <<endl;
        size--;
        return true;
    }
    front = front -> next;
    while(front->next != NULL) {
        front = front->next;
        back = back->next;
    }
    cout << "Deleted Customer Whose ID is : " << last->ID << endl;
    last = back;
    last->next = NULL;
    delete front;
    size--;
    return true;
}

bool CustomerBag::removeAll() {
    link front;
    front = first;
    if(front == NULL) {
        cout<< ".... Customer List is Empty ...." <<endl;
        return false;
    }
    cout << "Customers :: " ;
    while(first != NULL){
        first = first->next;  //List has atleast 1 customer node
        cout << front->ID << " , ";
        delete front;
        size--;
        front = first;
    }
    cout << endl << "are deleted...." << endl;
    return true;
}

bool CustomerBag::has(unsigned short int id) // Check if the bag has item "str", // You can return bool too
{
    link it = first;
    for (int i=0; i < size; i++)
    {
        if (it->ID == id) return true;
        it = it->next;
    }
    return false;
}

bool CustomerBag::add() {
    link newCust;
    char name[] = "";
    string dob = "";
    string address = "";
    unsigned short int idval =  0;
    //To generate a random string for name
    for ( int i=0; i<=5; i++) {
        name[i] = stringarr[rand()% (sizeof(stringarr) - 1)];
        if(i == 0) name[i] = toupper(name[i]); //Make the first letter uppercase
    }
    //Generate ID for Customer
    while(idval >= 0) {
        idval = (rand()%8999+1000);
        if(!has(idval)) {
            break;
        }
    }
    
    //Generate DOB
    int day = 0;
    string month = months[rand()% 11];
    int year = rand()%99 +1920; //gives value from 1920-2019
    if(month == "Feb" && year%4==0) day = rand()%28 +1; //Leap year calculation
    else if(month == "Feb" && year%4>0) day=rand()%27+1; // Feb days 1-28
    else if(month == "Apr" || month=="Jun" || month=="Sep" || month=="Nov")
        day = rand()%29 +1; // gives random values from 1-30
    else day = rand()%30 +1; //gives random val from 1-31
    
    dob = month +" "+ to_string(day)+ ", " + to_string(year);
    
    //Get Random Address from an array
    address = states[rand()%6];
    
    newCust = new Customer(name, idval, dob, address);
    add(newCust);
    return true;
}

void CustomerBag::ListCustomers()
{
    link it = first;
    int i=0;
    if(it == NULL ) cout << "Sorry, there are no customers in Bag " <<endl;
    while (it != NULL) {
        cout << "Customer["<< i << "] ==> ID:" << it->ID << " name:"<<it->name << " DOB:" << it->DOB << " Address:" << it->address << endl;
        it = it->next;
        if ( (i+1)%5 == 0) cout << endl;
        i++;
    }
    cout << endl;
}

void CustomerBag::ListCustomers(string addr)
{
    link it = first;
    int i=0;
    if(it == NULL ) cout << "Sorry, there are no customers in Bag " <<endl;
    while (it != NULL) {
        if(it->address.compare(addr)==0) {
            cout << "Customer["<< i << "] ==> ID:" << it->ID << " name:"<<it->name << " DOB:" << it->DOB << " Address:" << it->address << endl;
            i++;
            if ( (i+1)%5 == 0) cout << endl;
        }
        it = it->next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    CustomerBag newbag;
    for ( int i=0; i<newbag.getCapacity() ; i++) {
        newbag.add();
    }
    int sel = 0;
    unsigned short int idval=0;
    char option = ' ';
    while (sel < 10)
    {
        cout << "1. Add a Customer \n2. Remove Customer with ID \n" ;
        cout << "3. Remove Last Customer \n4. Remove All Customers \n";
        cout << "5. No of customers in bag \n6. List All Customers \n" ;
        cout << "7. ListCustomers With Same Address \n8. Enter any No. >7 to exit"<< endl;
        cin >> sel;
        
        switch(sel)
        {
            case 1:
                cout << "Adding a new Customer..." << endl;
                newbag.add();
                break;
            case 2:
                cout << "Enter Customer ID to Delete.." << endl;
                cin >> idval;
                newbag.remove(idval);
                newbag.ListCustomers();
                break;
            case 3:
                cout << "Deleting Last Customer..." << endl;
                newbag.remove();
                break;
            case 4:
                cout<< "Are you sure you want to remove all customers" << endl;
                cout << "say 'y' or 'n'" << endl;
                cin >> option;
                if(tolower(option) == 'y')
                    newbag.removeAll();
                break;
                
            case 5:
                cout << "No Of Customers in Bag Currenlty are ::::: " << newbag.getSize() << endl;
                cout << endl;
                break;
                
            case 6:
                newbag.ListCustomers();
                break;
            case 7:
                cout << "Enter city number to display customers" << endl;
                for (int i=0 ; i<6 ; i++ )
                {
                    cout<< (i+1) << ". " << states[i] << endl;
                }
                cin >> sel;
                cout << states[sel];
                cout << "Customers from "<<states[sel-1] << " are :::: " <<endl;
                newbag.ListCustomers(states[sel-1]);
                
                break;
            default:
                cout << endl;
                break;
        }
    }
}




