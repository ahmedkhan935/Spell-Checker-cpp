#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
static const char alpha[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int length(string x) //length of string
{
    int i;
    for(i=0;x[i]!='\0';i++);
    return i;

}
string lower(string x) //converting to lowercase
{
    for(int g=0;g<(length(x));g++)
        {
            x[g]=tolower(x[g]);
        }
        return x;
}
string add(string x,char alph)
{
    return x+alph;
}

string sort(string x)//sorting of string
{
    for(int i=0;i<length(x);i++)
    {
        for(int j=i+1;j<length(x);j++)
        {
            if(((int)x[i])>((int)x[j]))
            {
                int temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }
    }
    return x;
}
string first(string x,char y)
{
    char arr[length(x)+1];
    for(int i=0;i<(length(x)+1);i++)
    {
        if(i==0)
            arr[i]=y;
        else
            arr[i]=x[i-1];
    }
    string news=arr;
    return news;
}
void suggest1(string word,string check,bool &sug)
{
    string new1,new2,new3,new4;
    for(int i=0;i<=25;i++)
    {

        if(length(check)==(length(word)+1))
        {
            new1=add(word,alpha[i]);
            new2=new1.substr(1,length(new1)-1);
            new2=sort(new2);
            new2=first(new2,new1[0]);
            new4=check.substr(1,length(check)-1);
            new4=sort(new4);
            new4=first(new4,check[0]);
            if(new2==new4)
            {
                cout<<"Did you mean: "<<check<<endl;
                sug=true;
                break;
            }
        }
    }

}
void suggest2(bool &sug,string word,string check)
{
    string new1=word;
    if((length(word)-1)==length(check))
    {
        for(int i=0;i<length(word);i++)
        {
            word.erase(word.begin()+i);
            if(word==check)
            {
                cout<<"Did you mean: "<<check<<endl;
                sug=true;
                break;
            }
            word=new1;
        }
    }

}
void suggest3(string word,string check,bool &sug)
{   if(length(word)==length(check))
    {
        string new1=word,new2,new3,new4,new5;
        bool extra=false;
        for(int i=1;i<length(word);i++)
        {
            word.erase(word.begin()+i);
            for(int j=0;j<26;j++)
            {
                new3=word;
                word=word+alpha[j];
                word.erase(0,1);
                word=sort(word);
                new2=new1[0]+word;
                new4=check;
                check.erase(0,1);
                check=sort(check);
                new5=new3[0]+check;
                check=new4;
                word=new3;
                if(new2==new5)
                {
                    cout<<"Did you mean: "<<check<<endl;
                    sug=true;
                    extra=true;
                    break;
                }
            }
            word=new1;
            if(extra)
                break;
        }
    }
}
void suggest4(string word,string check,bool &sug)
{
    word=sort(word);
    string new1=check;
    check=sort(check);
    if(word==check)
    {
        cout<<"Did you mean: "<<new1<<endl;
        sug=true;
    }
}
