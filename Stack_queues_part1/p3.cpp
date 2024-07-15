class MyStack {
public:
    // BRUTE - using 2 queues
    queue<int> Q1;
    queue<int> Q2;

    MyStack() {
        
    }
    
    void push(int x) {
        // 1. push into Q2
        Q2.push(x);

        // 2. move all elements of Q1 to Q2
        while(!Q1.empty()){
            Q2.push(Q1.front());
            Q1.pop();
        }

        // 3. move all elements of Q2 to Q1
        while(!Q2.empty()){
            Q1.push(Q2.front());
            Q2.pop();
        }
    }
    
    int pop() {
        int ele = Q1.front();
        Q1.pop();
        return ele;
    }
    
    int top() {
        return Q1.front();
    }
    
    bool empty() {
        if(Q1.empty()) return true;
        return false;
    }
};

// TC : O(N) + O(N) in push , O(1) in pop
// SC : O(N) + O(N)

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */