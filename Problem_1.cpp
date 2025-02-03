// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: 733: Flood Fill
// Approach: DFS
// TC: O(m * n)
// SC: O(m * n)

class Solution
{
public:
    int m, n;
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // U D L R

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        // Base Case
        if (image.empty() || image[sr][sc] == color)
        {
            return image;
        }

        m = image.size();
        n = image[0].size();
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int oldColor)
    {
        // Base case
        if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != oldColor)
        {
            return;
        }

        // Change color
        image[sr][sc] = color;

        // Recursive calls for all four directions
        for (auto &dir : dirs)
        {
            int nr = sr + dir[0];
            int nc = sc + dir[1];
            dfs(image, nr, nc, color, oldColor);
        }
    }
};
