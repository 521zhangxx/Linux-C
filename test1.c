 #include<stdio.h>
 #include<stdlib.h>
 #define N 42
//build a type of struct array
 struct stu{
     char name[9];
     int score[6];
     float average;
     int sum;
 }class[N];
int inorder(struct stu *pclass);
void display(struct stu *pclass);
int main(){
     int i=0,j=0;
     //distribute the number for array
     for(j=0;j<6;j++){
         for(i=0;i<N;){
             int a=rand()%101;   //distribute a number by random
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
             i++;
         }
     }
     //distribute a name to students
     for(i=0;i<N;){
     	int a=rand()%8;
	if(a>=4){
	   for(j=0;j<a;){
	   	int p=0;
		p=rand()%112;
		if(p>=97){class[i].name[j]=(char)p;j++;}
	   }
	   for(j;j<9;j++){if(j>=8){class[i].name[j]='\0';break;}class[i].name[j]=' ';}

	   i++;
	}
     }
     //call this function that put them in order according sum of score
     inorder(class);
     //print the result
 //    printf("order in the end: ");
     int b[N];
     for(i=0;i<N;i++){
	b[i]=0;
        for(j=0;j<6;j++){
           b[i]+=class[i].score[j];
        }
   //     printf("%d ",b[i]);
	class[i].sum=b[i];
	class[i].average = class[i].sum/6.0;
     }
   //  printf("\n");
   //  printf("\n");
     display(class);

 }
 int inorder(struct stu *pclass){
     int i=0,j=0,q=0,tem=0;
     int a[N];

  /*   printf("order in the beginning: ");
     for(i=0;i<N;i++){
     	a[i]=0;
         for(j=0;j<6;j++){
             a[i]+=pclass[i].score[j];
         }
	 //print the number before put in order
	 printf("%d ",a[i]);
     }
     printf("\n");
     printf("\n");  */
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
void display(struct stu *pclass){
	printf("Name\t");
	printf("grade1\t");
	printf("grade2\t");
	printf("grade3\t");
	printf("grade4\t");
	printf("grade5\t");
	printf("grade6\t");
	printf("average\t");
	printf("sum\t");
	printf("rank\t");
	printf("\n");
	printf("\n");
	
	for(int i=0;i<N;i++){
		for(int j=0;j<9;j++){printf("%c",pclass[i].name[j]);}
		printf(" ");
		for(int j=0;j<6;j++){
			int num =pclass[i].score[j];
			printf("%d\t",num);
		}
		printf("%3.3f\t",pclass[i].average);
		printf("%d\t",pclass[i].sum);
		printf("%d\t",i+1);
		printf("\n");
	}
}
