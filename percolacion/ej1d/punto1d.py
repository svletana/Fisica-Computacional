import matplotlib.pyplot as plt
from numpy import polyfit, poly1d
from math import log10

arc = open("out1d.txt","r")
data = arc.read().split('\n\n')
data.pop()
probs = []
s = []
for i in data:
    ps = i.split('\n')
    probs.append(float(ps[0]))
    s = ps[1].split(',')
    s.pop()
    s = [int(i) for i in s]
    u = list(set(s))

ns = []
for i in u:
    ns.append(s.count(i))

u = [log10(i) for i in u]
ns = [log10(i) for i in ns]

uu=[]
nns=[]
for i in ns:
    if i!=0:
        nns.append(i)
        uu.append(u[ns.index(i)])

fit = polyfit(uu,nns,1)
print(fit)
fitfunc = poly1d(fit)

plt.plot(u,ns,'o')
#plt.plot(uu,nns,'or')
plt.plot(uu,fitfunc(uu),'--r')
plt.show()
