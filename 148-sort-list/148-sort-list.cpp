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
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        while(head)
        {
            v.push_back(head->val);
            head= head->next;
        }
        sort(v.begin(), v.end());
        ListNode *temp = new ListNode(0);
        ListNode *ans = temp;
        for(int i=0; i<v.size(); i++)
        {
            ListNode *t = new ListNode(v[i]);
            temp->next = t;
            temp = temp->next;
        }
        return ans->next;
    }
};