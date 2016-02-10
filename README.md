## Synopsis

ExactMatches checks whether a given read or its reverse complement matches a not-so-long
reference sequence or not.
 
## Motivation

This code was generated to look for rRNA exact matching contaminations from tophat2 accepted reads.

## Code Example

Usage: 

   ExactMatches <reads.fa> <ref_seq.fa> nentriesref

 where: 
  - **reads.fa**: fasta file with accepted reads. Example: 

      >HWI-ST933:227:C8C7YACXX:1:2215:17204:32048
      GCGGGCGCCTGTAGTCCCAGCTACTTGGGAGGCTGAGACAGGAGAATGGCGTGAACCCCGGGGGGCGGA
      >HWI-ST933:227:C8C7YACXX:1:2113:14665:43703
      CCTGGGTTCAAGCGATTCTCCTGCCTCAGCCTCCTGAGTAGCTGGGACTACAGGGCCCCACCACCACGC
      >HWI-ST933:227:C8C7YACXX:1:2309:5571:96349
      CTTGTCTCTACTAAAAAAATACAAAAAAATTAGCTGGGCGTGGTGGTGGGGCCCTGTAGTCCCAGCTAC
      >HWI-ST933:227:C8C7YACXX:1:2216:15383:28082
      GAAGTGCGTGCCTGTAGTCCCAACTGCTCAGGAGGCTGAGGCAGGAGAATCGCTTGAACCTGGGAAGTA
      >HWI-ST933:227:C8C7YACXX:1:2106:16798:18157
      CGTCTCTACTAAAAAAAAATACAAAATTAACTGGGTGTGGTGGCACACGCCTGTAATCCCAGCTACTCG
  - **ref_seq.fa**: fasta file with the reference sequence(s) (more than one allowed).
      >gi|555853|gb|U13369.1|HSU13369 Human ribosomal DNA complete repeating unit
      GCTGACACGCTGTCCTCTGGCGACCTGTCGTCGGAGAGGTTGGGCCTCCGGATGCGCGCGGGGCTCTGGC
      CTCACGGTGACCGGCTAGCCGGCCGCGCTCCTGCCTTGAGCCGCCTGCCGCGGCCCGCGGGCCTGCTGTT
      CTCTCGCGCGTCCGAGCGTCCCGACTCCCGGTGCCGGCCCGGGTCCGGGTCTCTGACCCACCCGGGGGCG
      GCGGGGAAGGCGGCGAGGGCCACCGTGCCCCGTGCGCTCTCCGCTGCGGGCGCCCGGGGCGCCGCACAAC
      CCCACCCGCTGGCTCCGTGCCGTGCGTGTCAGGCGTTCTCGTCTCCGCGGGGTTGTCCGCCGCCCCTTCC
      CCGGAGTGGGGGGTGGCCGGAGCCGATCGGCTCGCTGGCCGGCCGGCCTCCGCTCCCGGGGGGCTCTTCG
      ATCGATGTGGTGACGTCGTGCTCTCCCGGGCCGGGTCCGAGCCGCGACGGGCGAGGGGCGGACGTTCGTG
      GCGAACGGGACCGTCCTTCTCGCTCCGCCCGCGCGGTCCCCTCGTCTGCTCCTCTCCCCGCCCGCCGGCC
      GGCGTGTGGGAAGGCGTGGGGTGCGGACCCCGGCCCGACCTCGCCGTCCCGCCCGCCGCCTTCGCTTCGC
  - **nentriesref**: number of reference sequences contained in ref_seq.fa


## Installation

1. Download the package.
2. The Makefile was written for a g++ compiler, and is using -std=gnu++0x. 
   Customize the compiler and compiling flags. 
3. Run make. 
4. Executable should land in the folder bin, and should be called ExactMatches. 


## Structure of the package.

   Package contents:
 
  |- bin/
      |- ExactMatches
  |- include/
      |- FastaFile.h
      |- Sequence.h
      |- utils.h
  |- obj/ (object files land here. Not included in repository)
  |- src/
      |- ExactMatches.cc  (main)
      |- FastaFile.cc
      |- Sequence.cc
      |- utils.cc   (general functions)
  |- test_files/
      |- reads.fa
      |- ref_seq.fa


In folder test_files there are two test files: 

- reads.fa :  example of a file with reads.
- ref_seq.fa  :  example of a fasta reference file. 

refs_seq.fa contains two entries, so, one can run the executable 
by doing: 

 bin/ExactMatches test_files/reads.fa test_files/ref_seq.fa 2

