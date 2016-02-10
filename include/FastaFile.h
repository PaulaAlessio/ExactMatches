//FastaFile.h 
#ifndef FastaFile_H
#define FastaFile_H
#include <string>
#include "Sequence.h"
class FastaFile{
   std::string *contents;
   std::string *names;
   int nentries;
   public: 
      FastaFile(){}; //Default Constructor
      FastaFile(std::string fastafile,int nentries);
      void ContainsSequence(std::string sequence, bool *match);
      ~FastaFile();  // Destructor (delete the dynamically allocated stuff!)
};
#endif
