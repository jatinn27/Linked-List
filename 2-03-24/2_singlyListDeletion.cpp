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
    ~node(){
        cout<<"Deleting Node with data: "<<data<<endl;
        if(this->next!=NULL){
            delete next;
        }
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

void deleteAThead(node *&head, node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    node *temp = head;

    head = head->next;
    temp->next = NULL;
    delete temp;
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

void deleteAtlast(node* &head,node* &tail){
    node* temp = head;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    while(temp->next->next!=NULL){
        temp = temp->next;
    }

    tail = temp;
    temp = temp->next;
    tail->next = NULL;
    delete temp;
}

void deleteAtpossition(node* &head,node* &tail,int possition){
    if(possition == 1){
        deleteAThead(head,tail);
        return ;
    }

    if(possition == len(head)){
        deleteAtlast(head,tail);
        return ;
    }

    if(possition >len(head)){
        cout<<"You are trying deleting a node that doesn't exist"<<endl;
        return ;
    }

    if(head == tail){
        delete head;
        head = tail =NULL;
        return ;
    }
    
    node* prev =NULL;
    node* temp =head;
    int count =1;
    while(count< possition){
        prev = temp;
        temp = temp->next;
        count++;
    }

    prev->next = temp->next;
    temp->next = NULL;
    delete temp;

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

    deleteAThead(head,tail);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deleteAtlast(head,tail);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    insertAThead(head, tail, 3);
    insertAThead(head, tail, 27);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deleteAtpossition(head,tail,1);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deleteAtpossition(head,tail,4);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deleteAtpossition(head,tail,5);
    separator();
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deleteAtpossition(head,tail,3);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    deleteAtpossition(head,tail,2);
    print(head);
    separator();
    cout << "Head: " << head->data << " " << endl;
    cout << "Tail: " << tail->data << " " << endl;
    separator();

    return 0;
}
