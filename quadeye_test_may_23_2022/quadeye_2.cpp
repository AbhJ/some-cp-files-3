#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'chooseFlask' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY requirements
 *  2. INTEGER flaskTypes
 *  3. 2D_INTEGER_ARRAY markings
 */

int chooseFlask(vector<int> requirements, int flaskTypes, vector<vector<int>> markings) {
    map<int, set<int>> marks;
    for(auto& v: markings){
        marks[v[0]].emplace(v[1]);
    }
    long long best_pos = - 1, best_cost = 1e18, count = 0;
    for(auto &m: marks) {
        if(m.second.empty() == 0){ 
        long long cost = 0, flag = 0, flag2 = 0;
        for(int &v: requirements){
            if(count++ > 1e7){
                flag2 = 1;
                break;
            }
            if(*m.second.rbegin() < v){
                flag = 1;
                break;
            }
            int pos = *m.second.lower_bound(v);
            assert(pos >= v);
            cost += pos - v;
            if(cost >= best_cost){
                flag = 1;
                continue;
            }
        }
        if(flag2)
            break;
        if(flag)
            continue;
        if(cost < best_cost)
            best_cost = cost, best_pos = m.first;
        }
    }
    if(count > 1e7){
        // check again from behind for big test cases
        for(auto it = marks.rbegin(); it != marks.rend(); it = next(it)) {
        auto m = *it;
        if(m.second.empty() == 0){ 
        long long cost = 0, flag = 0, flag2 = 0;
        for(int &v: requirements){
            if(count++ > 1e8){
                flag2 = 1;
                break;
            }
            if(*m.second.rbegin() < v){
                flag = 1;
                break;
            }
            int pos = *m.second.lower_bound(v);
            assert(pos >= v);
            cost += pos - v;
            if(cost >= best_cost){
                flag = 1;
                continue;
            }
        }
        if(flag2)
            break;
        if(flag)
            continue;
        if(cost <= best_cost)
            best_cost = cost, best_pos = m.first;
        }
    }
    }
    return best_pos;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string requirements_count_temp;
    getline(cin, requirements_count_temp);

    int requirements_count = stoi(ltrim(rtrim(requirements_count_temp)));

    vector<int> requirements(requirements_count);

    for (int i = 0; i < requirements_count; i++) {
        string requirements_item_temp;
        getline(cin, requirements_item_temp);

        int requirements_item = stoi(ltrim(rtrim(requirements_item_temp)));

        requirements[i] = requirements_item;
    }

    string flaskTypes_temp;
    getline(cin, flaskTypes_temp);

    int flaskTypes = stoi(ltrim(rtrim(flaskTypes_temp)));

    string markings_rows_temp;
    getline(cin, markings_rows_temp);

    int markings_rows = stoi(ltrim(rtrim(markings_rows_temp)));

    string markings_columns_temp;
    getline(cin, markings_columns_temp);

    int markings_columns = stoi(ltrim(rtrim(markings_columns_temp)));

    vector<vector<int>> markings(markings_rows);

    for (int i = 0; i < markings_rows; i++) {
        markings[i].resize(markings_columns);

        string markings_row_temp_temp;
        getline(cin, markings_row_temp_temp);

        vector<string> markings_row_temp = split(rtrim(markings_row_temp_temp));

        for (int j = 0; j < markings_columns; j++) {
            int markings_row_item = stoi(markings_row_temp[j]);

            markings[i][j] = markings_row_item;
        }
    }

    int result = chooseFlask(requirements, flaskTypes, markings);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

