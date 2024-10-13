//https://leetcode.com/problems/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Define a very large value to represent infinity (used for unreachable nodes)
        int INF = 1e9 + 9;
        
        // Create an adjacency list where each node points to a vector of pairs
        // (travel time, neighboring node). The graph has n nodes (1-indexed).
        vector<pair<int, int>> nodes[n + 1];
        
        // Distance array to store the shortest distance to each node, initialized later
        int dis[n + 1];

        // Build the adjacency list from the given times input
        for (auto it : times) {
            // it[0] is the source node, it[1] is the travel time, and it[2] is the target node
            nodes[it[0]].push_back({it[2], it[1]});
        }

        // Initialize all distances to infinity, since at the start we assume all nodes are unreachable
        for (int i = 1; i <= n; i++) {
            dis[i] = INF;
        }

        // Priority queue to select the next node with the smallest distance (min-heap)
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;

        // Start by pushing the source node k with distance 0
        pq.push({0, k});
        dis[k] = 0;  // Distance to the source node is 0

        // Dijkstra's algorithm to find the shortest path from k to all other nodes
        while (!pq.empty()) {
            // Get the node with the smallest distance (current node and distance)
            auto crnt = pq.top();
            pq.pop();
            int par_weight = crnt.first;  // Current distance
            int par_vrtx = crnt.second;   // Current node
            
            // If the stored distance is already smaller, skip this node
            if (dis[par_vrtx] < par_weight) continue;

            // Explore all neighboring nodes of the current node
            for (auto it : nodes[par_vrtx]) {
                int child_weight = it.first;  // Weight to the neighboring node
                int child_vrtx = it.second;   // Neighboring node
                
                // If a shorter path to the neighboring node is found, update the distance
                if (dis[child_vrtx] > dis[par_vrtx] + child_weight) {
                    dis[child_vrtx] = dis[par_vrtx] + child_weight;
                    pq.push({dis[child_vrtx], child_vrtx});  // Push the updated node into the queue
                }
            }
        }

        // Find the maximum time required to reach any node
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dis[i]);  // Maximum of all the shortest distances
        }

        // If any node is unreachable, return -1 (indicated by INF), otherwise return the max time
        return ans == INF ? -1 : ans;
    }
};
