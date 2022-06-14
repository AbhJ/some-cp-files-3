#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'segment' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER x
 *  2. INTEGER_ARRAY space
 */

int segment(int x, vector<int> space) {
    multiset<int>m;
    int ans = 0;
    for(int i = 0; i < space.size(); i++){
        m.emplace(space[i]);
        if(i >= x)
            m.erase(m.find(space[i - x]));
        if(i >= x - 1)
            ans = max(ans, *m.begin());
    }
    return ans;
    // time O(n log n) space O (n)
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string x_temp;
    getline(cin, x_temp);

    int x = stoi(ltrim(rtrim(x_temp)));

    string space_count_temp;
    getline(cin, space_count_temp);

    int space_count = stoi(ltrim(rtrim(space_count_temp)));

    vector<int> space(space_count);

    for (int i = 0; i < space_count; i++) {
        string space_item_temp;
        getline(cin, space_item_temp);

        int space_item = stoi(ltrim(rtrim(space_item_temp)));

        space[i] = space_item;
    }

    int result = segment(x, space);

    fout << result << "\n";

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

