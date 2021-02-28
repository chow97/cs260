#ifndef STRUCTURETYPE_H
#define STRUCTURETYPE_H

enum structure_type {WIND, WATER, SOLAR,UNK};
structure_type getFromString(const char* str);
void toString(const structure_type type,char* str);
const char* str(const structure_type type);

#endif
