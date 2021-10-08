//
// main.cpp  
//
// Driver program for BSTree ADT Template -- The text files (read by this code) contain a series 
// of commands that will help you test your BSTree ADT Template code by triggering various class methods.
//
// NOTES:
//
// A pointer variable of type void* may hold the address of any type of object,
// but it cannot be dereferenced with an explicit type cast.
//
// Example:    void* tPtr;                    // Generic pointer variable
//
//      static_cast< BSTree<int>* >(tPtr)     // Treat address in tPtr as a pointer to a BSTree of ints
//      static_cast< BSTree<Item>* >(tPtr)    // Treat address in tPtr as a pointer to a BSTree of Items
//
// DO NOT MODIFY OR SUBMIT THIS FILE
//
#include <iostream>
#include <fstream>
#include <string>
#include "bstree.h"
#include "item.h"


using namespace std;


int main (int argc, char * const argv[]) 
{
  ifstream inputs;                     // Input file for commands
  char op, ch;                         // Hold operation and optional char input
  void* tPtr = NULL;                   // Will point to BSTree object
  string  txt;                         // Holds text input from file
  string  dtype;                       // Holds template datatype information input from file

  
  // Output usage message if one input file name is not provided
  if (argc != 2)
  {
    cout << "Usage:\n  project05  <inputfile>\n";
	return 1;
  }
  
  // Attempt to open input file -- terminate if file does not open
  inputs.open(argv[1]);
  if (!inputs)
  {
    cout << "Error - unable to open input file" << endl;
	return 1;
  }

  // Process commands from input file
  getline(inputs, txt);
  cout << endl << txt << endl << endl;   // Output header comment
  inputs >> op;                          // Attempt to input first command
  while (inputs)
  {
    // Select and perform operation input from file

    switch (op)  
    {
      case '#':   // Test file comment
                  getline(inputs, txt);
                  cout << '#' << txt;
                  break;
			
      case 'c':   // Constructor
                  inputs >> dtype;       // Input datatype information from file

                  cout << endl << "Constructor() -- BSTree<" << dtype << ">";
                  try
                  {
                    // Information from input file determines the type of bstree created
                    if (dtype == "int")
                      tPtr = new BSTree<int>;
                    else if (dtype == "Item")
                      tPtr = new BSTree<Item>;
                    cout << endl;
                  }
                  catch ( std::bad_alloc )
                  {
                    cout << "-- Failed-bad_alloc: Terminating now..." << endl;
                    return 1;
                  }
                  catch ( ... )
                  {
                    cout << "-- Failed-unanticipated exception: Terminating now..." << endl;
                    return 1;
                  }
                  break;

      case 'd':   // Destructor
                  try
                  {
                    cout << "Destructor() -- BSTree<" << dtype <<">";
                    if (dtype == "int")
                    {
                      delete static_cast< BSTree<int>* >(tPtr);
                    }
                    else if (dtype == "Item")
                    {
                      delete static_cast< BSTree<Item>* >(tPtr);
                    }
                    tPtr = NULL;
                    cout << endl << endl;
                  }
                  catch ( ... )
                  {
                    cout << "-- Unexpected Exception" << endl;
                  }
                  break;


      case '!':   // Test copy constructor
                  try
                  {
                    cout << endl << "*** Start Copy Constructor Test ***" << endl;
                    if (dtype == "int")
                    {
                      BSTree<int> dummy = * static_cast< BSTree<int>* >(tPtr);
                      int temp;
                      inputs >> temp;
                      cout << "Print Copy without new value" << endl;
                      dummy.Print();
                      dummy.InsertItem(temp);
                      cout << "Print Copy plus new value" << endl;
                      dummy.Print();
                      cout << "Print Original without new value" << endl;
                      static_cast< BSTree<int>* >(tPtr)->Print();
                      cout << "CopyConstructor -- successful" << endl;
                    }
                    else if (dtype == "Item")
                    {
                      BSTree<Item> dummy = * static_cast< BSTree<Item>* >(tPtr);
                      Item i;
                      inputs >> i;
                      cout << "Print Copy without new value" << endl;
                      dummy.Print();
                      dummy.InsertItem(i);
                      cout << "Print Copy plus new value" << endl;
                      dummy.Print();
                      cout << "Print Original without new value" << endl;
                      static_cast< BSTree<Item>* >(tPtr)->Print();
                      cout << "CopyConstructor -- successful" << endl;
                    }
                  }
                  catch (...)
                  {
                    cout << "CopyConstructor -- Failed: copy constructor" << endl;
                  }
                  cout << "*** End Copy Constructor Test ***" << endl;
                  break;

      case '=':   // Test overloaded assignment operator
                  try
                  {
                    cout << endl << "*** Start Operator= Test ***" << endl;
                    if (dtype == "int")
                    {
                      BSTree<int> dummy;
                      dummy = * static_cast< BSTree<int>* >(tPtr);
                      int temp;
                      inputs >> temp;
                      cout << "Print Copy without new value" << endl;
                      dummy.Print();
                      dummy.InsertItem(temp);
                      cout << "Print Copy plus new value" << endl;
                      dummy.Print();
                      cout << "Print Original without new value" << endl;
                      static_cast< BSTree<int>* >(tPtr)->Print();
                      cout << "Operator= -- successful" << endl;
                    }
                    else if (dtype == "Item")
                    {
                      BSTree<Item> dummy;
                      dummy = * static_cast< BSTree<Item>* >(tPtr);
                      Item i;
                      inputs >> i;
                      cout << "Print Copy without new value" << endl;
                      dummy.Print();
                      dummy.InsertItem(i);
                      cout << "Print Copy plus new value" << endl;
                      dummy.Print();
                      cout << "Print Original without new value" << endl;
                      static_cast< BSTree<Item>* >(tPtr)->Print();
                      cout << "Operator= -- successful" << endl;
                    }
                  }
                  catch ( ... )
                  { 
                    cout << "Operator= -- Failed: assignment operator" << endl;
                  }         
                  cout << "*** End Operator= Test ***" << endl;
                  break;

      case '+':   // InsertItem
                  try
                  {
                    if (dtype == "int")
                    {
                      int temp;
                      inputs >> temp;
                      cout << "InsertItem(" << temp << ") ";
                      static_cast< BSTree<int>* >(tPtr)->InsertItem(temp);
                    }
                    else if (dtype == "Item")
                    {
                      Item temp;
                      inputs >> temp;
                      cout << "InsertItem(" << temp << ") ";
                      static_cast< BSTree<Item>* >(tPtr)->InsertItem(temp);
                    }
                  }
                  catch (FullBSTree)
                  {
                    cout << "-- Failed Full BSTree"; 
                  }
                  catch (FoundInBSTree)
                  {
                    cout << "-- Failed Item Already Found In BSTree";
                  }
                  catch ( ... )
                  {
                    cout << "-- Unexpected Exception";
                  }
                  cout << endl;
                  break;

      case '-':   // DeleteItem
                  try
                  {
                    if (dtype == "int")
                    {
                      int temp;
                      inputs >> temp;
                      cout << "DeleteItem(" << temp << ") ";
                      temp = static_cast< BSTree<int>* >(tPtr)->DeleteItem(temp);
                      cout << "Deleted " << temp;
                    }
                    else if (dtype == "Item")
                    {
                      int id;
                      inputs >> id;
                      Item i(id, "", -1.00);
                      cout << "DeleteItem(" << id << ") ";
                      i = static_cast< BSTree<Item>* >(tPtr)->DeleteItem(i);
                      cout << "Deleted " << i;
                    }
                  }
                  catch (EmptyBSTree)
                  {
                    cout << "-- Failed Empty BSTree";
                  }
                  catch (NotFoundBSTree)
                  {
                    cout << "-- Failed Not Found in BSTree";
                  }
                  catch ( ... )
                  {
                    cout << "-- Unexpected Exception";
                  }
                  cout << endl;
                  break;
			  
      case 'p':   // Print BSTree
                  if (dtype == "int")
                    static_cast< BSTree<int>* >(tPtr)->Print();
                  else if (dtype == "Item")
                    static_cast< BSTree<Item>* >(tPtr)->Print();
                  break;

      case 's':   // Size of BSTree
                  try
                  {
                    cout << "Size() -- ";
                    if (dtype == "int")
                      cout << static_cast< BSTree<int>* >(tPtr)->Size() << endl;
                    else if (dtype == "Item")
                      cout << static_cast< BSTree<Item>* >(tPtr)->Size() << endl;
                  }
                  catch ( ... )
                  {
                    cout << "Unexpected Exception" << endl;
                  }
                  break;
				  
      case 'm':   // Make BSTree Empty
                  try
                  {
                    cout << "MakeEmpty() ";
                    if (dtype == "int")
                      static_cast< BSTree<int>* >(tPtr)->MakeEmpty();
                    else if (dtype == "Item")
                      static_cast< BSTree<Item>* >(tPtr)->MakeEmpty();
					cout << endl;
                  }
                  catch ( ... )
                  {
                    cout << "-- Unexpected Exception" << endl;
                  }
                  break;
		
      case '<':   // Minimum value in BSTree
                  cout << "Min() -- ";
                  try
                  {
                    if (dtype == "int")
                      cout << static_cast< BSTree<int>* >(tPtr)->Min() << endl;
                    else if (dtype == "Item")
                      cout << static_cast< BSTree<Item>* >(tPtr)->Min() << endl;
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "Failed Empty BSTree" << endl;
                  }
                  catch ( ... )
                  {
                    cout << "Unexpected Exception" << endl;
                  }
                  break;

       case '>':  // Maximum value in BSTree
                  cout << "Max() -- ";
                  try
                  {
                    if (dtype == "int")
                      cout << static_cast< BSTree<int>* >(tPtr)->Max() << endl;
                    else if (dtype == "Item")
                      cout << static_cast< BSTree<Item>* >(tPtr)->Max() << endl;
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "Failed Empty BSTree" << endl;
                  }
                  catch ( ... )
                  {
                    cout << "Unexpected Exception" << endl;
                  }			
                  break;
		
        case 'l': // TotalLevels in BSTree
                  try
                  {
                    cout << "TotalLevels() -- ";
                    if (dtype == "int")
                      cout << static_cast< BSTree<int>* >(tPtr)->TotalLevels() << endl;
                    else if (dtype == "Item")
                      cout << static_cast< BSTree<Item>* >(tPtr)->TotalLevels() << endl;
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "Failed Empty BSTree" << endl;
                  }
                  catch ( ... )
                  {
                    cout << "Unexpected Exception" << endl;
                  }
                  break;	

        case '?': // Level within BSTree
                  try
                  {
                    if (dtype == "int")
                    {
                      int temp;
                      inputs >> temp;
                      cout << "Level('" << temp << "') -- ";
                      cout << static_cast< BSTree<int>* >(tPtr)->Level(temp) << endl;
                    }
                    else if (dtype == "Item")
                    {
                      int id;
                      inputs >> id;
                      Item i(id, "", -1.00);
                      cout << "Level('" << i << "') -- ";
                      cout << static_cast< BSTree<Item>* >(tPtr)->Level(i) << endl;
                    }
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "Failed Empty BSTree" << endl;
                  }
                  catch ( ... )
                  {
                    cout << "Unexpected Exception" << endl;
                  }
                  break;

        case '^': // Parent within BSTree
                  try
                  {
                    if (dtype == "int")
                    {
                      int temp;
                      inputs >> temp;
                      cout << "Parent('" << temp << "') -- ";
                      cout << static_cast< BSTree<int>* >(tPtr)->Parent(temp) << endl;
                    }
                    else if (dtype == "Item")
                    {
                      int id;
                      inputs >> id;
                      Item i(id, "", -1.00);
                      cout << "Parent('" << i << "') -- ";
                      cout << static_cast< BSTree<Item>* >(tPtr)->Parent(i) << endl;
                    }
                  }
                  catch ( EmptyBSTree )
                  {
                    cout << "Failed Empty BSTree" << endl;
                  }
                  catch ( NotFoundBSTree )
                  {
                    cout << "Not Found in BSTree" << endl;
                  }
                  catch ( NoParentBSTree )
                  {
                    cout << "Root has no parent in BSTree" << endl;
                  }
                  catch ( ... )
                  {
                    cout << "Unexpected Exception" << endl;
                  }
                  break;

        default:  // Error
                  cout << "Error - unrecognized operation '" << op << "'" << endl;
                  cout << "Terminating now..." << endl;
				      return 1;
                  break;
    }
 
    inputs >> op;	// Attempt to input next command
  }

  return 0;
}




