#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
	public:
		Inventory();
		void setDisplayState(bool x);
		bool getDisplayState();
		void renderInventory();
		void toggleDisplayState();

	private:
		bool displayed;
};



#endif