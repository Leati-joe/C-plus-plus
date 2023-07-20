#include<iostream>
#include<string>

class Book
{
public:
    std::string title;
    std::string author;
    int pages;
    std::string recommendation;
    float *rates;
    int rates_counter;

    //a constructor that assigns values to the data members
    //during instantiation
    Book(std::string title, std::string author, std::string recommendation, 
    int pages, int array[], const int array_size)
    {
        this -> title=title;
        this -> author=author;
        this -> pages= pages;
        this -> recommendation=recommendation;
        rates_counter = array_size;
        rates= new float[rates_counter];
        for(int i=0; i<rates_counter; i++)
        {
            rates[i]=array[i];
        }
    }

    //destructor 
    ~Book()
    {
        delete []rates;
        rates = nullptr;
    }

    //copy constructor
    Book(const Book &original)
    {
        title = original.title;
        author = original.author;
        pages = original.pages;
        recommendation = original.recommendation;
        rates = new float[original.rates_counter];
        for(int i=0; i<original.rates_counter; i++)
        {
            rates[i]=original.rates[i];
        }
    }

};

void take_data();
void instantiate(std::string title, std::string author, std::string recommended, 
int pages, int rates[], int size);
void print_book(Book book);

//main
int main()
{
    take_data();
}

//function that takes data from user
void take_data()
{
    //pass in the title, author, number of pages to whom its recommended 
    //an array that stores the ratings and the size of the array
    std::string title;
    std::string author;
    std::string recommended;
    int pages;
    std::cout<<"Title of the book: ";
    getline(std::cin, title);
    std::cout<<"Author of the book: ";
    getline(std::cin, author);
    std::cout<<"To whom is the book recommended: ";
    getline(std::cin, recommended);
    std::cout<<"Number of pages of the book: ";
    std::cin>>pages;
    //size of the array "rates" below
    int size=0;
    std::cout<<"You can rate at maximum three times\n"
             <<"five star rating is considered the best\n"
             <<"No negative numbers\n";
    //do..while loop to ensure the user rates the book at least three times
    do
    {
        std::cout<<"How many times do you want to rate the book?";
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
            std::cout<<"Rate the book three times\n";
            break;
        }
    }while(size==0 && size > 3);
    int rates[size];
    int i=0;
    while(i<size)
    {
        std::cin>>rates[i];
        i++;
    }
    //the execution stops here
    //calling "instantiate" function in which I have instantiated my "book" class
    //declared at the start of the program
    instantiate(title, author, recommended, pages, rates, size);
}

void instantiate(std::string title, std::string author, std::string recommended, 
int pages, int rates[], int size)
{
    //instantiating our first book
    Book book1(title, author, recommended, pages, rates, size);
    //instantiating another book as we assign to it the properties of the book above
    //i.e making use of the copy constructor
    Book book2(book1);
    //Funstion call that prints out the properties of book2
    print_book(book2);
}

//function that prints the book
void print_book(Book book)
{
    std::cout<<"TITLE: "<<book.title<<std::endl;
    std::cout<<"AUTHOR: "<<book.author<<std::endl;
    std::cout<<"PAGES: "<<book.pages<<std::endl;
    std::cout<<"RECOMMEMDED TO: "<<book.recommendation;
    float sum=0;
    for(int i=0; i<book.rates_counter; i++)
    {
        sum +=book.rates[i];
    }
    std::cout<<"RATINGS = "<<sum/book.rates_counter<<std::endl;
}