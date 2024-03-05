#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void separator()
{
    cout << "-------------------------------------" << endl;
}

void print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLen(node *&head)
{
    int len = 0;
    node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

void insertAthead(node *&head, node *&tail, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertAttail(node *&head, node *&tail, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void deletionAtHead(node *&head, node *&tail)
{
    if (head == NULL)
    {
        cout << "Nothing to delete " << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }

    node *temp = head;
    head = head->next;
    head->prev = NULL;
    temp->next = NULL;
    delete temp;
}

void deletionAtTail(node *&head, node *&tail)
{
    if (head == NULL)
    {
        cout << "Nothing to delete " << endl;
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }

    node *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
}
// **************************************************************
void deletionByValue(node *&head, node *&tail, int value)
{
    if (head == NULL)
    {
        cout << "Nothing to Delete" << endl;
        return;
    }

    if (head->data == value)
    {
        deletionAtHead(head, tail);
        return;
    }

    node *previous = NULL;
    node *current = head;
    while (current!=NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    if(current == NULL){
        cout<<"Value Not found "<<endl;
        return ;
    }
    if (current->next == NULL)
    {
        deletionAtTail(head, tail);
        return;
    }

    previous->next = current->next;
    current->next->prev = previous;
    current->next = NULL;
    current->prev = NULL;

    delete current;
}
// ******************************************************
bool isSorted(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    node *temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data > temp->next->data)
        {
            return false;
        }
        temp = temp->next;
    }

    return true;
}

void insertAscending(node *&head, node *&tail, int data)
{
    if (!isSorted(head))
    {
        cout << "List ain't Sorted" << endl;
        return;
    }

    node *newnode = new node(data);

    if (data < head->data)
    {
        insertAthead(head, tail, data);
        return;
    }

    node *temp = head;
    while (temp->next != NULL && data > temp->next->data)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        insertAttail(head, tail, data);
        return;
    }

    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertAthead(head, tail, 80);
    insertAthead(head, tail, 70);
    insertAthead(head, tail, 60);
    insertAthead(head, tail, 50);
    insertAthead(head, tail, 40);

    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    insertAscending(head, tail, 30);
    print(head);
    separator();

    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    insertAscending(head, tail, 65);
    print(head);
    separator();

    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    insertAscending(head, tail, 90);
    print(head);
    separator();

    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deletionByValue(head,tail,90);
    print(head);
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deletionByValue(head,tail,65);
    print(head);
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deletionByValue(head,tail,35);
    separator();
    print(head);
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    return 0;
}