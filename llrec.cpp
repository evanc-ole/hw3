#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	if(head == nullptr){
		//do nothing
		smaller = nullptr;
		larger = nullptr;
	}
	else if(head->val > pivot){
		larger = head;
		head = head->next;
		larger->next = nullptr;
		llpivot(head, smaller, larger->next, pivot);
	}
	else{
		smaller = head;
		head = head->next;
		smaller->next = nullptr;
		llpivot(head, smaller->next, larger, pivot);
	}
}
