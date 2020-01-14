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

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include "StoreItem.h"

using namespace std;

typedef vector<string> vstring;
vector<vstring> data;



void StoreItem::mainMenu()			//Displays main menu
{
	cout <<"\n************Main Menu************"
	<<"\n\nSelect by entering the corresponding numbers:\n\n"
	<<"[1]	Enter a new record\n"
	<<"[2]	Delete an existing record\n"
	<<"[3] 	Update or delete a data field from a record\n"
	<<"[4]	Search by data field\n"
	<<"[5]	Display all records\n"
	<<"[6]	Exit Program\n";
}

void StoreItem::getMain(int& a)			//Gets the user's choice for main menu	
{
	cin >> a;
	while(a <1 || a >6)
	{
		cout << "\nInvalid choice, please re-enter: ";
		cin >> a;
	}
}

void StoreItem::dataMenu()			//Displays data field that can be chosen								
{
	cout << "\nWhich data field would you like to search?\n\n"
	<<"[1]	Item ID\n"
	<<"[2]	Item Name\n"
	<<"[3]	Item Description\n"
	<<"[4]	Category\n"
	<<"[5]	Manufacturer\n"
	<<"[6]	Selling Price\n"
	<<"[7]	Cost Price\n"
	<<"[8]	Units in Store\n"
	<<"[9]	Units Sold\n"
	<<"[10]	Year of Date First Introduced\n"
	<<"[11]	Month of Date First Introduced\n"
	<<"[12]	Day of Date First Introduced\n"
	<<"[13]	Return\n";
}

void StoreItem::getSub(int& b)			//Gets the user's choice for sub menu	
{	
	cin >> b;
	while(b <1 || b >12)
	{
		cout << "\nInvalid choice, please re-enter: ";
		cin >> b;
	}
}

void StoreItem::getItem(int& c)			//Gets the record that the user wants to modify
{
	int col, count=0;
	string line;
	ifstream file;
    file.open("data.txt");
	

	while(getline(file, line))	 
	count++;
	
	col = count/12;
	
	cin >> c;
	
	while(c <1 || c >col)
	{
		cout << "\nInvalid choice, please re-enter: ";
		cin >> c;
	}
}

void StoreItem::getDel(int& h)			//Gets the record that the user wants to delete
{
	int col, count=0;
	string line;
	ifstream file;
    file.open("data.txt");
	

	while(getline(file, line))	 
	count++;
	
	col = count/12;
	
	cin >> h;
	
	while(h <1 || h >col)
	{
		cout << "\nInvalid choice, please re-enter: ";
		cin >> h;
	}
}

void StoreItem::commandMenu() 			//Displays command menu
{
	cout <<"\n\nSelect desired action:\n\n"
	<<"[1]	Update of current data field\n"
	<<"[2]	Deletion of current data field\n"
	<<"[3]	Return\n";
}


void StoreItem::getCommand(int& d)			//Gets the user's choice for command menu
{
	cin >> d;
	while(d <1 || d >3)
	{
		cout << "\nInvalid choice, please re-enter: ";
		cin >> d;
	}
}

void StoreItem::newRecord()				//Gets a new record from the user
{
    string tempData;
	
	string list[12] = 
	{
		"[1]	Item ID: ",
		"[2]	Item Name: ",
		"[3]	Item Description: ",
		"[4]	Category: ",
		"[5]	Manufacturer: ",
		"[6]	Selling Price: ",
		"[7]	Cost Price: ",
		"[8]	Units in Store: ",
		"[9]	Units Sold: ",
		"[10]	Year of Date First Introduced: ",
		"[11]	Month of Date First Introduced: ",
		"[12]	Day of Date First Introduced: "
	};

	fstream file;
	file.open("data.txt", fstream::app);
	cin.seekg(0,ios::end);
	cin.clear();
	
	for(int i=0; i<12; i++)
	{
		cout << list[i];
		getline(cin, tempData);
		file << tempData << endl;
	}
	
	file.close();
}

void StoreItem::createVector()	//Creates a vector that contains data from existing text file
{
	int count = 0, col;
	string line, tempStr;
	
	data.clear();
	
    ifstream file;
    file.open("data.txt");

	while(getline(file, line))	 
	count++;
	
	col = count/12;
	
	file.clear();
	file.seekg(0, ios::beg);

    if (checkFile() == false) {
        for (int i = 0; i < col; i++){
            vector<string> tmpVec;
            string tmpString;

                for (int j = 0; j < 12; j++){
                getline(file, tmpString);
                tmpVec.push_back(tmpString);
                }
            data.push_back(tmpVec);
		}
	}	
	
    while (getline(file, line)) 
    {
        
        data.push_back(vstring());

       
        istringstream strm(line);
        while (strm >> tempStr)
          
            data.back().push_back(tempStr);
    }
}

void StoreItem::displayAll()		//Displays all the contents of existing records
{
	int col, count=0;
	string line;
	
	string list[12] = 
	{
		"[1]	Item ID:                         ",
		"[2]	Item Name:                       ",
		"[3]	Item Description:                ",
		"[4]	Category:                        ",
		"[5]	Manufacturer:                    ",
		"[6]	Selling Price:                   ",
		"[7]	Cost Price:                      ",
		"[8]	Units in Store:                  ",
		"[9]	Units Sold:                      ",
		"[10]	Year of Date First Introduced:   ",
		"[11]	Month of Date First Introduced:  ",
		"[12]	Day of Date First Introduced:    "
	};
	
	if (checkFile() == true)
	{
		for(int k=0; k<12; k++)
		{
			cout << list[k] << "No data" << endl;
		}
	}
	else 
	{
		ifstream outfile("data.txt");
		while(getline(outfile, line))	 
		count++;
	
		col = count/12;
		
		for(int k=0;k<12;k++)
		{
			cout << list[k] ;
			
			for(int l=0;l<col;l++)
			{
				cout << left << setw(25) << data[l][k]  ;
			}
			cout <<endl;
		}
	}
}
	
bool StoreItem::checkFile()			//Check for contents of existing text file
{
	ifstream file;
    file.open("data.txt");
	
	if (file.peek() == ifstream::traits_type::eof())
		return true;
	else
		return false;
}

void StoreItem::displayOne(int e)		//Displays the content of one record
{
	string list[12] = 
	{
		"[1]	Item ID:                         ",
		"[2]	Item Name:                       ",
		"[3]	Item Description:                ",
		"[4]	Category:                        ",
		"[5]	Manufacturer:                    ",
		"[6]	Selling Price:                   ",
		"[7]	Cost Price:                      ",
		"[8]	Units in Store:                  ",
		"[9]	Units Sold:                      ",
		"[10]	Year of Date First Introduced:   ",
		"[11]	Month of Date First Introduced:  ",
		"[12]	Day of Date First Introduced:    "
	};

	for(int i=0; i<12; i++)
	{
		cout << list[i] << left << setw(25) << data[e-1][i] <<endl;
	}
	
}

void StoreItem::getField(int& f)		//Gets the data field that the user wants to modify	
{	
	cin >> f;
	while(f <1 || f >13)
	{
		cout << "\nInvalid choice, please re-enter: ";
		cin >> f;
	}
}

void StoreItem::updateData(int row, int col, int uod)	//Updates a single data field of a record
{
	std::string update;
	
	if(uod == 1)
	{
		cout << "Enter new data here: ";
		cin.seekg(0,ios::end);
		cin.clear();
		getline(cin, update);
		data[row-1][col-1] = update;
		cout <<"The data has been updated.\n";
	}
	else
	{
		data[row-1][col-1] = "N/A";
		cout <<"The data has been deleted.\n";
	}
}

void StoreItem::vectorToFile()		//Updates content of existing vector to text file
{	
	string tempLine;
	
	ofstream writefile("data.txt");
    
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < 12; j++)
        writefile << data[i][j] << endl;
    }
}

int StoreItem::search(int datatype, std::string value)  //Search for exact data input by user
{
	int index = 0, i = 0, position = -2;
	
	while(index < data.size())
	{
		if(data[index][datatype-1] == value)
		{
			position = index;
			i++;
		}
		index++;
	}
	return position+1;
}

void StoreItem::getString(std::string& input)	//Gets the data that the user wants to search
{
	cout << "Enter the exact data that you would like to search: ";
	cin >> input;
}

void StoreItem::deleteRecord(int i)		//Deletes the record chosen by user
{
	data.erase(data.begin()+(i-1));
}

