class MyStack {
public:
    // OPTIMAL - using single queue
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        // 1. push into queue
        q.push(x);

        // 2. insert top (size-1) elements again in queue , and pop them from front;
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.empty()) return true;
        return false;
    }
};

// TC : O(N-1) in push , O(1) in pop
// SC : O(N)

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */