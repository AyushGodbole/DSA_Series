class MyQueue {
public:

    // BRUTE FORCE - using 2 stacks

    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        // 1. move all elements from st1 to st2
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        // 2. push x in st1
        st1.push(x);

        // 3. move all elements from st2 to st1
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int ele = st1.top();
        st1.pop();
        return ele;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        if(st1.empty()) return true;
        return false;
    }
};

// TC : O(N) + O(1) + O(N) in push , O(1) in pop
// SC : O(N) + O(N)



/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */