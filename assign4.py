import re
import string
import sys
import matplotlib.pyplot as plt
import matplotlib.legend as legend
import numpy as np
import operator
import argparse
import json
from operator import itemgetter
from pprint import pprint
from matplotlib.backends.backend_pdf import PdfPages

data = json.load(sys.stdin)
data = dict(data)


g = []
h = []
for key, value in sorted(data.iteritems(), key=lambda (k,v): (v,k), reverse=True):
    g.append(key)
    h.append(value)
for i in range(len(h)):
        h[i] = round(h[i],4)
        h[i] = (float)(h[i]/17354)
j = np.cumsum(h)
print j
      
with PdfPages('Graph_pdf.pdf') as pp:	
    plt.figure(1)
    plt.figure(figsize=(80,80))
    plt.plot(h, "red",label = "PDF")
    plt.legend()
    plt.rc('legend', fontsize=100)
    plt.title('word frequency',fontsize=100)
    plt.xticks(range(len(g)),g,rotation='vertical',fontsize = 5)
    plt.xlabel('word',fontsize=80)
    plt.ylabel('Probability',fontsize=80)
    plt.legend(loc=1)
    pp.savefig()
    plt.figure(2)
    plt.figure(figsize=(80,80))
    plt.plot(j, "blue",label = "CDF")
    plt.legend()
    plt.rc('legend', fontsize=100)
    plt.title('word frequency',fontsize=100)
    plt.xticks(range(len(g)),g,rotation='vertical',fontsize = 5)
    plt.xlabel('word',fontsize=80)
    plt.ylabel('Cumulative value',fontsize=80)    
    plt.legend(loc=1)
    pp.savefig()
    plt.show()

