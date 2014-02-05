#include<stdio.h>

void main(){

	long long int num,a[100],cost,curr,i,j,k,count;
	num=0;
	k=0;
	curr=0;
	j=0;
	scanf("%lld",&num);
	k=num;
		for(i=0;i<k;i++){
		scanf("%lld ",&j);
		a[i]=j;}

   scanf("%lld",&cost);
		for(i=0;i<num;i++){
			if(a[i]<=-1)
			count++;}
		while(count!=0){

		if(cost<=num&&count!=0){
		
		if(count==num){
			for(i=0;i<num;i++){
			a[i]++;}
			curr=curr+cost;
			}
		else if(cost>count&&count!=num){
		for(i=0;i<num;i++){
		if(a[i]<=-1){
		a[i]++;
		curr=curr+1;
	 	i=num;}
		}
      }
		else if(cost<=count&&count!=num){
			for(i=0;i<num;i++){
			a[i]++;}
			curr=curr+cost;
			}
     }

		else if(cost>num&&count!=0){
			for(i=0;i<num;i++){
			if(a[i]<=-1){
			a[i]++;
			i=num;
			curr=curr+1;}
			}
		}
		count=0;
			for(i=0;i<num;i++){
			if(a[i]<=-1)
			count++;}
		}

  printf("%lld ",curr);

}
