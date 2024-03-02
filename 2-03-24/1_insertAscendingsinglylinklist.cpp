#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

void separator()
{
    cout << "-----------------------------------------" << endl;
}

void insertAThead(node *&head, node *&tail, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
}

void insertAtTail(node *&head, node *&tail, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

bool isSorted(node *&head)
{
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
    node *temp = head;
    node *prev = NULL;
    if (head == NULL || data < temp->data)
    {
        insertAThead(head, tail, data);
        return;
    }

    while (temp->next != NULL && data > temp->data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    node *newnode = new node(data);
    prev->next = newnode;
    newnode->next = temp;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertAThead(head, tail, 80);
    insertAThead(head, tail, 70);
    insertAThead(head, tail, 60);
    insertAThead(head, tail, 50);
    insertAThead(head, tail, 40);

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
    return 0;
}
