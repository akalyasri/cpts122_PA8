#include "BTS.hpp"
using std::istringstream;

class DataAnalysis {

public:

	DataAnalysis() {


	}

	~DataAnalysis() {

		//closeFile();

	}

	void runAnalysis(void) {

		//this function calls the other private functions

		openFile();

		readFile(mCsvStream);

		displayTrends();

		closeFile();


	}


private:

	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	ifstream& openFile(void) {
		mCsvStream.open("data.csv");

		return mCsvStream;
	}

	void closeFile(void) {
		mCsvStream.close();
	}


	// courtesy of www.geeksforgeeks.org/getline-string-c/
	void readOneLine(string& line, int& units, string& type, string& status) { 

	/*	A function that reads one line from the file and splits the line into units, type,
		and transaction fields*/
		
		string temp;

		stringstream ss(line);

		getline(ss, temp, ',');

		units = stoi(temp);

		getline(ss, type, ',');
		getline(ss, status, ',');

	}

	void readFile(ifstream& stream) {

	/*	A function that loops until all lines are read from the file; calls the function
		below, and then displays the current contents of both BSTs; use inOrderTraversal() to
		display the trees*/

		string line;
		string type;
		string status;
		int units = 0;

		//read header line
		getline(mCsvStream, line);

		while (!mCsvStream.eof()) {

			getline(mCsvStream, line);
			readOneLine(line, units, type, status);

			TransactionNode* newNode = new TransactionNode(type, units);

			compareANDinsert(units, type, status);

		}
		

	}

	void compareANDinsert(int units, string type, string status) {


		//A function that compares the transaction field and inserts the units and type
		//	into the appropriate tree(mTreeSold or mTreePurchased) // note with the way the
		//	data.csv file is organized the trees will be fairly balanced

		if (status == "Sold") {
			mTreeSold.insert(units, type);
		}
		else if (status == "Purchased") {
			mTreePurchased.insert(units, type);
		}
		else {
			cout << "Error. Check code." << endl;
		}



	}

	void displayTrends(void) {


		/*A function that writes to the screen the trends we see in our tree; the
			function must display the type and number of units that are least purchased and sold,
			and the most purchased and sold*/


		TransactionNode* leastPurchased = mTreePurchased.findSmallest();
		TransactionNode* leastSold = mTreeSold.findSmallest();

		TransactionNode* mostPurchased = mTreePurchased.findLargest();
		TransactionNode* mostSold = mTreeSold.findLargest();


		cout << endl << "Least Purchased: " << endl;
		cout << "Type: " << leastPurchased->getData() << endl;
		cout << "Units: " << leastPurchased->getUnits() << endl;



		cout << endl << "Least Sold:" << endl;
		cout << "Type: " << leastSold->getData() << endl;
		cout << "Units: " << leastSold->getUnits() << endl;


		cout << endl << "Most Purchased:" << endl;
		cout << "Type: " << mostPurchased->getData() << endl;
		cout << "Units: " << mostPurchased->getUnits() << endl;



		cout << endl << "Most Sold" << endl;
		cout << "Type: " << mostSold->getData() << endl;
		cout << "Units: " << mostSold->getUnits() << endl;

		


	}




};