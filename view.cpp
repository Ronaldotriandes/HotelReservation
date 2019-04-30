#include "header.h"

void ShowAllData(multilist l)
{
    addresskota k=first(l);
    if(k==nil)
    {
        cout<<endl;
        cout<<"No Data Found";
    }
    else
    {
        while(k!=nil)
        {
            cout<<endl;
            cout<<"--------------------"<<infok(k).kota<<"--------------------";
            if(infok(k).hotels>0)
            {
                addresshotel h=nexth(k);
                while(h!=nil)
                {
                    cout<<endl;
                    cout<<"\t"<<infoh(h).hotel<<endl;
                    if(infoh(h).suites>0)
                    {
                        addresssuite s=nexts(h);
                        while(s!=nil)
                        {
                            cout<<endl;
                            cout<<"\t\t"<<infos(s).suite<<endl;
                            if(infos(s).rooms>0)
                            {
                                addressroomoom r=nextr(s);
                                while(r!=nil)
                                {
                                    cout<<endl;
                                    cout<<"\t\t\t"<<infor(r).room<<endl;
                                    r=nextr(r);
                                }
                            }
                            s=nexts(s);
                        }
                    }
                    h=nexth(h);
                }
            }
            k=nextk(k);
        }
    }
}

void ShowKota(multilist l)
{
    addresskota p=first(l);
    if(p==nil)
    {
        cout<<endl;
        cout<<"No Data Found";
    }
    else
    {
        cout<<endl;
        cout<<"------KOTA------"<<endl;
        while(p!=nil)
        {
            cout<<"- "<<infok(p).kota<<endl;
            p=nextk(p);
        }
    }
}

void ShowHotel(multilist l, addresskota k)
{

    if(infok(k).hotels>0)
    {
        addresshotel h=nexth(k);
        cout<<endl;
        cout<<"------"<<infok(k).kota<<"------"<<endl;
        while(h!=nil)
        {
            cout<<"- "<<infoh(h).hotel<<endl;
            h=nexth(h);
        }
    }
}



void ShowSuite(multilist l,addresshotel h)
{

    if(infoh(h).suites>0)
    {
        addresssuite s=nexts(h);
        cout<<endl;
        cout<<"------"<<infoh(h).hotel<<"------"<<endl;
        while(s!=nil)
        {
            cout<<"- "<<infos(s).suite<<endl;
            s=nexts(s);
        }
    }
}

void ShowRoom(multilist l,addresssuite s)
{

    if(infos(s).rooms>0)
    {
        addressroomoom r=nextr(s);
        cout<<endl;
        cout<<"------"<<infos(s).suite<<"------"<<endl;
        while(r!=nil)
        {
            if(infor(r).stats==false)
                cout<<"- "<<infor(r).room<<endl;

            r=nextr(r);
        }
    }
}

void ShowBook(addressuser usr,userlist m)
{
    if(infou(usr).books>0)
    {
        addressbook b=nextb(usr);
        cout<<endl;
        cout<<"------Booked Hotel Room------"<<endl;
        while(b!=nil)
        {
            cout<<"Kota  : "<<infob(b).kota<<endl;
            cout<<"Hotel : "<<infob(b).hotel<<endl;
            cout<<"Suite : "<<infob(b).suite<<endl;
            cout<<"Room  : "<<infob(b).room<<endl;
            b=nextb(b);
        }
    }
    else
    {
        cout<<endl;
        cout<<"------No Booked Data Found------"<<endl;

    }
    getch();
}
