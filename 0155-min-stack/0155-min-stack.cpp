class MinStack {
public:
    vector<int> arr;
    vector<int> minArr;

    MinStack() {
    }

    void push(int value) {
        arr.push_back(value);

        if (minArr.empty()) {
            minArr.push_back(value);
        }
        else {
            minArr.push_back(min(value, minArr.back()));
        }
    }

    void pop() {
        arr.pop_back();
        minArr.pop_back();
    }

    int top() {
        return arr.back();
    }

    int getMin() {
        return minArr.back();
    }
};