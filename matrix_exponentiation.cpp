#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define N 50
using namespace std;

ll arr[N][N], I[N][N];
ll n, dim;

void multiply(ll A[][N], ll B[][N], ll dim){
	ll res[N][N];
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			res[i][j] = 0;
			for(int k = 0; k < dim; k++){
				res[i][j] = (res[i][j] +  (A[i][k] * B[k][j]) % mod) % mod;
			}
		}
	}

	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			A[i][j] = res[i][j];
		}
	}
}

void power_linear(ll A[][N], ll n, ll dim){
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			if(i == j) I[i][j] = 1;
			else I[i][j] = 0;
		}
	}

	/* linear exponentiation */
	for(int i = 0 ; i < n; i++){
		multiply(I, A, dim);
	}

	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			A[i][j] = I[i][j];
		}
	}
}

void power_fast(ll A[][N], ll n, ll dim){
	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			if(i == j) I[i][j] = 1;
			else I[i][j] = 0;
		}
	}

	/* Fast matrix exponentiation */
	while(n){
		if(n % 2 == 1) multiply(I, A, dim), n--;

		multiply(A, A, dim);
		n >>= 1;
	}

	for(int i = 0; i < dim; i++){
		for(int j = 0; j < dim; j++){
			A[i][j] = I[i][j];
		}
	}
}
 

int main() {
	// your code goes here

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	#endif

	int t;
	cin>>t;


	while(t--){
	    cin >> dim >> n;
	    for(int i = 0; i < dim; i++){
	    	for(int j = 0; j < dim; j++){
	    		cin >> arr[i][j];
	    	}
	    }

	    // power_linear(arr, n, dim);
	    power_fast(arr, n, dim);

	    for(int i = 0; i < dim; i++){
	    	for(int j = 0; j < dim; j++){
	    		cout << arr[i][j] << " ";
	    	}
	    	cout << endl;
	    }

	}
	return 0;
}  