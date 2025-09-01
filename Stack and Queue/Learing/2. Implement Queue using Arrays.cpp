//Queue Using Array

/*

The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    arr[rear] = x;
    rear = (rear+1)%100005;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    int popped = arr[front];
    if(front == rear){
        return -1;
    }else{
        front = (front+1)%100005;
    }
    return popped;
    
}


//This solution is provided wrt to gfg.. we need to keep in mind what is provided in the constructor due to which this is different from code given in striver's sheet
