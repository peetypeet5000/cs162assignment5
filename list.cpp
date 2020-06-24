/******************************************************
** Program: list.cpp
** Author: Peter LaMontagne
** Date: 06/07/2020
** Description: All the functions to make a linked list work  
** Input: None
** Output: None (head is stored in list object), does cout
******************************************************/\
#include "list.h"

using std::cout;
using std::cin;


/*************************************************
 * Notes/Funct: Linked list constructor
 * In: none
 * Out: none
 * Conditions: makes 0 nodes 
 * ***********************************************/
Linked_List::Linked_List() {
    head = nullptr;
    length = 0;
}



/*************************************************
 * Notes/Funct: Destructor, just calls clear
 * In: none
 * Out: none
 * Conditions: all nodes deleted, length = 0 
 * ***********************************************/
Linked_List::~Linked_List() {
    clear();
}



/*************************************************
 * Notes/Funct: Clear -- Clears all nodes
 * In: uses head pointer
 * Out: head = nullptr, length = 0
 * Conditions: none
 * ***********************************************/
void Linked_List::clear() {
    while (head != nullptr) {
        Node* temp = head->next;
        delete head;
        head = temp;
    }

    head = nullptr;
    length = 0;
}



//Getter for length variable
int Linked_List::get_length() {
    return length;
}



/*************************************************
 * Notes/Funct: pushes element to front of list
 * In: head ptr
 * Out: ++length
 * Conditions: none
 * ***********************************************/
unsigned int Linked_List::push_front(int val) {
    Node* temp = new Node(val, head);
    head = temp;
    return ++length;
}



/*************************************************
 * Notes/Funct: pushes element to back of list
 * In: head ptr
 * Out: ++length
 * Conditions: none
 * ***********************************************/
unsigned int Linked_List::push_back(int val) { 
    if (length == 0) {
        head = new Node(val);
    }

    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(val);
    }

    return ++length;
}



/*************************************************
 * Notes/Funct: prints all vals in list
 * In: head ptr
 * Out: couts the vals with "  " between
 * Conditions: none, checks if empty
 * ***********************************************/
void Linked_List::print() const{
    if(length > 0) {
        //print first
        cout << CYAN << "\n\nYour Linked List: " << head->val << "  ";

        //print remaininig
        Node* temp = head->next;
        if(length > 1 ) {
            while (temp != nullptr) {
                cout << temp->val << "  ";
                temp = temp->next;
            }
        }
        cout << RESET;
    } else {
        cout << CYAN << "\nYour list is empty!\n" << RESET;
    }
}



/*************************************************
 * Notes/Funct: inserts an element in the list at specified index
 * In: value & index to insert
 * Out: new node, ++length
 * Conditions: works if length is zero
 * ***********************************************/
unsigned int Linked_List::insert(int val, unsigned int index) {
    length++;
    if (length == 1) {
        head = new Node(val);
     } else {
        Node* prev = head;
        //loop thru list to find speicifed element
        for(unsigned int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        //make new element point to same thing as the old one pointed to
        Node* new_one = new Node(val, prev->next);
        prev->next = new_one;
    }

    return length;
}



/*************************************************
 * Notes/Funct: Finds prime numbers, couts them
 * In: head ptr
 * Out: couts found primes with "  " between
 * Conditions: none
 * ***********************************************/
void Linked_List::printPrimes() {
    bool prime;
    Node* temp = head;

    while(temp != nullptr) {    //go untill no nodes left
        prime = true;   //assume true
        for(int i = 2; i <= (temp->val/2); i++) {
            if(temp->val % i == 0) {
                prime = false;  //prove wrong
                break;
            }
        }
        if(prime == true) { //if none of the numbers devide evenly, bool is stil true
            std::cout << temp->val << " ";
        }

        temp = temp->next; //go to next node
    }

    cout << "\n\n";
}



//ASCENDING SORT -> just calls merge sort with 0
//to sort ascending
void Linked_List::sort_ascending() {
    merge_sort(&head, 0);
}



//DESCENDING SORT -> just calls merge sort with 1
//to sort descending
void Linked_List::sort_descending() {
    merge_sort(&head, 1);
}


/*************************************************
 * Notes/Funct: recusrsive merge sort algorithm
 * splits into two repeatedly, then sorts all back togeather
 * In: head ptr (because it will replace as it splits), type
 * 1 - descending 0 - ascending
 * Out: modifies list to be sorted, replaces head with new head
 * Conditions: none, will work if empty
 * ***********************************************/
void Linked_List::merge_sort(Node** head_ref, int type) 
{ 
    Node* head = *head_ref;  //uses passed parameted b/c list is split
    //each recursive call, cant just use this->head 

    //two lists to sort into
    Node* a;
    Node* b;
  
    //BASE CASE, if length is 0 or 1
    if ((head == NULL) || (head->next == NULL)) { 
        return; //lists are sorted
    } 
  
    //Split "source" list into a and b lists
    split_list(head, &a, &b); 
  
    //Keep calling this function to keep splitting the lists into halves
    merge_sort(&a, type); 
    merge_sort(&b, type); 
  
    //Once all split into length 0 or 1, sort them togeather
    *head_ref = sorted_merge(a, b, type); 
} 
  


/*************************************************
 * Notes/Funct: Merges the two lists back togeather,
 * works either ascending or descending
 * In: list a and list b, type (1 or 0)
 * Out: returns a head ptr that points to sorted list
 * Conditions: none
 * ***********************************************/
Node* Linked_List::sorted_merge(Node* a, Node* b, int type) 
{ 
    //this list will be slowly built by sorting the two smaller ones
    Node* sorted_list = NULL; 
  
    //BASE CASE -> if either list is empty, they are all sorted
    if (a == NULL) 
        return b; 
    else if (b == NULL) 
        return a; 
  
    //for ascending
    if (type == 0) {
        //if list a is less then list b, add a into sorted list
        if (a->val <= b->val) { 
            sorted_list = a; 
            //keep calling sort for the next value in the sorted linked list
            sorted_list->next = sorted_merge(a->next, b, type); 
        } 
        else { 
            sorted_list = b; 
            sorted_list->next = sorted_merge(a, b->next, type); 
        } 
    } else {    //for descending
        if (a->val >= b->val) { 
            sorted_list = a; 
            sorted_list->next = sorted_merge(a->next, b, type); 
        } 
        else { 
            sorted_list = b; 
            sorted_list->next = sorted_merge(a, b->next, type); 
        } 
    }
    return sorted_list;    //once everything is sorted, return the sorted list
} 



/*************************************************
 * Notes/Funct: Split list into two half lists
 * In: source list, list a and b to sort into
 * Out: returns by refereance lists a and b which are halfs
 * of source list
 * Conditions: if odd number, first gets extra element
 * ***********************************************/
void Linked_List::split_list(Node* source, Node** a, Node** b) 
{ 
    Node* two_time; 
    Node* one_time; 
    one_time = source; 
    two_time = source->next; 
  
    //twotime advances 2 nodes, onetime advances one
    //so two time will always by 2x further along
    while (two_time != NULL) { 
        two_time = two_time->next; 
        if (two_time != NULL) { 
            one_time = one_time->next; 
            two_time = two_time->next; 
        } 
    } 
  
    //twotime has reached the end, slow is 1/2 of the way along
    *a = source; 
    *b = one_time->next; 
    one_time->next = NULL; //sets next of slow to null, so it stops after getting 1/2 way thru list
} 
