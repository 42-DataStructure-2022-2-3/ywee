#include "../includes/binSearchTree.h"

// 이진탐색트리 생성시 루트노드가 있는 것을 전제함
BinSearchTree* makeBinSearchTree(BSTNode rootNode) {
    BinSearchTree* ret = (BinSearchTree *)calloc(sizeof(BinSearchTree), 1);
    if (!ret) return NULL;
    ret->pRootNode = copyBSTNode(rootNode);
    if (!ret->pRootNode) {
        free(ret);
        return NULL;
    }
    return ret;
};

BSTNode* copyBSTNode(BSTNode element) {
    BSTNode *ret = (BSTNode *)calloc(sizeof(BSTNode), 1);
    if (!ret) return NULL;
    ret->data = element.data;
    return ret;
};

BSTNode* makeBSTNode(int inputData) {
    BSTNode *ret = (BSTNode *)calloc(sizeof(BSTNode), 1);
    if (!ret) return NULL;
    ret->data = inputData;
    return ret;
};

BSTNode* getRootNodeBST(BinSearchTree* pBSTree) {
    return pBSTree->pRootNode;
};

// 이진탐색이란 ?
// 데이터의 정 중앙에서 탐색을 시작해서
// 탐색 대상을 반으로 줄여나가는


BSTNode* search_recursive(BSTNode* pParentNode, int data) {
    if (!pParentNode || pParentNode->data == data) {
        return pParentNode;
    } else if (pParentNode->data < data) {
        return (search_recursive(pParentNode->pRightChild, data));
    } else {
        return (search_recursive(pParentNode->pLeftChild, data));
    }
};

BSTNode* search_loop(BinSearchTree* pBinSearchTree, int data) {
    BSTNode *ret = pBinSearchTree->pRootNode;
    while (ret != NULL) {
        if (ret->data == data) {
            break ;
        } else if (ret->data < data) {
            ret = ret->pRightChild;
        } else {
            ret = ret->pLeftChild;
        }
    }
    return ret;
};

void printTreeData_InOrder(BSTNode* rootNode)
{
    if (rootNode->pLeftChild)
        printTreeData_InOrder(rootNode->pLeftChild);
    printf("%d ",rootNode->data);
    if (rootNode->pRightChild)
        printTreeData_InOrder(rootNode->pRightChild);
}

bool    insert_loop(BinSearchTree* pBinSearchTree, BSTNode element) {
   BSTNode  *parent;
   BSTNode *node = pBinSearchTree->pRootNode;
   while (node)
   {
        if (node->data == element.data) {
            printf("already exist!");
            return false;
        }
        else if (node->data > element.data)
        {
            parent = node;
            node = node->pLeftChild;
        }
        else if (node->data < element.data)
        {
            parent = node;
            node = node->pRightChild;
        }
   }
    if (parent->data > element.data)
        parent->pLeftChild = copyBSTNode(element);
    if (parent->data < element.data)
        parent->pRightChild = copyBSTNode(element);
    return true;
};

// insert_rec(pBinSearchTree->pRootNode, element, 0);
bool    insert_recursive(BSTNode* targetNode, BSTNode element, BSTNode *target_parent) {
    if (!targetNode) {
        if (target_parent->data > element.data) target_parent->pLeftChild = copyBSTNode(element);
        else target_parent->pRightChild = copyBSTNode(element);
        return true;
    }
    if (targetNode->data == element.data) return false;
    if (targetNode->data > element.data) return insert_recursive(targetNode->pLeftChild, element ,targetNode);
    if (targetNode->data < element.data) return insert_recursive(targetNode->pRightChild, element, targetNode);
    return true;
}

bool deleteBSTNode(BinSearchTree* pBinSearchTree, int data) {
    BSTNode *del_Node = search_loop(pBinSearchTree, data);
    if (!del_Node) return false; // 이진탐색트리에 지우고자 하는 값이 없음
    BSTNode *parentNode = search_parentNode(pBinSearchTree, data); // 지우고자 하는 부모노드를 탐색
    // 지우고자 하는 노드가 리프인 경우
    if (!del_Node->pLeftChild && !del_Node->pRightChild)
    {
        if (parentNode->pLeftChild == del_Node) parentNode->pLeftChild = NULL;
        if (parentNode->pRightChild == del_Node) parentNode->pRightChild = NULL;
        free(del_Node);
        del_Node = NULL;
    }
    // 지우고자 하는 노드의 자식이 1개인 경우
    else if (!del_Node->pLeftChild || !del_Node->pRightChild)
    {
        BSTNode *delchild = del_Node->pLeftChild ? del_Node->pLeftChild : del_Node->pRightChild;
        if (parentNode->pLeftChild == del_Node) parentNode->pLeftChild = delchild;
        if (parentNode->pRightChild == del_Node) parentNode->pRightChild = delchild;
        free(del_Node);
        del_Node = NULL;
    }
    // 지우고자 하는 노드의 자식이 두 개 모두 있는 경우
    else if (del_Node->pLeftChild && del_Node->pRightChild)
    {
        BSTNode *del = del_Node;
        BSTNode *successor = del_Node->pLeftChild;
        while (true)
        {
            if (!successor->pRightChild)
                break ;
            successor = successor->pRightChild;
        }
        BSTNode *successor_parrent = search_parentNode(pBinSearchTree, successor->data);
        if (successor->pLeftChild)
            successor_parrent->pLeftChild = successor->pLeftChild;
        else
            successor_parrent->pLeftChild = NULL;
        successor->pLeftChild = del->pLeftChild;
        successor->pRightChild = del->pRightChild;
        if (parentNode != NULL)
        {
        if (parentNode->pLeftChild == del)
            parentNode->pLeftChild = successor;
        else
            parentNode->pRightChild = successor;
        }
        else
            pBinSearchTree->pRootNode = successor;
        free(del);
    }
    return true;
};

BSTNode* search_parentNode(BinSearchTree* pBinSearchTree, int data) {
    BSTNode *parentNode = NULL;
    BSTNode *ret = pBinSearchTree->pRootNode;
    while (ret != NULL) {
        if (ret->data == data) {
            break ;
        } else if (ret->data < data) {
            parentNode = ret;
            ret = ret->pRightChild;
        } else {
            parentNode = ret;
            ret = ret->pLeftChild;
        }
    }
    return parentNode;
};
