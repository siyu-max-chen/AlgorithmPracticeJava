# traversal 树的遍历
--------------------------------------------------------
树的遍历需要了解代码的写法、根据已有的树木判断出经过不同顺序得到的次序。
preorder, inorder, postorder, level, vertical
假设树木如下：
这几种遍历的时间复杂度都是O(N)

--------------------------------------------------------
#### preorder traversal
``` java
得到的结果：[]
private List<Integer> res = new ArrayList<>();
private void preorder(TreeNode p){
    res.add(p.val);
    if(p.left != null)
        preorder(p.left);
    if(p.right != null)
        preorder(p.right);
}
public List<Integer> preorderTraversal(TreeNode root) {
    if(root == null)  return res;
    preorder(root);
    return res;
}
```
相关题目：
 [144 Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal/)

--------------------------------------------------------
#### inorder traversal
``` java
得到的结果：[]
private List<Integer> res = new ArrayList<>();
private void inorder(TreeNode p){
    if(p.left != null)
        inorder(p.left);
    res.add(p.val);
    if(p.right != null)
        inorder(p.right);
}
public List<Integer> inorderTraversal(TreeNode root) {
    if(root == null) return res;
    inorder(root);
    return res;
}
```
相关题目：
[94 Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

--------------------------------------------------------
#### postorder traversal
``` java
得到的结果：[]
private List<Integer> res = new ArrayList<>();
private void postorder(TreeNode p){
    if(p.left != null)
        postorder(p.left);
    if(p.right != null)
        postorder(p.right);
    res.add(p.val);
}
public List<Integer> postorderTraversal(TreeNode root) {
    if(root == null)  return res;
    postorder(root);
    return res;
}
```
相关题目：
[145 Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/)

--------------------------------------------------------
#### level order traversal
``` java
使用 Queue 可以轻松完成层级遍历。代码可以说是 BFS 的最经典的写法！
得到的结果：[]
class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> tempList;
    private List<TreeNode> tempNodeList;
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root == null)
            return res;
        tempNodeList = new ArrayList<>();
        tempNodeList.add(root);
        tempList = new ArrayList<>();
        while(!tempNodeList.isEmpty()){
            int len = tempNodeList.size();
            for(int i = 0; i < len; ++i){
                TreeNode p = tempNodeList.get(0);
                tempList.add(p.val);
                if(p.left != null)
                    tempNodeList.add(p.left);
                if(p.right != null)
                    tempNodeList.add(p.right);
                tempNodeList.remove(0);
            }
            res.add(new ArrayList<>(tempList));
            tempList.clear();
        }
        return res;
    }
}
```
相关题目：
[102 Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)

