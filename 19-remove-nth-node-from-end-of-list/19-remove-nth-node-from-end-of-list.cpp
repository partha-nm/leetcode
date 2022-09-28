class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) 
    {
        if(!head->next) return NULL;
        ListNode *fast = head, *slow = head;
        int cnt =0;
        while(fast->next)
        {
            if(cnt < k) fast=fast->next;
            else
            {
                slow = slow->next;
                fast = fast->next;
            }
            cnt++;
        }
         if(cnt < k) return head->next;
        slow->next = slow->next->next;
        return head;
    }
};