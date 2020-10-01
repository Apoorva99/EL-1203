#include<bits/stdc++.h>
using namespace std;
/*

input
Code

output
CCoCode

*/
int main(){
	string s;
	cin>>s;
	string res="";
	for(int i=0;i<s.length();i++){
		res += s.substr(0,i+1);
	}
	cout<<res<<endl;
	return 0;
}