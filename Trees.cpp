
#include <iostream>
using namespace std;
struct BSTNode /// BinarySearchTreeNode
{

	int value;
	BSTNode* left = NULL;
	BSTNode* right = NULL;
};
class BST // BinarySearchTree
{
private:
	BSTNode* root;
public:
	BST() { root = NULL; }
	void insert(int value)
	{
		if (root == nullptr) {
			BSTNode *p = new BSTNode;
			p->value = value;
			root = p;
			return;
		}
		for (;;) {
			BSTNode *cur = root;
			if (value == cur->value) {
				return;
			}
			if (value < cur->value) {
				if (cur->left != NULL) {
					cur = cur->left;
				}
				else {
					BSTNode *n = new BSTNode;
					n->value = value;
					cur->left = n;
					n->left = NULL;
					n->right = NULL;	
					return;
				}
			}
			else if (value > cur->value) {
				if (cur->right != NULL) {
					cur = cur->right;
				}
				else {
					BSTNode *n = new BSTNode;
					n->value = value;
					cur->right = n;
					n->left = NULL;
					n->right = NULL;
					return;
				}
			}
		}
	}
	/// ------------------------------------------
	void remove(int value)
	{
		BSTNode *p = NULL;
		BSTNode *cur = root;
		while(cur != NULL) {
			if (cur == NULL) {
				return;
			}
			
			if (value == cur->value) {
				if (root == cur) {
					if (cur->left == NULL && cur->right == NULL) {
						root = NULL;
						delete cur;
					}

				}
				if (cur->left == NULL && cur->right == NULL) {				
					cur->value == p->left->value ? p->left = NULL : p->right = NULL;
					delete cur;
				}
				else if (cur->left != NULL && cur->right == NULL) {
					cur->left->value > p->value ? p->right = cur->left : p->left = cur->left;
					delete cur;
				}
				else if (cur->left == NULL && cur->right != NULL) {
					cur->right->value > p->value ? p->right = cur->right : p->left = cur->right;
					delete cur;
				}
				else if (cur->left != NULL && cur->right != NULL) {

				}
			}
			if (value < cur->value) {
				p = cur;
				cur - cur->left;
			}
			if (value > cur->value) {
				p = cur;
				cur = cur->right;
			}
		}
	}
	/// ------------------------------------------
	BSTNode* finMin() const
	{
		BSTNode *pRoot = root;

		if (pRoot == NULL) {
			return 0;
		}
		while(pRoot->left != NULL) {
			pRoot = pRoot->left;
		}
		return pRoot;
	}
	/// ------------------------------------------
	BSTNode* finMax() const
	{
		BSTNode *pRoot = root;

		if (pRoot == NULL) {
			return 0;
		}
		while (pRoot->right != NULL) {
			pRoot = pRoot->right;
		}
		return pRoot;
	}
	/// ------------------------------------------
	void preOrderTraversal() const
	{
		cout << "preOrderTraversal: ";
		preOrderTraversal(root);
		cout << endl;
	}
	void preOrderTraversal(BSTNode* node) const
	{
		if (node != NULL) {
			cout << node->value << " ";
			preOrderTraversal(node->left);
			preOrderTraversal(node->right);
		}
	}
	/// ------------------------------------------
	void inOrderTraversal() const
	{
		cout << "inOrderTraversal: ";
		inOrderTraversal(root);
		cout << endl;
	}
	void inOrderTraversal(BSTNode* node) const
	{
		if (node != NULL) {
			inOrderTraversal(node->left);
			cout << node->value << " ";
			inOrderTraversal(node->right);
		}
	}
	/// ------------------------------------------
	void postOrderTraversal() const
	{
		cout << "postOrderTraversal: ";
		postOrderTraversal(root);
		cout << endl;
	}
	void postOrderTraversal(BSTNode* node) const
	{
		if (node != NULL) {
			postOrderTraversal(node->left);
			postOrderTraversal(node->right);
			cout << node->value << " ";
		}
	}
};
const int SIZE = 15;
int main()
{
	BST bst;
	int values[SIZE] = { 5, 2, 12, -4, 3, 9, 21, -7, 19, 25, -8, -6, -4, 3, 12 };
	
	for (int i = 0; i < SIZE; i++) {
		
		bst.insert(values);
		bst.preOrderTraversal(); /// should be 5 2 -4 -7 -8 -6 3 12 9 21 19 25
		bst.inOrderTraversal(); /// should be -8 -7 -6 -4 2 3 5 9 12 19 21 25
		bst.postOrderTraversal(); /// should be -8 -6 7 -4 3 2 9 19 25 21 12 5
		bst.remove(3); /// Node 3 has 0 children --> delete the node and make it NULL;
		bst.remove(-4); /// Node -4 has 1 children --> Link parent to child --> delete the node and make it NULL;
		bst.remove(12); /// Node 12 has 2 children --> findMin for the right subtree --> swap value -> delete
		bst.preOrderTraversal(); /// should be 5 2 -7 -8 -6 19 9 21 25
		bst.inOrderTraversal(); /// should be -8 -7 -6 2 5 9 19 21 25
		bst.postOrderTraversal(); /// should be -8 -6 7 2 9 25 21 19 5
	}
	return 0;
}