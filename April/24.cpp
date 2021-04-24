class Solution {
  public:
    void dfs(int curr, vector < vector < int >> & g, vector < int > & disc, vector < int > & low, vector < int > & parent, vector < vector < int >> & ans) {
      static int time = 0;
      disc[curr] = time;
      low[curr] = time;
      time += 1;
      for (auto neigh: g[curr]) {
        if (disc[neigh] == -1) // if not visited
        {
          parent[neigh] = curr;
          dfs(neigh, g, disc, low, parent, ans);
          low[curr] = min(low[curr], low[neigh]);
          if (low[neigh] > disc[curr]) {
            ans.push_back({
              neigh,
              curr
            });
          }
        } else if (neigh != parent[curr])
          low[curr] = min(low[curr], disc[neigh]); // if its a backedge

      }

    }
  vector < vector < int >> criticalConnections(int n, vector < vector < int >> & connections) {
    vector < int > disc(n, -1);
    vector < int > low(n, -1);
    vector < int > parent(n, -1);

    vector < vector < int >> g(n, vector < int > ());
    for (auto it: connections) {
      g[it[0]].push_back(it[1]);
      g[it[1]].push_back(it[0]);
    }

    vector < vector < int >> ans;
    for (int i = 0; i < n; i++) {
      if (disc[i] == -1)
        dfs(i, g, disc, low, parent, ans);
    }
    return ans;
  }
};
