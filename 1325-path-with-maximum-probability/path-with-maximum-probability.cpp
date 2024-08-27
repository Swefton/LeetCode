class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, vector<pair<int, double>>> edge_list;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            edge_list[u].emplace_back(v, prob);
            edge_list[v].emplace_back(u, prob);
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        
        vector<double> max_prob(n, 0.0);
        max_prob[start_node] = 1.0;

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if (node == end_node) {
                return prob;
            }

            for (auto& [neighbor, edge_prob] : edge_list[node]) {
                double new_prob = prob * edge_prob;
                if (new_prob > max_prob[neighbor]) {
                    max_prob[neighbor] = new_prob;
                    pq.push({new_prob, neighbor});
                }
            }
        }

        return 0.0;
    }
};
