
#pragma once

#include <ostream>

template<typename T>
class Node {
       T _data;
       Node *_next=nullptr;
       Node *_prev=nullptr;

public:

       explicit Node(T data);
       Node(T data, Node* next, Node* prev);

       T getData(){return _data;}


       // free up the memory
       ~Node() { delete _next,_prev;}

       friend std::ostream& operator<<(std::ostream& os,const Node<T>& node) {
              os << "node("<<node._data << ")" << "---*";
              return os;
       }
};

template<typename T>
Node<T>::Node(T data): _data{data}{}

template<typename T>
Node<T>::Node(T data, Node *next, Node *prev): _data{data},_next{next},_prev{_prev} {}





