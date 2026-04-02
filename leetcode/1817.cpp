class Solution {
public:
	vector<int> findingUsersActiveMinutes (vector<vector<int>>& logs, int k) {
		map <int, set<int>> minUser;
		map <int, int> freq;
		vector <int> ans (k);
		for (auto v : logs) {
			minUser[v[1]].emplace (v[0]);
		}
		for (auto [min, users] : minUser) {
			for (auto user : users) {
				freq[user]++;
				// how many minutes this user was online
			}
		}
		for (auto [user, f] : freq) {
			ans[f - 1]++;
		}
		return ans;
	}
};