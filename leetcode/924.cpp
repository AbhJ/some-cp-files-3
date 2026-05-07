class DSU {

public:
    std::vector<int> parent;
    std::vector<int> size;
    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0); // Each element is its own parent initially
        size.assign(n, 1);
    }

    // Find the representative (leader) of the set containing 'i'
    // Path compression makes future finds faster by flattening the structure
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    // Merge sets containing 'i' and 'j'
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            // Union by size: attach the smaller tree under the larger one
            if (size[root_i] < size[root_j])
                std::swap(root_i, root_j);
            
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
        }
    }

    // Check if 'i' and 'j' belong to the same set
    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};

class Solution {
public:
    void dfs (int u, DSU &dsu, vector<vector<int>>& graph, vector <bool> &vis) {
        int n = graph.size();
        vis[u] = true;
        for (int i = 0; i < n; i++)
            if (i != u and graph[i][u]) {
                if (dsu.find(i) == dsu.find(u))
                    continue;
                dsu.unite (i, u);
                dfs (i, dsu, graph, vis);
            }
    }
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size(), ans = - 1;
        set <int> uniques, bad;
        sort (initial.begin(), initial.end());
        DSU dsu (n);
        vector <bool> vis (n);
        for (auto i: initial) {
            if (!vis[i]) {
                set <int> tmp {i};
                dfs (i, dsu, graph, vis);
            }
            if (uniques.contains(dsu.find(i)))
                bad.emplace(dsu.find(i));
            else
                uniques.emplace(dsu.find(i));
        }
        for (auto i: initial) {
            if (uniques.contains(dsu.find(i)) and bad.contains(dsu.find(i)) == 0) {
                if (ans == - 1 or dsu.size[dsu.find(i)] > dsu.size[dsu.find(ans)])
                    ans = i;
            }
        }
        if (ans == - 1)
            return initial[0];
        return ans;
    }
};