# Bowtie2
# Language: C++
# Input: TXT
# Output: PREFIX
# Tested with: PluMA 1.0, GCC 4.8.4
# Dependency: Bowtie 2.2.3

PluMA plugin that interfaces to Bowtie2 (Langmead et al, 2009).

The plugin accepts as input a text file of keyword-value pairs,
tab-delimited:

db: Database
sequences: FASTQ file of sequences or sequences1/2: forward/reverse
threads: Number of threads (optional)
all: True or False (optional)
atleast: int (optional)
local: True or False (optional)
processors: int (number of processors, optional)
veryfastlocal: True or False (optional)
nodiscordant: True or False (optional)
verysensitive: True or False (optional)
nomixed: True or False (optional)
nounal: True or False (optional)
reorder: True or False (optional)

Output files will be SAM format, using the user-specified prefix
