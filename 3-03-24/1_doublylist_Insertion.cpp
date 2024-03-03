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

void insertAtpossition(node *&head, node *&tail, int data, int possition)
{
    if (possition == 1)
    {
        insertAthead(head, tail, data);
        return;
    }
    if (possition == getLen(head) + 1)
    {
        insertAttail(head, tail, data);
        return;
    }

    node *newnode = new node(data);
    int count = 1;
    node *temp = head;
    while (count < possition - 1)
    {
        temp = temp->next;
        count++;
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
    insertAthead(head, tail, 10);
    insertAthead(head, tail, 20);
    insertAthead(head, tail, 30);
    insertAthead(head, tail, 40);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    insertAttail(head, tail, 18);
    insertAttail(head, tail, 3);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    insertAtpossition(head, tail, 45,1);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    insertAtpossition(head, tail,7,8);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    insertAtpossition(head, tail,17,4);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    return 0;
}