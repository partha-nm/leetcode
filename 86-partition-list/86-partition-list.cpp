
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode *small = new ListNode(0), *large = new ListNode(0);
        ListNode *first = small, *second = large;
        while(head)
        {
            if(head->val < x) 
            {
                small->next = new ListNode(head->val);
                small = small->next;
            }
            else 
            {
                large->next = new ListNode(head->val);
                large = large->next;
            }
            head = head->next;
        }
        small->next = second->next;
        first = first->next;
        // while(first)
        // {
        //     cout<<first->val<<" ";
        //     first = first->next;
        // }
        return first;
    }
};