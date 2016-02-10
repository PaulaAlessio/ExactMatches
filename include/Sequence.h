// Sequence.h 
#ifndef Sequence_H
#define Sequence_H
#include <string>
#include "utils.h"
class Sequence{
   std::string seq;
   std::string rev;
   public:
      Sequence(){}; //Constructor   
      Sequence(std::string const& str,bool reverse=true);  //Constructor + initializer
      void RevComp();
      std::string GetReverse();
      std::string GetSequence();
      ~Sequence();  //Destructor declaration 
};
#endif
