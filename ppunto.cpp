#include <iostream>
using namespace std;
int productPunto(int *a1,int *a2,int n){
	int *p1=a1;
	int *p2=a2;
	int suma=0;
	while(p1<a1+n){
		suma+=(*(p1++)**(p2++));
	}
	return suma;
}

int main() {
	int arr1[]={2,3,5};
	int arr2[]={4,1,0};
	cout<<"Producto punto ->\t"<<productPunto(arr1,arr2,3);
	return 0;
}
