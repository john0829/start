#ifndef ENTER_H_INCLUDED
#define ENTER_H_INCLUDED
#include "cppunitlite/TestHarness.h"
#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
#include "test.h"

using namespace std;
Vector stringtodouble(string word,int &num)
{
    stringstream aa;
    stringstream change;
    char place;
    int i=0,dim=1,continueok=1,counter=1,over=0;
    string vecsum[100];
    double * const x = new double[100];
    aa<<word;
    aa>>place;
    while(!aa.eof())
    {
        while(isspace(word[counter-1]))
            counter++;

        if(place=='-')
        {
            change<<place;
            aa>>place;
            counter++;
        }
        if(isdigit(place))
        {
            change<<place;
            while(isdigit(word[counter]))
            {
                aa>>place;
                change<<place;
                counter++;
            }
            change>>x[dim-1];
            aa>>place;
            if(place=='\\')
            over=1;

            counter++;
            dim++;
    }
    change.clear();
    counter++;
    if(over==1)
        break;
    }
    dim--;
    for(i=0;i<dim;i++)
    {
        cout<<x[i]<<" "<<"hi"<<endl;
        cout<<i<<endl;
    }
    Vector v(dim,x);
    cout<<"dim"<<dim<<endl;

    for(int j=1;j<=5;j++)
        cout<<"component111"<<v.component(j)<<endl;
    return v;

}

void enter()
{
    int gameover=0,dimension=0,surefrontisdigit=0,wrong=0,num=0,arraynum=0;
    int x=1,y=0,i=0;
    string vec[100];
    int counter[100];
    char place;
    stringstream ss;
    while(gameover==0)
    {
      cout<<"a workspace is a way to seperate every number"<<endl;
      cout<<"enter your vector(a row is a vector)"<<endl;
      getline(cin,vec[arraynum]);
      ss.clear();
      ss<<vec[arraynum];
      ss>>place;
    while(!ss.eof())
    {
      cout<<place<<endl;
      if(isdigit(place))
        ss>>place;
        else if(place=='-')
        ss>>place;
        else if(place=='\\')
        {
        gameover=1;
          break;
        }
        else if(place=='\n')
        {
        cout<<endl;
        cout<<"your enter is wrong,please enter again"<<endl;
         while(!ss.eof())
         ss>>place;

         wrong=1;
           break;
        }
        else
        {
         cout<<endl;
         cout<<"your enter is wrong,please enter again"<<endl;
            while(!ss.eof())
            ss>>place;

            wrong=1;
             break;
        }
    }
    if(wrong==0)
     {
         arraynum++;
            num++;
     }
     wrong=0;
 }
    cout<<"correct"<<endl;
    Vector vs[arraynum];
    int dimensionwrong=0;
    for(i=0;i<arraynum;i++)
    {
        vs[i]=stringtodouble(vec[i],dimension);
        if(vs[i].dimension()!=vs[0].dimension())
        {
            dimensionwrong=1;
            cout<<"dimensionwrong!!!! enter again please!!!"<<endl;
            break;
        }
        for(int j=1;j<=5;j++)
            cout<<"component"<<vs[i].component(j)<<endl;
    }
    if(dimensionwrong==1)
        enter();

    matrix cp(arraynum,vs);
    cp.reduce();
    Vector t=cp.vertex(1);
    cp.independent();
    cp.pivotnumpoint();


}













#endif // ENTER_H_INCLUDED
