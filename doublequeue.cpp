#include<iostream>
using namespace std;

class doublequeue{
    public:

    int rear;
    int front;
    int *arr;
    int size;

    doublequeue(int size){
        this->size = size;
        front = -1;
        rear =-1;
        arr = new int[size];
    }

    void pushrear(int data){
        if((front==0 && rear==size-1) || (rear == (front-1)%(size-1))){
            cout<<"Queue is full."<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear=size-1 && front !=0){
            rear=0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pushfront(int data){
        if((front==0 && rear==size-1) || (rear == (front-1)%(size-1))){
            cout<<"Queue is full."<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[front] = data;
        }
        else if(front ==0){
            front = size - 1;
            arr[front] = data;
        }
        else{
            front--;
            arr[front] = data;
        }
    }
    int popfront(){
        if(rear == -1 && front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear){
            int x = arr[front];
            front = rear = -1;
            return x;
        }
        else if(front == size-1 && rear !=0){
            front=0;
        }
        else {
             int x = arr[front];
            front++;
            return x; 
        }
    }

    int poprear(){
        if(rear == -1 && front == -1){
            cout<<"Queue is empty"<<endl;
        }
        else if(rear == front){
            int x = arr[rear];
            rear = front = -1;
            return x;
        }
        else if(rear == 0){
            rear = size -1;
        }
        else{
            rear --;
        }
    }
};

int main(){
    doublequeue q(5);
    q.pushfront(5);
    q.pushfront(1);
    q.pushfront(2);
    q.pushrear(9);

    q.popfront();
    q.poprear();
}