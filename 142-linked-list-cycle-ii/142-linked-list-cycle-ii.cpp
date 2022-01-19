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
    ListNode *detectCycle(ListNode *head) 
    {
          if(!head || !head->next) return NULL;
          ListNode *slow =head,*fast = head, *ans = head;
          while(fast->next && fast->next->next)
          {
              fast = fast->next->next;
              slow = slow->next;
              if(fast == slow)
              {
                  while(slow!=ans) slow=slow->next, ans = ans->next;
                  return ans;
              }
          }
        return NULL;
    }
};