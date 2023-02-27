#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include "heap.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

struct oddfunc {
    bool operator() (int num1, int num2){
        return num1 < num2;
    }
};



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);
    oddfunc f;
    // Test out your linked list code
    Heap<int, oddfunc> h(2, f);
    while(head){
        h.push(head->val);
        head = head->next;
    }
    

    while(!h.empty()){
        //cout << h.top() << " ";
        int m = 0;
        int n = 1;
        for(int i = 0; i < h.arr_.size(); i++){
            if(i == m){
                cout << h.arr_[i] << endl;
                m += n*2;
                n *= 2;
            }
            else{
                cout << h.arr_[i] << " ";
            }
        }
        cout << endl;
        h.pop();
    }


    
    return 0;

}
