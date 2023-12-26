#include <iostream>
#include <vector>
using namespace std;
struct binaryTreeNode // 二叉树节点的定义
{
    int element;
    binaryTreeNode *leftChild;
    binaryTreeNode *rightChild;

    binaryTreeNode(int x) : element(x), leftChild(nullptr), rightChild(nullptr) {}
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
    };
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
};

void insert(binaryTreeNode* &root, binaryTreeNode* node) {
    if (root == nullptr) {
        root = node;
    } else if (node->element < root->element) {
        insert(root->leftChild, node);
    } else if(node->element > root->element){
        insert(root->rightChild, node);
    }
}
//根据数组构建二叉搜索树,不用数组0号元素
binaryTreeNode* creatBST(vector<int> arr){
    binaryTreeNode* root=new binaryTreeNode(arr[1]);
    for (int i = 2; i < arr.size(); i++)
    {
        binaryTreeNode* node = new binaryTreeNode(arr[i]);
        insert(root,node);
    }
    return root;
}
void max_heapify(vector<int> &arr, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(vector<int> &arr, int len) {
    //初始化，i从最后一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

void initMaxHeap(vector<int> &heap){
    int p = heap.size()-1;
    for (int i = heap.size()-1; i >1; i--)
    {
        int temp=i;
        while (i!=1)
        {
            if (heap[i]>heap[i/2])
        {
            swap(heap[i],heap[i/2]);
        }
        i=i/2;
        }
        i=temp;
        
        
    }
    
}
int main(){
    cout << "Input" << endl;
    int count = 0;
    vector<int> arr;
    arr.push_back(0);
    vector<int> heap;
    heap.push_back(0);
    int temp;
    while (1)
    {
        cin >> temp;
        if (temp==0)
        {
            break;
        }
        arr.push_back(temp);
        heap.push_back(temp);
        count++;
    }
    vector<int> a = arr;
    // initMaxHeap(heap);
    if (count==2)
    {
        if (a[1]<a[2])
        {
            swap(a[1],a[2]);
        }
        
    }
    else{for (int i = count / 2; i > 0; i--)
    {
        int rootElement = a[i]; // 子树的根
        // 寻找放置rootElement的位置
        int child = 2 * i; // child的父节点是rootElement的位置
        while (child <= count)
        {
            // a[child]应该是子节点中较大的节点
            if (child <= count && a[child] < a[child + 1])
                child++;
            // 能把rootElement放入节点a[child]吗？
            if (rootElement >= a[child])
                break; // 能
            // 不能
            a[child / 2] = a[child]; // 将孩子上移
            child *= 2;              // 下移一层
        }
        a[child / 2] = rootElement;
    }}
    cout << "Output" << endl;
    for (int i = 1; i < count; i++)
    {
        cout << a[i] << ",";
    }
    cout << a[a.size()-1] << endl;

    //堆排序
    heap_sort(heap,heap.size());
    for (int i = 1; i < heap.size()-1; i++)
    {
        cout << heap[i] << ",";
    }
    cout << heap[heap.size()-1] << endl;
    binaryTreeNode* root = creatBST(arr);
    root->preOrder();
    cout << endl;
    root->inOrder();
    cout << endl;
    cout << "end";
}