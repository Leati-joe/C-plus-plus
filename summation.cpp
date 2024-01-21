#include<iostream>

int main()
{
    //code to calculate the summation of i mulptipled by a constant from i=1 to i=n
    std::cout<<"Constant you want to multiply i against: ";
    int multiplier;
    std::cin>>multiplier;
    std::cout<<"Maximum limit of i: ";
    int limit;
    std::cin>>limit;
    if(limit > 0 and limit != 0)
    {
        int total = 0;
        for(int i=1; i<=limit; i++)
        {
            int summation = multiplier*i;
            total += summation;
        }
        std::cout<<total<<::std::endl;
    }
    else
    {
        std::cout<<"Limit should be a natural number\n";
    }
}

