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
void deletionAtHead(node* &head,node* &tail){
    if(head == NULL){
        cout<<"Nothing to delete "<<endl;
        return;
    }

    if(head->next == NULL){
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

void deletionAtTail(node* &head,node* &tail){
    if(head == NULL){
        cout<<"Nothing to delete "<<endl;
        return;
    }

    if(head->next == NULL){
        delete head;
        head = NULL;
        tail = NULL;
    }

    node* temp =tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
}

void deletionAtPosition(node* &head,node* &tail,int position){
    if(head == NULL){
        cout<<"Nothing to Delete"<<endl;
        return ;
    }

    if(position == 1){
        deletionAtHead(head,tail);
        return ;
    }

    if(position == getLen(head) ){
        deletionAtTail(head,tail);
        return ;
    }

    if(position <= 0 && position > getLen(head)){
        cout<<"Invalid Position"<<endl;
        return ;
    }
    node* curr =head;
    node * prev = NULL;
    int count = 0;
    while(count < position - 1){
        prev = curr;
        curr = curr ->next;
        count++;
    }

    prev->next = curr ->next;
    curr->next ->prev = prev;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;

}
bool isSorted(node *&head)
{
    if(head == NULL || head ->next == NULL){
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

    deletionAtPosition(head,tail,1);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deletionAtPosition(head,tail,7);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();




    return 0;
}