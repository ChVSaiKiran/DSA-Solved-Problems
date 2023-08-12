/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        if((node -> neighbors).size() == 0)
            return new Node(node -> val);
        unordered_map<int, Node*> graph;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node *src = q.front();
            Node *u = graph.count(src -> val) == 0 ? new Node(src -> val) : graph[src ->val];
            q.pop();
            for(Node *v: src -> neighbors){
                if(graph.count(v -> val) == 0){
                    graph[v -> val] = new Node(v -> val);
                    q.push(v);
                }
                (u -> neighbors).push_back(graph[v -> val]);
            }
        }
        return graph[node ->val];
    }
};