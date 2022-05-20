#include "../includes/treeTester.h"

void testfield(void) {
    BinTreeNode *rootNode = makeBTNode('A');
    BinTree *btr = makeBinTree(*rootNode);
    BinTreeNode *bin1 = makeBTNode('B');
    BinTreeNode *bin2 = makeBTNode('C');
    BinTreeNode *bin1_1 = makeBTNode('D');
    BinTreeNode *bin1_2 = makeBTNode('E');
    BinTreeNode *bin2_1 = makeBTNode('F');
    BinTreeNode *bin2_2 = makeBTNode('G');
    BinTreeNode *bin1_1_1 = makeBTNode('H');
    BinTreeNode *bin1_1_2 = makeBTNode('I');
    BinTreeNode *bin1_2_1 = makeBTNode('J');
    BinTreeNode *bin2_1_2 = makeBTNode('K');
    BinTreeNode *bin2_2_1 = makeBTNode('L');
    BinTreeNode *bin2_2_2 = makeBTNode('M');

    insertLeftChildNodeBT(btr->pRootNode, *bin1);
    insertRightChildNodeBT(btr->pRootNode, *bin2);
    insertLeftChildNodeBT(btr->pRootNode->pLeftChild, *bin1_1);
    insertRightChildNodeBT(btr->pRootNode->pLeftChild, *bin1_2);
    insertLeftChildNodeBT(btr->pRootNode->pRightChild, *bin2_1);
    insertRightChildNodeBT(btr->pRootNode->pRightChild, *bin2_2);
    insertLeftChildNodeBT(btr->pRootNode->pLeftChild->pLeftChild, *bin1_1_1);
    insertRightChildNodeBT(btr->pRootNode->pLeftChild->pLeftChild, *bin1_1_2);
    insertLeftChildNodeBT(btr->pRootNode->pLeftChild->pRightChild, *bin1_2_1);
    insertRightChildNodeBT(btr->pRootNode->pRightChild->pLeftChild, *bin2_1_2);
    insertLeftChildNodeBT(btr->pRootNode->pRightChild->pRightChild, *bin2_2_1);
    insertRightChildNodeBT(btr->pRootNode->pRightChild->pRightChild, *bin2_2_2);

    // InOrder == H D I B J E A F K C L G M
    // PreOrder == A B D H I E J C F K G L M
    // PostOrder == H I D J E B K F L M G C A
    printTreeData(btr->pRootNode, "inorder");
    printTreeData(btr->pRootNode, "preorder");
    printTreeData(btr->pRootNode, "postorder");

    deleteBinTree(btr);
    system("leaks binTree");
}

int main(void) {
    testfield();
    return 0;
}
