//The Coin Tracking Problem
#include<stdio.h>
#include<stdlib.h>
int *coin=NULL;
int *value=NULL;
int *track=NULL;
int exchange(int m,int n){
	int i,t=0,min,temp;
	for(i=n-1;i>=0;i--){
		if(m-coin[i]>=0){
			temp=exchange(m-coin[i],n)+1;
			if(t==0){
				min=temp;
				value[m]=i;
			}
			else if(min>temp){
				min=temp;
				value[m]=i;
			}
				
			t++;	
		}
	}	
	if(t==0){
		return 0;
	}
	else{
		return min;
	}
}
void count(int m){
	int i=m;
	while(i!=0){
		track[value[i]]+=1;
		i=i-coin[value[i]];
	}
}
int main(){
	int n,i,m;
	printf("\nEnter How Many Coins:");
	scanf("%d",&n);
	coin=(int *)malloc(sizeof(int)*n);
	track=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){
		track[i]=0;
	}
	printf("\n Enter the values:");
	for(i=0;i<n;i++){
		scanf("%d",&coin[i]);
	}
	printf("Enter Money:");
	scanf("%d",&m);
	value=(int *)malloc(sizeof(int)*(m+1));
	printf("%d",exchange(m,n));
	printf("\n");
	count(m);
	printf("\n");
	printf("\n Please give the customer in exchange:");
	for(i=0;i<n;i++){
		if(track[i]!=0){
			printf("\n %d value->%d coins",coin[i],track[i]);
		}
	}
}
