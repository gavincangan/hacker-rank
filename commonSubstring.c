#include<stdio.h>

void main(){
char a[75],b[75];
int mat[75][75]={0};
int i=1,j=1,max=0,maxi=0,maxj=0;

printf("String 1: ");
gets(a);
printf("String 2: ");
gets(b);

for(i=0;a[i];i++)
if(a[i]==b[0])
mat[i][0]= 1;

for(j=0;b[j];j++)
if(a[0]==b[j]) 
mat[0][j]= 1;

for(i=1;a[i];i++){
for(j=1;b[j];j++){
if(a[i]==b[j]){
mat[i][j]= mat[i-1][j-1] + 1;
//printf("\n %c  a->%d  b->%d",a[i],i,j);
}}}

printf("\n");

printf("    ");
for(j=0;b[j];j++)
printf("%3d",j);
printf("\n");

printf("    ");
for(j=0;b[j];j++)
printf("  %c",b[j]);
printf("\n");

for(i=0;a[i];i++){
printf("%2d %c",i,a[i]);
for(j=0;b[j];j++){
printf("%3d",mat[i][j]);}
printf("\n");}

for(i=0;a[i];i++){
for(j=0;b[j];j++){
if(mat[i][j]>max){
max=mat[i][j];
maxi=i;
maxj=j;}
}}

printf("\n\nmax=%d\tmaxi=%d\tmaxj=%d\n\n",max,maxi,maxj);

printf("Longest substring: ");
for(i=maxi-max+1;i<=maxi;i++)
printf("%c",a[i]);

printf("\n");
}
