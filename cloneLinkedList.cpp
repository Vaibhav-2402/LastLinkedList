Node *copyList(Node *head)
    {
        //step 1: clone the list
        Node* temp = head;
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }
        
        //step 2: place the clone node in between the original node
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            Node* next = originalNode -> next;
            originalNode -> next  = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        //step 3: copy the random pointers
        
        temp = head;
        
        while(temp != NULL) {
            if(temp -> next != NULL) {
                temp -> next -> arb = temp -> arb ? temp ->arb -> next : temp -> arb;
            }
            temp = temp -> next -> next;
        }
        
        //step 4: refresh the clone linked list
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL) {
            
            if(originalNode -> next != NULL) {
                
            originalNode -> next = originalNode -> next -> next;
            originalNode = originalNode -> next;
            }
            
            if(cloneNode -> next != NULL) {
                
                cloneNode -> next = cloneNode -> next -> next;
                cloneNode = cloneNode -> next;
            }
            
        }
        
        //step 5: return clone head
        
        return cloneHead;
    }
