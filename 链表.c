#include<stdio.h>
#include<stdlib.h>
typedef struct stu{
    int age;
    struct stu *next;
}stu,*pstu;
 
pstu creatlist(int points){
    int nianling=0;
 
    pstu pheader = (pstu)malloc(sizeof(stu)); 			       //place a peace of point
    if(pheader==NULL){   		                            	   // if failed   
        printf("LinkList was failed!");
	        exit(0);				
    }
    pstu pend = pheader;										// if place a peace a point successfully,creat a end-point tawards to the header-point
    pend->next = NULL;
	  
    for(int i=0;i<points;i++){
        pstu pnew = (pstu)malloc(sizeof(stu));
        if(pnew==NULL){
            printf("LinkList just has zero point");
            exit(1);
        }

        pend->next = pnew;										//end-point's point towards to the next point
		pnew->age = ++nianling;
		pnew->next = NULL;
		pend = pnew;
    }
    printf("LinkList is successful\n");
    return pheader;
}
 
int main(){
	int point=0;
	printf("Please enter the number of points:  \n");
    scanf("%d",&point);
    
    
	pstu list = creatlist(point);
	
	for(int i=0;i<point;i++){
		list = list->next;
		printf("%d ",list->age);
		
	}
}
