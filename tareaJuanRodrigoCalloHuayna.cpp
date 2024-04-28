//JUAN RODRIGO CALLO HUAYNA _SEGUNDO EJERCICIO
#include <iostream>
using namespace std;
void print_matriz(int **m, int f,int c){
	int **p= m;
	int *q=nullptr;
	while(p<m+f){
		q=*p;
		while(q<*p+c){
			cout<<*q++<<"\t";
		}
		cout<<"\n";
		p++;
	}
	cout<<"\n";
}
//matriz inicializada con ceros
int** new_matriz( int f,int c) {
	int **m = new int*[f];
	for (int i = 0; i < f; ++i) {
		m[i] = new int[c];
	}
	int **p = m;
	int *q = nullptr;
	while (p < m + f) {
		q = *p;
		while (q < *p + c) {
			*(q++)=0;
		}
		p++;
	}
	return m;
}
void change_matriz( int **m,int f,int c,int x_f,int x_c) {
	if(x_f>=f || x_c>=c||x_f<0||x_c<0 )
	{
		cout<<"Posicion fuera de rango\n\n";
		return;
	}
	int **p = m;
	int* q = *(p+x_f);
	*(q+x_c)=1;
}
int* getColumn(int **mat,int f, int c, int x){
	int *a=new int[f];
	int **p=mat;
	int *r=a;
	while(p<mat+f){
		*(r++)=*(*(p++)+x);
	}
	return a;
}
bool check_row(int **m,int f, int c){
	int **p = m;
	while (p < m + f) {
		int *q = *p;
		int contador=0;
		while (q < *p + c) {
			if(*(q++)==1)contador++;
			if(contador>1)return false;
		}
		p++;
	}
	return true;
}
bool check_col(int **m,int f, int c){
	int **p = m;
	int cont = 0;
	while (p < m + f) {
		int *matriz= getColumn(m, f,  c, cont);
		int *q=matriz;
		int contador=0;
		while (q < matriz + f) {
			if(*(q++)==1)contador++;
			if(contador>1)return false;
		}
		p++;
		cont++;
	}
	return true;
}
void chequeo_fila_columna(int **m,int f, int c){
	cout<<"\t\t\tChequeo de fila.\n";
	(check_row(m,f,c))?(cout<<"\t\t\tVerdadero"):(cout<<"\t\t\tFalso");
	cout<<"\n";
	cout<<"\t\t\tChequeo de columna.\n";
	(check_col(m,f,c))?(cout<<"\t\t\tVerdadero\n"):(cout<<"\t\t\tFalso\n");
}

int main() {
	int f=3;
	int c=2;
	int **nueva_m=new_matriz(f,c);
	print_matriz(nueva_m,f,c);
	chequeo_fila_columna(nueva_m,f,c);
	int x_f=2;
	int x_c=1;
	change_matriz(nueva_m,f,c,x_f,x_c);
	x_f=2;
	x_c=0;
	change_matriz(nueva_m,f,c,x_f,x_c);
	print_matriz(nueva_m,f,c);
	chequeo_fila_columna(nueva_m,f,c);
	x_f=0;
	x_c=0;
	change_matriz(nueva_m,f,c,x_f,x_c);
	print_matriz(nueva_m,f,c);
	chequeo_fila_columna(nueva_m,f,c);
	return 0;
}

