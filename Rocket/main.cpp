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
    int *S = new int[100]; // There are 100 stars by default
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


    for(int i=0;i<100;i++)
    {

      sum+=Get_Equation(Stars[i]); // Get The sum(Fuels) for all modules
    }

    return sum;
}

/////////////////////////////////////////////////

//Part2
int Get_Equation_Part_Two(int Mass)
{
    int sum = 0;
while((Mass/3)-2>0)
{

    Mass = (Mass/3)-2;
    sum+=Mass;
}
    return sum;
}
///////////////
int Get_Fuels_For_Part2(int *S)
{
    int sum = 0;
    for(int i=0;i<100;i++)
    {
        sum+=Get_Equation_Part_Two(S[i]);

    }
    return sum;
}

/////
int main()
{int Part ;
int *Stars= Read_Stars("Stars.txt");
cout<<"Part one ?? Part Two ??";
   cin>>Part;


   switch(Part){
   case 1:{
       cout<<"Part 1 ....";
    int choice ;
 // Read Text File
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


    for(int i=0;i<100;i++)
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

break;
}
break;
   }
   case 2:{


 int sumPart2 =  Get_Fuels_For_Part2(Stars);

 cout<<"Total Fuels in Part Two is :"<<sumPart2;

   }
break;
}
    return 0;
}
