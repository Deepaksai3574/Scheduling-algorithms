import random
import string
import time as t
import pandas as pd
import numpy as np
def stringregen(sequence,size):
    l = []
    
    if(size>len(sequence)):
        print('\nUNABLE TO GENERTAE K-MERS....')
        t.sleep(1)
        print("\nTry Again")
    else:
        for i in range(len(sequence)-size+1):
                   l.append(sequence[i:i+size])
        return l
length = int(input("Enter the size of DNA Sequence: "))
size = int(input("Enter the size of Kmer: "))
text = 'ATGC'
print("\nEnter 0 to give your own genome sequence and 1 to run random: ")
z = int(input())
if(z==0):
      print("\nEnter your genome sequence: ")
      sequence = str(input())
      print("\nLength of the sequence you have entered is: ",len(sequence))
      x = stringregen(sequence,size)
else:
    sequence = ''.join((random.choice(text))for x in range(length))
    t.sleep(2)
    print("GENERATING RANDOM SEQUENCE...............")
    t.sleep(1)
    print("\n\n")
    seq = print("Generated sequence is: \n",sequence)
    t.sleep(0.5)
print("\nNucleotide Details in the following string are: \n")
print("\nNo.of A's in the genome sequence are: ",sequence.count("A"))
t.sleep(0.2)
print("\nNo.of T's in the genome sequence are: ",sequence.count("T"))
t.sleep(0.2)
print("\nNo.of G's in the genome sequence are: ",sequence.count("G"))
t.sleep(0.2)
print("\nNo.of C's in the genome sequence are: ",sequence.count("C"))
t.sleep(0.01)
x = stringregen(sequence,size)
print("\nk-MER COMPOSITION OF THE SEQUENCE ENTERD IS \n\n",x)
print("\nK-mer count of the entire sequence are: ")
oop= pd.value_counts(np.array(x))
print(oop)
c = x[0]
for i in range(len(x)-1):
    if(x[i][1:]==x[i+1][:size-1]):
        c+=x[i+1][-1]
print("\nGETTING STRING REGENERATED........")
if(len(sequence)<50):
    t.sleep(1)
elif(len(sequence)>50&len(sequence)<10000):
    t.sleep(2)
else:
    t.sleep(3)
print("\nTHE REGENERATED STRING IS")
print("\n",c)
if(c==sequence):
    print("\nSTRING IS REGENERATED SUCCESSFULLY")
else:
    print("\nPROBLEM IN REGEENRATING THE STRING")    
