class MyCircularQueue {
public:
    int *arr;
    int size;
    int front;
    int rear;
    
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        rear = front = -1;
    }
    
    bool enQueue(int value) {
        if((rear + 1) % size == front){
            return false;
        }
        if(front == -1){
            rear = front = 0;
        }
        else{
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1){
            return false;
        }
        if(front == rear){
            rear = front = -1;
        }
        else{
            front = (front + 1) % size;
        }
        return true;
    }
    
    int Front() {
        if(front == -1){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int Rear() {
        if(rear == -1){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if((rear + 1) % size == front){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */