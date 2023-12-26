#include <iostream>
using namespace std;
struct listNode
{
    //节点包含元素和指向下一个节点的指针
    int element;
    listNode* next;
};


void out(listNode *firstNode){
    listNode* cur = firstNode;
    if (cur == nullptr)
    {
        cout << "<null>" << endl;
        return;
    }
    
    if (cur->next==nullptr)
    {
        cout << cur->element << endl;return;
    }
    
    while (true)
    {
        cout << cur->element << ",";
        cur = cur->next;
        if (cur->next==nullptr) break;
    }
    cout << cur->element << endl;
}

void bubbleSort(listNode *headNode, int n){
    for (int i = 0; i < n; i++)
    {
        listNode* pre = headNode;
        listNode* cur = headNode->next;
        for (int j = 0; j < n-1; j++)
        {
            if (pre->element>cur->element)
            {
                swap(pre->element,cur->element);
            }
            cur=cur->next;
            pre=pre->next;
        }
        
    }
    
}
void deleteNode(listNode* &head, int i) {
    listNode* temp = head, *prev;

    // 如果头节点本身就是要删除的节点
    if (temp != NULL && temp->element == i) {
        head = temp->next; // 改变头
        delete temp;       // 释放旧头
        return;
    }

    // 搜索要删除的节点，并且跟踪前一个节点，因为我们需要改变 'prev->next'
    while (temp != NULL && temp->element != i) {
        prev = temp;
        temp = temp->next;
    }

    // 如果链表中没有找到要删除的节点
    if (temp == NULL) return;

    // 从链表中解除节点
    prev->next = temp->next;

    delete temp;  // 释放内存
}

void insert(listNode* &head, int i) {
    listNode* newNode = new listNode;
    newNode->element = i;
    if (head == NULL || head->element >= newNode->element) {
        newNode->next = head;
        head = newNode;
    } else {
        listNode* current = head;
        while (current->next != NULL && current->next->element < newNode->element) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int find(listNode* head, int i) {
    listNode* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->element == i) {
            return position;
        }
        current = current->next;
        position++;
    }
    return 0; 
}

int main(){
    cout << "Input1" <<endl;
    int tem,n1=0;
    listNode* head1 = nullptr;
    while (true)
    {
        cin >> tem;
        if (tem==0) break;
        listNode* newNode = new listNode();
        newNode->element=tem;
        if (head1==nullptr) {head1=newNode;n1++;}
        else{
            listNode* temp = head1;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            n1++;
        }
    }
    bubbleSort(head1,n1);
    cout << "Output1" <<endl;
    out(head1);
    cout << "Input2" <<endl;
    listNode* head2 = nullptr;
    int n2=0;
    while (true)
    {
        cin >> tem;
        if (tem==0) break;
        listNode* newNode = new listNode();
        newNode->element=tem;
        if (head2==nullptr) {head2=newNode;n2++;}
        else{
            listNode* temp = head2;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            n2++;
        }
    }
    bubbleSort(head2,n2);
    cout << "Output2" <<endl;
    out(head2);

    cout << "Combine" <<endl;
    listNode* temp = head1;
    if (temp==nullptr)
    {
        head1 = head2;
    }else{
        while (temp->next!=nullptr)
    {
        temp = temp->next;
    }
    temp->next = head2;
    }
    int n = n1+n2;
    bubbleSort(head1,n);
    out(head1);
    cout << "Insert" << endl;
    cin >> tem;
    insert(head1,tem);
    cout << "Insertion" << endl;
    out(head1);
    cout << "Delete" << endl;
    cin >> tem;
    deleteNode(head1,tem);
    cout << "Deletion" << endl;
    out(head1);
    cout << "Find" << endl;
    cin >> tem;
    cout << "Position" <<endl;
    cout << find(head1,tem)<<endl;
    cout << "End" << endl;
}