class Solution {
public:
ListNode* sortList(ListNode* head) {
// brute force
ListNode *temp= head;
vector<int>arr;
while(temp!=NULL)
{
arr.push_back(temp->val);
temp=temp->next;
}
sort(arr.begin(),arr.end());
int i=0;
temp=head;
while(temp!=NULL)
{
temp->val=arr[i];
i=i+1;
temp=temp->next;
}
return head;
}
};