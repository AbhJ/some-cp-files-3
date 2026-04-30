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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * h = new ListNode ( - 1), * nex = list1;
        int cnt = 0;
        while (cnt != a) {
            h = nex;
            nex = nex -> next;
            cnt++;
        }
        ListNode* cut = nex;
        nex = list2;
        h -> next = nex;
        while (nex != NULL) {
            h = nex;
            nex = nex -> next;
        }
        nex = cut;
        while (cnt != b) {
            nex = nex -> next;
            cnt++;
        }
        h -> next = nex -> next;
        return list1;
    }
};