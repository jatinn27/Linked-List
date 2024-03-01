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

void seperator()
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

int len(node *&head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}
void insertAtpossition(node *&head, node *&tail, int data, int possition)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    if (possition == 1)
    {
        insertAThead(head, tail, data);
        return;
    }
    else if (possition == len(head) + 1)
    {
        insertAtTail(head,tail,data);
        return ;
    }

    
    node *temp = head;

    int i = 1;
    while (i < possition - 1)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}
int main()
{
    node *head = NULL;
    node *tail = NULL;
    insertAThead(head, tail, 10);
    insertAThead(head, tail, 20);
    insertAThead(head, tail, 30);
    insertAThead(head, tail, 40);
    insertAtTail(head, tail, 18);

    print(head);
    seperator();

    insertAtpossition(head, tail, 27, 3);
    print(head);
    seperator();
    insertAtpossition(head, tail, 3, 1);
    print(head);
    seperator();
    cout<<"Head: "<<head->data<<" "<<endl;
    cout<<"Tail: "<<tail->data<<" "<<endl;
    seperator();
    cout<<"length: "<<len(head)<<endl;
    seperator();
    insertAtpossition(head, tail, 7, 8);
    print(head);
    seperator();

    cout<<"Head: "<<head->data<<" "<<endl;
    cout<<"Tail: "<<tail->data<<" "<<endl;
    seperator();

    return 0;
}