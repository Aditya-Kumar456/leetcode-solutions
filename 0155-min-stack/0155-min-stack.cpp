class MinStack {
public:
    int *arr;
    int *minArr;
    int size;
    int topIndex;
    MinStack() {
        size = 30000;
        topIndex = -1;
        arr = new int[size];
        minArr = new int[size];
    }
    
    void push(int value) {
        if(topIndex < size - 1){
            topIndex++;
            arr[topIndex] = value;

            if(topIndex == 0){
                minArr[topIndex] = value;
            }
            else {
                minArr[topIndex] = min(value, minArr[topIndex - 1]);
            }
        }
    }
    
    void pop() {
        if(topIndex >= 0){
            topIndex--;
        }
    }
    
    int top() {
        return arr[topIndex];
    }
    
    int getMin() {
        return minArr[topIndex];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */