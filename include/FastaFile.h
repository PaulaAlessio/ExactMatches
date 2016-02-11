//FastaFile.h 
#ifndef FastaFile_H
#define FastaFile_H
#include <iostream>
#include <string>
#include "Sequence.h"
class FastaFile{
   std::string *contents=NULL;
   std::string *names=NULL;
   int nentries;
   public: 
//      FastaFile(){ std::cout << "Sono scema" << std::endl;}; //Default Constructor
      FastaFile(std::string fastafile,int nentries);
      void ContainsSequence(std::string sequence, bool *match);
      ~FastaFile();  // Destructor (delete the dynamically allocated stuff!)
};
#endif
