class Solution {
public:
	int findDuplicate (vector<int> &A) {
		int n = A.size();
		for (int i = 0; i < n; i++) {
			if (A[abs (A[i]) - 1] < 0)
				return abs (A[i]);
			else
				A[abs (A[i]) - 1] = - A[abs (A[i]) - 1];
		}
		return - 1;
	}
};
