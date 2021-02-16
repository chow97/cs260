#ifndef EVENT_H
#define EVENT_H

#include "structuretype.h"
class event
{
    private:
        int sector;
        structure_type type;
    
    public:
        event();
        event(const int sector, const structure_type type);
        ~event();
        int getSector();
        structure_type getType();
        void setSector(int sector);
        void setType(structure_type type);
};
#endif