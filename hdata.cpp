#include "header.h"

addresskota alokasik(infotypeK x)
{
    addresskota p=(addresskota)malloc(sizeof(elementkota));
    infok(p)=x;
    nextk(p)=nil;
    nexth(p)=nil;
    prevk(p)=nil;
    return p;
}
void dealokasik(addresskota &p)
{
    delete p;
}

addresshotel alokasih(infotypeH x)
{
    addresshotel p=(addresshotel)malloc(sizeof(elementhotel));
    infoh(p)=x;
    nexth(p)=nil;
    nexts(p)=nil;
    return p;
}
void dealokasih(addresshotel &p)
{
    delete p;
}
addresssuite alokasis(infotypeS x)
{
    addresssuite p=(addresssuite)malloc(sizeof(elementsuite));
    infos(p)=x;
    nexts(p)=nil;
    nextr(p)=nil;
    return p;
}

addressroomoom alokasir(infotypeR x)
{
    addressroomoom p=(addressroomoom)malloc(sizeof(elementroom));
    infor(p)=x;
    nextr(p)=nil;
    return p;
}

addresskota cariK(multilist l,infotypeK a)
{
    addresskota k=first(l);
    while(k!=nil)
    {
        if (strcmp(infok(k).kota,a.kota)==0)
            return k;
        k=nextk(k);
    }
    return nil;
}

addresshotel cariH(multilist l,addresskota k,infotypeH b)
{
    addresshotel h=nexth(k);
    while(h!=nil)
    {
        if (strcmp(infoh(h).hotel,b.hotel)==0)
            return h;
        h=nexth(h);
    }
    return nil;
}
addresssuite cariS(multilist l,addresshotel h,infotypeS c)
{
    addresssuite s=nexts(h);
    while(s!=nil)
    {
        if (strcmp(infos(s).suite,c.suite)==0)
            return s;
        s=nexts(s);
    }
    return nil;
}

addressroomoom cariR(multilist l,addresssuite s,infotypeR d)
{
    addressroomoom r=nextr(s);
    while(r!=nil)
    {
        if (strcmp(infor(r).room,d.room)==0)
            return r;
        r=nextr(r);
    }
    return nil;
}
/*void cariH(multilist &l)
{
    infotypeR r;
    addressroomoom rom;
    infotypeK k;
    addresskota kot;
    infotypeH h;
    addresshotel hot;
    system("cls");
    cout<<endl;
    cout<<"masukan room berapa : ";
    cin>>r.room;
    rom=cariR(l,r);
    if (rom==NULL)
    {
        cout<<endl;
        cout<<"data tidak ditemukan "<<endl;

    }
    else
    {
        system("cls");
        cout<<endl;
        cout<<infoh()
    }
}*/
void InsertKota(multilist &l)
{
    infotypeK k;
    addresskota kot;

    system("cls");
    cout<<endl;
    cout<<"Masukan nama kota : ";
    cin>>k.kota;
    kot=cariK(l,k);
    if (kot ==NULL)
    {
        kot=alokasik(k);
            if (first(l)== NULL)
            {

                first(l)=kot;
                last(l)=kot;
                cout<<endl;
                cout<<"kota "<<infok(kot).kota<<" ditambahkan !"<<endl;
                getch();
            }
            else
            {
                nextk(last(l))=kot;
                prevk(kot)=last(l);
                last(l)=kot;
                cout<<endl;
                cout<<"kota "<<infok(kot).kota<<"ditambahkan ! "<<endl;
                getch();
            }
    }
    else
    {
        cout<<endl;
        cout<<"Kota sudah ada"<<endl;
        getch();
    }
}
void InsertHotel(multilist &l)
{
    infotypeH b;
    infotypeK a;
    addresskota k;
    addresshotel h;

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
            b.suites=0;

            h=alokasih(b);
            if(infok(k).hotels==0)
            {
                nexth(k)=h;
                //prevh(h)= NULL;
                nexth(h)=NULL;
                infok(k).hotels=1;
                cout<<endl;
                cout<<"Hotel "<<infoh(h).hotel<<" Pada Kota "<<infok(k).kota<<" Ditambahkan !";
                getch();
            }
            else
            {
                addresshotel h1=nexth(k);
                while(nexth(h1)!=nil)
                    h1=nexth(h1);
                nexth(h1)=h;
                nexth(h)=NULL;
                infok(k).hotels++;
                cout<<endl;
                cout<<"Hotel "<<infoh(nexth(h1)).hotel<<" Pada Kota "<<infok(k).kota<<" Ditambahkan !";
                getch();
            }

        }
        else
        {
            cout<<endl;
            cout<<"Hotel ada di List"<<endl;
            getch();
        }
    }
}

void InsertSuite(multilist&l)
{
    infotypeS c;
    infotypeH b;
    infotypeK a;
    addresskota k;
    addresshotel h;
    addresssuite s;


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
                c.rooms=0;
                s=alokasis(c);
                if(infoh(h).suites==0)
                {
                    nexts(h)=s;
                    infoh(h).suites=1;
                    cout<<endl;
                    cout<<"Suite "<<infos(s).suite<<" Pada Hotel "<<infoh(h).hotel<<" Ditambahkan !";
                    getch();
                }
                else
                {
                    addresssuite s1=nexts(h);
                    while(nexts(s1)!=nil)
                        s1=nexts(s1);
                    nexts(s1)=s;
                    infoh(h).suites++;
                    cout<<endl;
                    cout<<"Suite "<<infos(nexts(s1)).suite<<" Pada Hotel "<<infoh(h).hotel<<" Ditambahkan !";
                    getch();
                }
            }
            else
            {
                cout<<endl;
                cout<<"Suite ada di List"<<endl;
                getch();
            }
        }
    }
}



void InsertRoom(multilist&l)
{
    infotypeR d;
    infotypeS c;
    infotypeH b;
    infotypeK a;
    addresskota k;
    addresshotel h;
    addresssuite s;
    addressroomoom r;

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
                system("cls");
                ShowRoom(l,s);
                cout<<endl;
                cout<<"Masukkan Nomor Kamar  : ";
                cin>>d.room;
                cout<<"Masukkan Rate Kamar   : ";
                cin>>d.rate;
                r=cariR(l,s,d);
                if(r==nil)
                {
                    d.stats=false;
                    r=alokasir(d);

                    if(infos(s).rooms==0)
                    {
                        nextr(s)=r;
                        infos(s).rooms=1;
                        cout<<endl;
                        cout<<"Room "<<infor(r).room<<" Pada Suite "<<infos(s).suite<<" Ditambahkan !";
                        getch();
                    }
                    else
                    {
                        addressroomoom r1=nextr(s);
                        while(nextr(r1)!=nil)
                            r1=nextr(r1);
                        nextr(r1)=r;
                        infos(s).rooms++;
                        cout<<endl;
                        cout<<"Room "<<infor(nextr(r1)).room<<" Pada Suite "<<infos(s).suite<<" Ditambahkan !";
                        getch();
                    }
                }
                else
                {
                    cout<<endl;
                    cout<<"Room ada di List"<<endl;
                    getch();
                }
            }
        }
    }
}
void DeleteKota(multilist &l)
{
    infotypeK a;
    addresskota k,x;

    cout<<"Masukkan Nama Kota : ";
    cin>>a.kota;
    k=cariK(l,a);

    if(k==nil)
    {
        a.hotels=0;

        k=alokasik(a);
        if(first(l)==nil)
        {
           cout<<"Tidak ada kota yang ada"<<endl;
        }


        cout<<endl;
        cout<<"Tidak ada kota yang ada"<<endl;
        getch();
    }
    else
    {
        cout<<endl;
        if (first(l) == k && first(l) != last(l))
        {
            x= first(l);
            first(l)= nextk(first(l));
            prevk(first(l))=NULL;
            nextk(x)=NULL;
            prevk(x)=NULL;
            //dealokasik(x);
        }
        else if (first(l) == k && first(l) == last(l))
        {
            x= first(l);
            nextk(x)=NULL;
            first(l)=NULL;
        }
        else if (last(l)== k)
        {
            x= last(l);
            last(l)= prevk(last(l));
            prevk(x)=NULL;
            nextk(last(l))=NULL;
            //dealokasik(x);
        }
        else
        {
            addresskota q,i,m;
            q=k;
            i= prevk(q);
            m=nextk(q);
            x= q;
            nextk(i)= nextk(x);
            prevk(m)= i;
            nextk(x)= NULL;
            prevk(x)=NULL;
            //dealokasik(x);
        }
         cout<<endl;
        cout<<"Kota "<<infok(x).kota<<" Dihapus"<<endl;
        dealokasik(x);
        getch();
    }


}
