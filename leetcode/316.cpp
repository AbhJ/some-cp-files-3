class Solution {
public:
	string removeDuplicateLetters (string s) {
		int n = s.length();
		vector<bool>vis (26);
		string ans;
		vector<int>cnt (26);
		for (int i : s)
			cnt[i - 'a']++;
		for (int i = 0; i < n; i++) {
			if (vis[s[i] - 'a'] == 1) {
				cnt[s[i] - 'a']--;
				continue;
			}
			if (ans.empty()) {
				ans += s[i];
				vis[s[i] - 'a'] = 1;
				continue;
			}
			while (ans.empty() == 0 and ans.back() > s[i] and cnt[ans.back() - 'a'] > 1) {
				vis[ans.back() - 'a'] = 0;
				cnt[ans.back() - 'a']--;
				ans.pop_back();
			}
			ans += s[i];
			vis[s[i] - 'a'] = 1;
		}
		return ans;
	}
};
