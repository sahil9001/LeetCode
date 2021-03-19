class Solution
{
public:
    vector<bool> visited;
    void DFS(int i, vector<vector<int>> &rooms)
    {
        visited[i] = true;

        for (auto room : rooms[i])
            if (!visited[room])
                DFS(room, rooms);
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        visited = vector<bool>(rooms.size(), false);
        DFS(0, rooms);
        for (auto r : visited)
            if (r == false)
                return false;
        return true;
    }
};