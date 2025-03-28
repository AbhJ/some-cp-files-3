/*
Problem Statement

There is a new alien language which uses the latin alphabet.
However, the order among letters are unknown to you.
You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"


t -> f
w -> e
r -> t
e -> r


w -> e -> r -> t -> f

[
  "a"
  "bc"
]
*/

string findOrder (vector<string> &words) {
	vector<set<int>>adj (26);
	vector<int>ind (26);
	int n = words.size();
	for (int i = 0; i < n - 1; i++) {
		// firstly generate the adjacency list
		for (int j = 0; j < min (words[i].length(), words[i + 1].length()); j++) {
			if (words[i][j] != words[i + 1][j]) {
				adj[words[i][j] - 'a'].emplace (words[i + 1][j] - 'a');
				break;
			}
		}
	}
	for (auto i : adj) {
		for (auto j : i)
			ind[j]++;
	}
	set <int> charsInDict;
	for (int i = 0; i < n; i++) {
		// add characters in Dictionary
		for (int j = 0; j < words[i].length(); j++) {
			charsInDict.emplace (words[i][j] - 'a');
		}
	}
	string answer;
	queue<char>q;
	for (auto i : charsInDict)
		if (ind[i] == 0) {
			q.emplace ((char) (i + 'a'));
		}
	while (q.empty() == 0) {
		char cur = q.front();
		q.pop();
		for (auto i : adj[cur - 'a']) {
			if (--ind[i] == 0)
				q.emplace ((char) (i + 'a'));
		}
		answer += cur;
	}
	if (answer.size() != charsInDict.size()) {
		return "false";
	}
	return answer;
}