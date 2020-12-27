#include <iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct node{                      //Creating NOde
    char data[20];
    node *next;
}*head=NULL,*tail=NULL;

void insert(char value[20]){       //insert at the end
    node *temp=new node;
    strcpy(temp->data,value);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp=NULL;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void insert_begin(char value[20])   //insert at beginning
{
    node *temp=new node;
    strcpy(temp->data,value);
    temp->next=head;
    head=temp;

}

void pos_insert(int pos,char value[20])     //  insert at specific position
{
    node *temp=new node;
    node *prev=new node;
    node *curr=new node;
    curr=head;
    for(int i=1;i<pos;i++)
    {
        prev=curr;
        curr=curr->next;
    }
    strcpy(temp->data,value);
    prev->next=temp;
    temp->next=curr;

}


void deletenode(char name[20])      //delete by name
{

    node *temp=new node;
    node *curr=new node;
    temp=head;
    if(temp!=NULL&&strcmpi(temp->data,name)==0)
    {head=temp->next;
    free(temp);
    return;
    }
    if(temp==NULL)
    {
        cout<<"Not Found";
        return;

    }
    while(temp!=NULL&&strcmpi(temp->data,name)==1)
    {
        curr=temp;
        temp=temp->next;
    }
    curr->next=temp->next;
    free(temp);
}

void deletecomp()       //delete completely
{
node *temp;
node *next;
temp=head;
while(temp!=NULL)
{
    next=temp->next;
    delete temp;
    temp=next;

}
delete head;
head=NULL;
}

void pos_delete(int pos)        //delete by position
{int i=1;
    node *temp=new node;
    node *curr=new node;
    temp=head;
    if(temp==NULL){
    cout<<"List is empty";
    }
    if(pos==1)
    {
        head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&i<pos)
    {
        curr=temp;
        temp=temp->next;
        i++;
    }
    curr->next=temp->next;
    free(temp);
}

void display()
{
    node *cur=new node;
    cur=head;
    while(cur!=NULL)
    {
        cout<<cur->data<<"  ";
        cur=cur->next;
    }
    cout<<endl;
}
int main()
{
    int n,choice,choice2,pos;
    char v[20];
    char flag='y';
    while(flag=='y'||flag=='Y')
    {

    cout<<"\n\n\\____________________________Menu_____________________________//";
    cout<<"\nSelect from Following.............";
    cout<<"\n1. Insert";
    cout<<"\n2. Delete";
    cout<<"\n3. display";
    cout<<"\n4. Search";
    cout<<"\n5. Exit";
    cout<<"\n Press Any Key= ";
    cin>>choice;
    switch(choice)
    {
        case 1:
            system("cls");
            cout<<"\\___________Insertion_____________//";
            cout<<"\n\nSelect an option:- \t\t\tP.S.= If list is empty select option 1 to begin with.";
            cout<<"\n1.Insertion at end.";
            cout<<"\n2.Insertion at beginning.";

            cout<<"\n3.Insertion at Specific Position.\n";
            cin>>choice2;
            switch(choice2)
            {
            case 1:
                cout<<"\nEnter how many names you wants to insert= ";
                cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"\nenter the name to be inserted= ";
                cin>>v;
                insert(v);
            }
                break;
            case 2:
                cout<<"\nEnter how many names you wants to insert= ";
                cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"\nenter the name to be inserted= ";
                cin>>v;
                insert_begin(v);
            }
            break;
            case 3:

                cout<<"\nEnter how many names you wants to insert= ";
                cin>>n;
            for(int i=0;i<n;i++)
            {
                cout<<"\nenter the name to be inserted= ";
                cin>>v;
                cout<<"enter the Position where you wants to insert= ";
                cin>>pos;
                pos_insert(pos,v);
            }
            default:
                cout<<"\nInvailed option";
            }

        break;

        case 2:
            system("cls");
            cout<<"\\_________________Deletion_________________//";
            cout<<"\n\n Select an option:-";
            cout<<"\n1.delete by name.";
            cout<<"\n2.delete by location.";
            cout<<"\n3.complete delete\n";
            cin>>choice2;
            switch(choice2)
            {

                case 1:cout<<"enter the name to be deleted= ";
                cin>>v;
                deletenode(v);
                cout<<"deletion Success-full";
                break;

                case 2:cout<<"enter the position to be deleted= ";
                cin>>pos;
                pos_delete(pos);
                cout<<"deletion Success-full";
                break;

                case 3:
                deletecomp();
                cout<<"deletion Success-full";
            }

            break;
        case 3:
            display();
            break;
        case 5:
            flag='n';
            break;
        default:
            cout<<"Invailed Option, TRY AGAIN!";


    }


    }

return 0;
getch();
}


