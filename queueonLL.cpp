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
        rear = front  = NULL;
    }

    void enqueue(int data){
        Node *newnode = new Node(data);
        if(rear == NULL){
            rear = front = newnode;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
    }

    int dequeue(){
        if(rear == NULL && front == NULL){
            cout<<"Queue is empty "<<endl;
            return -1;
        }
        else{
            int x;
            Node *temp = front;
            x= temp->data;
            front = front->next;
            temp->next = NULL;
            delete temp;
            return x;
        }
    }
    void display(){
        Node *temp = front;
        while(temp != rear->next){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
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
    cout<<"dequeed element "<<q.dequeue();
    cout<<endl;
    q.display();

}