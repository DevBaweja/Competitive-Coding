#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int t;
    cin >> t;
    int rotate = 0;
    while (t--)
    {
        char type;
        cin >> type;
        int k;
        cin >> k;
        if (type == 'l')
            rotate += k;
        if (type == 'r')
            rotate += (n - k);
        rotate %= n;
    }
    /*
	queue<char> q;
	for(char el: s)
		q.push(el);
	while(rotate--){
		char h = q.front();
		q.pop();
		q.push(h);
	}
	string res = "";
	while(!q.empty()){
		char h = q.front();
		q.pop();
		res += h;
	}
	*/

    cout << s.substr(rotate, n - rotate) << s.substr(0, rotate);
}