#include <iostream>
using std::cout;
using std::endl;


class abstractBase{ // pure vitrual

public:

	//virtual void setA(int input) = 0;  // pure vitrual bc theres is no implementation

	void setB(int input) { // virtual with implementation -> not pure virtual
		b = input;
	}

//protected:

	int a = 0;
	int b = 0;


};



class derivedClass: abstractBase{

public:
	
	virtual void setA(int input) {
		b = input;
	}

	int getA() {
		return b;
	}

private:

};


int main(void) {

	derivedClass test;
	abstractBase test2;

	test.setA(343);

	cout << "A: "<< test2.a << " B: "<< test.getA() << endl;

	test.setA(10);
	
	cout << "A: " << test2.a << " B: " << test.getA() << endl;



	std::cout << "Hello World" << std::endl;



}