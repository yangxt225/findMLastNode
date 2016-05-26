#include <iostream>
#include <assert.h>

struct Node
{
    int key;
    Node* nextNode;
};

// 创建单向链表, 尾插入
void createList(Node* &pHead, int n = 10)
{
    pHead = new Node;
    pHead->key= 0;
    pHead->nextNode = NULL;
    Node* p = pHead;
    for(int i=1; i<n; ++i)
    {
        Node* pNewNode = new Node;
        pNewNode->key = i;
        pNewNode->nextNode = NULL;
        p->nextNode = pNewNode;
        p = pNewNode;
    }
}

// 打印链表key
void printList(Node* pHead)
{
    Node* pNext = pHead;
    while(pNext)
    {
        std::cout << pNext->key << ", ";
        pNext = pNext->nextNode;
    }
    std::cout << std::endl;
}

// 查找倒数第M个节点, 返回给节点key值
int findMLastNode(Node* pHead, int last_m = 1)
{
    assert(pHead);
    assert(last_m > 0);
    int lastNodeKey  = -1;
    // 通过两个指针指示一个标尺,移动标尺进行倒数元素的定位
    Node* p1 = pHead;
    Node* p2 = pHead;
    int count = 1;
    while(count < last_m && p2->nextNode)
    {   
        p2 = p2->nextNode;
        ++count;
    }
    while(p2->nextNode)
    {
        p2 = p2->nextNode;
        p1 = p1->nextNode;
    }

    lastNodeKey = p1->key;
    return lastNodeKey;   
}

int main()
{
    Node* head = NULL;
    createList(head);
    printList(head);

    int last_m = 4;
    std::cout << "enter the last node number: ";
    std::cin >> last_m;
    std::cout << "output the m last node : ";
    std::cout << findMLastNode(head, last_m) << std::endl;
    
    return 0;
}

