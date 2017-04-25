from subprocess import Popen, PIPE
import matplotlib.pyplot as plt

sigma = 1.421875

def obtener_curva(npc,np):
    L = len(npc)
    F = [0 for i in range(L)]
    S = [0 for i in range(L)]

    for i in npc:
        if i!=0:
            u = npc.index(i)
            F[u] = np[u]/npc[u] #que pasa si np[u] no existe...?
            S[u] = u #vector de tamaños de fragmentos

    return S,F

def obtener_ns(i):
    process = Popen(["./out", "1000", "1", "1", i],stdout=PIPE)
    out = process.stdout.read()
    data = str(out).split("FIN")

    #print(len(data))

    #vector clase
    etiquetas = data[0].split(',')
    etiquetas.remove(etiquetas[0])
    etiquetas.remove(etiquetas[-1])
    etiquetas = [int(i) for i in etiquetas]
    etiquetas = list(filter(lambda a: a > 0 , etiquetas))

    #vector s
    sizes = data[1].split(',')
    sizes.remove(sizes[0])
    sizes.remove(sizes[-1])
    sizes = [int(i) for i in sizes]
    sizes = list(filter(lambda a: a != 0, sizes))

    #etiqueta percolante
    perco = data[2]

    proba = data[3]
    #print(proba)

    s = []
    for i in sizes:
        if i!=0 and i not in s:
            s.append(i)
            #ns.append(sizes.count(i))


    L = max(s)
    ns = [0 for i in range(L)]
    for i in range(1,L+1):
        if i in s:
            ns[i-1] = sizes.count(i)

    return s,ns

spc,nspc = obtener_ns("0.5927")
#sp_3,nsp_3 = obtener_ns("0.3")
sp_5,nsp_5 = obtener_ns("0.5")
#sp_6,nsp_6 = obtener_ns("0.6")
#sp_7,nsp_7 = obtener_ns("0.7")

S,F = obtener_curva(nspc,nsp_5)

SS = [(0.5-0.5927)*i**sigma for i in S]

plt.plot(S,F,'o')
plt.show()
