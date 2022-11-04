#include <iostream>
using namespace std;

class Node
{
 public:    
    int data;
    Node* next;
};

class LinkedList
{
 private:
    Node* head;
 public:
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void insertFirst(int val);
    void insertLast(int val);
    void insertAfter(int target, int val);
    void deleteItem(int val);
    void deleteList();
    void displayList();
    bool isFound(int target);
    int  getLength();

};

LinkedList::LinkedList()
{
    head=NULL;
}
LinkedList::~LinkedList()
{
    deleteList();
}
bool LinkedList::isEmpty()
{
    return (head==NULL);
}
void LinkedList::insertFirst(int val)
{
    Node* NewNode= new Node();
    NewNode->data=val;
    NewNode->next=head;
    head=NewNode;
}
void LinkedList::insertLast(int val)
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

    }
}
void LinkedList::insertAfter(int target, int val)
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
        temp->next=NewNode;
    }

}
void LinkedList::deleteItem(int val)
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
        Node* headtemp=head;
        Node* deleted=head;
        if(head->data==val)
        {
            head=head->next;
            delete deleted;
        }
        else
        {
            deleted=head->next;
            while(deleted->data!=val)
            {
                deleted=deleted->next;
                headtemp=headtemp->next;
            }
            headtemp->next=deleted->next;
            delete deleted;
        }
    
    }
}
void LinkedList::deleteList()
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
bool LinkedList::isFound(int target)
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
void LinkedList::displayList()
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
int  LinkedList::getLength()
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
    LinkedList myList;
    myList.isFound(8);
    myList.insertFirst(5);
    myList.insertFirst(4);
    myList.isFound(8);
    myList.insertFirst(1);
    myList.insertLast(8);
    myList.insertLast(9);
    myList.isFound(8);
    myList.displayList();
    myList.insertAfter(1,2);
    myList.displayList();
    myList.insertAfter(2,3);
    myList.insertFirst(0);
    myList.insertAfter(1,1);
    myList.insertLast(10);
    myList.insertAfter(10,11);
    myList.insertAfter(5,6);
    myList.displayList();

    myList.deleteItem(80);
    myList.insertAfter(4,88);
    myList.insertAfter(11,99);
    myList.insertFirst(77);
    myList.displayList();
    myList.deleteItem(88);
    myList.deleteItem(77);
    myList.deleteItem(99);
    myList.displayList();
    myList.insertLast(12);
    myList.displayList();
    
    cout<<"list lenght: "<<myList.getLength()<<endl;
    cout<<"****delete process*****\n";
    myList.deleteList();


    return 0;
}