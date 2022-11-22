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
    typedef StackNode<type> _StackNode;
    _StackNode* start;
    _StackNode* end;
    size_t size;

public:

    StackList() {
        start = new _StackNode();
        end = start;
        size = 1;
    }
    StackList(initialser values) {

        size = values.size();
        start = new _StackNode(*(values.begin()));

        _StackNode* temp = start;

        for (int x = 1; x < size; x++) {
            //std::cout << temp->value;
            temp->next = new _StackNode(*(values.begin() + x));
            temp = temp->next;

        }
        end = temp;
    }
    //misc functions

    int GetSize() {
        return size;
    }

    void RemoveElem(size_t index) {//this function works in all cases
        CatchInvalidIndex(index);
        CatchNullEnd();
        CatchNullStart();
        size--;
        _StackNode* temp = start;
        for (int x = 0; x < index - 2; x++) {
            temp = temp->next;
        }
        if (temp == start) {
            PopStart();
            return;
        }
        else if (temp == end) {
            PopEnd();
            return;
        }
        _StackNode* ptr = temp->next;
        temp->next = temp->next->next;
        free(ptr);
    }
    void ShiftLeft() {
        //start = end , second = start , 
        CatchNullEnd();
        CatchNullStart();
        if (size < 1) {
            return;
        }
        _StackNode* temp = start;
        start = start->next;
        temp->next = NULL;
        end->next = temp;
        end = end->next;
    }
    void PrintStack() {

        _StackNode* temp = start;
        while (temp != NULL) {
            std::cout << temp->value << std::endl;
            temp = temp->next;

        }
    }
    //end functions
    void PushEnd(type value) {
        size++;
        end->next = new _StackNode(value);
        end = end->next;
    }
    type PopEnd() {
        CatchNullEnd();
        size--;
        _StackNode* temp = start;//traverse until next = end;
        while (temp->next != end) {//get the "index" before end, free next. than return end->value 
            temp = temp->next;
        }
        type temp1 = temp->next->value;
        free(temp->next);//free end;
        end = temp;
        return temp1;
    }
    type& GetEnd() {
        CatchNullEnd();
        return end->value;
    }
    //start functions
    void PushStart(type value) {
        CatchNullStart();
        size++;
        _StackNode* temp = new _StackNode(value);
        temp->next = start;
        start = temp;
    }
    type PopStart(void) {
        //i could free start? 
        CatchNullStart();
        _StackNode* temp = start->next;
        int tem = start->value;
        free(start);
        size--;
        start = temp;
        return tem;
    }
    type& GetStart(void) {
        CatchNullStart();
        return start->value;
    }
    //indexing is working fine :P 
    type& operator[](size_t index) {
        CatchInvalidIndex();
        CatchNullEnd();
        CatchNullStart();

        _StackNode* temp = start;
        for (int x = 0; x < index - 1; x++) {//probably something slightly wrong with this but idgaf 
            temp = temp->next;
        }
        return temp->value;

    }
    private://catch error functions 
    void CatchInvalidIndex(size_t index) {
        if (index > size) {
            while (1) {
                throw (std::out_of_range("indexing past length of stack\n"));
            }

        }
    }
    void CatchNullStart(void) {
        if (start == NULL) {
            while (1) {
                throw("Start/root became NULL ");
            }
        }
    }
    void CatchNullEnd(void){
        if (end == NULL) {
            while (1) {
                throw("Start/root became NULL ");
            }
        }
    }
};