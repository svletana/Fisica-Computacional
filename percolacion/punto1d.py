from subprocess import Popen, PIPE
from statistics import variance
import matplotlib.pyplot as plt
from math import log10

#punto 1
#resultados = []
#resultados.append(["L","vector clase","vector s"])

#for i in [4,16,32,64,128]:
def syns(L,pp):
    process = Popen(["./unod", str(L), "1", "1",str(pp)],stdout=PIPE)
    out = process.stdout.read()
    data = str(out).split("\\n\\n")

    #vector clase
    etiquetas = data[0].split(",")
    etiquetas.pop()
    etiquetas[0] = etiquetas[0][2:]
    etiquetas.remove(etiquetas[0])
    etiquetas = [int(i) for i in etiquetas]

    #vector s
    s = data[1].split(',')
    s.remove(s[0])
    s.remove(s[-1])
    s = [int(i) for i in s]

    csize = []
    for i in range(len(s)):
        if etiquetas[i]>1 and s[i] not in csize:
            csize.append(s[i])

    ns = []
    for i in csize:
        ns.append(s.count(i))

    return csize,ns

#spc,nspc = syns(40,0.59)
s,ns = syns(90,0.55)
plt.plot(s,ns,'ok')
plt.yscale('log')
plt.xscale('log')
plt.show()
