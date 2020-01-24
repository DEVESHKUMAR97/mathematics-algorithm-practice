#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int maxrange = 90000000;
vector<int> prime;


void sieve(bool *p){
	// initiallization : let all odd nos are prime
	for(ll i = 3; i <= maxrange; i += 2){
		p[i] = 1;
	}

	for(ll i = 3; i * i <= maxrange; i += 2){

		// if the number is still a prime
		if(p[i] == 1){
			for(ll j = i * i; j <= maxrange; j += i){
				p[j] = 0;
			}
		}
	}

	// special case
	p[2] = 1;
	p[0] = p[1] = 0;

	for(int i = 2; i <= maxrange; i++){
		if(p[i] == 1)
			prime.push_back(i);
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

	bool p[maxrange + 1] = {0};
	sieve(p); // O(nlog(log(n)))

	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		cout << prime[k - 1] << endl;
	}
	return 0;
}  
