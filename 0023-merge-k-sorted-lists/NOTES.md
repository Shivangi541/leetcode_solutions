ptr = ptr->next;
head2 = head2->next;
}
}
while (head1)
{
ptr->next = head1;
ptr = ptr->next;
head1 = head1->next;
}
while (head2)
{
ptr->next = head2;
ptr = ptr->next;
head2 = head2->next;
}
return ans->next;
}
ListNode* mergeKLists(vector<ListNode*>& lists)
{
if (lists.size() == 0)
return NULL;
ListNode* head1 = lists[0];
for (int i = 1; i < lists.size(); i++)
head1 = mergeTwoList(head1, lists[i]);
return head1;
}
};