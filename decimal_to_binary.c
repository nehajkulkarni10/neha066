#include <stdio.h>

#define MAX 32

struct Stack
{
    int top;
    int items[MAX];
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }

    s->items[++(s->top)] = value;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    return s->items[(s->top)--];
}

void decimalToBinary(int num)
{
    struct Stack s;
    initStack(&s);

    if (num == 0)
    {
        printf("Binary equivalent: 0\n");
        return;
    }

    int originalNum = num;

    while (num > 0)
    {
        push(&s, num % 2);
        num = num / 2;
    }

    printf("Binary equivalent of %d: ", originalNum);

    while (!isEmpty(&s))
    {
        printf("%d", pop(&s));
    }

    printf("\n");
}

int main()
{
    int number;

    printf("Enter a non-negative decimal integer: ");

    if (scanf("%d", &number) != 1 || number < 0)
    {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    decimalToBinary(number);

    return 0;
}