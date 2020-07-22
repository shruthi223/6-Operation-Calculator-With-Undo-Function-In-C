#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max 9 //max no. of digits allowed in one number

struct node
{
    double val;
    struct node *next;
}; //linked stack

typedef struct node *ptr;
double res=0; //global variable that stores the result of computations
ptr top;

void eval(double num,char op) //function to evaluate the operations
{
    if (op == '\0')
    {
        printf("\n= %f\n", num);
        return;
    }
    switch(op)
    {
        case '+': res=top->val+num;
                    break;
        case '-': res=top->val-num;
                    break;
        case '*': res=top->val*num;
                    break;
        case '%': res=fmod(top->val,num);
                    break;
        case '/': if(num==0)
                    {
                        printf("Divide by zero error.");
                    }
                  else
                    res=top->val/num;
                  break;
    }
    printf("\n= %f\n",res);
}

void push() //push function for linked stack
{
    ptr temp=(struct node*)malloc(sizeof(struct node));
    temp->val=res;
    temp->next=top;
    top=temp;
}

double pop() //pop function for linked stack
{
    double x=top->val;
    ptr temp=top;
    top=top->next;
    free(temp);
    return x;
}

void undo_print() //function that prints result once user selects undo
{
    printf("\n= %f\n", top->val);
}

void main()
{
    printf("\n\n***************** 6 OPERATION CALCULATOR WITH UNDO FUNCTION *******************\n");
    char ch[max];
    ptr a;
    int p;
    char op;
    top=NULL;
    int counter=0;
    while(1)
    {
        printf("\nEnter the numbers or operations to compute.\n('+':Add\t'-':Subtract\t'*':Multiply\t'/':Divide\t'%c':Modulus\t'^':Square-root of previous result)\nEnter u to undo and e to exit:\n",'%');
        scanf("%s", ch);
        counter++;
        switch(ch[0])
        {
            case '+':
            case '-':
            case '*':
            case '%': 
            case '/': op=ch[0];
                        break;
            case '^': res=sqrt(top->val);   //sqrt(): in built function to compute sqrt 
                        printf("\n=%f\n",res);
                        break;
            case 'u':
                    p=pop();
                    undo_print();
                    break;
            case 'e': exit(0);
            default: if(counter==1)
                    {
                        res = atof(ch);
                        eval(res, '\0');
                    }
                    else
                        eval(atof(ch), op);
                    break;
        }
        push();
    }
}