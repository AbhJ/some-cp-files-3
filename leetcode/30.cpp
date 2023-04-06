class Solution {
public:
    bool isSubstring (unordered_map<string, int> cnt, string s, int n, int each_len){
        string tmp;
        for(int i = 0; i < s.length(); i++){
            if(i % each_len == 0)
                tmp.clear();
            tmp += s[i];
            if(i % each_len == each_len - 1 and -- cnt[tmp] < 0)
                return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_len = s.length(), n = words.size(), each_len = words[0].length();
        unordered_map<string, int> cnt;
        for(auto word: words){
            cnt[word]++;
        }
        vector<int> indices;
        for(int i = 0; i <= s_len - each_len * n; i++){
            string subString = s.substr(i, each_len * n);
            if(isSubstring(cnt, subString, n, each_len))
                indices.emplace_back(i);
        }
        return indices;
    }
};