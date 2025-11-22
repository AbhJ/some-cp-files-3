class Solution {
public:
	bool isPossible (vector<int>& target) {
		long long sum = accumulate (target.begin(), target.end(), 0LL);
		priority_queue <long long> q;
		for (int i = 0; i < target.size(); i++) {
			q.emplace (target[i]);
		}
		while (q.top() != 1) {
			long long curMa = q.top();
			q.pop();
			sum -= curMa;
			// this sum is now the sum of all the other elements before
			if (curMa - sum <= 0 or sum <= 0)
				return false;
			if (curMa % sum)
				q.emplace (curMa % sum);
			else
				q.emplace (sum);
			sum += curMa % sum;
		}
		while (q.empty() == 0)
			cout << q.top() << " ", q.pop();
		return true;
	}
};