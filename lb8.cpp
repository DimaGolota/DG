#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <regex>
#include <fstream>
using namespace std;


class Except{
protected:
    char err[255];
public:
    Except(char* s){
        strcpy(err,s);
    }

    void what(){
        cout<<err<<endl;
    }
};


class Complexn{
    char re[65535];
    int kre; 
public:
    Complexn(string r);
    Complexn(char r[]);
    void show();
    int kkre();

    Complexn operator +(Complexn &o2);
    Complexn operator -(Complexn &o2);
    Complexn operator <(Complexn &o2);
    Complexn operator >(Complexn &o2);
    Complexn operator <= (Complexn &o2);
    Complexn operator >=(Complexn &o2);
    bool operator ==(Complexn &o2);
    bool operator !=(Complexn &o2);

    void* operator new(size_t size);
    void* operator new[](size_t size);
    void operator delete(void *p);
    void operator delete[](void *p);
};

void* Complexn::operator new(size_t size){
void *p;
p=malloc(size);
if(!p){
    bad_alloc pp;
    throw pp;
}
}
void Complexn::operator delete(void *p){
free(p);
}
void* Complexn::operator new[](size_t size){
void *p;
p=malloc(size);
if(!p){
bad_alloc pp;
throw pp;
}
}
void Complexn::operator delete[](void *p){
free(p);
}




int Complexn::kkre(){
    kre = strlen(re);
    return kre;
}

Complexn::Complexn(string r){
    strcpy(re,r.c_str());
    kre = strlen(re);
}
Complexn::Complexn(char r[]){
    int kre = strlen(r)+1;
    for (int i=0; i<kre; i++){
        re[i]= r[i];
    }
}
void Complexn::show(){
    cout<<re<<endl;
}

Complexn Complexn::operator+(Complexn &o2){
    
    return strcat(re, o2.re );
}

Complexn Complexn::operator-(Complexn &o2){
    string n = regex_replace(re,regex(o2.re)," ");
    if(n.length()<2){
        throw(Except ("??????? ? ?????????i '-'"));
    }
    
    return n;
}

Complexn Complexn::operator<(Complexn &o2){
    if(re<o2.re){
        return re;
    }
    else{
        return o2.re;
    }
    
}
Complexn Complexn::operator>(Complexn &o2){
    if(re>o2.re){
        return re;
    }
    else{
        return o2.re;
    }
    
}
Complexn Complexn::operator<=(Complexn &o2){
    if(re<=o2.re){
        return re;
    }
    else{
        return o2.re;
    }
    
}
Complexn Complexn::operator>=(Complexn &o2){
    if(re>=o2.re){
        return re;
    }
    else{
        return o2.re;
    }
    
}
bool Complexn::operator==(Complexn &o2){
    if(re==o2.re){
        return true;
    }
    else{
        return false;
    }
    
}
bool Complexn::operator!=(Complexn &o2){
    if(re!=o2.re){
        return true;
    }
    else{
        return false;
    }
    
}



int main()
{
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
try{
    string a;
    cin>>a;
    string b("ddddddddd");
    char c[] ="Hello";
    Complexn obj1(a);
    Complexn obj2(b);
    Complexn obj3(c);

    ifstream fin;
    fin.open("lb8i.txt");
if (!fin) throw Except("Input file open error");
    float ab,ba;
    fin>>ab>>ba;
if (ba==0) throw Except("b=0!!!! ");

ofstream fout;
fout.open("lb8o.txt");
if(!fout) throw Except("Output file open error");
fout<<ab/ba;
fout.close();
fin.close();

    cout<<"obj1: ";
    obj1.show();
    cout<<"obj2: ";
    obj2.show();
    cout<<"obj3: ";
    obj3.show();
    cout<<endl;
    obj3 = obj1+obj2;
    cout<<"obj3 = obj1+obj2: ";
    obj3.show();
    obj3 = obj3-obj1;
    cout<<"obj3 = obj3-obj1: ";
    obj3.show();
    obj3 = obj1<obj2;
    cout<<"?????? ????? obj1 i obj2: ";
    obj3.show();
    
    bool bb  = obj1 == obj2;
    cout<<"obj1 == obj2? "<<bb<<endl;
    bb = obj1!=obj2;
    cout<<"obj1 != obj2? "<<bb<<endl;
}
catch(Except &a){
    a.what();
}
catch(char *a){
    cout<<a<<endl;
}

catch(bad_alloc){
    cout<<"bad alloc"<<endl;
    return 1;
}
system("pause");
cin.get();
return 0;
}