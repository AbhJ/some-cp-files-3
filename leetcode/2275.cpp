class Solution {
public:
	int largestCombination (vector<int> &candidates) {
		vector<int>cnt (32);
		for (int i = 0; i < candidates.size(); i++)
			for (int j = 0; j < 32; j++)
				if (candidates[i] & (1 << j))
					cnt[j]++;
		return *max_element (cnt.begin(), cnt.end());
	}
};
