#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'minimumDistance' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY area as parameter.
 */

vector<int> dx {-1, 0, 1, 0};
vector<int> dy {0, -1, 0, 1};

// this function returns if the position x is dimensionally siutated within the area matrix
bool ok(int x, int len){
    if(x < 0 or x >= len)
        return 0;
    return 1;
}

int minimumDistance(vector<vector<int>> area) {
    queue<pair<int, int>>q;
    q.emplace(0, 0);
    int n = area.size(), m = area[0].size(), count = 0;
    if(area[0][0] == 9)
        return 0;
    // This is a special corner case in which the starting and finishing nodes coincide
    while(q.empty() == 0){
        // We use the variable siz to keep track of the queue size.
        // In one interation of this while loop, we only look at
        // nodes which are at the same distance from the starting
        // point (0, 0). This helps in noting the distance of each
        // node without having another n * m size table / matrix to store the distances.
        int siz = q.size();
        count++;
        // Count is the variable that stores the distance of all the nodes (which are equidistant from (0, 0))
        // seen / popped in this particular iteration of the outer while loop.
        while(siz--){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for(int i = 0; i < 4; i++){
                int X = x + dx[i], Y = y + dy[i];
                // X and Y represent the indices to the new possible position
                if (ok(X, n) == 0 or ok(Y, m) == 0)
                // in case the indices are outside the box we skip
                    continue;
                if(area[X][Y] == 9)
                // here, we have reached the finishing point so we return count
                    return count;
                if(area[X][Y] == 1){
                    // the node X, Y has not been visited before, so it is indeed at a distance of 1 more than x, y
                    // here we label the node X, Y as visited by marking it 2 and then push it into the queue
                    area[X][Y] = 2;
                    q.emplace(X, Y);
                }
            }
        }
    }
    return -1;
    // The complexity of code is O(n * m) space and O(n * m) time where n is the number of rows
    // and m is the number of columns in the area matrix
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string area_rows_temp;
    getline(cin, area_rows_temp);

    int area_rows = stoi(ltrim(rtrim(area_rows_temp)));

    string area_columns_temp;
    getline(cin, area_columns_temp);

    int area_columns = stoi(ltrim(rtrim(area_columns_temp)));

    vector<vector<int>> area(area_rows);

    for (int i = 0; i < area_rows; i++) {
        area[i].resize(area_columns);

        string area_row_temp_temp;
        getline(cin, area_row_temp_temp);

        vector<string> area_row_temp = split(rtrim(area_row_temp_temp));

        for (int j = 0; j < area_columns; j++) {
            int area_row_item = stoi(area_row_temp[j]);

            area[i][j] = area_row_item;
        }
    }

    int result = minimumDistance(area);

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
