#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    
public:
    LinkedList(): head(nullptr), tail(nullptr) {}
    ~LinkedList();
    
    void printList() const;
    void append(const T data);
    void prepend(const T data);
    bool removeFront();
    void insert(const T data);
    bool remove(const T data);
    bool find(const T data);
    bool isEmpty() const;
    T getFirst() const;
    T getLast() const;
};

/*
 1. It receives nothing.
 2. It returns nothing.
 3. It is the destructor of the class.
 It tranverses the link list and delete
 each node in the list. It sets the head and
 tail pointer to null.
 */
template <class T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while(current != nullptr)
    {
        Node<T>* next = current->link;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

/*
 1. It receives nothing.
 2. It returns nothing.
 3. It goes through the list and
 prints all the nodes in the list.
 */
template <class T>
void LinkedList<T>::printList() const {
    Node<T>* iter = head;
    cout << endl;
    while(iter != nullptr)
    {
        cout << iter->data;
        iter = iter->link;
    }
}

/*
 1. It receives a constant value.
 2. It returns nothing.
 3. It adds a node to the end of the list.
 */
template <class T>
void LinkedList<T>::append(const T data) {
    Node<T>* newNode = new Node<T>(data);
    newNode->data = data;
    newNode->link = nullptr;
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        Node<T>* iter = head;
        while(iter->link != nullptr) {
            iter = iter->link;
        }
        iter->link = newNode;
    }
}

/*
 1. It receives a constant value.
 2. It returns nothing.
 3. It adds a node to the front of the list.
 */
template <class T>
void LinkedList<T>::prepend(const T data) {
    Node<T>* newNode = new Node<T>(data);
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->link = head;
        head = newNode;
    }
}

/*
 1. It receives nothing.
 2. It returns a bool value.
 3. It removes the front node.
 */
template <class T>
bool LinkedList<T>::removeFront() {
    if(head == nullptr) {
        return false;
    } else {
        Node<T>* temp = head;
        head = head->link;
        if(head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return true;
    }
}

/*
 1. It receives a constant value.
 2. It returns nothing.
 3. It inserts the value into the link list in the correct order.
 */
template <class T>
void LinkedList<T>::insert(const T data) {
    Node<T>* newNode = new Node<T>(data);
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    } else if(newNode->data <= head->data ) {
        newNode->link = head;
        head = newNode;
    } else {
        Node<T>* iter = head;
        while(iter->link != nullptr && iter->link->data <= data) {
            iter = iter->link;
        }
        newNode->link = iter->link;
        iter->link = newNode;
        if(newNode->link == nullptr) {
            tail = newNode;
        }
    }
}

/*
 1. It receives a constant value.
 2. It returns a bool value true if the node
 was found and removed.
 3. It removes the node with that value from the list.
 */
template <class T>
bool LinkedList<T>::remove(const T data) {
    Node<T>* nodePtr; //To tranverse the list
    Node<T>* previousNode = nullptr; //To point to the previous node
    
    //If the list is empty, do nothing
    if (!head) {
        cout << "\n" << data.getName() <<
        " was not successfully removed from the list.\n";
        cout << endl;
        return false;
    }
    
    //Determine if the first node is the one
    if (head->data == data) {
        removeFront();
        cout << "\n" << data.getName() <<
        " was successfully removed from the list.\n";
        cout << endl;
        return true;
    } else {
        nodePtr = head;
        
        while(nodePtr != nullptr && !(nodePtr->data == data)) {
            previousNode = nodePtr;
            nodePtr = nodePtr->link;
        }
        
        //If nodePtr is not at the end of the list,
        //link the previous node to the node after
        //nodePtr, then delete nodePtr.
        if (nodePtr) {
            previousNode->link = nodePtr->link;
            delete nodePtr;
            cout << "\n" << data.getName() <<
            " was successfully removed from the list.\n";
            cout << endl;
            return true;
        }
    }
    cout << "\n" << data.getName() <<
    " was not found in the list when attempting to remove.\n";
    cout << endl;
    return false;
}

/*
 1. It receives a constant value.
 2. It returns a bool value, true if the value
 is in the list and false otherwise.
 3. It searches for the passed value in the linkedlist.
 */
template <class T>
bool LinkedList<T>::find(const T data) {
    Node<T>* nodePtr = head; //To tranverse the list
    
    //If the list is empty, do nothing
    if(!head) {
        return false;
    }
    //Determine if the first node is the one
    if(head->data == data) {
        cout << "\n" << data.getName() << " was found on the list.\n" << endl;
        return true;
    } else {
        nodePtr = head;
        while(nodePtr)
        {
            if(nodePtr->data == data)
            {
                cout << "\n" << data.getName() <<
                " was found on the list.\n" << endl;
                return true;
            }
            nodePtr = nodePtr->link;
        }
    }
    cout << "\n" << data.getName() << " was not found on the list.\n" << endl;
    return false;
}

/*
 1. It receives nothing.
 2. It returns true if list is empty and
 false otherwise.
 3. It checks if the list is empty or not.
 */
template <class T>
bool LinkedList<T>::isEmpty() const {
    if(!head) {
        return true;
    }
    return false;
}

/*
 1. It receives nothing.
 2. It returns the value stored in the first node
 of the list (not a pointer to the node).
 3. It finds and gives the value of
 first node of the list.
 */
template <class T>
T LinkedList<T>::getFirst() const {
    if(isEmpty()) {
        cout << "\n" << "List is empty." << endl;
    }
    return head->data;
}

/*
 1. It receives nothing.
 2. It returns the value stored in the last node
 of the list (not a pointer to the node).
 3. It finds and gives the value of
 last node of the list.
 */
template <class T>
T LinkedList<T>::getLast() const {
    Node<T>* current = head;
    Node<T>* next = current->link;
    
    if(isEmpty()) {
        cout << "\n" << "List is empty." << endl;
    } else {
        while(current->link != nullptr) {
            current = next;
            next = current->link;
        }
    }
    return current->data;
}

#endif /* LinkedList_h */


