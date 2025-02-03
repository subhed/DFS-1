// Author: Subhed Chavan
// Batch: December 24
// Problem Statement: 542: 01 Matrix
// Approach: BFS
// TC: O(m * n)
// SC: O(m * n)

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // Base Case
        if (mat.empty())
        {
            return mat;
        }

        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // U, D, L, R

        // Initialize the queue with all 0 and mark 1 cells as -1
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    // Push 0 cells to the queue
                    q.push({i, j});
                }
                else
                {
                    // Mark 1 cells as unprocessed
                    mat[i][j] = -1;
                }
            }
        }

        // BFS
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();

            // Explore all directions
            for (auto dir : dirs)
            {
                int nr = curr.first + dir[0];
                int nc = curr.second + dir[1];

                // Check if the new position is within bounds and unprocessed and update distance
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1)
                {
                    q.push({nr, nc});
                    mat[nr][nc] = mat[curr.first][curr.second] + 1;
                }
            }
        }

        return mat;
    }
};
