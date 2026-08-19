class Solution {
public:
	int subarrayBitwiseORs (vector<int>& arr) {
		unordered_set <int> s, ans;
		for (auto i : arr) {
			unordered_set <int> _s;
			_s.emplace (i);
			for (auto j : s)
				_s.emplace (i | j);
			ans.insert (_s.begin(), _s.end());
			s = _s;
		}
		return ans.size();
	}
};