/**
 * @author      : acer (acer@abj-ubuntu)
 * @file        : royal_names
 * @created     : Sunday May 01, 2022 09:55:31 IST
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim (const string &);
string rtrim (const string &);

// Complete the getSortedList function below.

size_t split (const std::string &txt, std::vector<std::string> &strs, char ch) {
	size_t pos = txt.find (ch);
	size_t initialPos = 0;
	strs.clear();
	// Decompose statement
	while (pos != std::string::npos) {
		strs.push_back (txt.substr (initialPos, pos - initialPos));
		initialPos = pos + 1;
		pos = txt.find (ch, initialPos);
	}
	// Add the last one
	strs.push_back (txt.substr (initialPos, std::min (pos, txt.size()) - initialPos + 1));
	return strs.size();
}

int value (char r) {
	// I in roman is equal to
	// 1 in decimal
	if (r == 'I')
		return 1;
	// V in roman is equal to
	// 5 in decimal
	if (r == 'V')
		return 5;
	// X in roman is equal to
	// 10 in decimal
	if (r == 'X')
		return 10;
	// L in roman is equal to
	// 50 in decimal
	if (r == 'L')
		return 50;
	// C in roman is equal to
	// 100 in decimal
	if (r == 'C')
		return 100;
	// D in roman is equal to
	// 500 in decimal
	if (r == 'D')
		return 500;
	// M in roman is equal to
	// 1000 in decimal
	if (r == 'M')
		return 1000;
	return -1;
}

// Function to return the decimal value
// of a roman numaral
int romanToDecimal (string &str) {
	// Initialize result
	int res = 0;
	for (int i = 0; i < (int)str.length(); i++) {
		int s1 = value (str[i]);
		if (i + 1 < (int)str.length()) {
			int s2 = value (str[i + 1]);
			if (s1 >= s2)
				res = res + s1;
			else {
				res = res + s2 - s1;
				i++;
			}
		}
		else
			res = res + s1;
	}
	return res;
}

// Function to sort the array according to
// the increasing order
vector<string> sortArr (vector<string> arr) {
	int n = arr.size();
	vector<pair<int, string> > vp;
	for (int i = 0; i < n; i++)
		vp.push_back (make_pair (romanToDecimal (arr[i]), arr[i]));
	sort (vp.begin(), vp.end());
	vector<string>s;
	for (int i = 0; i < (int)vp.size(); i++)
		s.emplace_back (vp[i].second);
	return s;
}

vector<string> getSortedList (const vector<string> &names) {
	map<string, vector<string>> m;
	for (auto i : names) {
		vector<string> v;
		split (i, v, ' ');
		assert (v.size() == 2 or v.empty() == 1);
		m[v[0]].emplace_back (v[1]);
	}
	vector<string> name;
	for (auto &i : m) {
		for (auto j : sortArr (i.second))
			name.emplace_back (i.first + " " + j);
	}
	return name;
}
int main() {
	ofstream fout (getenv ("OUTPUT_PATH"));
	string names_count_temp;
	getline (cin, names_count_temp);
	int names_count = stoi (ltrim (rtrim (names_count_temp)));
	vector<string> names (names_count);
	for (int i = 0; i < names_count; i++) {
		string names_item;
		getline (cin, names_item);
		names[i] = names_item;
	}
	vector<string> res = getSortedList (names);
	for (int i = 0; i < res.size(); i++) {
		fout << res[i];
		if (i != res.size() - 1)
			fout << "\n";
	}
	fout << "\n";
	fout.close();
	return 0;
}

string ltrim (const string &str) {
	string s (str);
	s.erase (
		s.begin(),
		find_if (s.begin(), s.end(), not1 (ptr_fun<int, int> (isspace)))
	);
	return s;
}

string rtrim (const string &str) {
	string s (str);
	s.erase (
		find_if (s.rbegin(), s.rend(), not1 (ptr_fun<int, int> (isspace))).base(),
		s.end()
	);
	return s;
}
