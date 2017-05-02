/*VARIABLES GLOBALES*/
extern int *clase;
extern int *s;

void  llenar(int *red,int n,float prob); //done
int   hoshen(int *red,int n); //done
int   actualizar(int *red,int *clase,int s,int frag); //done
void  etiqueta_falsa(int *red,int *clase,int s1,int s2,int n); //done
void  corregir_etiqueta(int *red,int *clase,int n);
int percola(int *red, int*perco, int n);
void  imprimir(int *red,int n); //done
int   *masa(int *red, int *clase, int n);
int count(int *s, int n);

