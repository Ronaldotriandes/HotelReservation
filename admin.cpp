#include "header.h"

void LoginAdmin(multilist *l)
{
    infotypeAdm x;
    int valid;

    system("cls");
    cout<<endl;
    cout<<"------------------ Login Admin GANTENG ------------------"<<endl;
    cout<<"Username : ";
    cin>>x.user;
    cout<<"Password : ";
    cin>>x.pass;
    valid=CekAdmin(x);

    if(valid==0)
    {

        AdminMenu(l);
    }
    else
    {
        cout<<endl;
        cout<<"Username or Password Invalid";
    }
    getch();

}
void UserMenu(addressuser usr,multilist &l,userlist &m)
{
    int pil;


    system("cls");
    do
    {
        system("cls");
        cout<<endl;
        cout<<"------------------ You're Logged In As : '"<<infou(usr).user <<"' ------------------"<<endl;
        cout<<" 1. Book A Room"<<endl;
        cout<<" 2. My Books"<<endl;
        cout<<" 3. Exit"<<endl;
        cout<<endl;
        cout<<" Pilihan : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            Booking(usr,l,m);
            break;
        case 2:
            ShowBook(usr,m);
            break;
        case 3:
            break;
        }
    }
    while(pil!=3);
}

void AdminMenu(multilist *l)
{
    int pil;
    do
    {
        system("cls");
        cout<<endl;
        cout<<"------------------ Welcome Admin GANTENG------------------"<<endl;
        cout<<" 1. Insert City"<<endl;
        cout<<" 2. Insert Hotel"<<endl;
        cout<<" 3. Insert Room Suite"<<endl;
        cout<<" 4. Insert Room"<<endl;
        cout<<" 5. View All Data"<<endl;
        cout<<" 6. Exit"<<endl;
        cout<<" 7. Delete Kota "<<endl;
        cout<<"                                                                    credits: Ronaldo & Ishlah"<<endl;
        cout<<endl;
        cout<<" Pilihan : ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            system("cls");
            InsertKota(*l);
            break;

        case 2:
            system("cls");
            InsertHotel(*l);
            break;

        case 3:
            system("cls");
            InsertSuite(*l);
            break;

        case 4:
            system("cls");
            InsertRoom(*l);
            break;

        case 5:
            ShowAllData(*l);
            getch();
            break;
        case 6:
            break;
        case 7:
            DeleteKota(*l);
            break;
        }
    }
    while(pil!=6);
}
int CekAdmin(infotypeAdm a)
{
    int user, pass, valid;

    user=strcmp("admin",a.user);
    pass=strcmp("adminn",a.pass);

    if(user==0 && pass==0)
    {
        valid=0;
    }
    else
    {
        valid=1;
    }

    return valid;
}

void CreateList(multilist *l,userlist *m)
{
    first(*l)=nil;
    last(*l)=nil;

    first(*m)=nil;
    last(*m)=nil;
}
