import matplotlib.pyplot as plt
from numpy import polyfit, poly1d
from math import log10

arc = open("out1d.txt","r")
data = arc.read().split('\n\n')
data.pop()

probs = []
s = []
sarray = []
ns = []

for i in data:
    ps = i.split('\n')
    probs.append(float(ps[0]))

    s = ps[1].split(',')
    s.pop()
    s = [int(i) for i in s]
    u = list(set(s))
    sarray.append(u)

    nns = []
    for t in u:
        nns.append(s.count(t))

    ns.append(nns)

    #paso los vectores u y nns a escala logaritmica
    u = [log10(t) for t in u]
    nns = [log10(t) for t in nns]

    up = []
    nnsp=[]
    for y in nns:
        if y>0.5: #discrimino algunos valores para el ajuste
            ind = nns.index(y)
            up.append(u[ind])
            nnsp.append(y)


fit = polyfit(up,nnsp,1)
print(fit)
fitfunc = poly1d(fit)

plt.plot(u,nns,'ob')
plt.plot(up,fitfunc(up),'-r',linewidth=1.3)
plt.text(2.0,1.0,r'$valor\ \tau={0:.2f}$'.format(-fit[0]),size='large')
plt.ylabel(r'$n_{s}(p) (log)$')
plt.xlabel(r'$s (log)$')
plt.show()
