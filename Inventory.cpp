/**********|**********|**********|
Program: Inventory.cpp 
Course: Data Structures and Algorithms
Year: 2018/19 Trimester 1
Name: Ng Yan Teng
ID: 1171303161
Lecture Section: TC02
Tutorial Section: TT03
Email: teng8111@gmail.com/1171303161@student.mmu.edu.my
Phone: 010-3333933
**********|**********|**********/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include "StoreItem.h"

using namespace std;


int main()
{
	StoreItem a;
	
	int mainchoice, subchoice, itemchoice, command, field, position, del;
	string update, input;
	char confirm;
	
	cout <<"\n************Inventory Record************\n"
	<<"\nWelcome! Begin by selecting from choices below.\n";
	
	while(mainchoice != 6)
	{
		a.mainMenu();	
		a.getMain(mainchoice);
		a.checkFile();
		a.createVector();
		
		if (mainchoice == 1)
		{
			cout << "\nIf the data field is unavailable, enter N/A.\n";
			a.newRecord();
			a.createVector();
		}
		else if(mainchoice == 2)
			if (a.checkFile() == false)
			{
				a.displayAll();
				cout << "\nSelect the record that you would like to delete: ";
				a.getDel(del);
				a.displayOne(del);
				cout << "\nAre you sure you want to delete this record? (Y/N) ";
				cin >> confirm;
				if(confirm == 'Y' || confirm == 'y')
				{
					a.deleteRecord(del);
					a.vectorToFile();
					cout << "\nRecord deleted.\n";
				}
				else
					cout << "\nReturning to main menu.\n";
			}
			else
				cout << "There are no records.\n";
		else if(mainchoice == 3)
		{
			if (a.checkFile() == false)
			{
				if(command != 3)
				{
					cout << endl;
					a.displayAll();
					cout << "\nSelect the record that you would like to modify: ";
					a.getItem(itemchoice);
					cout << endl;
					a.displayOne(itemchoice);
					cout << "\nSelect the data field that you would like to modify: ";
					a.getSub(subchoice);
					a.commandMenu();
					a.getCommand(command);
					if(command == 1 || command == 2)
					{								
						a.updateData(itemchoice, subchoice, command);
						a.vectorToFile();
					}
				}
			}
			else
				cout << "There are no records.";
		}
		else if(mainchoice == 4)
		{
			
			a.dataMenu();
			a.getField(field);
			if(field != 13)
			{
				a.getString(input);
				position = a.search(field, input);
				if(position == -1)
				{
					cout << "\nData not found.\n";
				}
				else
				{
					cout <<"\nBelow are the data records containing search condition.\n\n";
					a.displayOne(position);
					
				}
			}
		}
		else if(mainchoice == 5)
		{
			a.checkFile();
			a.createVector();
			a.displayAll();
		}
		
	}
	
	
	return 0;
}
