// https://leetcode.com/problems/clone-graph/

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
    unordered_map<Node*,Node*>vis;
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        Node* copyNode = new Node(node->val);
        vis[node] = copyNode;
        for(auto x:node->neighbors){
            if(vis.find(x)==vis.end()){
                Node* tmp = cloneGraph(x);
                copyNode->neighbors.push_back(tmp);
            }
            else{
                copyNode->neighbors.push_back(vis[x]);
            }
        }
        return copyNode;
    }
};
