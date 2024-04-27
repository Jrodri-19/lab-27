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
int productPunto(int *a1,int *a2,int n){
	int *p1=a1;
	int *p2=a2;
	int suma=0;
	while(p1<a1+n){
		suma+=(*(p1++)**(p2++));
	}
	return suma;
}
		
int **multmatrices(int **m1,int **m2,int f_m1,int c_m1,int f_m2,int c_m2){
	if(c_m1!=f_m2)return NULL;
	
	int **result= new int *[f_m1];
	for (int i = 0; i < f_m1; ++i) {
		result[i] = new int[c_m2];
	}
	int **rf=result;
	int *rc=nullptr;
	int **p1=m1;
	int contador=0;
	while(rf<result+f_m1){
		rc=*rf;
		while(rc<*rf+c_m2){
			*(rc++)=productPunto(*p1,getColumn(m2,f_m2,c_m2,(contador)%c_m2),c_m1);
			contador++;
		}
		rf++;
		p1++;
	}
	return result;
	
}
int main() {
	int m1[3][3]={{2,3,5},{6,1,0},{2,3,4}};
	int m2[3][2]={{4,2},{1,9},{0,7}};
	int **arr1= new int *[3];
	for(int i=0;i<3;i++){
		arr1[i]=m1[i];
	}
	int **arr2= new int *[3];
	for(int i=0;i<3;i++){
		arr2[i]=m2[i];
	}
	cout<<"\t\tMultiplicacion de matrices\n\nMatriz 1 \n\n";
	print_matriz(arr1,3,3);
	cout<<"\nMatriz 2 \n\n";
	print_matriz(arr2,3,2);
	int**result=multmatrices(arr1,arr2,3,3,3,2);
	cout<<"\nMultilicacion \n\n";
	if(result == NULL){
		cout<<"No Se puede";
	}else{
		print_matriz(result,3,2);
	}
	return 0;
}
