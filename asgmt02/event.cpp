#include <iostream>
#include "event.h"
#include "structuretype.h"

using namespace std;

event::event()
{
    sector = 0;
    type = UNK;
}

event::event(int sector, structure_type type)
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

void event::print() const{
    cout << "Sector: " << sector << " Structure: " << type << endl;
}