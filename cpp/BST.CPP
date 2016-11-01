#include <iostream>
using namespace std;
class BST
{
public:
    class node
    {
    public:
        node(){ left = right = NULL; }
    public:
        int data;
        node* left;
        node* right;
    };
public:
    BST(){ root = NULL; };
    BST(int item){ root->data = item; root = NULL; }
    bool empty()const;
    void Search(int item, bool &found, node* &pre, node* &p);
    void Insert(int value);
    void Delete(int item);
private:
    node* root;
};
bool BST::empty()const
{
    return (root == NULL);
}
void BST::Search(int item, bool &found, node* &pre, node* &p)
{
    for (;;)
    {
        if (found||p==NULL)
            break;
        else
        {
            if (item<p->data)
            {
                pre = p;
                p = p->left;
            }
            else if (item > p->data)
            {
                pre = p;
                p = p->right;
            }
            else
                found = true;
        }
    }
}
void BST::Insert(int value)
{
    bool found = false;
    node* p = root;
    node* pre = p;
    Search(value, found, pre, p);
    if (found)
        cout << "The value has been in the BST" << endl;
    else
    {
        node* n = new node;
        n->data = value;
        if (empty())
            root = n;
        else
        {
            if (value < pre->data)
                pre->left = n;
            if (value>pre->data)
                pre->right = n;
        }
    }
}
void BST::Delete(int item)
{
    bool found = false;
    node* p = root;
    node* pre = p;
    Search(item, found, pre, p);
    if (!found)
        cout << "The value is not in the BST" << endl;
    else
    {
        if (p->left!=NULL&&p->right!=NULL)
        {
            node* p2 = p->right;//找到右子树最小点
            node* pre2 = p;//找到右子树最小点的父节点
            while (p2->left!=NULL)
            {
                pre2 = p2;
                p2 = p2->left;
            }
            p->data = p2->data;
            pre = pre2;//与情况1和2合并
            p = p2;//与情况1和2合并
        }
        node* subtree = NULL;
        if (p->left == NULL)
            subtree = p->right;
        if (p->right == NULL)
            subtree = p->left;
        if (pre == NULL)
            root = subtree;
        else
            if (pre->right==p)
                pre->right = subtree;
            else
                pre->left = subtree;
        delete p;
    }
}


public class Node{
    public int score;
    public HashSet<String> IDSet;
    public int size;
    public Node left;
    public Node right;
    Node(String ID, int score){
        IDSet = new HashSet<String>();
        IDSet.add(ID);
        this.score = score;
    }
}

public class BinarySearchTree{
public HashMap<String,Node> scoreIDMap;
Node root;
    BinarySearchTree(){
           scoreIDMap = new HashMap<String,Node>();
   }
public void update(String ID, int score){
        if(scoreIDMap.containsKey(ID)){
                Node  node = scoreIDMap.get(ID);
                if(node.IDSet.size()>1){
IDSet.remove(ID);
}
else{
        delete(node);
}
        Node newNode =insert(ID, score);
        scoreIDMap.put(ID,newNode);
}. from: 1point3acres.com/bbs 
public void insert(String ID, int score){
}
public void insert(Node n, String ID, int score){
        if(n==null){ 
                n =new Node(ID,score);
}else{
        if(n.score==score){
                n.IDSet.add(ID);
}
else if(n.score>score){
        n.size++;
        insert(n.left,ID,score);
}
else{
        insert(n.right,ID,score);
}
}
}
public void delete(Node node){
//find parent of node
//check three case: leaf, one child, two children-google 1point3acres
Node parent = findParent(node);
if(parent==null){
        if( node.left==null&& node.right==null) root=null; 
        else if(node.left ==null){-google 1point3acres
                root= node.right;
}
else if(node.right == null){
root = node.left;

}
else{
        //find leftmost node of right subtree. From 1point 3acres bbs
Node rootCand = findLeftmost(root.right);
rootCand.left = root.left;
rootCand.size = root.size;
rootCand.right = root.right;
}
}
else{
        if(node.left == null && node.right == null){
                if(parent.left == node) parent.left =null;
                        else parent.right = null;
}
else if(node.left == null){
        if(parent.left == node)parent.left = node.right;. from: 1point3acres.com/bbs 
        else parent.right = node.right;
}
else if(node.right == null){
        if(parent.right == node) parent.right = node.left;
        else parent.left = nodel.left;
}. more info on 1point3acres.com
else{
        Node candidate = findLefmMost(node.right);. visit 1point3acres.com for more.
        candidate.left = node.left;
        candidate.size = node.size;. from: 1point3acres.com/bbs 
        candidate.right = node.right;
        if(parent.right = node) parent.right = candidate; 
        Else parent.left = candidate;
}

}
}
public Node findLeftmost(Node node){
        if(node.left==null) return node;
        Node.size--;
        return findLeftmose(node.left);
}

public Node findParent(Node node){
        if(root==node) return null;
        Node prev = root;
        Node cur = root;
        while(cur!=node){       
if(cur.score>node.score){
cur =cur.right;

}
else{
        Cur.size--;
        Cur = cur.left;
}
}
}


public List<String> findByRank(int k){
        if(k<0) return new ArrayList<String>();
        Return findByRank(root,k);
}
public List<String> findByRank(Node node,int k){
        if(node ==null) return new ArrayList<String>();
if(node.size>k) return findByRank(node.left,k);
else if(node.size<k && node.size+IDSet.size()>k){
        ArrayList<String> ans = new ArrayList<>();
        ans.addAll(IDSet);
        return ans;
}
else return findByRank(node.right,k-node.size-IDSet.size());


}

}
