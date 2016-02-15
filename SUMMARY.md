## 1. Overrepresented sequences. 

Die Sequenz
 
   `GTCGGGTCTGCGAGAGCGCCAGCTATCCTGAGGGAAACTTCGGAGGGAAC`

wurde von FastQC in manchen Samples als &uuml;berrepresentiert markiert. 

      | Sample               |   Count  | Percentage          |
      |----------------------|----------|---------------------| 
      | 00_Myclow-ctrl_A_1   |   71431  | 0.17136014485115192 |   
      | 01_Myclow-ctrl_A_2   |          |                     |
      | 02_Myclow-ctrl_A_3   |   94998  | 0.11580425382603367 |   
      | 03_MyclowIL10_B_1    |          |                     |
      | 04_MyclowIL10_B_2    |   60922  | 0.1731420284724594  |   
      | 05_MyclowIL10_B_3    |          |                     |
      | 06_MyclowCpG_C_1     |   50352  | 0.12451734444110872 |   
      | 07_MyclowCpG_C_2     |          |                     |
      | 08_MyclowCpG_C_3     |          |                     |
      | 09_MyclowIL10CpG_D_1 |          |                     |
      | 10_MyclowIL10CpG_D_2 |   52877  | 0.13767827718667536 |   
      | 11_MyclowIL10CpG_D_3 |          |                     |
      | 12_Mychigh-ctrl_E_1  |   59630  | 0.1290563500539762  |   
      | 13_Mychigh-ctrl_E_2  |          |                     |
      | 14_Mychigh-ctrl_E_3  |   95007  | 0.11733052511680535 |   
      |----------------------|----------|---------------------| 

Blast hat f&uuml;r diese Sequenz die folgenden Ergebnisse geliefert (100% query cover): 

      | Transcripts                                                     |Max.sc|Tot.sc|Query.cov| E.val | Iden |  Accession  |
      |----------------------------------------------------------------------------------------------------------------------|
      | Homo sapiens RNA, 45S pre-ribosomal 5 (RNA45S5), ribosomal RNA  | 99.6 | 99.6 |   100%  | 2e-19 | 100% | NR_046235.1 |
      | Homo sapiens RNA, 28S ribosomal 5 (RNA28S5), ribosomal RNA      | 99.6 | 99.6 |   100%  | 2e-19 | 100% | NR_003287.2 |
      |----------------------------------------------------------------------------------------------------------------------|
      | Genomic sequences                                               |Max.sc|Tot.sc|Query.cov| E.val | Iden |  Accession  |
      |----------------------------------------------------------------------------------------------------------------------|
      |HS.chr.21, GRCh38.p2 Primary Assembly                            | 99.6 | 541  |   100%  | 2e-19 | 100% | NC_000021.9 |
      |HS.chr.22 unloc.gen.scaf.GRCh38.p2 P.Ass.HSCHR22_UNLOCALIZED_CTG3| 99.6 | 199  |   100%  | 2e-19 | 100% | NT_187388.1 |
      |HS. unplac.gen.scaf. GRCh38.p2 P.Ass. HSCHRUN_RANDOM_CTG11       | 99.6 | 199  |   100%  | 2e-19 | 100% | NT_167214.1 |
      |----------------------------------------------------------------------------------------------------------------------|

Es k&ouml;nnte dann sich um rRNA-Kontamination handeln. 

## 2. rRNA-Kontamination. 

   Um rRNA-Kontamination zu untersuchen, wird die Sequenz 
[Human ribosomal DNA complete repeating unit](http://www.ncbi.nlm.nih.gov/nuccore/U13369.1)
benutzt. 

### 2.1. rRNA in GTF file

1. HumanDrosERCC.gtf file enth&auml;lt  570 entries mit:  idattr=gene_id & feature=exon & gene_biotype="rRNA"  & HUMAN
2. Von diesen Genen gibt es insgesamt 5764 counts (`FeatureCounts` output) von allen Samples die "rRNA-genen" entsprechen.


### 2.2. Biobloom tools. 

- 3 Filtern wurden von der rRNA-CRUnit Sequenz  mit `biobloommaker` erzeugt: 

      | Kmer-Groesse | Ziel           | 
      |--------------|----------------|
      |      25      | default        |
      |      10      | ++ sensitivity | 
      |      50      | ++ specificity | 
      |--------------|----------------|

- `biobloomcategorizer` ist  mit den 3 Filtern gelaufen auf Sample `00_Myclow-ctrl_A_1` `accepted_hits.bam`
   file. F&uuml;r jeden Filter ist ein score gew&auml;hlt:

      | Kmer-Groesse | score | Ziel           | 
      |--------------|-------|----------------|
      |      25      |  0.15 | default        |
      |      10      |  0.05 | ++ sensitivity | 
      |      50      |  0.5  | ++ specificity | 
      |--------------|-------|----------------|
      
   Zussamenfassung der Ergebnisse: 

      |              ==> 00_Myclow-ctrl_A_1_bbt_s0p05_summary.tsv <==             |
      |---------------------------------------------------------------------------|
      | filter_id         |    hits|  misses|shared|rate_hit|rate_miss|rate_shared|  
      | rRNA_CRUnit_kmer10|15178416|17948255|     0|0.458193| 0.541807|       0   |
      | multiMatch        |       0|33126671|     0|       0|        1|       0   |
      | noMatch           |17948255|15178416|     0|0.541807| 0.458193|       0   |
      |---------------------------------------------------------------------------|
      |              ==> 00_Myclow-ctrl_A_1_bbt_s0p5_summary.tsv <==              |
      |---------------------------------------------------------------------------|
      | filter_id         |    hits|  misses|shared|rate_hit|rate_miss|rate_shared|  
      | rRNA_CRUnit_kmer50|  642312|32484359|     0|0.019390|  0.98061|       0   |
      | multiMatch        |       0|33126671|     0|       0|        1|       0   |
      | noMatch           |32484359|  642312|     0|0.98061 | 0.019390|       0   |
      |---------------------------------------------------------------------------|
      |              ==> 00_Myclow-ctrl_A_1_bbt_summary.tsv <==                   |
      |---------------------------------------------------------------------------|
      | filter_id         |    hits|  misses|shared|rate_hit|rate_miss|rate_shared|  
      |-------------------|--------|--------|------|--------|---------|-----------|
      | rRNA_CRUnit_25    |  795573|32331098|     0|0.024016| 0.975984|       0   |
      | multiMatch        |       0|33126671|     0|       0|        1|       0   |
      | noMatch           |32331098|  795573|     0|0.975984|0.0240161|       0   |
      |---------------------------------------------------------------------------|


- Default Parametern (`score=0.15,kmer=25`) wurden f&uuml;r alle Samples benutzt. 
  (Nur _primary-alignments_ wurden ber&uuml;cksichtigt.)

      | Sample               | hits  |Percentage|exact hits| direct  |rev comple| 
      |----------------------|-------|----------|----------|---------|----------| 
      | 00_Myclow-ctrl_A_1   | 795573|    2.4   |   500606 |    31126|    469480|
      | 01_Myclow-ctrl_A_2   |1602122|    3.8   |  1068060 |   344059|    724001|
      | 02_Myclow-ctrl_A_3   |1895108|    3.0   |  1146257 |   371825|    774432|
      | 03_MyclowIL10_B_1    | 968817|    2.8   |   630844 |   113066|    517778|
      | 04_MyclowIL10_B_2    | 746450|    2.6   |   474447 |    24004|    450443|
      | 05_MyclowIL10_B_3    |2523834|    3.1   |  1563960 |   533120|   1030840|
      | 06_MyclowCpG_C_1     | 716420|    2.3   |   435953 |    38162|    397791|
      | 07_MyclowCpG_C_2     |1129302|    2.7   |   742852 |   195292|    547560|
      | 08_MyclowCpG_C_3     |1664487|    2.7   |   987757 |   190749|    797008|
      | 09_MyclowIL10CpG_D_1 |1300057|    2.3   |   840543 |   312406|    528137|
      | 10_MyclowIL10CpG_D_2 | 550167|    1.7   |   355474 |    16189|    339285|
      | 11_MyclowIL10CpG_D_3 |3152217|    3.0   |  1911667 |   685030|   1226637|
      | 12_Mychigh-ctrl_E_1  | 775083|    2.0   |   477019 |    19439|    457580|
      | 13_Mychigh-ctrl_E_2  |1058464|    2.6   |   728684 |   162746|    565938|
      | 14_Mychigh-ctrl_E_3  |2012209|    2.2   |  1152782 |    39789|   1112993|
      |----------------------|-------|----------|----------|---------|----------| 


 Man sieht eine erstaunliche Asymmetrie zwischen __"direct -- reverse complementary"__
Sequenzen. Es bleibt so wenn man direkt die fastq file als input gibt. Die Ergebnisse
f&uuml;r den Sample `00_Myclow-ctrl_A_1` sind (default Parametern): 


- Tophat2 auf `biobloomcategorizer` output. Align summary liefert:

```    Reads:
          Input     :    923653
           Mapped   :    795570 (86.1% of input)
            of these:    757804 (95.3%) have multiple alignments (0 have >20)
86.1% overall read mapping rate.
```
  95.3% haben "multiple alignments". Das ist zu erwarten, so Wikipedia: 

   _Eukaryotes generally have many copies of the rRNA genes organized in tandem 
   repeats; in humans approximately 300-400 repeats are present in five clusters 
   (on chromosomes 13, 14, 15, 21 and 22)._

Die Verteilung nach Chromosomen ist, 

      |---------------------------|
      | Chr |#align| Chr | #align | 
      |---------------------------|
      |   1 | 10702| 13  |     878|
      |   2 |  1917| 14  |     770|
      |   3 |  1797| 15  |     930|
      |   4 |  1792| 16  |    2129|
      |   5 |  1794| 17  |    1894|
      |   6 |  2686| 18  |     563|
      |   7 |  1885| 19  |    2560|
      |   8 | 10493| 20  |     958|
      |   9 |  2138| 21  | 2867084|
      |  10 |  1222| 22  |     699|
      |  11 |  1599|  X  |    1096|
      |  12 | 14128|  Y  |     170|
      |---------------------------|

### 2.3. FeatureCounts.
   
`*bam` output von Tophat2 in 2.2 wurde als input f&uuml;r  `FeatureCounts`
gegeben. Da es so viele _multiple alignments_ gibt (die nicht von `FeatureCounts` 
akzeptiert werden), werden die Mehrheit der Reads weggeschmissen. F&uuml;ur 
den Sample `00_Myclow-ctrl_A_1`. Output summary lautet, 

```
Assigned                  12421
Unassigned_Ambiguity        388
Unassigned_MultiMapping 2894120
Unassigned_NoFeatures     24957
Unassigned_Unmapped           0
Unassigned_MappingQuality     0
Unassigned_FragementLength    0
Unassigned_Chimera            0
Unassigned_Secondary          0
Unassigned_Nonjunction        0
Unassigned_Duplicate          0
```
Nur 12421 _"counts"_ wurden zugeordnet (0.42 %). 

### 2.4. Tophat2. 

Tophat2 wurde auch verwendet mit der 
_Human ribosomal DNA complete repeating unit_  
als Referenz-Sequenz. Align summary liefert: 

``` Reads:
        Input     :  41684722
         Mapped   :    690342 ( 1.7% of input)
          of these:       117 ( 0.0%) have multiple alignments (0 have >20)
1.7% overall read mapping rate.
```
- [ ] Den Output muss noch mit `biobloomcategorizer` verglichen werden. 

## 3. Konklusion. 

  Es gibt _"reads"_ von rRNA in den `*fq` files (~ 2 - 3% pro Sample). 
Die meisten f&uuml;hren zu _"multiple mapping"_. Das bedeutet sie werden
von FeatureCounts komplett vernachl&auml;ssigt. Es gibt aber immer noch 
Sequenzen die nur einmal auftauchen und die als rRNA gez&auml;hlt worden sind. 
Die sind ~ 0.03% des urspr&uuml;nglichen Inputs. 
