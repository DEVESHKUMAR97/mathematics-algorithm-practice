#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin >> str;
    int n;
    n = str.length();
    int T[n][n];
    int last[n][n][26];
    // int lastf[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // lastf[i][j] = 0;
            for(int k = 0; k < 26; k++){
                last[i][j][k] = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        T[i][i] = 0;
    }

    int j, len , i, k;
    for(len = 2; len <= n; len++){
        for (i=0; i < n - len + 1; i++) 
        { 
            j = i + len - 1; 
            if (str[i] == str[j] && len == 2){
                T[i][j] = 2; 
                last[i][j][str[i] - 'a']++;
            }
            else if (str[i] == str[j]){
                for(k = 0; k < 26; k++){
                    if(last[i + 1][j - 1][k] > 0 && k != str[i] - 'a'){
                        T[i][j] = T[i+1][j-1] + 2;
                        last[i+1][j-1][str[i] - 'a'] = 0;
                        last[i][j][str[i] - 'a']++;
                        break;
                    }
                }
                if(k == 26){
                    for(k = 0; k < 26; k++){
                        last[i][j][k] = last[i+1][j-1][k];
                    }
                    last[i][j][str[i] - 'a'] = 1;
                }
                 
            }
            else{
                if(T[i][j-1] > T[i+1][j]){
                    T[i][j] = T[i][j - 1];
                    for(k = 0; k < 26; k++){
                        last[i][j][k] = last[i][j-1][k];
                    }
                } else if(T[i][j-1]< T[i+1][j]){
                    T[i][j] = T[i + 1][j];
                    for(k = 0; k < 26; k++){
                        last[i][j][k] = last[i+1][j][k];
                    }
                } else {
                    T[i][j] = T[i][j - 1];
                    for(k = 0; k < 26; k++){
                        last[i][j][k] = last[i][j-1][k];
                        last[i][j][k] += last[i+1][j][k];
                    }
                }
                // T[i][j] = max(T[i][j-1], T[i+1][j]); 
            }
 
            // if (str[i] == str[j] && len == 2) 
            //     T[i][j] = 2; 
            // else if (str[i] == str[j]) 
            //     T[i][j] = T[i+1][j-1] + 2; 
            // else
            //     T[i][j] = max(T[i][j-1], T[i+1][j]); 
        }
    }


    cout << T[0][n-1] << endl;

    return 0;
}


























