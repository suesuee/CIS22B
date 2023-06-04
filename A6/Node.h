#ifndef Node_h
#define Node_h

template <class T>
class Node{
    
public:
    T data;
    Node* link;
    Node() {}
    Node(T d): data(d), link(nullptr) {}
};

#endif /* Node_h */
