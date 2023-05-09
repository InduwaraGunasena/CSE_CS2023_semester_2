#include <iostream>
#include <ctime>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node* top = NULL;


void push(int value)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = value;
    new_node -> next = top;
    top = new_node;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        cout << top -> data << " is popped out of the stack." << endl;
        top = top -> next;
    }
}

void isEmpty()
{
    if (top == NULL)  // if it is empty
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;
}

void stackTop()
{
    if (top == NULL) //if it is empty
        cout << "Stack is empty. So there is no top value." << endl;
    else
        cout << top -> data << " is the top value of the stack." << endl;

}

void display()
{
    struct Node* ptr;
    if (top == NULL)     // if stack is empty.
        cout << "Stack is empty. So we cannot have anything to display." << endl;
    else    // otherwise print all the elements.
    {
        ptr = top;
        while (ptr != NULL)
        {
            cout << ptr -> data << " " ;
            ptr = ptr -> next;
        }
        cout << "\n";
    }
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
