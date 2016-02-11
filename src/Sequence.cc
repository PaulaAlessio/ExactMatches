// Sequence.cc
#include "Sequence.h"
#include "utils.h"
#include <iostream>

void Sequence::RevComp(){
   rev = std::string(seq.rbegin(),seq.rend());
   for(size_t i = 0; i < rev.length(); i++){
        rev[i]=LT[rev[i]];
   }
}
Sequence::Sequence(std::string const& str,bool reverse):
   seq(str) 
{
   if (reverse) RevComp();      
}

std::string Sequence::GetReverse(){
   return rev;
}

std::string Sequence::GetSequence(){
   return seq;
}

Sequence::~Sequence(){
//   std::cerr << "Object Sequence is being deleted" << std::endl;
}
