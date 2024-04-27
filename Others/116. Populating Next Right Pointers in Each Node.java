/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public void getNodesByLevel(Node root, List<List<Node>> nodes, int i){
        if(root == null) return;
        if(i == nodes.size()){
            nodes.add(new ArrayList<>());
        }
        nodes.get(i).add(root);
        getNodesByLevel(root.left, nodes, i+1);
        getNodesByLevel(root.right, nodes, i+1);
    }
    public Node connect(Node root) {
        if(root == null) return null;
        List<List<Node>> nodes = new ArrayList<>();
        getNodesByLevel(root, nodes, 0);
        for(int i = 0; i < nodes.size(); i++){
            for(int j = 0; j < nodes.get(i).size()-1; j++){
                nodes.get(i).get(j).next = nodes.get(i).get(j+1);
            }
        }
        return root;
    }
}