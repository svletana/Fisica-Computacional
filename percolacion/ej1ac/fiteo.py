import matplotlib.pyplot as plt
from numpy import polyfit, poly1d
from numpy import log10

disp = [0.00474064357754146,0.0018532088678616875,0.0007040579496844691,0.0002763793349900241,0.00027574297570012] # valores de dispersion obtenidos
pc = [0.58286,0.586175,0.59377,0.593381,0.593474] # probabilidades criticas

#hago el fiteo lineal a los datos anteriores
fit =polyfit(disp,pc,1)
print(fit)
fitfunc = poly1d(fit)

pcinf = float(fit[1]) #ordenada al origen --> Pc(inf)

#ploteo
plt.plot(disp,pc,'bo')
plt.plot(disp,fitfunc(disp),'-r')
plt.text(0.003,0.592,r'$P_c(\infty)={0:.4f}$'.format(fit[1]),size='large')
plt.xlabel(r'$dispersión$')
plt.ylabel(r'$P_c(L)$')
plt.show()
