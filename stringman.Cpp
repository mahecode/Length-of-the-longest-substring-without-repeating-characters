#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int lengthLStr(string s){
	bool flag[256] = {false};
	int n = s.length();
	int result = 0;
	int start =0;
	for(int i = 0; i< n;i++){
		char current = s[i];
		if(flag[current]){
			result = max(result,i - start);
			for(int k=start;k<i;k++){
				if(s[k]==current){
					start = k + 1;
					break;
				}
				flag[s[k]] = false;
			}
		}
		else{
			flag[current] = true;
		}
	}
	result = max(n - start,result);
	return result;
}
int main(){
	string x = "abcabcabcbb";
	int m = lengthLStr(x);
	cout << "Length: " << m;
	return 0;
}
