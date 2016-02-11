#include <stdio.h>
#include "utils.h"

char LT[255];
// Initializes the char* map
void init_map(char *LT){
   for (int i = 0; i < 255; i++){
      LT[i] = 'N';
   }
   LT['A'] = 'T';
   LT['T'] = 'A';
   LT['C'] = 'G';
   LT['G'] = 'C';
   LT['a'] = 't';
   LT['t'] = 'a';
   LT['c'] = 'g';
   LT['g'] = 'c';
}


// Implements the Knuth-Morris-Pratt pattern matcher
// to find a substring in a string
//----------------------------
//  Returns a boolean: 
//  - true if  match.
//  - false if no match.
//----------------------------

bool KMP(std::string S, std::string K)
{
        int T[K.size()];
        for (size_t i = 0; i < K.size(); i++) T[i] = -1; //qua inizializzo tante volte
        bool matches=false;
        
        if(K.size() == 0)
        {
            return matches;
        }
        for(size_t i = 1; i <= K.size(); i++)
        {
                int pos = T[i - 1];
                while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
                T[i] = pos + 1;
        }

        size_t sp = 0;
        int kp = 0;
        while(sp < S.size())
        {
                while(kp != -1  && (kp == int(K.size()) || K[kp] != int(S[sp]))) kp = T[kp];
                kp++;
                sp++;
                if(kp == int(K.size())) matches = true;
        }
        
        return matches;
}
