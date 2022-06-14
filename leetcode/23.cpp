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
	ListNode *mergeKLists (vector<ListNode *> &lists) {
		int n = lists.size();
		ListNode *head = new ListNode (- 1);
		ListNode *head_prime = head;
		while (1) {
			ListNode *smallest = new ListNode (1e9);
			int ind;
			for (int i = 0; i < n; i++) {
				if (lists[i] == NULL)
					continue;
				if (smallest -> val > lists[i] -> val)
					smallest = lists[i], ind = i;
			}
			if (smallest -> val == 1e9)
				break;
			head -> next = smallest;
			head = head -> next;
			lists[ind] = lists[ind] -> next;
		}
		head -> next = NULL;
		return head_prime -> next;
	}
};
