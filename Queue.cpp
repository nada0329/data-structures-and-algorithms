#include <iostream>
using namespace std;

class Node
{
 public:    
    int data;
    Node* next;
};

class Queue
{
 private:
    Node* head;
    Node* rear;
 public:
    Queue();
    ~Queue();
    void Enqueue(int val);
    int  Dequeue();
    int  getRear();
    int  getFirst();
    bool isEmpty();
    bool isFull();
    void clear_Queue();
    void Display();
    int  count();
    bool isFound(int val);

};

Queue::Queue()
{
    head=NULL;
    rear=NULL;
}
Queue::~Queue()
{
    clear_Queue();
}

void Queue::Enqueue(int val)
{
    Node* NewNode= new Node();
    NewNode->data=val;
    NewNode->next=NULL;
    if(isEmpty())
    {
        head=NewNode;
        rear=NewNode;
    }
    else
    {
        rear->next=NewNode;
        rear=NewNode;
    }
}
int  Queue::Dequeue()
{
    int target=-1;
    if(isEmpty())
    {
        cout<<"Empty Queue \n";
        return target;
    }
    else
    {
        Node* temp=head; 
        target=temp->data;
        if(rear==head)
        {
            delete temp;
            head=NULL;
            rear=NULL;
        }
        else
        {
            head=temp->next;
            delete temp;
        }

    }
    return target;
}
int  Queue::getRear()
{
    return rear->data;
}
int  Queue::getFirst()
{
    return head->data;
}
bool Queue::isEmpty()
{
    return (head==NULL && rear==NULL);
}
bool Queue::isFull()
{
    Node* ptr=new Node();
    if(ptr==NULL)
    {
        cout<<"full queue\n";
        return true;
    }
    else
    {
        cout<<"not full queue\n";
        delete ptr;
        return false;
    }

}
void Queue::clear_Queue()
{
    if(isEmpty())
    {
        cout<<"Empty Queue \n";
        return;
    }
    else
    {
        Node* deleted=head;
        while(head!=NULL)
        {
            head=head->next;
            delete deleted;
            deleted=head;
        }
        rear=NULL;
    }
}
void Queue::Display()
{
    if(isEmpty())
    {
        cout<<"Empty Queue \n";
    }
    else
    {
        cout<<"Queue items: ";
        Node* temp=head;
        while(temp!= NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }

}
int  Queue::count()
{
    int counter=0;
    if(isEmpty())
    {
        cout<<"Empty Queue \n";
        return counter;
    }
    else
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            counter++;
            temp=temp->next;
        }
        
        return counter;
    }
}
bool Queue::isFound(int val)
{
    if(isEmpty())
    {
        cout<<"Empty Queue \n";
        return false;
    }
    else
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data== val)
            {
                cout<<val<<" found\n";
                return true;
            }
            temp=temp->next;
        }
        cout<<val<<" not found\n";
        return false;
    }
}



int main()
{
   Queue myQ;
   myQ.Display();
   cout<<"remove "<<myQ.Dequeue()<<endl;
   myQ.Enqueue(3);
   myQ.Display();
   cout<<"remove "<<myQ.Dequeue()<<endl;
   myQ.Display();
   myQ.Enqueue(88);
   myQ.Enqueue(77);
   myQ.Enqueue(6);
   myQ.Enqueue(4);
   myQ.Enqueue(3);
   myQ.Enqueue(2);
   myQ.Display();
   cout<<"remove "<<myQ.Dequeue()<<" "<<myQ.Dequeue()<<" "<<myQ.Dequeue()<<endl;
   myQ.Display();
   myQ.Enqueue(8);
   myQ.Enqueue(7);
   myQ.Display();
   myQ.clear_Queue();
   myQ.Display();


    return 0;
}