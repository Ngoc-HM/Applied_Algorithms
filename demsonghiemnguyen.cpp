#include <iostream>
using namespace std;
const int MAXN = 100;
int A[100], X[100], t[100];
int N,M;
int B = 0; 
int result = 0;

void solution(){
	if (B == M) result++;
}

void initT(){
	t[1] = A[1];
	for (int i=2; i<=N; i++) t[i] = t[i-1]+A[i];
}

void Try(int i){
	int v;
	for (int v = 1; v <= (M-B-(t[N]-t[i]))/A[i]; v++){
		X[i] = v;
		B += A[i]*X[i];
		if (i == N){
			solution();
		}
		else Try(i+1);
		B -= A[i]*X[i];
	}
}

int main(){
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> A[i];
	initT();
	Try(1);
	cout << result;
	
}