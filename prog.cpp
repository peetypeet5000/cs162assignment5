/******************************************************
** Program: prog.cpp
** Author: Peter LaMontagne
** Date: 06/07/2020
** Description: Driver files for Linked List, allows use of
** all the functions
** Input: user input ints
** Output: couts stuff about list, no data
******************************************************/
#include "list.h"
#include "util.h"
#include <iostream>

using std::cout;

//function prototypes
int getInput(Linked_List& list);
void doFunction(Linked_List&, int, int, int);



int main() {
    Linked_List list;

    int done = 0;
    do {
        done = getInput(list);
    } while(done != 9);

}



/*************************************************
 * Notes/Funct: gets the user input
 * In: list referance
 * Out: returns the input to see if done (8)
 * Conditions: need list ref, chekcs range
 * ***********************************************/
int getInput(Linked_List& list) {
    int input = 0, input2 = 0, input3 = 0;

    do {
        cout << "\n\nPlease enter the option you want:\n[1] - Push Back\n[2] - Push Front\n[3] - Insert\n[4] - Sort Ascending\n[5] - Sort Descending\n[6] - Print List\n[7] - Find Primes\n[8] - Clear List\n[9] - Quit\nYour Input: ";
        input = getInt();
    } while (checkRange(input, 9, 1) == false);

    if(input == 1 || input == 2 || input == 3) {
        cout << "\nPlease enter the number to add: ";
        input2 = getInt();
    }

    if(input == 3) {
        do {
            cout << "\nPlease enter an index less then " << (list.get_length() + 1) << " to insert at: ";
            input3 = getInt();
        } while(checkRange(input3, list.get_length(), 0) == false);
    }

    doFunction(list, input, input2, input3);

    return input;
}



/*************************************************
 * Notes/Funct: Takes the user input and does the correct function 
 * In: input 1 (type) , input2 (num to add)
 * Out: changed list
 * Conditions: need list referance, does not check range
 * ***********************************************/
void doFunction(Linked_List& list, int input, int input2, int input3) {
    switch (input) {
        case 1:
            cout << "\nPushed back " << input2 << std::endl;
            list.push_back(input2);
            break;
        case 2:
            cout << "\nPushed front " << input2 << std::endl;
            list.push_front(input2);
            break;
        case 3:
            cout << "\nInserted " << input2 << " at index " << input3;
            list.insert(input2, input3);
            break;
        case 4: 
            cout << "\nList sorted!\n";
            list.sort_ascending();
            break;
        case 5:
            cout << "\nList sorted!\n";
            list.sort_descending();
            break;
        case 6:
            list.print();
            break;
        case 8:
            cout << "\nList cleared!";
            list.clear();
            break;
        case 7:
            cout << "\nYour Prime Numbers Are: ";
            list.printPrimes();
            break;
        case 9:
            cout << "\nGoodbye!\n\n";
            break;
    }
}