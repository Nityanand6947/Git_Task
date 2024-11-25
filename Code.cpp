#include<iostream>
using namespace std;

int main(){
    string name;
    int age;
    cout<<"Enter your name"<<endl;
    getline(cin,name);
    cout<<"Enter you age"<<endl;
    cin>>age;
    cout<<"Hey it's "<<name<<endl;
    cout<<"And age is "<<age<<endl;
}