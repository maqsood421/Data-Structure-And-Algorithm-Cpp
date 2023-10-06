#include <iostream>
using namespace std;

//preprocessors macros
#define N 100

class queue{
    private:
    int* arr;
    int front;
    int back;

    public:

    queue(){
        arr = new int[N];
        front = -1;
        back = -1;
    } 

    void enqueue(int val){
        if(back == N - 1){
            cout << "Queue overflow\n";
            return;
        }
        back++;
        arr[back] = val;

        if(front == -1)
            front++;
    }

    void dequeue(){
        if(front == -1 || front > back){
            cout << "No elements in queue\n";
            return;
        }
        front++;
    }

    int peek(){
        if(front == -1 || front > back){
            cout << "No elements in queue\n";
            return - 1;
        }

        return arr[front];
    }

    bool empty(){
        if(front == -1 || front > back){
            return true;
        }
        
        return false;
    }

};


int main(void)
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.empty() << endl;
    return 0;
}   