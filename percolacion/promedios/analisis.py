import matplotlib.pyplot as plt
from os import listdir
from os.path import isfile, join
from statistics import variance, mean

def read_data(data):
  path = "/home/lusia/Documents/Fisica-Computacional/percolacion/promedios"
  archv = open(path + '/' + data)
  dats = archv.read().split('\n')

  header = dats[:2]
  contents = dats[3:-3]
  avg = float(dats[-2][-7:])

  archv.close()

  contents = [float(i) for i in contents]
  #plt.hist(contents)
  #plt.title(data)
  #plt.show()
  print(data)
  print("promedio: {}".format(avg))
  print("mean: {}".format(mean(contents)))
  print("dispersion: {}".format(variance(contents)))


path = "/home/lusia/Documents/Fisica-Computacional/percolacion/promedios"
archivos = [f for f in listdir(path) if isfile(join(path,f)) and f[-2:]!='py']
for i in archivos:
    read_data(i)
#read_data("256x256_p")
