#include "Node.hpp"

class BST {
public:

	~BST() {

		// calls destroy tree 

	}
	
	BST() {


	}

	void setRoot(Node* newRoot) {
		mpRoot = newRoot;
	}

	Node* getRoot(void) {
		return mpRoot;
	}

	void insert() {
		/*public used to hide pointer information, i.e.won’t pass in the
			root of the tree into this function, only the private insert() function*/
	}

	void inOrderTraversal(void) {
		//calls privae inOrderTraversal function
		inOrder(mpRoot);
		
	}


private:
	Node* mpRoot;

	void destroyTree() {
		// should visit each node in postOrder to delete them
	}

	void insert(Node* root, int key) {

		/*it dynamically allocates a TransactionNode and inserts recursively in the correct subtree based on
		mUnits; should pass in a reference to a pointer(i.e.Node * &pT)*/

		if (root == nullptr) {
			return new Node()
		}

	}

	void inOrder(Node*root) {
		/*which recursively visits and prints the contents(mData and mUnits) of each node 
		in the tree in order; each node’s printData() should be called*/

		if (root == nullptr) {

			return;
		}

		inOrder(root->getLeftPtr());
		root->printData();
		inOrder(root->getRightPtr());

	}



};
