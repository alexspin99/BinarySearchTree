//
// item.h    
//
// DO NOT MODIFIY OR SUBMIT THIS FILE
//

#include <iostream>
#include <iomanip>
using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item                     // Models a single item from the catalog
{
private:
	int      itemID;            // Item ID number (search key)
	string   itemName;          // Item name
	float    itemPrice;         // Item price

public:
	/**** Start of functions you must implement for Item class ****/
	
	Item();
	// Default constructor initializes itemID to -1, itemPrice to -1.00, and itemName to empty string
	
	Item(int id, string name, float price);   
	// Constructor initializes itemID, itemName, itemPrice to id, name, and price respectively
	
	Item(const Item&  i);
	// Copy constructor -- copies attributes of item into attribute variables of current object

	friend bool operator==(const Item& leftop, const Item& rightop);   
   // Overloaded SAME AS operator  
	// Returns true if leftop.itemID == rightop.itemID.  Returns false otherwise

	friend bool operator<(const Item& leftop, const Item& rightop);    
   // Overloaded LESS THAN operator  
	// Returns true if leftop.itemID < rightop.itemID.  Returns false otherwise
	
	friend bool operator>(const Item& leftop, const Item& rightop);    
   // Overloaded GREATER THAN operator  
	// Returns true if leftop.itemID > rightop.itemID.  Returns false otherwise
	
	void operator=(const Item& op);                                       
   // Overloaded ASSIGNMENT operator  
	// Sets this->itemID = op.itemID,	this->itemName = op.itemName, this->itemPrice = op.itemPrice
	
	/***** End of functions you must implement for Item class *****/
	
	/***** Below are additional functions for your Item class -- DO NOT MOVE OR MODIFY THE CODE BELOW *****/ 
	
   friend istream& operator>>(istream& leftop, Item& rightop)            
   // Overloaded >> operator
	// This allows all data associated with a Item object to be input simultaneously from an input stream
	{
		leftop >> rightop.itemID >> rightop.itemName >> rightop.itemPrice;
		
		return leftop;
	}

   friend ostream& operator<<(ostream& leftop, const Item& rightop)
   // Overloaded << operator
	// This allows all data associated with a Item object to be output simultaneously to an output stream
	{
		leftop << "[" << rightop.itemID << ", " << rightop.itemName << ", $" 
             << fixed << showpoint << setprecision(2) << rightop.itemPrice << "]";
		
		return leftop;
	}	
	
	void Print() const      
   // Print()
   // Outputs Item information in desired format.  DO NOT MOVE OR MODIFY
	{
		cout << "[" << itemID << ", " << itemName << ",$" 
           << fixed << showpoint << setprecision(2) << itemPrice << "]";
		
	}  // End Print()
};

#endif




