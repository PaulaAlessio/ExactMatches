//FastaFile.cc
#include "FastaFile.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <fstream>
FastaFile::FastaFile(std::string fastafile,int n){
    nentries=n;
    std::ifstream input(fastafile.c_str());
    if(!input.good()){
        std::cerr << "Error opening '"<<fastafile<<"'. Bailing out." << std::endl;
        throw std::exception();
    }
    std::string line;
    contents = new std::string [n]; 
    names = new std::string [n]; 
    int cc=0;
    while(std::getline(input,line).good()){
      if(line.empty()){
         std::cerr << "Warning: there are empty lines in file.\
                       Read until read " << cc+1 << std::endl;
         break;
      }
      else if (line[0]=='>'){
         names[cc] = line;
         contents[cc].clear();
         cc++;
      }
      else{
         contents[cc-1] +=line;
      
      }
      if(cc > n) {
         std::cerr << "Warning: Number of reads passed smaller\
                       than the actual reads in file!" << std::endl;
         break;
      }
         
    }

}

void FastaFile::ContainsSequence(std::string sequence, bool *match){
   for(int i=0; i<nentries;i++){
      match[i] = KMP(contents[i],sequence) ;
   }
}

FastaFile::~FastaFile(){
   delete[] contents;
   delete[] names;
   std::cerr << "Deleting an instance of Fastafile" << std::endl;
}
