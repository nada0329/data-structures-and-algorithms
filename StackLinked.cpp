#include <iostream>
using namespace std;

class Node
{
 public:    
    int data;
    Node* next;
};

class StackLinked
{
 private:
    Node* Top;
 public:
    StackLinked();
    ~StackLinked();
    bool isEmpty();
    void push(int val);
    int pop();
    int peek();
    void displayStack();
    bool isFound(int target);
    int  getLength();
    bool isFull();
    void deleteStack();
    

};

StackLinked::StackLinked()
{
    Top=NULL;
}
StackLinked::~StackLinked()
{
    deleteStack();
}
bool StackLinked::isEmpty()
{
    return (Top==NULL);
}
void StackLinked::push(int val)
{
    Node* NewNode= new Node();
    NewNode->data=val;
    NewNode->next=Top;
    Top=NewNode;
}
int StackLinked::pop()
{
    int val=Top->data;
    Node* temp=Top;
    Top=Top->next;
    delete temp;
    return val;
}
int StackLinked::peek()
{
    return Top->data;
}
bool StackLinked::isFull()
{
    Node* temp=new Node();
    if(temp==NULL)
    {
        cout<<"Full Stack !!"<<endl;
        return true;
    }
    else
    {
        delete temp;
        return false;
    }
    return false;
}
/*void StackLinked::deleteStack()
{
    if(isEmpty())
    {
        cout<<"empty Stack"<<endl;
        return;
    }
    Node* temp=Top;
    while (Top!=NULL)
    {
        //displayStack();
        Top=Top->next;
        delete temp;
        temp=Top;
    }

}*/
void StackLinked::deleteStack()
{
    if(isEmpty())
    {
        cout<<"empty Stack"<<endl;
        return;
    }
    else
    {
        int len=getLength();
        for(int i=0;i<len;i++)
        {
            displayStack();
            pop();
        }
    }
}
bool StackLinked::isFound(int target)
{
    if(isEmpty())
    {
        cout<<"empty Stack"<<endl;
        return false;
    }
    Node* temp=Top;
    while(temp!=NULL)
    {
        if(temp->data==target)
        {
            cout<<target<<" found"<<endl;
            return true;
        }
        temp=temp->next;
    }
    cout<<target<<" not found"<<endl;
    return false;
}
void StackLinked::displayStack()
{
    Node* temp=Top;
    if(isEmpty())
    {
        cout<<"empty Stack"<<endl;
        return;
    }
    else
    {
        cout<<"Stack items: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int  StackLinked::getLength()
{
    int count=0;
    Node* temp=Top;
    if(isEmpty())
    {
        cout<<"empty Stack"<<endl;
        return 0;
    }
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    return count;
}


int main()
{
    
    StackLinked myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    cout<<"peek is: "<<myStack.peek()<<endl;
    myStack.displayStack();
    myStack.pop();
    myStack.displayStack();
    myStack.pop();
    myStack.displayStack();
    myStack.pop();
    myStack.displayStack();
    myStack.pop();
    myStack.displayStack();
    myStack.push(5);
    myStack.push(5);
    myStack.push(5);
    myStack.push(5);
    myStack.push(58);
    myStack.displayStack();
    myStack.deleteStack();
    myStack.displayStack();
    return 0;
}