import matplotlib.pyplot as plt

arc = open("sarasa.txt","r")
data = arc.read().split('\n\n')
data.pop()

cluster = int(input("cluster a observar: "))
sigma = 0.3956043956
pc = 0.59
threshold = 0.01

prob = [] #probabilidades
ns = [] #ns

nspc=0
for i in data:
    u = i.split('\n')
    probactual = float(u[0])
    prob.append(probactual) #agrego probabilidad al array prob -> para aeje x

    s = u[1].split(',')
    s.pop()
    s = [int(i) for i in s]

    ns.append(s.count(cluster)) #ns(p) para s=cluster

    if probactual > (pc - threshold) and probactual < (pc - threshold):
        nspc = s.count(cluster)

x = [((i-pc)/pc)*cluster**sigma for i in prob]

if nspc!=0:
    y = [i/nspc for i in ns]
else:
    y = ns

plt.plot(x,y,'o')
plt.show()
