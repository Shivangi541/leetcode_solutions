/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       set<ListNode *> s1;
        ListNode* temp=head;
        while(temp!=NULL)
        {      
            if(s1.find(temp)!=s1.end())
            {
                return temp;
            }
            s1.insert(temp);
            temp=temp->next;
        }
        return NULL;
    }
};