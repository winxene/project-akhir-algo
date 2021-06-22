//2440052192-Fadhil Catrapraja Mus Saeho
//2440066815-Winxen Eric Ryandiharvin
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

//Struct to define info datatype
struct info
{
  string name;
  int weight;
  float height;
  string bmi_data;
}data[100000];

//Functions to calculate BMI
float bmi(int weight, float height)
{
    float bmi_result= weight/(pow((height),2));
   return bmi_result;
}

int main()
{
    
    int j=0; //int j=0 used at while loop function
    //mainmenu
    mainmenu:
        cout<<"\nWelcome to BMI Calculator, what would you want to do?\n";
        cout<<"\n";
        cout<<"Note that BMI= weight/(height)^2\n";
        cout<<"1. New BMI Data\n";
        cout<<"2. Load BMI Data\n";
        cout<<"3. BMI Info\n";

        //Menu interface
        int option;
        do
        {
            cout<<"Option: ";
            cin>>option;
        }while(option>3 && option<1);

        //Option 1: Creating & Storing BMI DATA
        if(option==1)
        {
            cout<<"\n";
            cout<<"\n";
            cout<<"New BMI Data\n";
            ofstream outfile;
            outfile.open("bmi.dat");
            int people, i;
            printf("Number of People: ");scanf("%d",&people);
            for(i=0; i<people; i++)
            {
                printf("Insert name of person number %d: ",i+1); cin>>data[i].name;
                fflush(stdin);
                cout<<"Insert "<<data[i].name<<"'s weight in kg: ";cin>>data[i].weight;
                fflush(stdin);
                do
                {
                    cout<<"Insert "<<data[i].name<<"'s height in m: ";cin>>data[i].height;
                    fflush(stdin);
                }while(data[i].height>3);
            }
            //Processing BMI Data + storing them as strings
            while(j<people)
            {
                if (bmi(data[j].weight,data[j].height)<18.5)
                {
                    string str1=" is underweight with BMI value: ";
                    string number=to_string(bmi(data[j].weight,data[j].height));
                    data[j].bmi_data=data[j].name+str1+number;
                    outfile<<data[j].bmi_data<<endl;
                }
                else if (bmi(data[j].weight,data[j].height)<25)
                {
                    string str1=" is normal weight (Ideal) with BMI value: ";
                    string number=to_string(bmi(data[j].weight,data[j].height));
                    data[j].bmi_data=data[j].name+str1+number;
                    outfile<<data[j].bmi_data<<endl;    
                }
                else if (bmi(data[j].weight,data[j].height)<30)
                {
                    string str1=" is overweight with BMI value: ";
                    string number=to_string(bmi(data[j].weight,data[j].height));
                    data[j].bmi_data=data[j].name+str1+number;
                    outfile<<data[j].bmi_data<<endl;
                }
                else
                {
                    string str1=" is obese with BMI value: ";
                    string number=to_string(bmi(data[j].weight,data[j].height));
                    data[j].bmi_data=data[j].name+str1+number;
                    outfile<<data[j].bmi_data<<endl;
                }
                fflush(stdin);
                j++;
            }
            outfile.close();

            //Options to quit or return to the main menu
            cout<<"Your data has been saved!, would you want to return to main menu?\n";
            cout<<"1. yes\n";
            cout<<"2. no\n";
            do
            {
                cout<<"Option: ";
                cin>>option;
            }while(option>2 && option<1);
            if(option==1)
            {
                goto mainmenu;
            }
            else
            {
                printf("Thank you for using this application\n");
            } 
        }
        //Showing BMI DATA
        else if(option==3)
        {
            printf("BMI Indicator\n");
            printf("BMI <18.5= Underweight\n");
            printf("BMI 18.5-15= Ideal Weight\n");
            printf("BMI 25-30= Overweight\n");
            printf("BMI >30= Obese\n");
            goto mainmenu;
        }
        //Load BMI DATA
        else
        {
            cout<<"\n";
            cout<<"\n";
            ifstream infile; 
            infile.open("bmi.dat"); 
            cout<<"Here is the result of BMI which have been captured: \n";
            do
            {
                getline(infile,data[j].bmi_data);
                cout<<data[j].bmi_data<<endl;
                infile.clear();
            }while(!infile.eof()&& !data[j].bmi_data.empty());
            infile.close();

            //Options to quit or return to the main menu
            cout<<"That's all, would you want to return to main menu?\n";
            cout<<"1. yes\n";
            cout<<"2. no\n";
            do
            {
                cout<<"Option: ";
                cin>>option;
            }while(option>2 && option<1);
            if(option==1)
            {
                goto mainmenu;
            }
            else
            {
                printf("Thank you for using this application\n");
            } 
        }
        return 0;
}