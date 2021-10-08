#include "item.h"

using namespace std;


Item::Item()
{
	itemID = 0;
	itemPrice = -1.00;
	itemName = "";
}

Item::Item(int id, string name, float price)
{
	itemID = id;
	itemName = name;
	itemPrice = price;
}

Item::Item(const Item& i)
{
	//copies data from item
	itemID = i.itemID;
	itemPrice = i.itemPrice;
	itemName = i.itemName;
}

bool operator==(const Item& leftop, const Item& rightop)
{
	if (leftop.itemID == rightop.itemID)
		return true;
	return false;
}

bool operator<(const Item& leftop, const Item& rightop)
{
	if (leftop.itemID < rightop.itemID)
		return true;
	return false;
}

bool operator>(const Item& leftop, const Item& rightop)
{
	if (leftop.itemID > rightop.itemID)
		return true;
	return false;
}

void Item::operator=(const Item& op)
{
	this->itemID = op.itemID;
	this->itemPrice = op.itemPrice;
	this->itemName = op.itemName;
}
