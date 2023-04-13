#include "Node.hpp"

class TransactionNode : Node{
public:
	~TransactionNode() {

	}

	TransactionNode(string newData, int newUnits) {


	}

	void setUnits(int newUnits) {
		mUnits = newUnits;
	}

	int getUnits(void) {
		return mUnits;
	}

	virtual void printData(void) {
		cout << "Units: " << mUnits << "Data: " << mData << endl;
	}

private:
	int mUnits;

};

