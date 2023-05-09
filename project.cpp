#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<windows.h>
#include "testf.cpp"
using namespace std;
int main()
{
    char choice;
    do
    {
        string word,check;
        bool found=false;
        fstream ifs("dic.txt");         //opening file
        if (ifs.is_open())
        {
            cout<<"Enter the word"<<endl;       //input
            cin>>word;
            word=lower(word);
            while(getline(ifs,check))           //reading file
            {
                    if(word==check)             //found condition
                    {
                        found=true;
                        break;
                    }
            }
            if(found)
            {
                cout<<"Your spellings are correct"<<endl;
            }
        }
        ifs.close();            //file close
        bool sug=false;
        if(!(found))
        {
            fstream ifs("dic.txt");
            if(ifs.is_open())
            {
                while(getline(ifs,check))
                {
                    suggest1(word,check,sug); //functinons for suggestion
                    suggest2(sug,word,check);
                    suggest4(word,check,sug);

                }
            }
            if(!sug)
            {
                cout<<"No match"<<endl;
            }
        }
        ifs.close();
        cin.ignore();
        cout<<"Do you want to try again"<<endl;
        choice=getch();
        while(!(choice=='y' || choice=='Y' || choice=='n' || choice=='N'))
        {
            cout<<"Wrong choice.Please choose from Y or N"<<endl;
            choice=getch();
        }
        system("CLS");
        Sleep(1000);
    }while(choice=='y' || choice=='Y');
    cout<<"Thank you for using my spell checker.\nMADE BY AHMED RAZA\nBS SE P\n21I-1152"<<endl;
}
