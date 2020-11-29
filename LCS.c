//lcs: dynamic programming
#include<stdio.h>
#include<string.h>
#define MAX 50

int L[MAX][MAX];

int max(int a, int b){
	return a>b?a:b;
}

void lcs(char*a,char*b,int r,int c){
	int i,j;
	for(i=1;i<r;i++){
		for(j=1;j<c;j++){
			if(a[i-1]==b[j-1]){
				L[i][j]=1+L[i-1][j-1];
			}
			else{
				L[i][j]=max(L[i-1][j],L[i][j-1]);
			}
		}
	}
}

int main(){
	char s1[MAX];
	char s2[MAX];
	char ans[MAX];
	char ans2[MAX];
	int i,j,k;
	printf("Enter two strings:\n");
	fgets(s1,MAX,stdin);
	fgets(s2,MAX,stdin);
	lcs(s1,s2,strlen(s1),strlen(s2));
	//printf("str1:%sstr2:%s",s1,s2);
	/*printf("TABLE:\n");
	for(i=0;i<strlen(s1);i++){
		for(j=0;j<strlen(s2);j++){
			printf("%d  ",L[i][j]);
		}
		printf("\n");
	}*/
	//finding lcs
	i=strlen(s1)-1;
	j=strlen(s2)-1;
	k=L[strlen(s1)-1][strlen(s2)-1];
	ans[k]='\0';
	k--;
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			ans[k--]=s1[i-1];
			i--;
			j--;
		}
		else if(L[i-1][j]>L[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}
	printf("LCS:\n%s",ans);
	i=strlen(s1)-1;
	j=strlen(s2)-1;
	k=L[strlen(s1)-1][strlen(s2)-1];
	ans2[k]='\0';
	k--;
	while(i>0 && j>0){
		if(s1[i-1]==s2[j-1]){
			ans2[k--]=s1[i-1];
			i--;
			j--;
		}
		else if(L[i-1][j]<L[i][j-1]){
			j--;
		}
		else{
			i--;
		}
	}
	if(strcmp(ans,ans2)==0){
		return 0;
	}
	printf("\n%s",ans2);
	return 0;
}
