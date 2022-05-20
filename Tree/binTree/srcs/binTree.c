#include "../includes/binTree.h"

BinTree* makeBinTree(BinTreeNode rootNode) {
    BinTree* ret = (BinTree *)calloc(sizeof(BinTree), 1);
    if (!ret) return NULL;
    ret->pRootNode = copyBTNode(rootNode);
    if (!ret->pRootNode) {
        free(ret);
        return NULL;
    }
    return ret;
};

BinTreeNode* makeBTNode(char inputData) {
    BinTreeNode* ret = (BinTreeNode *)calloc(sizeof(BinTreeNode), 1);
    if (!ret) return NULL;
    ret->data = inputData;
    return ret;
};

BinTreeNode* getRootNodeBT(BinTree* pBinTree) {
    return pBinTree->pRootNode;
};

BinTreeNode* copyBTNode(BinTreeNode element) {
    BinTreeNode* nptr = (BinTreeNode *)calloc(sizeof(BinTreeNode), 1);
    if (!nptr) return NULL;
    nptr->data = element.data;
    nptr->visited = element.visited;
    nptr->pLeftChild = element.pLeftChild;
    nptr->pRightChild = element.pRightChild;
    return nptr;
};

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
    BinTreeNode* nptr = copyBTNode(element);
    if (pParentNode->pLeftChild) free(pParentNode->pLeftChild);
    pParentNode->pLeftChild = nptr;
    return nptr;
};

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
    BinTreeNode* nptr = copyBTNode(element);
    if (pParentNode->pRightChild) free(pParentNode->pRightChild);
    pParentNode->pRightChild = nptr;
    return nptr;
};

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode) {
    return pNode->pLeftChild;
};

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode) {
    return pNode->pRightChild;
};

void deleteAllBTNode(BinTreeNode* rootNode) {
    // L -> R -> M
    if (rootNode->pLeftChild) {
        deleteAllBTNode(rootNode->pLeftChild);
        rootNode->pLeftChild = NULL;
    }
    if (rootNode->pRightChild) {
        deleteAllBTNode(rootNode->pRightChild);
        rootNode->pRightChild = NULL;
    }
    deleteBinTreeNode(rootNode);
}

void deleteBinTree(BinTree* pBinTree) {
    deleteAllBTNode(pBinTree->pRootNode);
    free(pBinTree);
};

void deleteBinTreeNode(BinTreeNode* pNode) {
    free(pNode);
};

void printTreeData_PreOrder(BinTreeNode* rootNode) {

    printf("%c ", rootNode->data);
    if (rootNode->pLeftChild)
        printTreeData_PreOrder(rootNode->pLeftChild);
    if (rootNode->pRightChild)
        printTreeData_PreOrder(rootNode->pRightChild);
}

void printTreeData_InOrder(BinTreeNode* rootNode) {
    if (rootNode->pLeftChild)
        printTreeData_InOrder(rootNode->pLeftChild);
    printf("%c ",rootNode->data);
    if (rootNode->pRightChild)
        printTreeData_InOrder(rootNode->pRightChild);
}

void printTreeData_PostOrder(BinTreeNode* rootNode) {
    if (rootNode->pLeftChild)
        printTreeData_PostOrder(rootNode->pLeftChild);
    if (rootNode->pRightChild)
        printTreeData_PostOrder(rootNode->pRightChild);
    printf("%c ",rootNode->data);
}

void printTreeData(BinTreeNode* rootNode, const char *key) {
    if (strcmp(key, "inorder") == 0)
        printTreeData_InOrder(rootNode);
    if (strcmp(key, "preorder") == 0)
        printTreeData_PreOrder(rootNode);
    if (strcmp(key, "postorder") == 0)
        printTreeData_PostOrder(rootNode);
    printf("\n");
}
