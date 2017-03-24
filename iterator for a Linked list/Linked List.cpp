// Helper Node class
class Node {
public:
    int value;
    Node* next;
};
// Linked List class
class LinkedList {
public:
    Node* root; //root node

    //Iterator class
    class iterator : public std::iterator<std::forward_iterator_tag, int> {
    public:
        friend class LinkedList; // declare LinkedList as a friend class
        Node* curr; /// the node this iterator is pointing to

        // the following typedefs are needed for the iterator to play nicely with C++ STL
        typedef int value_type;
        typedef int& reference;
        typedef int* pointer;
        typedef int difference_type;
        typedef std::forward_iterator_tag iterator_category;

        // iterator constructor
        iterator(Node* x=0):curr(x){}

        // overload the == operator of the iterator class
        bool operator==(const iterator& x) const {
            return curr == x.curr;// compare curr pointers for equality
        }
        // overload the != operator of the iterator class
        bool operator!=(const iterator& x) const {
            return curr != x.curr; // compare curr pointers for inequality
        }
        //overload the * operator of the iterator class
        reference operator*() const {
            return curr->value; // return curr's value
        }
        // overload the ++ (pre-increment) operator of the iterator class
        iterator& operator++() {
            curr =  curr->next;
            return *this;
        }

    };
    //return iterator to the first element
    iterator begin() {
        return iterator(root);
    }
    iterator end() {
        return iterator(NULL);
    }

}

int main() {
    LinkedList l;

    for (auto it = l.begin(); it!-l.end(); it++) {
        cout << *it << endl;
    }
}
