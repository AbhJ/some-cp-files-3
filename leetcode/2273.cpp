class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string w;
        for(auto wordit = prev(words.end()); wordit != prev(words.begin()); wordit = prev(wordit)){
            string word = * wordit;
            sort(word.begin(), word.end());
            if(word == w)
                words.erase(next(wordit));
            w = word;
        }
        return words;
    }
};
