

class Node {
public:
   int val;    // the value that this node stores
   Node *next; // a pointer to the next node in the list
   // you can add constructors or other functionality if you find it useful or necessary
   Node();
   Node(int);
   Node(int, Node*);
};