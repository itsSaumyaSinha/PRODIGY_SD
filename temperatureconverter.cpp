#include<iostream>
#include<stdlib.h>

using namespace std;

void celconverter(float celsius=0)
{   float fahrenheit=0,kelvin=0;
     cout<<"Enter your [DEGREE CELSIUS]";
     cin>>celsius;
    //celsius to fahreheit
    fahrenheit = (celsius * 9 / 5) + 32;
    cout<<"Degree fahrenheit is\t"<<fahrenheit<<endl;
    //celsius to kelvin
     kelvin = celsius+ 273.15;
     cout<<"Degree kelvin is\t"<<kelvin<<endl;
}

void fahrenconverter(float fahrenheit=0)
{   float kelvin=0,celsius=0;
    cout<<"Enter your[DEGREE FAHREHEIT]";
    cin>>fahrenheit;
    //fahreheit to kelvin
    kelvin = (fahrenheit + 459.67) * 5/9;
    cout<<"Degree kelvin is\t"<<kelvin<<endl;
    //fahrenheit to celsius
    celsius= (fahrenheit-32)*5/9 ;
    cout<<"Degree Celsius is\t"<<celsius<<endl;
}

void kelconverter(float kelvin=0)
{  float fahrenheit=0,celsius=0;
    cout<<"Enter your[DEGREE KELVIN]";
    cin>>kelvin;
    //kelvin to fahrenheit
    fahrenheit=(kelvin* 9/5 )-459.67;
    cout<<"Degree fahreheit is\t"<<fahrenheit<<endl;
    //kelvin to celsius
    celsius=kelvin-273.15;
    cout<<"Degree celsius is\t"<<celsius<<endl;

}

int main()
{ int choice;
    cout<<"WHAT DO YOU GO ON WITH:"<<endl
        <<"1:CELSIUS"<<endl
        <<"2:FAHREHEIT"<<endl
        <<"3:KELVIN"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:  celconverter();
        break;
        case 2: fahrenconverter();
        break;
        case 3: kelconverter();
        break;

    }
    cout<<"ENDED";   
}