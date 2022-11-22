#pragma once
#include <iostream>
#include <exception>

template<class type>class  StackList {
private:
    typedef std::initializer_list<type> initialser;
    template<class type> class StackNode {
    public:
        StackNode<type>* next;
        type value;
        StackNode() : next(NULL), value(0) {};
        StackNode(type value) : next(NULL), value(value) {};
        StackNode(type value, StackNode<type>* next) :next(next), value(value) {};
    };

    StackNode<type> * start;
    StackNode<type> * end;
    int size;

public:
    StackList() {
        start = new StackNode<type>();
        end = start;
        size = 1;
    }
    StackList(initialser values) {

        size = values.size();
        start = new StackNode<type>( * (values.begin() ));
        
        StackNode<type>* temp = start;

        for (int x = 1; x < size; x++) {
            //std::cout << temp->value;
            temp->next = new StackNode<type>(*(values.begin() + x));
            temp = temp->next;

        }
        end = temp;
        temp = start;
    }
    void PrintStack() {
        StackNode<type>* temp = start;
        while (temp != NULL) {
            std::cout << temp->value << std::endl;
            temp = temp->next;

        }
    }
    void PushStart(type value) {
        StackNode<type>* temp = new StackNode<type>(value);
        temp->next = start;
        start = temp;
    }
    void PushEnd(type value) {
        end->next = new StackNode<type>(value);
        end = end->next;
    }
    type PopEnd() {
        StackNode<type>* temp = start;//traverse until next = end;
        while (temp->next != end) {
            temp = temp->next;
        }
        free(temp->next);//free end;
        end = temp;
    }
    type& GetEnd() {
        return end->value;
    }
    //start functions
    type PopStart(void) {
        //i could free start? 
        
        StackNode<type>* temp = start->next;
        free(start);

        start = temp;
        return start->value;
    }
    type& GetStart(void) {
        return start->value;
    }
    //indexing is working fine :P 
    type& operator[](size_t index) {
        if (index > size) {
            throw (std::out_of_range("indexing past length of stack\n"));
            exit(-1);

        }
        StackNode<type>* temp = start;
        for (int x = 0; x < index-1; x++) {//probably something slightly wrong with this but idgaf 
            temp = temp->next;
        }
        return temp->value;

    }
};