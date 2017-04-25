from subprocess import Popen, PIPE
from statistics import variance

#punto 1
resultados = []
resultados.append(["L", "promedio","dispersion"])

for i in [4,16,32,64,128]:
    process = Popen(["./pro", str(i), "10000", "1000", "5.0"],stdout=PIPE)
    out = process.stdout.read()
    data = str(out).split("\\n\\n")

    #valores pc para sacar dispersion
    datos = data[0].split(",")
    datos[0] = datos[0][2:]
    datos.pop()
    datos = [float(i) for i in datos]

    #promedio pc's
    avg = float(data[1][:-1])

    #print(datos)
    #print("\n")
    #print("promedio: {}".format(avg))

    var = variance(datos)
    #print(var)
    resultados.append([i,avg,var])

arch = open("punto1ac.txt","w")
for line in resultados:
    arch.write(str(line))
    arch.write("\n")
arch.close()
