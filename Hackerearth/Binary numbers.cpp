#include<bits/stdc++.h>
using namespace std;

string getBinaryNumber(int k){
	int count = 0;
	queue<string> q;
	q.push("1");
	while(!q.empty()){
		string t = q.front();
		q.pop();
		count++;
		if(count == k) return t;
		int n = t.size();
		char last = t[n-1];
		q.push(t+"0");
		if(last == '0')
			q.push(t+"1");
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		cout << getBinaryNumber(k) << endl;
	}
	return 0;
}