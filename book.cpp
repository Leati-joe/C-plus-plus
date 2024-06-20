/*
C++ code to create books
Attributes associated with a book are passed in by the user
They are then used to create a book object
Once created, the book number based on previously instantiated books is stated and the books attributes printed
All this done by invoking one funtion: create()

        SAMPLE
        Title: The Sweetest Oblivion
        Author: Danielle Lori
        Publisher: Createspace Independent Publishing Platform
        Audience: Dark Romantics
        Pages: 386

        Rating: based on how many times the user rates the book, the average is taken

*/

#include<iostream>
#include<string>

int count = 0;      //keeps count of the number of books instantiated

class Book
{
public:
    std::string title;
    std::string author;
    std::string publisher;
    int pages;
    std::string audience;
    float ratings=0;
    bool flag = 0;
    float *rates;
    int rates_counter;

    float rating()
    {
       if(flag == 1)
       {
         for(int i=0; i<rates_counter; i++)
         {
             ratings += rates[i];
         }
         ratings = ratings/rates_counter;
       }
        return ratings;
    }


    //constructor 
    Book(std::string title, std::string author, std::string publisher, std::string audience, int pages, float rate_array[], const int rates_count,bool flag)
    {
        this -> title=title;
        this -> author=author;
        this -> publisher=publisher;
        this -> pages= pages;
        this -> audience=audience;
        rates_counter = rates_count;
        rates= new float[rates_count];
        for(int i=0; i<rates_count; i++)
        {
            rates[i]=rate_array[i];
        }
        this -> flag = flag;
    }

    //copy constructor
    Book(const Book &original)
    {
        title = original.title;
        author = original.author;
        pages = original.pages;
        audience = original.audience;
        publisher = original.publisher;
        rates_counter = original.rates_counter;
        flag = original.flag;
        rates = new float[rates_counter];
        for(int i=0; i<rates_counter; i++)
        {
            rates[i]=original.rates[i];
        }
    }

    //destructor 
    //invoked at the end of the scope of a Book object
    ~Book()
    {
        std::cout<<"DESTRUCTOR INVOKED\n";
        delete []rates;
        rates = nullptr;
    }

};

Book take_data();
void print_book(Book book);
void create();


int main()
{
    create();
}


Book take_data()
{
    //function that takes data about a book from user 
    std::string title;
    std::string author;
    std::string publisher;
    std::string audience;    //To whom is the book recommended
    int pages;
    std::cout<<"Title: ";
    getline(std::cin, title);
    std::cout<<"Author: ";
    getline(std::cin, author);
    std::cout<<"Publisher: ";
    getline(std::cin, publisher);
    std::cout<<"Audience: ";
    getline(std::cin, audience);
    std::cout<<"Pages: ";
    std::cin>>pages;
    //size of the array "rates" below
    int size=0;
    float rates[size];
    std::cout<<"Will you rate the book(YES: press 1\t NO: press 0)\n";
    bool flag;
    std::cin>>flag;
    if(flag == 1)
    {
        std::cout<<"\t\tRatings out of five\n";
        //do..while loop to make the user rate the book at least three times
        do
        {
            //from the frequency at which the author rates the book, the average is calculated
            std::cout<<"\tYou can rate three times at maximum\n"
                     <<"How many times do you want to rate the book:";
            std::cin>>size; 
            if(size==1)
            {
                std::cout<<"Rate the book once";
                break;
            } 
            else if(size == 2)
            {
                std::cout<<"Rate the book twice\n";
                break;
            }
            else
            {
                std::cout<<"Rate the book thrice\n";
                break;
            }
        }while(size<=0 && size > 3);
        //an array that stores the ratings and the size of the array

        int i=0;
        while(i<size)
        {
            if(size==1)
            {
                std::cout<<"Rating: ";
                std::cin>>rates[i];
                i++;
            }
            else
            {
                std::cout<<"Rating "<<i+1<<": ";
                std::cin>>rates[i];
                i++;
            }
            
        }
    }
    //instantiating a book based on the user input above
    Book book(title, author, publisher, audience, pages, rates, size, flag);
    count++;        
    //returning the book from the function
    return book;
    //DESTRUCTOR IS INVOKED
}


void print_book(Book book)
//Prints the data of an instantiated book
{
    std::cout<<"\n\n\t\tBOOK "<<count<<std::endl;
    std::cout<<"TITLE: "<<book.title<<std::endl;
    std::cout<<"AUTHOR: "<<book.author<<std::endl;
    std::cout<<"PAGES: "<<book.pages<<std::endl;
    std::cout<<"PUBLISHER: "<<book.publisher<<std::endl;
    std::cout<<"AUDIENCE: "<<book.audience<<std::endl;
    std::cout<<"RATING: "<<book.rating()<<" star"<<std::endl;
    std::cout<<"\n\n";
    
    //DESTRUCTOR INVOKED
}


void create()
{
    Book book=take_data();
    print_book(book);
}