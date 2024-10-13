//https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        // Adjacency list to store the graph with probabilities as edge weights
        vector<pair<double,int>> nodes[n]; // 'nodes[i]' contains pairs (probability, neighbor node)
        
        // Distance (or probability) array initialized to 0 for all nodes
        vector<double> dis(n, 0);
        
        // Constructing the graph: For each edge, add both directions with the corresponding success probability
        for(int i = 0; i < edges.size(); i++) {
            nodes[edges[i][0]].push_back({succProb[i], edges[i][1]});
            nodes[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }
        
        // Max-heap (priority_queue) to explore the nodes with the highest current probability first
        priority_queue<pair<double, int>> pq;
        
        // Start by pushing the start node with probability 1 (100%)
        pq.push({1, start_node});
        
        // Set the distance to the start node as 1 (100% probability)
        dis[start_node] = 1;
        
        // Process the nodes in the priority queue
        while(!pq.empty()) {
            auto crnt = pq.top();  // Get the node with the highest probability
            pq.pop();
            
            double crnt_weight = crnt.first;  // The current probability
            int crnt_vrtx = crnt.second;      // The current node (vertex)
            
            // If we've already found a higher probability for this node, skip it
            if(dis[crnt_vrtx] > crnt_weight) continue;
            
            // Explore the neighbors of the current node
            for(auto it : nodes[crnt_vrtx]) {
                double ch_weight = it.first;  // Probability of edge to the neighbor
                int ch_vrtx = it.second;      // Neighbor node
                
                // If passing through the current node results in a higher probability to reach the neighbor
                if(dis[ch_vrtx] < dis[crnt_vrtx] * ch_weight) {
                    dis[ch_vrtx] = dis[crnt_vrtx] * ch_weight;  // Update the probability
                    pq.push({dis[ch_vrtx], ch_vrtx});  // Push the neighbor into the priority queue
                }
            }
        }
        
        // Return the maximum probability to reach the end_node
        return dis[end_node];
    }
};
