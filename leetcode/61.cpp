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
	ListNode *rotateRight (ListNode *head, int k) {
		ListNode *oriHead = head;
		int cnt = 0;
		while (head != NULL) {
			cnt++;
			head = head -> next;
		}
		if (cnt == 0)
			return head;
		k %= cnt;
		if (k == 0)
			return oriHead;
		head = oriHead;
		int tmpCnt = 0;
		ListNode *newStart;
		while (head != NULL) {
			tmpCnt++;
			if (tmpCnt == cnt - k) {
				newStart = head -> next;
				head -> next = NULL;
				break;
			}
			head = head -> next;
		}
		head = newStart;
		tmpCnt = 0;
		while (head != NULL) {
			tmpCnt++;
			if (tmpCnt == k) {
				head -> next = oriHead;
				break;
			}
			head = head -> next;
		}
		return newStart;
	}
};
