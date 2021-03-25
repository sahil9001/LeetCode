class Solution
{
private:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> result;
        // set<vector<int>> reachableFromPacific, notAdded;
        int M = matrix.size();
        if (M == 0)
        {
            return result;
        }
        int N = matrix[0].size();
        vector<vector<bool>> reachableFromPacific(M, vector<bool>(N, false));
        vector<vector<bool>> notAdded(M, vector<bool>(N, false));
        // Top
        for (int j = 0; j < N; j++)
        {
            reachContinents(0, j, M, N, matrix, reachableFromPacific, result, false, notAdded);
        }
        // Left
        for (int i = 0; i < M; i++)
        {
            reachContinents(i, 0, M, N, matrix, reachableFromPacific, result, false, notAdded);
        }
        // Right
        for (int i = 0; i < M; i++)
        {
            reachContinents(i, N - 1, M, N, matrix, reachableFromPacific, result, true, notAdded);
        }
        // Bottom
        for (int j = 0; j < N; j++)
        {
            reachContinents(M - 1, j, M, N, matrix, reachableFromPacific, result, true, notAdded);
        }
        return result;
    }

    bool reachContinents(int i, int j, int &M, int &N, vector<vector<int>> &matrix, vector<vector<bool>> &reachableFromPacific, vector<vector<int>> &result, bool atlantic, vector<vector<bool>> &notAdded)
    {
        queue<vector<int>> cellQueue;
        vector<vector<bool>> isVisited(M, vector<bool>(N, false));
        cellQueue.push({i, j});
        isVisited[i][j] = true;
        while (!cellQueue.empty())
        {
            vector<int> cur = cellQueue.front();
            cellQueue.pop();
            if (atlantic)
            {
                if (reachableFromPacific[cur[0]][cur[1]] == true && notAdded[cur[0]][cur[1]] == false)
                {
                    result.push_back({cur[0], cur[1]});
                    notAdded[cur[0]][cur[1]] = true;
                }
            }
            else
            {
                reachableFromPacific[cur[0]][cur[1]] = true;
            }
            for (vector<int> &direction : directions)
            {
                int nx = direction[0] + cur[0];
                int ny = direction[1] + cur[1];
                if ((nx >= 0 && nx < M && ny >= 0 && ny < N) && (matrix[nx][ny] >= matrix[cur[0]][cur[1]]) && !isVisited[nx][ny])
                {
                    cellQueue.push({nx, ny});
                    isVisited[nx][ny] = true;
                }
            }
        }
        return false;
    }
};