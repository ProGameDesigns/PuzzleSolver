#include "Region.h"

#include "Cell.h"

#include <iostream>

Region::Region(Cell* InCell, const std::set<Cell*>& InUnknowns)
{
	m_RegionState = InCell->GetState();
	m_Unknowns = InUnknowns;

	// No I don't when I create a region from a cell I add it's unknown neighbors to it.
	// - Then at the start of this function I use the std::set<Cell*> default copy assignment operator to copy the ptr values.
	if (m_RegionState == State::Unknown)
	{
		throw std::logic_error("LOGIC ERROR: Grid::Region::Region() - state must be known!");
	}


	m_Cells.insert(InCell);
}


std::set<Cell*>::const_iterator Region::Begin() const
{
	return m_Cells.begin();
}

std::set<Cell*>::const_iterator Region::End() const
{
	return m_Cells.end();
}

int Region::RegionSize() const
{
	return m_Cells.size();
}

std::set<Cell*>::const_iterator Region::UnknownsBegin() const
{
	return m_Unknowns.begin();
}

std::set<Cell*>::const_iterator Region::UnknownsEnd() const
{
	return m_Unknowns.end();
}

int Region::UnknownsSize() const
{
	return m_Unknowns.size();
}

bool Region::IsWhite() const
{
	return m_RegionState == State::White;
}

bool Region::IsBlack() const
{
	return m_RegionState == State::Black;
}

bool Region::IsNumbered() const
{
	return static_cast<int>(m_RegionState) > 0;
}

int Region::GetNumber() const
{
	if (!IsNumbered())
	{
		throw std::logic_error("Trying to get a number for a non-numbered-region");
	}
	else
	{
		return static_cast<int>(m_RegionState);
	}
}

bool Region::Contains(Cell* InCellPtr) const
{
	auto FindCell = m_Cells.find(InCellPtr);

	if (FindCell != m_Cells.end())
	{
		return true;
	}

	return false;
}

void Region::EraseUnknown(Cell * InUnknownCell)
{
	m_Unknowns.erase(InUnknownCell);
}

std::ostream & operator<<(std::ostream & os, const Region & RHS)
{

	os << "Cells In Region:" << "\n";
	for (auto& Cell : RHS.m_Cells)
	{
		os << *Cell << "\n";
	}
	os << "End of Cells In Region:" << "\n";

	return os;

}
