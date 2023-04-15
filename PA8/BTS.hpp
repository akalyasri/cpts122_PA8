#include "TransactionNode.hpp"

class BST {
public:

	~BST() {

		// calls destroy tree 
		destroyTree(mpRoot);
	}
	
	BST() {

		mpRoot = nullptr;
	}

	void setRoot(TransactionNode*& newRoot) {
		mpRoot = newRoot;
	}

	Node*& getRoot(void) {
		return mpRoot;
	}

	void insert(int newUnits, string newData) {
		/*public used to hide pointer information, i.e.won’t pass in the
			root of the tree into this function, only the private insert() function*/
		privateInsert(mpRoot, newUnits, newData);
	}

	void inOrderTraversal(void) {
		//calls privae inOrderTraversal function
		privateTraversal(mpRoot);
		
	}

	TransactionNode*& findLargest(void) {



	}

	TransactionNode*& findSmallest(void) {



	}



private:
	Node* mpRoot;

	void destroyTree(Node*& current) {
		// should visit each node in postOrder to delete them

		if (current != nullptr) {
			destroyTree(current->getLeftPtr());
			destroyTree(current->getRightPtr());

			delete current;
		}

	}

	void privateInsert(Node*& root, int newUnits, string newData) {

		/*it dynamically allocates a TransactionNode and inserts recursively in the correct subtree based on
		mUnits; should pass in a reference to a pointer(i.e.Node * &pT)*/
	
		if (root == nullptr) {
			//return new Node()
			root = new TransactionNode(newData, newUnits);
		}
		else if(newUnits > ((TransactionNode*)root)->getUnits()){
			privateInsert(root->getRightPtr(),newUnits,newData);
		}
		else if (newUnits > ((TransactionNode*)root)->getUnits()) {
			privateInsert(root->getLeftPtr(), newUnits, newData);
		}else
		{

		}

	}

	void privateTraversal(Node*&root) {
		/*which recursively visits and prints the contents(mData and mUnits) of each node 
		in the tree in order; each node’s printData() should be called*/

		if (root == nullptr) {

			return;
		}

		privateTraversal(root->getLeftPtr());
		((TransactionNode*)root)->printData();
		privateTraversal(root->getRightPtr());

	}

	Node* privateMax(Node*& pTree) {

		if (pTree->getRightPtr() == nullptr) {
			return pTree;
		}
		privateMax(pTree->getRightPtr());
			
	}

	Node* privateMin(Node*& pTree) {

		if (pTree->getLeftPtr() == nullptr) {
			return pTree;
		}
		privateMin(pTree->getLeftPtr());
	}
};
