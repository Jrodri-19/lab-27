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
	int *q = nullptr;
	bool respuesta=true;
	while (p < m + f) {
		q = *p;
		while (q < *p + c) {
			if(*(q++)==1)!respuesta;
			if(respuesta)return !respuesta;
		}
		p++;
	}
	return true;
}
bool check_col(int **m,int f, int c){
	bool respuesta=true;
	int **p = m;
	int *q = nullptr;
	int cont = 0;

	while (p < m + f) {
		int* matriz = getColumn(m, f,  c, (cont++)%c);
		q=matriz;
		while (q < matriz + c) {
			if(*(q++)==1)!respuesta;
			if(respuesta)return !respuesta;
		}
		p++;
	}
	return true;
}
int main(int argc, char *argv[]) {
	int f=3;
	int c=2;
	int **nueva_m=new_matriz(f,c);
	print_matriz(nueva_m,f,c);
	
	int x_f=2;
	int x_c=1;
	change_matriz(nueva_m,f,c,x_f,x_c);
	 x_f=2;
	 x_c=0;
	change_matriz(nueva_m,f,c,x_f,x_c);
	print_matriz(nueva_m,f,c);
	
	(check_row(nueva_m,f,c))?(cout<<"Verdadero"):(cout<<"Falso");
	cout<<"\n";
	x_f=0;
	x_c=0;
	change_matriz(nueva_m,f,c,x_f,x_c);
	print_matriz(nueva_m,f,c);
	(check_col(nueva_m,f,c))?(cout<<"Verdadero"):(cout<<"Falso");
	return 0;
}
