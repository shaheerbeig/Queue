#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size,front,rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isfull(){
        if(rear == size  ){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data){
        //we can call is full here directly as well
        if(rear == size){
            cout<<"Queue is Full. "<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
    
    bool isempty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int dequeue(){
        if(front == rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            int x = arr[front];
            front++;
            if(front == rear){
                front = rear = 0 ;
            }
            return x;
        }
    }

    int peek(){
        if(!isempty()){
            return arr[front];
        }
        else{
            cout<<"empty queue"<<endl;
        }
    }
    void display(){
        int i = front;
        while(i < rear){
            cout<<arr[i]<<" ";
            i++;
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