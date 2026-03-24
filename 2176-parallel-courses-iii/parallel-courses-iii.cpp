class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        
        // Build adjacency list (converting to 0-indexed)
        for (const auto& rel : relations) {
            adj[rel[0] - 1].push_back(rel[1] - 1);
            inDegree[rel[1] - 1]++;
        }

        // completionTime[i] stores the earliest time course i can be finished
        vector<int> completionTime(n, 0);
        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
                completionTime[i] = time[i];
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                // Course v can only finish after its latest prerequisite u finishes
                completionTime[v] = max(completionTime[v], completionTime[u] + time[v]);
                
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return *max_element(completionTime.begin(), completionTime.end());
    }
};