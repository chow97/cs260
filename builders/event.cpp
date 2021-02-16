#include <iostream>
#include "event.h"
#include "structuretype.h"

using namespace std;

event::event()
{
    sector = 0;
    type = UNK;
}

event::event(const int sector, const structure_type type)
{
    setSector(sector);
    setType(type);
}

event::~event(){}

int event::getSector()
{
    return sector;
}

structure_type event::getType()
{
    return type;
}

void event::setSector(int sector)
{
    this->sector = sector;
}

void event::setType(structure_type type)
{
    this->type = type;
}

