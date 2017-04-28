from statistics import variance

arch = open("output.txt","r")
data = arch.read().split("\n\n")
pcs = data[0].split(',')
pcs.pop()
pcs = [float(i) for i in pcs]
var = variance(pcs)
print(var)

promedio = float(data[1][10:])
print(promedio)
