class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0, k});

        set<int> visited;
        int cost{0};

        for (auto time : times) {
            int u{time[0]}, v{time[1]}, w{time[2]};
            edges[u].push_back(pair<int,int>(v,w));
        }

        while (!minHeap.empty()) {
            auto [weight, node] = minHeap.top();
            minHeap.pop();

            if (visited.contains(node)) {
                continue;
            }
            visited.insert(node);
            cost = max(cost, weight);

            for (auto edge : edges[node]) {
                int nNode = edge.first;
                int nWeight = edge.second;

                if (!visited.contains(nNode)) {
                    minHeap.push({weight + nWeight, nNode});
                }
            }

        }

        return visited.size() == n ? cost : -1;
    }
};