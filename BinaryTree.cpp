#include <iostream>
using namespace std;

struct BTreeNode {
	int data;
	BTreeNode *left;
	BTreeNode *right;
};

BTreeNode* MakeBtreeNode(void) {
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

int getData(BTreeNode *bt) {
	return bt->data;
}

void setData(BTreeNode *bt, int data) {
	bt->data = data;
}

void deleteTree(BTreeNode *bt) {
	if(bt == NULL)
		return;

	
	deleteTree(bt->left);
	deleteTree(bt->right);
	cout << "del tree data: " << bt->data << '\n';

	free(bt);
}

BTreeNode * GetLeftSubTree(BTreeNode *bt) {
	return bt->left;
}

BTreeNode * GetrightSubTree(BTreeNode *bt) {
	return bt->right;
}

void MakeleftSubTree(BTreeNode *main, BTreeNode *sub) {
	if(main->left != NULL)
		deleteTree(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
	if(main->right != NULL)
		deleteTree(main->right);

	main->right = sub;
}

void InorderTraverse(BTreeNode *bt) {
	if(bt == NULL)
		return;

	
	InorderTraverse(bt->left);
	cout << bt->data << '\n';
	InorderTraverse(bt->right);
}




int main() {

	BTreeNode *bt1 = MakeBtreeNode();
	BTreeNode *bt2 = MakeBtreeNode();
	BTreeNode *bt3 = MakeBtreeNode();
	BTreeNode *bt4 = MakeBtreeNode();

	setData(bt1, 1);
	setData(bt2, 2);
	setData(bt3, 3);
	setData(bt4, 4);

	MakeleftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeleftSubTree(bt2, bt4);

	InorderTraverse(bt1);

	return 0;
}