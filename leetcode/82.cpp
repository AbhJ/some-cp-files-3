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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode (- 1), *cur = newHead, *tmp = head;
        while (tmp != NULL) {
            int val = tmp -> val, cnt = 0;
            while (tmp != NULL and tmp -> val == val) {
                tmp = tmp -> next;
                cnt++;
            }
            if (cnt == 1){
                cur -> next = new ListNode (val);
                cur = cur -> next;
            }
        }
        return newHead -> next;
    }
};