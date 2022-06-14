#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSongs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER rideDuration
 *  2. INTEGER_ARRAY songDurations
 */

vector<int> findSongs(int rideDuration, vector<int> songDurations) {
    rideDuration -= 30;
    // m is a hash table used to map indices of the songs to the songDurations
    map<int, int>m;
    vector<pair<int, int>>v;
    vector<vector<int>>ans;
    for(int i = 0; i < songDurations.size(); i++)
        // instead of i, we use negative of i as we want to minimize i and maximize songDurations[i]
        v.emplace_back(songDurations[i], - i);
    // Here we will sort the vector so that we have the songs with the highest durations followed by the
    // least indices at the end. 
    sort(v.begin(), v.end());
    if(v.size() > 1 and v.front().first == v.back().first and v.front().first * 2 == rideDuration)
        return vector<int> {0, 1};
    // This is a special corner case in which all the songs have the same duration
    for(int i = v.size() - 1; i != - 1; i--){
        // we check whether a pair is formed by looking up 'rideDuration - v[i].first' in the hash table m
        if(m.count(rideDuration - v[i].first))
            // in this case the sum of the durations of the songs '- v[i].second' and 'm[rideDuration - v[i].first]' will be
            // equal to rideDuration which is desired
            ans.emplace_back(vector<int>{max(songDurations[- v[i].second], songDurations[m[rideDuration - v[i].first]]), min(songDurations[v[i].second], songDurations[m[rideDuration - v[i].first]]), - v[i].second, m[rideDuration - v[i].first]});
            // the max and min functions are used for proper indexing
            // we store all the possible pairs of songs in the vector 'ans' and then return the best possible pair
            // by best, here we focus at the third constraint in the assumptions section of the question 'select the pair
            // with the longest song'
        m[v[i].first] = - v[i].second;
        // mapping the song index to its duration for later lookup
    }
    // handling the corner case of no possible pairs
    if(ans.empty())
        return vector<int>{-1 , -1};
    sort(ans.begin(), ans.end());
    // returning the best possible answer
    return vector<int>{min(ans.back()[2], ans.back()[3]), max(ans.back()[2], ans.back()[3])};
    // The complexity of code is O(n) space and O(n log n) time where n is the number of songs
    // the log n factor comes in due to the look - up time in the hashtable and sorting the vectors v and ans each of size O(n)
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rideDuration_temp;
    getline(cin, rideDuration_temp);

    int rideDuration = stoi(ltrim(rtrim(rideDuration_temp)));

    string songDurations_count_temp;
    getline(cin, songDurations_count_temp);

    int songDurations_count = stoi(ltrim(rtrim(songDurations_count_temp)));

    vector<int> songDurations(songDurations_count);

    for (int i = 0; i < songDurations_count; i++) {
        string songDurations_item_temp;
        getline(cin, songDurations_item_temp);

        int songDurations_item = stoi(ltrim(rtrim(songDurations_item_temp)));

        songDurations[i] = songDurations_item;
    }

    vector<int> result = findSongs(rideDuration, songDurations);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
