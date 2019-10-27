 #include<stdio.h>
 #include<stdlib.h>
 #define N 82
//build a type of struct array
 struct stu{
     int score[6];
 }class[N];
int inorder(struct stu *pclass);
 
 int main(){
     int i=0,j=0;
     //distribute the number for array
     for(i=0;i<N;i++){
         for(j=0;j<6;){
             int a=rand()%100;   //distribute a number by random
             int i60=0,i90=0;
	     //if the number less than 60,i60+1;if i60 big than 10,end this cycle
             if(a<60) {
                 i60++;
                 if(i60>=10) continue;
             }
	     //if the number big than 90,i90+1;if i90 big than 10,end this cycle
             if(a>90) {
                 i90++;
                 if(i90>=10) continue;
             }
             class[i].score[j]=a;
             j++;
         }
     }
     //call this function that put them in order according sum of score
     inorder(class);
     //print the result
     int b[N]={0,0,0,0,0,0,0,0,0,0};
     for(i=0;i<N;i++){
        for(j=0;j<6;j++){
           b[i]+=class[i].score[j];
        }
        printf("%d ",b[i]);
     }

 }
 int inorder(struct stu *pclass){
     int i=0,j=0,q=0,tem=0;
	 int a[N];
     for(i=0;i<N;i++){
     	a[i]=0;
         for(j=0;j<6;j++){
             a[i]+=pclass[i].score[j];
         }
		 printf("%d ",a[i]);
     }
     printf("\n");
     struct stu temp;
     
     for(i=0;i<N;i++)
         for(j=i+1;j<N;j++){
             if(a[i]<a[j]){
                temp=*(pclass + i);
                *(pclass + i)=*(pclass +j);
                *(pclass +j)=temp;
                tem=a[i];a[i]=a[j];a[j]=tem;  	
             }
         }
     return 0;
 }
