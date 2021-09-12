#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int A[n],B[n],C[n];
	for(int i=0;i!=n;i++){
		cin>>A[i];
	}
	for(int i=0;i!=n;i++){
		cin>>B[i];
		C[i]=B[i]+A[i];
	}
	for(int i=0;i!=n;i++){
		cout<<C[i]<<" ";
	}
	return 0;
}