#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    char c[50];
    char num[15];
    struct node *link;
};

int cal(struct node *q)
{
    int count = 0, temp;
        temp = q->c[0];
        count = count + temp;
        if (temp >= 65 && temp <= 90)
        {
            count = count + 32;
        }
    return count;
}
void add(struct node *t, struct node **head)
{
    if (*head == NULL)
    {
        t->link = NULL;
        *head = t;
    }
    else
    {
        struct node *next = *head, *back;
        while (t->data >= next->data)
        {

            back = next;
            next = next->link;
            if (next == NULL)
            {
                break;
            }
        }
        if (next == NULL)
        {
            t->link = NULL;
            back->link = t;
        }
        else if (next == *head)
        {
            t->link = *head;
            *head = t;
        }
        else
        {
            back->link = t;
            t->link = next;
        }
    }
}
void delete (char s[15], struct node **head)
{
    if (*head == NULL)
    {
        printf("\nlist is empty");
    }
    else
    {
        struct node *temp = *head;
        struct node *b = NULL;
        while (strcmp(temp->num,s) != 0)
        {
            b = temp;
            temp = temp->link;
            if (temp == NULL)
            {
                break;
            }
        }

        if (temp == *head)
        {
            *head = temp->link;
            free(temp);
        }
        else if (temp == NULL)
        {
            printf("\nNumber is not in the list\n");
        }
        else
        {
            b->link = temp->link;
            free(temp);
        }
    }
}
void display(struct node **head)
{
    struct node *temp = *head;
    if (*head == NULL)
    {
        printf("\nlist is empty!!\n");
    }
    else
    {
        // printf("\n# # # # # # # # # # # # # # # # # # # # # # # #\n");
        printf("\n\n-------------> CONTACT BOOK <-------------- \n");
        while (temp != NULL)
        {
            printf("-------------------------------------\n");
            printf("Name        : ");
            puts(temp->c);
            printf("Contact num : ");
            puts(temp->num);
            printf("--------------------------------------\n");
            temp = temp->link;
        }
    }
}
void search(struct node **head)
{
    struct node *temp = *head, *a[10];
    char s[50], k[50];
    int len, i = 0, flag = 0;
    if (*head == NULL)
    {
        printf("\nlist is empty!!\n");
    }
    else
    {
        printf("\nEnter name to find : ");
        fflush(stdin);
        gets(s);
        len = strlen(s);
        while (temp != NULL)
        {
            for (int j = 0; j < len; j++)
            {
                k[j] = temp->c[j];
            }
            if (strcmp(k, s) == 0)
            {
                a[flag] = temp;
                flag++;
                printf("-----------------------------\n");
                printf("%d)\n", flag);
                printf("Name        : ");
                puts(temp->c);
                printf("Contact num : ");
                puts(temp->num);
                printf("------------------------------\n");
                }
            temp = temp->link;
        }
        if (flag == 0)
        {
            printf("\nNo Contact Found!! \n");
        }
        else
        {
            printf("\n1) Edit \n2) Back");
            printf("\nEnter->>");
            if (getch() == '1')
            {
                int n;
                if (flag == 1)
                {
                    n = 1;
                }
                else
                {
                    do
                    {
                        printf("\nEnter Index Number : ");
                        scanf("%d", &n);
                    } while (n > flag && n < 0);
                }
                printf("\nWhat To Edit : ");
                printf("\n1) number \n2) name");
                printf("\nEnter->>");
                switch (getch())
                {
                case '1':
                    do
                    {
                        printf("\nEnter New Mobile Number : ");
                        scanf("%s", a[n - 1]->num);
                        if (strlen(a[n - 1]->num) != 10)
                        {
                            printf("\nEnter valid length of mobile number.");
                        }
                    } while (strlen(a[n - 1]->num) != 10);
                    break;
                case '2':
                    strcpy(s, a[n - 1]->num);
                    delete (s, head);
                    int a, b;
                    struct node *t = (struct node *)malloc(sizeof(struct node));
                    printf("\nEnter New Name : ");
                    fflush(stdin);
                    gets(t->c);
                    a = cal(t);
                    strcpy(t->num, s);
                    t->data = a;
                    add(t, head);
                default:
                    break;
                }
            }
        }
    }
}
int main()
{
    struct node *head = NULL;
    int t, x, k, h;
    while (1)
    {
        int a, b;
        char s[50];
        struct node *t = (struct node *)malloc(sizeof(struct node));
        printf("\n*********************************************\n");
        printf("Press 1 to INSERT a Contact       \n");
        printf("Press 2 to DELETE a Contact      \n");
        printf("Press 3 to DISPLAY ContactBook           \n");
        printf("Press 4 to SEARCH and Edit               \n");
        printf("Press 5 to EXIT                              \n");
        // printf("*********************************************\n");
        printf("Enter->>");
        switch (getch())
        {
        case '1':
        {
            printf("\nName          : ");
            fflush(stdin);
            gets(t->c);
            a = cal(t);
            do
            {
                printf("Mobile number : ");
                scanf("%s", t->num);
                if (strlen(t->num) != 10)
                {
                    printf("\nEnter valid Mobile Number!!");
                }
            } while (strlen(t->num) != 10);
            t->data = a;
            add(t, &head);
            break;
        }

        case '2':
        {
            do
            {
                printf("\nEnter mobile number : ");
                scanf("%s", s);
                if (strlen(s) != 10)
                {
                    printf("\nEnter valid Mobile Number!!");
                }
            } while (strlen(s) != 10);
            delete (s, &head);
            break;
        }

        case '3':
            display(&head);
            break;

        case '4':
            search(&head);
            break;

        case '5':
            exit(0);
            break;

        default:
            printf("\nEnter valid value!!\n");
            break;
        }
    }

    return 0;
}