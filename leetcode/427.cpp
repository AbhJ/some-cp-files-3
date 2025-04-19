/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
	Node * solve (int il, int ir, int jl, int jr, vector<vector<int>>& grid) {
		bool isLeaf = true;
		for (int i = il; i < ir; i++) {
			for (int j = jl; j < jr; j++) {
				if (grid[i][j] != grid[il][jl])
					isLeaf = false;
			}
		}
		if (isLeaf == true)
			return new Node (grid[il][jl], true, NULL, NULL, NULL, NULL);
		return new Node (grid[il][jl], false,
		                 solve (il, (il + ir) / 2, jl, (jl + jr) / 2, grid),
		                 solve (il, (il + ir) / 2, (jl + jr) / 2, jr, grid),
		                 solve ((il + ir) / 2, ir, jl, (jl + jr) / 2, grid),
		                 solve ((il + ir) / 2, ir, (jl + jr) / 2, jr, grid)
		                );
	}
	Node* construct (vector<vector<int>>& grid) {
		int n = grid.size();
		return solve (0, n, 0, n, grid);
	}
};