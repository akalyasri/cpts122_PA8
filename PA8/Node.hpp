#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;
using std::istringstream;

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::vector;

class Node {

public:

	Node() {
		mpLeft = nullptr;
		mpRight = nullptr;
	}

	virtual ~Node() { ; }
	

	Node(string& newData) {
		mData = newData;
		mpLeft = nullptr;
		mpRight = nullptr;
	}

	void setData(string newData) {
		mData = newData;
	}

	void setLeftPtr(Node* newLeft) {
		mpLeft = newLeft;
	}

	void setRightPtr(Node* newRight) {
		mpRight = newRight;
	}

	string getData(void) const {
		return mData;
	}

	Node*& getLeftPtr(void) {
		return mpLeft;
	}

	Node*& getRightPtr(void) {
		return mpRight;
	}

	virtual void printData(void) = 0;

	Node& operator = (Node& copy) {
		this->mData = copy.mData;
		this->mpLeft = copy.mpLeft;
		this->mpRight = copy.mpRight;

		return *this;
	}


protected:

	string mData;
	Node* mpLeft;
	Node* mpRight;
};