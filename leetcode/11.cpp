class Solution {
public:
	int maxArea (vector<int> &A) {
		int n = A.size(), i = 0, j = n - 1, ans = 0;
		for (; i < j;) {
			ans = max (min (A[i], A[j]) * (j - i), ans);
			if (A[i] > A[j])
				j--;
			else
				i++;
		}
		return ans;
	}
};
