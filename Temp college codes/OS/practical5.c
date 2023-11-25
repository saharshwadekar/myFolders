#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int wait(int s)
{
    return (--s);
}
int signal(int s)
{
    return (++s);
}
void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item%d", x);
    mutex = signal(mutex);
}
void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes the item%d", x);
    x--;
    mutex = signal(mutex);
}
int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
    while (1)
    {
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("BUFFER IS FULL");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("BUFFER IS EMPTY");
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}



// Output

1.PRODUCER
2.CONSUMER
3.EXIT

ENTER YOUR CHOICE
1
Producer produces the item1

ENTER YOUR CHOICE
1
Producer produces the item2

ENTER YOUR CHOICE
1
Producer produces the item3

ENTER YOUR CHOICE
1
BUFFER IS FULL

ENTER YOUR CHOICE
2
Consumer consumes the item3

ENTER YOUR CHOICE
2
Consumer consumes the item2

ENTER YOUR CHOICE
2
Consumer consumes the item1

ENTER YOUR CHOICE
2
BUFFER IS EMPTY

ENTER YOUR CHOICE
3
