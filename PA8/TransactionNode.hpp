#include "Node.hpp"

class TransactionNode : Node{
public:
	~TransactionNode() {
		//mUnits = 0;
	}

	TransactionNode(string &newData, int newUnits) {

		mUnits = newUnits;
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

