#include<iostream>

using namespace std;

int main(){
    float operand1,operand2;
    char _operator;
    int choice=0;
    while(choice==0){
        cout<<"CALCUTOR"<<endl;
        cin>>operand1>>_operator>>operand2;
        if(_operator=='+'){
            cout<<operand1+operand2<<endl;
        }
        else if(_operator=='-'){
            cout<<operand1-operand2<<endl;
        }
        else if(_operator=='*'){
            cout<<operand1*operand2<<endl;
        }
        else if(_operator=='/'){
            cout<<operand1/operand2<<endl;
        }
        else{
            cout<<"PLEASE USE THE RIGHT INPUT";
        }
        cout<<"TO D0 AGAIN ENTER 0\n TO END ENTER 1 "<<endl;
        cin>>choice;
    }
    return 0;
}

