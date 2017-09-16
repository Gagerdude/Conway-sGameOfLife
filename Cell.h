#ifndef CELL_H
#define CELL_H

class Cell
{
	public:
		Cell(bool firstState);
		bool getState();
		void setState(bool newState);
	private:
		bool state;
};

#endif