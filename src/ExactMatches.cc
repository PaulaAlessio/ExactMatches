#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Sequence.h"
#include "FastaFile.h"
#include "utils.h"

// This function checks which reads
// of a fasta file or its reverse complements 
// are contained in a longer sequence. Looks only for  
// exact matches. 
// Usage: ./bin/reverseComplement <reads.fa> <ref_seq.fa> nentries_fasta output_prefix n_threads
int main(int argc, char **argv )
{
   if( argc != 5){
        std::cerr << "Usage: "<<argv[0]<<" <reads.fa> <ref_seq.fa> nentriesref output_prefix" << std::endl;
        return -1;
    }
    
    int n=atoi(argv[3]);
    FastaFile rRNA(argv[2],n); 
    bool match_seq[n],match_rev[n];
    init_map(LT);
    std::ifstream input(argv[1]);
    if(!input.good()){
        std::cerr << "Error opening '"<<argv[1]<<"'. Bailing out." << std::endl;
        return -1;
    }
    std::string line, name, content,reverse;
    int cc=0;
    std::string oname_match=argv[4]+std::string("_exactmatch.fa");
    std::string oname_nomatch=argv[4]+std::string("_noexactmatch.fa");
    std::ofstream ofile_match(oname_match.c_str());
    std::ofstream ofile_nomatch(oname_nomatch.c_str());
    while( std::getline( input, line ).good() ){
        cc++;
        if(cc%50000==0) std::cerr<< "Currently Reading Read Number: "<< cc << std::endl; 
        if( line.empty() || line[0] == '>' ){ // Identifier marker
            if( !name.empty() ){ // Print out the marker
                Sequence seqfile(content,true);
                reverse=seqfile.GetReverse(); 
                rRNA.ContainsSequence(content,match_seq);
                rRNA.ContainsSequence(reverse,match_rev);
                for (int i=0; i<n; i++){
                   if (match_seq[i]){
                      ofile_match << "Read matches fasta entry : " << i << ". Read id: " << name <<std::endl;
                      ofile_match << content << std::endl;
                   }
                   else if (match_rev[i]){
                      ofile_match << "Reverse Complementary Read matches fasta entry : " << i << ". Read id: " << name <<std::endl;
                      ofile_match << reverse << std::endl;
                   }
                   else{
                      ofile_nomatch << "No exact match tofasta entry : " << i << ". Read id: " << name <<std::endl;
                      ofile_nomatch << content << std::endl;
                   }
                }
                name.clear();
            }
            if( !line.empty() ){
                name = line.substr(1);
            }
            content.clear();
        } else if( !name.empty() ){
            if( line.find(' ') != std::string::npos ){ // Invalid sequence--no spaces allowed
                name.clear();
                content.clear();
            } else {
                content += line;
            }
        }
    }
    if( !name.empty() ){ // Last entry
        Sequence seqfile(content);
        reverse=seqfile.GetReverse(); 
        for (int i=0; i<n; i++){
           if (match_seq[i]){
              ofile_match << "Read matches fasta entry : " << i << "Read id: " << name <<std::endl;
              ofile_match << content << std::endl;
           }
           else if (match_rev[i]){
              ofile_match << "Reverse Complementary Read matches fasta entry : " << i << ". Read id: " << name <<std::endl;
              ofile_match << reverse << std::endl;
           }
           else{
              ofile_nomatch << "No exact match tofasta entry : " << i << ". Read id: " << name <<std::endl;
              ofile_nomatch << content << std::endl;
           }
        }
    }
    ofile_match.close();
    ofile_nomatch.close();
 

    return 0; 
}
