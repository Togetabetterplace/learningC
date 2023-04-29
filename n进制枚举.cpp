#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
//#include<bits/stdc++.h>
#define ll long long
#define N 10000
#define num 2
stack<int>s;
int main() {
	int n = 0;
	while (scanf ("%d", &n) != EOF) {
		int a=0,b=0;
		while(b<pow(num,n)){
			a=b;
			for(int i=0;i<n;i++){
				s.push(a%num);
				a/=num;
			}
			for(int i=0;i<n;i++){
				int q=s.top();
				printf("%d",q);
				s.pop();
			}
			printf("\n");
			b++;
		}
	}
	return 0;
}
/*

 */
