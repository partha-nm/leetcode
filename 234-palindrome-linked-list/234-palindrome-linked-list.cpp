
class Solution {
public:
    ListNode* reverse(ListNode *head_)
    {
        ListNode *head2 = NULL;
        while(head_)
        {
            ListNode *nxt = head_->next;
            head_->next = head2;
            head2 = head_;
            head_ = nxt;
        }
        return head2;
    }
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next) return true;
        ListNode *slow = head, *fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* node = slow->next;
        slow->next = NULL;
        ListNode *newHead = reverse(node);
        while(head && newHead)
        {
            if(head->val != newHead->val) return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};