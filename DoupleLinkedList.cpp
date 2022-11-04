#include <iostream>
using namespace std;

class Node
{
 public:    
    int data;
    Node* next;
    Node* prev;
};

class DLinkedList
{
 private:
    Node* head;
 public:
    DLinkedList(); //
    ~DLinkedList();
    bool isEmpty(); //
    void insertFirst(int val); //
    void insertLast(int val); //
    void insertAfter(int target, int val); //
    void insertBefore(int target, int val); //
    void deleteItem(int val);
    void deleteList();
    void displayList(); //
    void displayListReverse(); //
    bool isFound(int target); //
    int  getLength(); //

};

DLinkedList::DLinkedList()
{
    head=NULL;
}
DLinkedList::~DLinkedList()
{
    deleteList();
}
bool DLinkedList::isEmpty()
{
    return (head==NULL);
}
void DLinkedList::insertFirst(int val)
{
    Node* NewNode= new Node();
    NewNode->data=val;
    if(isEmpty())
    {
        head=NewNode;
        NewNode->next=NULL;
        NewNode->prev=NULL;
    }
    else
    {
        NewNode->next=head;
        head->prev=NewNode;
        NewNode->prev=NULL;
        head=NewNode;
    }
    
}
void DLinkedList::insertLast(int val)
{
    if(isEmpty())
    {
        insertFirst(val);
    }
    else
    {
        Node* NewNode= new Node();
        NewNode->data=val; 
        NewNode->next=NULL;
        Node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NewNode;
        NewNode->prev=temp;

    }
}
void DLinkedList::insertAfter(int target, int val)
{
    if(isEmpty())
    {
        cout<<"no items in list "<<endl;
        return;
    }
    if(!isFound(target))
    {
        cout<<"target "<<target<<" not exist in list"<<endl;
        return;
    }
    else
    {
        Node* NewNode= new Node();
        NewNode->data=val; 
        Node* temp=head;
        while (temp->data!=target)
        {
            temp=temp->next;
        }
        NewNode->next=temp->next;
        NewNode->prev=temp;
        if(temp->next!=NULL)
            temp->next->prev=NewNode;
        temp->next=NewNode;
    }

}
void DLinkedList::insertBefore(int target, int val)
{
    if(isEmpty())
    {
        cout<<"no items in list "<<endl;
        return;
    }
    if(!isFound(target))
    {
        cout<<"target "<<target<<" not exist in list"<<endl;
        return;
    }
    else
    {
        Node* NewNode= new Node();
        NewNode->data=val; 
        Node* temp=head;
        while (temp->data!=target)
        {
            temp=temp->next;
        }
        NewNode->next=temp;
        NewNode->prev=temp->prev;
        if(temp!=head)
            temp->prev->next=NewNode;
        else
            head=NewNode;    
        temp->prev=NewNode;
    }

}
void DLinkedList::deleteItem(int val)
{
    if(isEmpty())
    {
        cout<<"no items in list "<<endl;
        return;
    }
    if(!isFound(val))
    {
        cout<<"item "<<val<<" not exist in list"<<endl;
        return;
    }
    else
    {
        
        Node* deleted=head;
        while(deleted->data!=val)
        {
            deleted=deleted->next;
        }
        if(deleted==head)
        {    
            head=deleted->next;
            deleted->next->prev=deleted->prev;
        }
        else if(deleted->next==NULL)    
        {
            deleted->prev->next=deleted->next;
        }
        else    
        {
            deleted->prev->next=deleted->next;
            deleted->next->prev=deleted->prev;
        }
        delete deleted;

    }

}
void DLinkedList::deleteList()
{
    if(isEmpty())
    {
        cout<<"empty list"<<endl;
        return;
    }
    Node* temp=head;
    while (head!=NULL)
    {
        displayList();
        head=head->next;
        delete temp;
        temp=head;
    }    

}
bool DLinkedList::isFound(int target)
{
    if(isEmpty())
    {
        cout<<"empty list"<<endl;
        return false;
    }
    Node* temp=head;
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
void DLinkedList::displayList()
{
    Node* temp=head;
    if(isEmpty())
    {
        cout<<"empty list"<<endl;
        return;
    }
    else
    {
        cout<<"list items: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
void DLinkedList::displayListReverse()
{
    if(isEmpty())
    {
        cout<<"empty list"<<endl;
        return;
    }
    else
    {
        Node* temp=head;
        while(temp->next !=NULL)
        {    
            temp=temp->next;
        }
        cout<<"list items: ";
        while(temp!=head)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<head->data;
        cout<<endl;
    }
}
int  DLinkedList::getLength()
{
    int count=0;
    Node* temp=head;
    if(isEmpty())
    {
        cout<<"empty list"<<endl;
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
    DLinkedList myList;
    cout<<"\ncheck empty operation\n";
    myList.displayList();
    myList.displayListReverse();
    
    myList.insertFirst(4);
    myList.insertFirst(3);
    myList.insertLast(8);
    myList.insertLast(9);
    myList.insertFirst(2);
    cout<<"\ncheck basic insert and display\n";
    myList.displayList();
    myList.displayListReverse();
    cout<<"\ncheck len and search\n";
    cout<<"list length: "<<myList.getLength()<<endl;
    myList.isFound(9);
    myList.isFound(22);

    cout<<"\ncheck insert after operation\n";
    myList.insertAfter(4,5);
    myList.insertAfter(5,6);
    myList.insertAfter(9,10);
    myList.insertAfter(10,12);
    myList.insertAfter(100,15);
    
    myList.displayList();
    myList.displayListReverse();
    cout<<"\ncheck insert before operation\n";
    myList.insertBefore(8,7);
    myList.insertBefore(12,11);
    myList.insertAfter(100,15);
    myList.insertBefore(2,1);
    myList.insertBefore(1,0);

    myList.displayList();
    myList.displayListReverse();

    cout<<"\ncheck delete operation\n";
    myList.insertBefore(8,66);
    myList.insertBefore(12,77);
    myList.insertBefore(0,88);
    myList.insertLast(99);
    myList.displayList();
    myList.displayListReverse();

    myList.deleteItem(99);
    myList.displayList();
    myList.displayListReverse();
    myList.deleteItem(66);
    myList.displayList();
    myList.displayListReverse();
    myList.deleteItem(88);
    myList.displayList();
    myList.displayListReverse();
    myList.deleteItem(77);
    myList.deleteItem(155);
    myList.displayList();
    myList.displayListReverse();
    cout<<"\ncheck delete list operation\n";
    myList.deleteList();
    myList.displayList();
    myList.displayListReverse();

    return 0;
}