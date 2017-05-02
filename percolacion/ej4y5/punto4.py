### EJERCICIO 4 ###
import matplotlib.pyplot as plt
from math import log10
from numpy import polyfit, poly1d

arc = open("data64z300p600","r")
data = arc.read().split('return')
data.pop() #good

cluster = [41,42,43,44,45] #clusters a observar
sigma = 0.3956043956 # valor teorico del exp critico sigma
pc = 0.593381
threshold = 0.025

for clus in cluster:
    prob = [] #probabilidades
    ns = []

    nspc=0
    for i in data:
        u = i.split('fin')
        probactual = float(u[0])
        prob.append(probactual) #agrego probabilidad al array prob -> para eje x

        ### grupos de vectores s ###
        sgroup = u[1].split('\n')
        if '' in sgroup:
            sgroup.remove('')

        ### nns -> promedio de ns que va a ns para esa probabilidad ###
        L = len(sgroup)
        temp = []
        for r in sgroup:
            r=r.split(',')
            if '' in r:
                r.remove('')
            if ',' in r:
                r.remove(',')
            r = [int(y) for y in r]
            temp.append(r.count(clus))

        ns.append(float(sum(temp))/L)


    x = [((i-pc)/pc)*clus**sigma for i in prob]
    for i in x:
        if i>-threshold and i<threshold:
            cero = x.index(i)

    norm = ns[cero]
    y = [i/norm for i in ns]
    #y = ns

    plt.plot(x,y,'o',label=str(clus))
    plt.ylabel(r'$<n_{s}(p)>/<n_{s}(p_c)>$')
    plt.xlabel(r'$s^{\sigma}\epsilon$')

plt.legend()
plt.show()
