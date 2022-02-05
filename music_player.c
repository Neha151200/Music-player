#include <stdio.h>
#include <windows.h>
#include <MMSystem.h>
#include <conio.h>

//creating node
struct node
{
    void (*newfunc)();
    struct node *prev, *next;
} * first,*second;

//play function
void play()
{
    system("color 3f");
    PlaySound(TEXT("music1.wav"), NULL, SND_SYNC);
    system("pause");
}
void play_1()
{
    system("color 3f");
    printf("Now Playing:music1\n");
    PlaySound(TEXT("music1.wav"), NULL, SND_SYNC);
    system("pause");
}
void play_2()
{
	system("color 5f");
	printf("Now Playing:music2\n");
    PlaySound(TEXT("music2.wav"), NULL, SND_SYNC);
    system("pause");
}

void play_3()
{
	system("color 2f");
	printf("Now Playing:music3\n");
    PlaySound(TEXT("music3.wav"), NULL, SND_SYNC);
    system("pause");
}

void play_4()
{
	system("color 3f");
	printf("Now Playing:music4\n");
    PlaySound(TEXT("music4.wav"), NULL, SND_SYNC);
    system("pause");
}
void play_5()
{
    system("color 4f");
    printf("Now Playing:music5\n");
    PlaySound(TEXT("music5.wav"), NULL, SND_SYNC);
    system("pause");
}
void play_6()
{
    system("color 6f");
    printf("Now Playing:music6\n");
    PlaySound(TEXT("music6.wav"), NULL, SND_SYNC);
    system("pause");
}
void play_7()
{
    system("color 8f");
    printf("Now Playing:music7\n");
    PlaySound(TEXT("music7.wav"), NULL, SND_SYNC);
    system("pause");
}

//inserting a node
struct node *insert(struct node *head, void (*func)())
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->newfunc = func;
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    temp = newnode;
    first = head;
    return head;
}

//creating a linked list
struct node *create(struct node *head, void (*func)())
{

    head->prev = NULL;
    head->newfunc = func;
    head->next = NULL;
    return head;
}

//adding songs in playlist
struct node *add(struct node *head, int n)
{
    struct node *current;
    current = head;
    void (*func_first)();
    switch (n)
    {
    case 1:
        func_first = &play_1;
        current = insert(current, func_first);
        break;
    case 2:
        func_first = &play_2;
        current = insert(current, func_first);
        break;
    case 3:
        func_first = &play_3;
        current = insert(current, func_first);
        break;
    case 4:
        func_first = &play_4;
        current = insert(current, func_first);
        break;
    case 5:
        func_first = &play_5;
        current = insert(current, func_first);
        break;
    case 6:
        func_first = &play_6;
        current = insert(current, func_first);
        break;
    case 7:
        func_first = &play_7;
        current = insert(current, func_first);
        break;
    default:
        printf("music out of list");
        break;
    }
    return current;
}

//creating playlist
struct node* create_playlist(struct node*head)
{       int i = 1;
	    void (*func)() = &play;
		struct node *top,*current;
		top = (struct node*)malloc(sizeof(struct node));
		current = create(top,func);

		while(i!=-1)
		{   int c;
	        printf("Enter the no. of song to be added : \n1.music1\n2.music2\n3.music3\n4.music4\n5.music5\n6.music6\n7.music7\n");
	        scanf("%d",&c);
	        current = add(current,c);
	        printf("Music added\nTo add or exit enter -1\n");
	        scanf("%d",&i);
	    }
		head = current;
		return head;
}

//Playlist number Function
void playlist_no(struct node*head)
{
	   struct node *temp = head;
	   int n;
	   printf("Enter number of song to be played \n");
	   scanf("%d",&n);
	   play_music(temp,n);
}

//alist playlist
void alist()
{
    system("color 3f");
    printf("Now Playing:music1\n");
    PlaySound(TEXT("music1.wav"), NULL, SND_SYNC);

    system("color 5f");
    printf("Now Playing:music2\n");
    PlaySound(TEXT("music2.wav"), NULL, SND_SYNC);

    system("color 7f");
    printf("Now Playing:music3\n");
    PlaySound(TEXT("music3.wav"), NULL, SND_SYNC);
}

//blist playlist
void blist()
{

    system("color 8f");
    printf("Now Playing:music4\n");
    PlaySound(TEXT("music4.wav"), NULL, SND_SYNC);

    system("color 3f");
    printf("Now Playing:music5\n");
    PlaySound(TEXT("music5.wav"), NULL, SND_SYNC);

    system("color 3f");
    printf("Now Playing:music6\n");
    PlaySound(TEXT("music6.wav"), NULL, SND_SYNC);
}

//play music
void play_music(struct node *head, int n)
{
    struct node *temp;
    temp = head;
    void (*func_access)();
    if (n == 1)
    {
        func_access = temp->newfunc;
    }
    else
    {

        for (int i = 2; i <= n && temp->next != NULL; i++)
        {
            temp = temp->next;
        }
        func_access = temp->newfunc;
    }
    (*func_access)();
}


int main()
{
    printf("****WELCOME TO THE MUSIC PLAYER***\n\n");
    printf("Project By:\n112003110 Dhanshree Pawar\n112003111 Neha Pawar\n\n");
    int i;
    //to create palylist
    int n;
    while(n!=-1)
    {

	    printf("Enter 1 to create playlist.\n");
	    printf("Enter 2 to play anyone song.\n");
	    printf("Enter 3 to play full playlist.\n");
	    scanf("%d",&i);

		if(i==1)
	    {   int number;
			struct node *current,*new_current;
			printf("To add in first playlist or second\nenter any number\n");
			scanf("%d",&number);
			if(number==1)
			{
				current = create_playlist(current);
				first = current;
		    }
		    else if(number==2)
		    {
		    	new_current = create_playlist(new_current);
				second = new_current;
			}

		}
		if (i == 2)
        {
        void (*func)() = &play;
        struct node *top, *current;
        top = (struct node *)malloc(sizeof(struct node));
        current = create(top, func);

        current = add(current, 2);
        current = add(current, 3);
        current = add(current, 4);
        current = add(current, 5);
        current = add(current, 6);
        current = add(current, 7);

        int n;
        printf("Enter no. of song to be played \n");
        scanf("%d", &n);
        play_music(current, n);
        }

    //for specific playlist
        else if (i == 3)
        {
        printf("Which playlist would you like to play?\nalist or blist\n");
        printf("\nEnter 5 for alist to play");
        printf("\nEnter 6 for alist to play\n");

        int m;
        scanf("%d",&m);

        if (m==5){
            printf("\nPlaying alist.\n");
            alist();
        }

        else if (m==6){
            printf("Playing blist.\n");
            blist();
        }
    }

    //to play song

    }
    return 0;
}
