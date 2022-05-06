#include <numeric>
int Solution::solve (int A, vector<int> &B) {
	int cnt = 0, sum = std::accumulate (B.begin(), B.end(), 0);
	if (sum % 3 == 0) {
		vector<int> pre (A);
		int pre_sum = 0;
		for (int i = 0; i < A - 1; i++) {
			pre_sum += B[i];
			if (pre_sum == sum / 3)
				pre[i] = 1 + (i == 0 ? 0 : pre[i - 1]);
			else
				pre[i] = (i == 0 ? 0 : pre[i - 1]);
			if (pre_sum == sum * 2 / 3)
				cnt += (i >= 1 ? pre[i - 1] : 0);
		}
	}
	return cnt;
}

