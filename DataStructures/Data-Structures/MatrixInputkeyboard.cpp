#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>
//#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html


using namespace std;

// A struct to keep items of a row
struct item
{
    unsigned int index;
    int data;
    item *next;
    item(unsigned int i, int d, item* t)
    {
        index = i; data = d; next = t;
    }
};

typedef item* link;

// A struct to maintain the all items in a matrix row
struct MatRow
{
    unsigned int size;
    link first;
    link last;
};

// Maintains index,data association for the matrix. Indexes are kept ordered.
class Matrix
{
public:
    Matrix();
    Matrix(unsigned short row, unsigned short col);      // Construction
    bool add(unsigned short row, unsigned short col, int data);        // Adds a new item to the matrix
    void show();                             // show all items of matrix
    Matrix operator + (Matrix&);
    link getfirst(int r);
    unsigned short rowN;            // how many row matrix has
    unsigned short colN;        // how many col matrix has
    MatRow *Head;                    // A pointer to show array of the "item" pointer
    
};

// Initialize the class
Matrix::Matrix(unsigned short row, unsigned short col)
{
    rowN = row;
    colN = col;
    Head = new MatRow[row];
    for (int i = 0; i < row; i++)
    {
        Head[i].first = Head[i].last = NULL;
        Head[i].size = 0;
    }
    
}

link Matrix::getfirst(int r)
{
    
    return Head[r].first;
}

Matrix Matrix::operator + (Matrix &param)  // To make  C = A + B
{
    Matrix MC(rowN, colN);
    
    for (int i = 0; i < rowN; i++)
    {
        link itA = Head[i].first;
        link itB = param.getfirst(i);
        
        while (itA != NULL || itB != NULL)
        {
            //cout << i << " " << endl;
            if (itB == NULL)
            {
                MC.add(i, itA->index, itA->data);
                itA = itA->next;
                continue;
            }
            if (itA == NULL)
            {
                MC.add(i, itB->index, itB->data);
                itB = itB->next;
                continue;
            }
            
            if (itA->index < itB->index)
            {
                MC.add(i, itA->index, itA->data);
                itA = itA->next;
            }
            else if (itA->index > itB->index)
            {
                MC.add(i, itB->index, itB->data);
                itB = itB->next;
            }
            else
            {
                MC.add(i, itA->index, itB->data + itA->data);
                itA = itA->next;
                itB = itB->next;
            }
        }
    }
    return MC;
}

void Matrix::show()
{
    link it;
    for (unsigned short rowC = 0; rowC < rowN; rowC++)
    {
        it = Head[rowC].first;
        for (unsigned short colC = 0; colC < colN; colC++)
        {
            if (it != NULL)
            {
                if(colC < it->index) continue;
                else{
                    if(it->data != 0) {
                        cout << "(" << rowC << "," << colC << "):";
                        cout << it->data << " ";
                        it = it->next;
                    }
                }
            }
            
        }
    }
    cout << endl;
}

bool Matrix::add(unsigned short row, unsigned short col, int data)        // Adds a new item to the matrix
{
    link Ptr = new item(col, data, NULL);            //  dynamically create a new struct/item. We append, add to end of list
    if (Ptr == NULL) return false;  // not enought memory
    
    if (Head[row].first == NULL)                     // first item to be added
    {
        Head[row].first = Ptr;
        Head[row].last = Ptr;
    }
    else
    {
        Head[row].last->next = Ptr;    // http://en.cppreference.com/w/cpp/language/operator_precedence
        Head[row].last = Ptr;
    }
    Head[row].size++;
    return true;    // added.
}

vector<string> split(char delimeter, string str) {
    istringstream input(str);
    vector<string> ips;
    for (string each;getline(input, each, delimeter); ips.push_back(each));
    return ips;
    
}

Matrix getMatrix(string name, map<string,Matrix> mat_map) {
    map<string, Matrix>::iterator it;
    it = mat_map.find(name);
    Matrix A(0,0);
    if(it != mat_map.end()) {
        Matrix MM = it -> second;
        return MM;
    }
    return A;
}

int main(int argc, const char * argv[])
{
    map<string, Matrix> mat_map;
    
    char command[30];
    cout << "enter\n";
    while(cin.getline(command,30)) {
        vector<string> words = split(' ', command);
        if(words[0] == "matrix") {
            if(mat_map.size() == 5)
                cout << "You have reached Maximum Limit, can not create more " << endl;
            else {
                string nm = words[1].substr(0,1);
                unsigned short row = stoi(words[1].substr(2));
                unsigned short col = stoi(words[1].substr(words[1].length()-2));
                Matrix M(row, col);
                mat_map.insert(pair<string,Matrix>(nm, M) );
            }
        }
        else if(words[0].length() == 1)
        {
            string name = words[0];
            Matrix M1 = getMatrix(name.substr(0,1), mat_map);
            M1.show();
        }
        else if( (words[0].find('(') != string::npos) && (words[0].find(')') != string::npos)
                && (words[0].find(',') != string::npos)) {
            string expr = words[0];
            string nm = words[0].substr(0,1);
            vector<string> ips = split('=', expr);
            vector<string> rc = split(',', ips[0].substr(2,ips[0].length()-2));
            Matrix M2 = getMatrix(expr.substr(0,1), mat_map);
            
            M2.add(stoi(rc[0]), stoi(rc[1]), stoi(ips[1]));
            mat_map.insert(pair<string,Matrix>(nm, M2) );
        }
        else if(words[0].find('+') != string::npos){
            string expr = words[0];
            vector<string> inputs = split('=', expr);
            vector<string> mats = split('+', inputs[1]);
            
            Matrix A = getMatrix(mats[0].substr(0,1), mat_map);
            Matrix B = getMatrix(mats[1].substr(0,1), mat_map);
            Matrix C(A.rowN, A.colN);
            C = A+B;
            mat_map.insert(pair<string,Matrix>(inputs[0].substr(0,1), C) );
            
        }
        else if( (words[0].find('=') != string::npos) && words[0].find('T') != string::npos) {
            vector<string> inputs = split('=', words[0]);
            char nm = inputs[1].at(2);
            //cout << nm << endl;
            string name(1,nm);
            string newMat = inputs[0].substr(0,1);
            link it;
            Matrix A = getMatrix(name, mat_map);
            Matrix B(A.colN, A.rowN);
            for (unsigned short rowC = 0; rowC < A.rowN; rowC++)
            {
                it = A.Head[rowC].first;
                for (unsigned short colC = 0; colC < A.colN; colC++)
                {
                    if (it != NULL)
                    {
                        if(colC < it->index) continue;
                        else{
                            B.add(colC, rowC, it->data);
                            it = it->next;
                        }
                    }
                }
            }
            mat_map.insert(pair<string,Matrix>(newMat, B) );
        }
        else if(words[0] == "quit"){
            break;
            return 0;
        }
        else {
            break;
        }
    }
    return 0;
}




