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
    void create(Node *u, unordered_map<int, Node*> &graph){
        Node *newnode = graph.find(u -> val) == graph.end() ? new Node(u -> val):graph[u -> val];
        for(Node *v: u -> neighbors){
            if(graph.find(v -> val) == graph.end()){
                Node *temp = new Node(v -> val);
                graph[v -> val] = temp;   
            }
            (newnode -> neighbors).push_back(graph[v -> val]);
        }
        graph[u -> val] = newnode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        unordered_map<int, Node*> graph;
        unordered_set<int> visited;
        queue<Node*> q;
        q.push(node), visited.insert(node -> val);
        while(!q.empty()){
            Node *u = q.front();
            q.pop();
            create(u, graph);
            for(Node *v: u -> neighbors){
                if(visited.find(v -> val) != visited.end())
                    continue;
                q.push(v);
                visited.insert(v -> val);
            }
        }
        return graph[node ->val];
    }
};