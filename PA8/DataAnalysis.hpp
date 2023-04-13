#include "BTS.hpp"

class DataAnalysis {

public:

	DataAnalysis() {


	}

	~DataAnalysis() {

		closeFile();

	}

	void runAnalysis(void) {

		//this function calls the other private functions


	}


private:

	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	void openFile(void) {
		mCsvStream.open("data.csv");
	}

	void closeFile(void) {
		mCsvStream.close();
	}

	void readOneLine(void) {

	/*	A function that reads one line from the file and splits the line into units, type,
		and transaction fields*/
		
		int newUnits = 0;
		string newType;
		string status;

		string line;

		getline(mCsvStream, line);

			string temp;
			stringstream ss(line);
			int fieldIndex = 0;

			while (getline(ss, temp, ',')) {

				switch (fieldIndex) {

				case 0:
					//units

					break;

				case 1:
					//type

					break;

				case 2:
					//transaction status

					//insert to BST
					break;

				default:

					break;

				}

				fieldIndex++;

			}


		


	}

	void readFile(void) {

	/*	A function that loops until all lines are read from the file; calls the function
		below, and then displays the current contents of both BSTs; use inOrderTraversal() to
		display the trees*/

		string line;

		while(getline(mCsvStream, line)){





		}

	}

	void compareInsert(void) {

		//A function that compares the transaction field and inserts the units and type
		//	into the appropriate tree(mTreeSold or mTreePurchased) // note with the way the
		//	data.csv file is organized the trees will be fairly balanced


	}

	void displayTrends(void) {


		/*A function that writes to the screen the trends we see in our tree; the
			function must display the type and number of units that are least purchased and sold,
			and the most purchased and sold*/


	}




};