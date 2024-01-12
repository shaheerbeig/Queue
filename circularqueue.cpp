#include<iostream>
using namespace std;

class Queue{
    public:
    int size;
    int *arr;
    int rear;
    int front;

    Queue(int size){
        this->size = size;
        rear =-1;
        front =-1;
        arr = new int[size];
    }

    void enqueue(int data){
        //checking for is queue full
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout<<"Queue is Full cannot add more elements"<<endl;
        }
        //first element is being inserted 
        else if(front == -1){
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front!= 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear ++;
            arr[rear] = data;
        }
    }

    int dequeue(){
        if(front == -1 && rear == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else if(front == rear){
            int x = arr[front];
            front = rear = -1;
            return x;
        }
        else if(front == size-1 && rear !=0){
            front = 0;
        }
        else{
            int x = arr[front];
            front++;
            return x;
        }
    }
    void display(){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Queue q(5);
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