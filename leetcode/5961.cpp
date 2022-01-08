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
	int pairSum (ListNode *head) {
		vector<int> v;
		ListNode *tmp = head;
		for (; tmp != NULL; tmp = tmp -> next)
			v.emplace_back (tmp -> val);
		int ans = 0, n = v.size();
		for (int i = 0; i < n / 2; i++)
			ans = max (ans, v[i] + v[n - i - 1]);
		return ans;
	}
};
