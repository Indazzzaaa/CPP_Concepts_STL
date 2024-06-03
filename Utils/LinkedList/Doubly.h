
#pragma once

#include "ll.h"


template<typename T>
class Doubly {
      Node<T>* _head;
      Node<T>* _tail;

public:
      Doubly(): _head{nullptr},_tail{nullptr}{} ;
      explicit Doubly(T data);
      ~Doubly();


      // For enabling for each loop
      class iterator {
            Node<T>* current;

      public:
            iterator(Node<T>* ptr): current(ptr){}

            //Move to next
            iterator& operator++() {
                  current = current->_next;
                  return *this;
            }

            // De-ref to extract the value out of iterator
            T& operator*() {
                  return current->_data;
            }

            bool operator!=(const iterator& other) const {
                  return current !=other.current;
            }

            iterator begin() {
                  return iterator(_head);
            }

            iterator end() {
                  return iterator(nullptr);
            }


      };

};

template<typename T>
Doubly<T>::Doubly(T data) {
      _head=_tail = new Node<T>(data);

}

template<typename T>
Doubly<T>::~Doubly() {
      // iterate over each node and delete them.
}
