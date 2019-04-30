#include "header.h"

void Login(multilist &l,userlist &m)
{
    infotypeU x;
    addressuser usr;

    system("cls");
    cout<<endl;
    cout<<"------------------ Login User ------------------"<<endl;
    cout<<"Username : ";
    cin>>x.user;
    cout<<"Password : ";
    cin>>x.pass;
    usr=CekUser(m,x);

    if(usr==nil)
    {
        cout<<endl;
        cout<<"login Failed, username or password invalid !"<<endl;
        getch();
    }
    else
    {
        UserMenu(usr,l,m);
    }

}
void Signup(userlist &m)
{
    infotypeU u;
    addressuser usr;
    std:string f;

    system("cls");
    cout<<"-------------SIGNUP-------------"<<endl;
    cout<<"Enter Username    : ";
    cin>>u.user;
    cout<<"Enter Password    : ";
    cin>>u.pass;
    u.books=0;
    cout<<"Re-enter Password : ";cin>>f;
    if(u.pass == f){
    usr=cariU(m,u);
    if(usr==nil)
    {

        usr=alokasiU(u);
        if(first(m)==nil)
        {
            first(m)=usr;
            last(m)=usr;

            cout<<endl;
            cout<<"User : "<<infou(usr).user<<" Terdaftar"<<endl;
            getch();
        }
        else
        {
            nextu(last(m))=usr;
            prevu(usr)=last(m);
            last(m)=usr;

            cout<<endl;
            cout<<"User "<<infou(usr).user<<" Registered"<<endl;
            getch();
        }
           }else{
             cout<<endl;
           cout<<"User Already Exist";
         getch();
        }

    }
    else
    {
        cout<<endl;
        cout<<"Password Doesn't Match"<<endl;
        getch();
    }
}

addressuser alokasiU(infotypeU x)
{
    addressuser p=(addressuser)malloc(sizeof(elementuser));
    infou(p)=x;
    nextu(p)=nil;
    prevu(p)=nil;
    return p;
}

addressuser cariU(userlist m,infotypeU x)
{
    addressuser u=first(m);
    while(u!=nil)
    {
        if (strcmp(infou(u).user,x.user)==0)
            return u;
        u=nextu(u);
    }
    return nil;
}

void ShowUser(userlist m)
{
    addressuser p=first(m);
    if(p==nil)
    {
        cout<<endl;
        cout<<"No Data Found";
    }
    else
    {
        cout<<endl;
        cout<<"------User------"<<endl;
        while(p!=nil)
        {
            cout<<"- Username : "<<infou(p).user<<endl;
            cout<<"- Password : "<<infou(p).pass<<endl;
            cout<<"---------------------------"<<endl;
            p=nextu(p);
        }
    }
}

addressuser CekUser(userlist m,infotypeU x)
{
    addressuser u=first(m);
    while(u!=nil)
    {
        if ((strcmp(infou(u).user,x.user)==0) && (strcmp(infou(u).pass,x.pass)==0))
            return u;
        u=nextu(u);
    }
    return nil;
}
