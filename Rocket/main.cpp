#include <iostream>
#include<fstream>
using namespace std;

int Get_Equation(double Mass)
{

    return (Mass/3)-2;
}

///////////////////////
int * Read_Stars(string file_path)
{string star;
    ifstream MyReadFile(file_path);
    int count = 0;
    int *S = new int[55]; // There are 55 stars by default
    while (getline (MyReadFile, star)) {
    if(star!="")
S[count++] = stoi(star); // convert String into integer number

}
 MyReadFile.close();

 return S;
}

//////////////

int Get_Summation_For_All_Stars_Fuel(int *Stars)
{
    int sum = 0;


    for(int i=0;i<55;i++)
    {

      sum+=Get_Equation(Stars[i]); // Get The sum(Fuels) for all modules
    }

    return sum;
}



int main()
{int choice ;
int *Stars= Read_Stars("Stars.txt"); // Read Text File
cout<<"Do you want to solve puzzle automatic(1) or by thinking(2)";
cin>>choice;
switch(choice){

   case 1:{

  int sum =  Get_Summation_For_All_Stars_Fuel(Stars);

cout<<"Total Fuels for All modules is Equal to :"<<sum;
break;
   }
   case 2:
       {


    for(int i=0;i<55;i++)
    {

        cout<<i+1<<"-"<<Stars[i]<<"\n";

    }
    cout<<"\n--------------------------------------\n";
    L:cout<<"\nWhich Star's no you Want for example 1 ,2 or 3 ...etc\n\n";
    int stars_no ;
     cin>>stars_no;
     stars_no--;
    cout<<"\nThe star is :"<<Stars[stars_no]<<"\n";
    int Fules_need;
    cout<<"\nWhat is The needs of fuels You Think??";
    cin>>Fules_need;

    if(Fules_need==Get_Equation(Stars[stars_no]))
    {

        cout<<"It is True You Can Go !!!";
         goto L;
    }

    else
    {

        cout<<"\n No Go !!!!\n";
    }



    break;
       }

}
    return 0;
}
