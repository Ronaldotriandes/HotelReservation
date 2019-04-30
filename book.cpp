#include "header.h"

addressbook alokasib(infotypeB x)
{
    addressbook p=(addressbook)malloc(sizeof(elementbook));
    infob(p)=x;
    nextb(p)=nil;
    return p;
}

void Booking(addressuser usr,multilist &l,userlist &m)
{
    infotypeB f;
    infotypeR d;
    infotypeS c;
    infotypeH b;
    infotypeK a;
    addresskota k;
    addresshotel h;
    addresssuite s;
    addressroomoom r;
    addressbook g;
    char con;

    system("cls");
    ShowKota(l);
    cout<<endl;
    cout<<"Masukkan Nama Kota : ";
    cin>>a.kota;
    k=cariK(l,a);

    if(k==nil)
    {
        cout<<endl;
        cout<<"Kota Tidak Ditemukan";
        getch();
    }
    else
    {
        system("cls");
        ShowHotel(l,k);
        cout<<endl;
        cout<<"Masukkan Nama Hotel  : ";
        cin>>b.hotel;
        h=cariH(l,k,b);

        if(h==nil)
        {
            cout<<endl;
            cout<<"Hotel Tidak Ditemukan";
            getch();
        }
        else
        {
            system("cls");
            ShowSuite(l,h);
            cout<<endl;
            cout<<"Masukkan Nama Suite  : ";
            cin>>c.suite;
            s=cariS(l,h,c);

            if(s==nil)
            {
                cout<<endl;
                cout<<"Suite Tidak Ditemukan";
                getch();
            }
            else
            {
                if(infos(s).rooms == 0)
                {
                    cout<<endl;
                    cout<<"No Room Avaliable";
                    getch();
                }
                else
                {
                    system("cls");
                    ShowRoom(l,s);
                    cout<<endl;
                    cout<<"Masukkan Nomor Kamar  : ";
                    cin>>d.room;
                    r=cariR(l,s,d);
                    if(r==nil)
                    {
                        cout<<"Room Tidak Ditemukan";
                        getch();
                    }
                    else
                    {
                        system("cls");
                        cout<<endl;
                        cout<<"---------- Info Hotel ----------"<<endl;
                        cout<<"Kota  : "<<infok(k).kota<<endl;
                        cout<<"Hotel : "<<infoh(h).hotel<<endl;
                        cout<<"Suite : "<<infos(s).suite<<endl;
                        cout<<"Room  : "<<infor(r).room<<endl;
                        cout<<"---------------------------------"<<endl;
                        cout<<"Price : Rp."<<infor(r).rate<<endl;
                        cout<<endl;
                        cout<<"Book Room ? (y/n) : ";
                        cin>>con;
                        if(con == 'y')
                        {
                            infor(r).stats=true;
                            infos(s).rooms=(infos(s).rooms - 1);

                            strcpy(f.kota, infok(k).kota);
                            strcpy(f.hotel, infoh(h).hotel);
                            strcpy(f.suite, infos(s).suite);
                            strcpy(f.room, infor(r).room);
                            f.price=infor(r).rate;

                            g=alokasib(f);
                            if(infou(usr).books==0)
                            {
                                nextb(usr)=g;
                                infou(usr).books=1;
                                cout<<endl;
                                cout<<"---------- Hotel Room Booked ----------"<<endl;
                                getch();
                            }
                            else
                            {
                                addressbook b1=nextb(usr);
                                while(nextb(b1)!=nil)
                                    b1=nextb(b1);
                                nextb(b1)=g;
                                infou(usr).books++;
                                cout<<endl;
                                cout<<"---------- Hotel Room Booked ----------"<<endl;
                                getch();
                            }

                        }
                        else if(con == 'n')
                        {
                            cout<<endl;
                            cout<<"Book Terminated";
                            getch();
                        }

                    }
                }

            }
        }
    }
}
