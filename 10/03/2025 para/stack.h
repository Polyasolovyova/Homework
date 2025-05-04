#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* data;    
    int capacity; 
    int topIndex; 

public:
    Stack(int size);    
    ~Stack();   

    void push(int value);
    void pop();
    int top();
    bool empty();
    bool full();
    int size();
};

#endif
