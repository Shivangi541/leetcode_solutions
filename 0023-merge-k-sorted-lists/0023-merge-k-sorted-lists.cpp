class Solution {
private:
    // using this stuct to compare the data of the node, bcz we are storing the list into the Priority Queue
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // using pq to store the nodes in the ascending order, by default priority queue stores elements into ascending order only
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // storing the first node of every k lists into pq
        for(int itr = 0; itr < lists.size(); itr++){
            if(lists[itr]) pq.push(lists[itr]);
        }
        
        // Using a dummy list to store the result
        ListNode* dummy = new ListNode(0);
        
        // using the res list to return the result
        ListNode* res = dummy;
        
        // iterating over the pq, and storing the nodes into dummy, and if particular kth node is having more nodes then storing those nodes into the pq
        while(pq.size()){

            // getting the node which is on the top of pq, bcz that will be our smallest node
            ListNode* temp = pq.top();
            
            // removing the top node
            pq.pop();
            
            // storing the temp node into dummy
            dummy->next = temp;
            
            // moving dummy one step ahead
            dummy = dummy->next;
            
            // if particular kth node(temp) is having more nodes then storing the node into the pq
            if(temp->next){
                pq.push(temp->next);
            }
        }
        
        // returning the result
        return res->next;
    }
};