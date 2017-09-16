#include "Cell.h"

Cell::Cell(bool firstState)
{
	state = firstState;
}

bool Cell::getState()
{
	return(state);
}

void Cell::setState(bool newState)
{
	state = newState;
}