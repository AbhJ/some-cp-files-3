class Solution {
public:
	vector<int> xorQueries (vector<int>& arr, vector<vector<int>>& queries) {
		int n = arr.size();
		vector <int> pref (n), ans;
		for (int i = 0; i < n; i++) {
			pref [i] = ((i == 0 ? 0 : pref[i - 1]) ^ arr[i]);
		}
		for (auto v : queries) {
			ans.emplace_back ((v[0] == 0 ? 0 : pref[v[0] - 1]) ^ pref[v[1]]);
		}
		return ans;
	}
};