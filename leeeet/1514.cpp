class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> best(n,0.0);
        best[start_node] = 1.0;
        pq.push({1.0, start_node});
        while (!pq.empty()){
            auto [prob, node] = pq.top();
            pq.pop();
            if(node == end_node) return prob;
            if(prob < best[node]) continue;
            for (auto &next : graph[node]){
                int nxt = next.first;
                double p = next.second;
                double newprob = prob * p;
                if (newprob > best[nxt]){
                    best[nxt] = newprob;
                    pq.push({newprob, nxt});
                }
            }
        }
        return 0.0;
    }
};