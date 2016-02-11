#ifndef utils_H
#define utils_H
#include <iostream>
void init_map(char *LT);
bool KMP(std::string S, std::string K); //checks whether K is in S
extern char LT[255];
#endif
