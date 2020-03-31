import re
import string
import sys
import matplotlib.pyplot as plt
import matplotlib.legend as legend
import numpy as np
import operator
import argparse
from operator import itemgetter


inFile = sys.argv[1]
frequency = {}
   
with open(inFile,'r') as i:
    text_string = i.read().lower()


    match_pattern = re.findall(r"\w+'\w+|\w+@\w+|\w+|\w+-\w+|\w+[.]\w+", text_string)

    for word in match_pattern:
        count = frequency.get(word,0)
        frequency[word] = count + 1
    g = []
    h = []
    for key, value in sorted(frequency.iteritems(), key=lambda (k,v): (v,k), reverse=True):
        g.append(key)
        h.append(value)
    k = np.cumsum(h)
    for i in range(len(h)):
        h[i] = round(h[i],4)
        h[i] = (float)(h[i]/17353)
    j = np.cumsum(h)
    

    plt.figure(1)
    plt.figure(figsize=(80,80))
    plt.plot(h, "red",label = "PDF")
    plt.title('word frequency')
    plt.xticks(range(len(g)),g,rotation='vertical',fontsize = 5)
    plt.xlabel('word')
    plt.ylabel('Probability')
    plt.legend(loc=1)
    plt.figure(2)
    plt.figure(figsize=(80,80))
    plt.plot(j, "blue",label = "CDF")
    plt.title('word frequency')
    plt.xticks(range(len(g)),g,rotation='vertical',fontsize = 5)
    plt.xlabel('word')
    plt.ylabel('Cumulative value')
    plt.legend(loc=1)
    plt.show()

