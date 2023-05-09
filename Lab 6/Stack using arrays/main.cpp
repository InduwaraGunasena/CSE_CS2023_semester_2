#include <iostream>
#include <ctime>

using namespace std;

const int n = 100;      // This is the length of the array which represents the size of our stack
int top = -1;           // This is used to the current position. DO NOT CHANGE THIS.
int stack[n];

void push(int value){
    if (top >= n - 1){   // if length of the array exceeds
        cout << "Stack Overflow! " <<endl;
    }else{
        top++;
        stack[top] = value;
    }
}

void pop(){
    if (top <= -1){
        cout << "Stack Underflow! " << endl;
    }else{
        cout << stack[top] << " is popped out of the stack." << endl;
        top--;
    }
}

void isEmpty(){
    if (top == -1)  // if stack is empty.
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;
}

void isFull(){
    if (top == n-1)  // if stack is full.
        cout << " Stack is full." << endl;
    else
        cout << " Stack is not full." << endl;
}

void stackTop(){
    if (top == -1)  // if stack is empty.
        cout << "Stack is empty. So there is no top value." << endl;
    else
        cout << stack[0] << " is the top value of the stack." << endl;

}

void display(){
    if (top == -1)     // if stack is empty.
        cout << "Stack is empty. So we cannot have anything to display." << endl;
    else   // otherwise print all the elements.
        for(int i = top; i >= 0; i--)
            cout << stack[i] << " " ;
        cout << "\n";
}


int main()
{
    const int size = 100;   // Type a positive number to add how many elements into the stack.

    clock_t start;
    clock_t end;

    start = clock();
    for(int i = 0; i < size; i++)
        push(rand()%100);

    display();
    stackTop();
    isEmpty();

    for(int i = 0; i < size; i++)
        pop();

    display();
    end = clock();

    double t = ((end - start) / (double)CLOCKS_PER_SEC);
    cout << "\nTime taken for pushing and popping " << size << " elements : " << fixed << t << "s\n" << endl;
    return 0;
}
