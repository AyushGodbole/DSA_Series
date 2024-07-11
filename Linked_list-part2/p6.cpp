/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

/*  Function which returns the  root of
    the flattened linked list. */

// MERGE 2 LINKED LISTS
Node* mergeLL(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* temp = dummy;
    
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            temp->bottom = head1;
            head1 = head1->bottom;
        } else {
            temp->bottom = head2;
            head2 = head2->bottom;
        }
        temp = temp->bottom;
    }
    
    if (head1 != NULL) {
        temp->bottom = head1;
    } else {
        temp->bottom = head2;
    }
    
    return dummy->bottom;
}

Node* flatten(Node* root) {
    // check if Last Linked List
    if (root == NULL || root->next == NULL) {
        return root;
    }
    
    // RECURSIVE CALL
    Node* res = flatten(root->next);
        
    // MERGE 2 LINKED LISTS
    Node* merged = mergeLL(root, res);
    return merged;
}

// TC : O(sum of all nodes)
// SC : O(1)
