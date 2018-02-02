#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int longestUniqueStr(char *s){
	int n = strlen(s);
	int curLen = 1;
	int maxLen = 1;
	int prevIndex;
	int i;
	int *visited = (int *)malloc(sizeof(int)*50);
	for(i=0;i<50;i++){
		visited[i] = -1;
	}
	visited[s[0]] = 0;
	for(i=1;i<n;i++){
		prevIndex = visited[s[i]];
		if(prevIndex == -1 || i - curLen > prevIndex){
			curLen++;
		}
		else{
			if(maxLen < curLen){
				maxLen = curLen;
			}
			curLen = i - prevIndex;
		}
		visited[s[i]] = i;
		
	}
	if(curLen > maxLen){
		maxLen = curLen;
	}
	return maxLen;
}

int main(){
	 char str[] = "pwwkew";
    printf("The input string is %s \n", str);
    int len = longestUniqueStr(str);
    printf("The length = %d", len);
    return 0;
}
