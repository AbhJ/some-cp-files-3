class Solution {
public:
	vector<string> largestString (vector<int>& nums) {
		vector <string> v;
		for (auto tot : nums) {
			string s;
			int ind = 25;
			while (tot) {
				if (tot >= (1 << ind)) {
					tot -= (1 << ind);
					s += (char) (ind + 'a');
				}
				else
					ind--;
			}
			v.emplace_back (s);
		}
		return v;
	}
};