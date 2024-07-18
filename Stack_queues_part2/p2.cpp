class LRUCache {
public:
    // APPROACH
    class Node{
      public:  
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key_, int val_){
            key = key_;
            val = val_;
        }
    };

    // creating doubly linked list
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    // initail configuation
    int cap;
    unordered_map<int,Node*> Mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // logic to add node
    void addNode(Node* newnode){
        Node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }
    
    // logic to delete node
    void deleteNode(Node * node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        // if already in map , we need to make that node last/previous used node
        if(Mp.find(key) !=Mp.end()){
            Node* resNode = Mp[key];
            int res = resNode->val;
            Mp.erase(key);

            deleteNode(resNode);
            addNode(resNode);
            Mp[key] = head->next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        // if node to be inserted is already there , delete it and insert it again
        if(Mp.find(key)!=Mp.end()){
            Node* existingNode = Mp[key];
            Mp.erase(key);
            deleteNode(existingNode);
        }
        // check if cache is full
        if(Mp.size()==cap){
            // delte LRU , pointed by tail
            Mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // add new node
        addNode(new Node(key,value));
        Mp[key] = head->next;
    }
};


// TC for get,put operations : O(1)
// SC : O(N)





/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */