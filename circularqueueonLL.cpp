#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue{
    public:
    Node *rear;
    Node *front;

    Queue(){
        rear = front = NULL;
    }

    void enqueue(int data){
        Node *newnode = new Node(data);
        if(rear == NULL ){
            front = rear = newnode;
            rear->next = front;
        }
        else{
            rear->next = newnode;
            rear = newnode;
            newnode->next = front;
        }
    }

    int dequeue(){
        if(rear == NULL && front == NULL){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            Node *temp = front;
            int x = front->data;
            delete temp;
            front = rear = NULL;
            return x;
        }
        else{
            Node *temp = front;
            int x = temp->data;
            front = front->next;
            rear->next = front;
            temp->next = NULL;
            delete temp;
            return x;
        }
    }

    void display(){
        Node *temp = front;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != front);
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    q.display();

    q.dequeue();

    q.display();

    q.dequeue();

    q.display();
}