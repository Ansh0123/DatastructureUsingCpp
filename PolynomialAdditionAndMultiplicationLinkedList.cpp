/*
  Author:
  Ashutosh Kumar
  @an_shuman777
  LINKED LIST POLYNOMIAL ARITHEMATICS
*/

#include<bits/stdc++.h>
using namespace std;

struct poly{
    int coeff;
    int expo;
    struct poly *link;
};

struct poly *insrt(struct poly *start,int cof,int exp){
    if(start==NULL){
        struct poly *tmp;
        tmp = (struct poly *)malloc(sizeof(struct poly));
        tmp->coeff=cof;
        tmp->expo=exp;
        start=tmp;
        tmp->link=NULL;
    }
    else{
        struct poly *tmp1;
        tmp1=start;
        while(tmp1->link !=NULL){
            tmp1=tmp1->link;
        }
        struct poly *tmp2;
        tmp2 = (struct poly *)malloc(sizeof(struct poly));
        tmp2->coeff=cof;
        tmp2->expo=exp;
        tmp1->link=tmp2;
        tmp2->link=NULL;
    }
    return start;
}

void disp(struct poly *start){
    while(start!=NULL){
        cout<<start->coeff<<"x^"<<start->expo;
        if(start->link!=NULL and start->coeff>0){
            cout<<" + ";
        }
        else cout<<" ";
        start=start->link;
    }
    cout<<"\n";
}

void polyMul(struct poly *first , struct poly *second){
    struct poly *mul=NULL,*tmp1,*tmp2;
    tmp1=first;
    while(tmp1!=NULL){
        tmp2=second;
        while(tmp2!=NULL){
            mul=insrt(mul,tmp1->coeff * tmp2->coeff,tmp1->expo + tmp2->expo);
            tmp2=tmp2->link;
        }
        tmp1=tmp1->link;
    }
    disp(mul);
}

void polyAdd(struct poly *first,struct poly *second){
    struct poly *add=NULL,*tmp1,*tmp2;
    tmp1=first;tmp2=second;
    while(tmp1 != NULL and tmp2 != NULL){
        if(tmp1->expo > tmp2->expo){
            add = insrt(add,tmp1->coeff,tmp1->expo);
            tmp1=tmp1->link;
        }
        else if(tmp1->expo < tmp2->expo){
            add=insrt(add,tmp2->coeff,tmp2->expo);
            tmp2=tmp2->link;
        }
        else if(tmp1->expo == tmp2->expo){
            add=insrt(add,tmp1->coeff + tmp2->coeff,tmp1->expo);
            tmp1=tmp1->link;
            tmp2=tmp2->link;
        }

    }
    while(tmp1 != NULL){
        add=insrt(add,tmp1->coeff,tmp1->expo);
        tmp1=tmp1->link;
    }
    while(tmp2!=NULL){
        add=insrt(add,tmp2->coeff,tmp2->expo);
        tmp2=tmp2->link;
    }
    disp(add);
}

int main()
{
    struct poly *first,*second;
    first=second=NULL;
    first=insrt(first,4,3);
    first=insrt(first,5,2);
    first=insrt(first,3,1);
    disp(first);
    /* first polynomial as 4x^3 + 5x^2 + 3x^1 */
    second=insrt(second,2,5);
    second=insrt(second,6,4);
    second=insrt(second,1,2);
    second=insrt(second,8,0);
    disp(second);
    /* Second polynomial as 2x^5 + 6x^4 + 1x^2 + 8x^0 */
    polyMul(first,second);
    /* polynomial multiplication as 8x^8 + 24x^7 + 4x^5
    + 32x^3 + 10x^7 + 30x^6 + 5x^4 + 40x^2 + 6x^6
    + 18x^5 + 3x^3 + 24x^1 */
    polyAdd(first,second);
    /* polynomial addition as 2x^5 + 6x^4 + 4x^3 + 6x^2
    + 3x^1 + 8x^0*/
    return 0;
}
