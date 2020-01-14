/**********|**********|**********|
Program: StoreItem.cpp 
Course: Data Structures and Algorithms
Year: 2018/19 Trimester 1
Name: Ng Yan Teng
ID: 1171303161
Lecture Section: TC02
Tutorial Section: TT03
Email: teng8111@gmail.com/1171303161@student.mmu.edu.my
Phone: 010-3333933
**********|**********|**********/

#ifndef STOREITEM_H
#define STOREITEM_H


class StoreItem
{	
	public:
		void mainMenu();
		void getMain(int&);
		void getSub(int&);
		void getItem(int&);
		void commandMenu();
		void getCommand(int&);
		void createVector();
		void displayAll();
		void newRecord();
		bool checkFile();
		void displayOne(int);
		void updateData(int, int, int);
		void vectorToFile();
		int search(int, std::string);
		void dataMenu();
		void getField(int&);
		void getString(std::string&);
		void getDel(int&);
		void deleteRecord(int);
	
};

#endif