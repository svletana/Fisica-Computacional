import matplotlib.pyplot as plt
from math import log10
from numpy import polyfit, poly1d

#valores de p maximo obtenidos para 1<s<=15 --> Pmax
Pmax = [6.43693901,5.999803304,5.250701066,5.192645215,4.916849015,4.950617284,4.87406015,4.900816803,4.705146036,4.661716172,4.091680815,4.133466135,4.344743276,4.891975309]
s = [2,3,4,5,6,7,8,9,10,11,12,13,14,15]

Pc = 0.593

s = [log10(i) for i in s]
y = [log10(j-Pc) for j in Pmax]

fit = polyfit(s,y,1)
print(fit)
fitfunc = poly1d(fit)

plt.plot(s,y,'o')
plt.plot(s,fitfunc(s),'-r',linewidth=2.0)
plt.text(0.4,0.55,r'$\sigma={0:.4f}$'.format(-fit[0]),size='large')
plt.xlabel("s (log)")
plt.ylabel("$P_{max} - P_c (log)$")
plt.show()
