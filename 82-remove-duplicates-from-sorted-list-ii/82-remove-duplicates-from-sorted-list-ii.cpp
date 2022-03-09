/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL) return NULL;
        ListNode *temp = new ListNode(0);
        ListNode *ans = temp;
        int cnt =0;
        while(head)
        {
            ListNode *temp1 = new ListNode(head->val);
            while(head->next && head->val == head->next->val) cnt++, head = head->next;
            if(cnt == 0) 
            {
                temp->next = temp1;
                temp = temp->next;
            }
             head= head->next;
             cnt =0;
        }
       
        return ans->next;
    }
};