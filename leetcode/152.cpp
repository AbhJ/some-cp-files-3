class Solution {
public:
	int maxProduct (vector<int> &A) {
		int n = A.size(), maxi = A[0], mini = A[0], answer = *max_element (A.begin(), A.end());
		for (int i = 1; i < n; i++) {
			int miniTemp = min ({A[i], A[i] * mini, A[i] * maxi});
			int maxiTemp = max ({A[i], A[i] * mini, A[i] * maxi});
			maxi = maxiTemp;
			mini = miniTemp;
			answer = max ({maxi, mini, answer});
		}
		return answer;
	}
};
