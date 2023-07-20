#include<iostream>

int main()
{
    char c1, c2, c3, c4, c5;
    std::cout<<"Enter five letters\n";
    std::cin>>c1 >> c2 >> c3 >> c4 >> c5;
    std::cout<<"ASCII message: " << int(c1) <<" "<<int(c2)<<" "
    << int(c3) << " " << int(c4)<<" "<<int(c5)<<std::endl;
    int i1, i2, i3, i4, i5;
    i1=int(c1);
    i2=int(c2);
    i3=int(c3);
    i4=int(c4);
    i5=int(c5);
    std::cout<<"Deciphering codes: " <<char(i1)<<char(i2)<<char(i3)
    <<char(i4)<<char(i5);
}