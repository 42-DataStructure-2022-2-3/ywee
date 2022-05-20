#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct BinSearchTreeNodeType {
	int data;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BSTNode;

typedef struct BinSearchTreeType {
	struct BinSearchTreeNodeType* pRootNode;
} BinSearchTree;

BinSearchTree* makeBinSearchTree(BSTNode rootNode);
BSTNode* getRootNodeBST(BinSearchTree* pBinSearchTree);
BSTNode* search_recursive(BSTNode* pParentNode, int data);
BSTNode* search_loop(BinSearchTree* pBinSearchTree, int data);
bool    insert_recursive(BSTNode* targetNode, BSTNode element, BSTNode *target_parent);
bool    insert_loop(BinSearchTree* pBinSearchTree, BSTNode element);
BSTNode* search_loop(BinSearchTree* pBinSearchTree, int data);
BSTNode* search_parentNode(BinSearchTree* pBinSearchTree, int data);
bool deleteBSTNode(BinSearchTree* pBinSearchTree, int data);
BSTNode* copyBSTNode(BSTNode element);
BSTNode* makeBSTNode(int inputData);
void printTreeData_InOrder(BSTNode* rootNode);

#endif // _BIN_SEARCH_TREE_