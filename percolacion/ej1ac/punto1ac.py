from statistics import variance

arch = open("output.txt","r")
data = arch.read().split("\n\n")
pcs = data[0].split(',')
pcs.pop()
pcs = [float(i) for i in pcs] #tira de datos de pc obtenidos

var = variance(pcs) #dispersion
print(var)

promedio = float(data[1][10:]) #promedio
print(promedio)
