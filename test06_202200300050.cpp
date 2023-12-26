#include <iostream>
#include <vector>
using namespace std;

//队列(队首元素位置为0号)
template<class T>
class queue
{
private:
    vector<T> myQueue;
public:
    bool empty(){
        return myQueue.size()==0;
    }
    int size(){
        return myQueue.size();
    }
    T front(){
        return myQueue[0];
    }
    T back(){
        return myQueue[myQueue.size()-1];
    }
    void pop(){
        myQueue.erase(myQueue.begin());
    }
    void push(T ele){
        myQueue.push_back(ele);
    }
};

//二叉树节点结构
template<class T>
struct binaryTreeNode
{
    binaryTreeNode* leftChild;
    binaryTreeNode* rightChild;
    T element;
    binaryTreeNode(){
        leftChild=rightChild=nullptr;
        element=0;
    }
    binaryTreeNode(T ele){
        element=ele;
        leftChild=rightChild=nullptr;
    }
    //前序遍历
    void preOrder(){
        cout << element;
        if(leftChild != nullptr){
            cout << ",";
            leftChild->preOrder();
        }
        if(rightChild != nullptr){
            cout << ",";
            rightChild->preOrder();
        }
    }

    //中序遍历
    void inOrder(){
        if(leftChild != nullptr){
            leftChild->inOrder();
            cout << ",";
        }
        cout << element;
        if(rightChild != nullptr){
            cout << ",";
            rightChild->inOrder();
        }
    }

    //后序遍历
    void postOrder(){
        
        if(leftChild != nullptr){
            leftChild->postOrder();
            cout << ",";
        }
        if(rightChild != nullptr){
            rightChild->postOrder();
            cout << ",";
        }
        cout << element;
    }
    //层次遍历
    void levelOrder(){
        queue<binaryTreeNode*> q;
        q.push(this);

        while (!q.empty()) {
            binaryTreeNode* node = q.front();
            q.pop();

            if (node != this) cout << ",";
            cout << node->element;

            if (node->leftChild != nullptr) q.push(node->leftChild);
            if (node->rightChild != nullptr) q.push(node->rightChild);
        }
    }

};

    // 计算二叉树的节点数
    template<class T>
    int countNodes(binaryTreeNode<T>* node) {
        if (node == nullptr) {
           return 0;
        } else {
            return 1 + countNodes(node->leftChild) + countNodes(node->rightChild);
        }
    }

    // 计算二叉树的高度
    template<class T>
    int height(binaryTreeNode<T>* node) {
        if (node == nullptr) {
            return 0;
        } else {
            int leftHeight = height(node->leftChild);
            int rightHeight = height(node->rightChild);
            return 1 + max(leftHeight, rightHeight);
        }
    }

// binaryTreeNode<char>* build(string preorder, int preStart, int preEnd, string inorder, int inStart, int inEnd);
// 根据前序和中序遍历序列构建二叉树
// binaryTreeNode<char>* buildTree(string preorder, string inorder) {
    
//     return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
// }

// binaryTreeNode<char>* build(string preorder, int preStart, int preEnd, string inorder, int inStart, int inEnd) {
//     if (preStart > preEnd) {
//         return nullptr;
//     }

//     // 前序遍历中的第一个节点就是根节点
//     char rootVal = preorder[preStart];
    
//     // 在中序遍历中定位根节点
//     int index = 0;
//     for (int i = inStart; i <= inEnd; i++) {
//         if (inorder[i] == rootVal) {
//             index = i;
//             break;
//         }
//     }
//     // 先把根节点建立出来
//     binaryTreeNode<char>* root = new binaryTreeNode<char>(rootVal);
//     // 得到左子树中的节点数目
//     int leftSize = index - inStart;
//     // 递归地构造左右子树，并连接到根节点
//     root->leftChild = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
//     root->rightChild = build(preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);
//     return root;
// }

binaryTreeNode<char>* buildTree(string preorder, string inorder) {
    if(preorder.empty()) return NULL;
    binaryTreeNode<char>* root = new binaryTreeNode(preorder[0]);
    int pos = inorder.find(preorder[0]);
    root->leftChild = buildTree(preorder.substr(1, pos), inorder.substr(0, pos));
    root->rightChild = buildTree(preorder.substr(pos+1), inorder.substr(pos+1));
    return root;
}
int main(){
    cout << "Input1" << endl;
    string str;
    cin >> str;
    binaryTreeNode<char>* head1 = new binaryTreeNode<char>(str[0]);
    queue<binaryTreeNode<char>*> q1;
    q1.push(head1);
    for (int i = 1; i < str.length(); i++)
    {
        binaryTreeNode<char>* p=q1.front();
        if (p->leftChild==nullptr)
        {
            p->leftChild=new binaryTreeNode<char>(str[i]);
            q1.push(p->leftChild);
        }else if (p->rightChild==nullptr)
        {
            p->rightChild=new binaryTreeNode<char>(str[i]);
            q1.push(p->rightChild);
            q1.pop();
        }
    }
    cout << "Output1" << endl;
    head1->preOrder();
    cout << endl;
    head1->inOrder();
    cout << endl;
    head1->postOrder();
    cout << endl;
    cout << countNodes(head1)<<endl;
    cout << height(head1) << endl;
    cout << "Input2" << endl;
    string preoder;
    string inorder;
    cin >> preoder;
    cin >> inorder;
    binaryTreeNode<char>* head2 = buildTree(preoder,inorder);
    cout << "Output2"<<endl;
    head2->postOrder();
    cout << endl;
    head2->levelOrder();
    cout << endl;
    cout << "End"<<endl;
}