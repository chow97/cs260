#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <cstring>
class box
{
    private:
        int num;
        char* name;
    public:
        box();
        box(int num, char* name);
        box(const box& data);
        ~box();
        const box& operator= (const box& src);
        friend bool operator< (const box& d1, const box& d2);
        void setNum(int num);
        void setName(char* name);
        int getNum();
        char* getName();
};
#endif