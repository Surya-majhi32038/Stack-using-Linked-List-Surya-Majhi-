// creat a stack using linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};
struct stack *st;
void push();
void pop();
int isEmpty();
void show();
void creat_stack(struct stack *st);
int main()
{
    int ch;

    // allocate memory for stakc
    st = (struct stack *)malloc(sizeof(struct stack));
    creat_stack(st);
    while (1)
    {
        printf("\n ======  MEAN MANU ==== \n 1. insert in the stack \n 2. delete in the stack \n 3. Element show \n 4. exit \n Enter your chooise :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            free(st);
            exit(0);
            break;

        default:
            printf("\n Invailed Input ");
            break;
        }
    }
}

// push operation in stakc
void push()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    // chekc stack is full or not
    if (ptr == NULL)
    {
        printf("\n Stack is full ");
        return;
    }
    // if upper part false then we push the element
    int value;
    printf("\n Enter the value :");
    scanf("%d", &value);
    ptr->data = value;

    // if stack is null then this part excute
    // its mean no element in the stack , it is a first element
    if (st->top == NULL)
    {
        ptr->next = NULL;
        st->top = ptr;
    }
    else // its mean one or more element in the stack
    {
        ptr->next = st->top;
        st->top = ptr;
    }
}
// check isEmpty function
int isEmpty()
{
    if (st->top == NULL)
    {
        return 1;
    }
    return 0;
}
// pop operation in stack
void pop()
{

    // if stack is empty or not
    if (isEmpty())
    {
        printf("\n Stack is empty ");
        return;
    }
    struct node *ptr;
    ptr = st->top;
    printf("\n Delete item :%d", ptr->data);
    st->top = ptr->next;
    free(ptr);
}

// show element from the stack
void show()
{
    // check stakc is empty or not
    if (isEmpty())
    {
        printf("\n Stack is empty ");
        return;
    }
    struct node *ptr;
    ptr =  st->top  ;
    printf("\n Element :");
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
// creat a default value of stack
void creat_stack(struct stack *st)
{
    st->top = NULL;
    // defalut it is null
}
