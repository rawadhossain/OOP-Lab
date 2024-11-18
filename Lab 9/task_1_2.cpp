#include <iostream>
#include <string>
using namespace std;

class LibraryResource
{
protected:
    string title;
    string author;
    double price;

public:
    LibraryResource(string title, string author, double price) : title(title), author(author), price(price) {}

    virtual void resourceDetails() = 0; // Task - 2
    virtual ~LibraryResource()
    {
    }
};

//  Task - 1
enum class CoverType
{
    Hardcover,
    Paperback
};

class Book : public LibraryResource
{
private:
    CoverType cover_type;

public:
    Book(string title, string author, double price, CoverType cover_type)
        : LibraryResource(title, author, price), cover_type(cover_type) {}

    void resourceDetails() override
    {
        cout << "Book: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Cover Type: " << (cover_type == CoverType::Hardcover ? "Hardcover" : "Paperback") << endl;
    }
};

class EBook : public LibraryResource
{
private:
    double file_size;

public:
    EBook(string title, string author, double price, double file_size)
        : LibraryResource(title, author, price), file_size(file_size) {}

    void resourceDetails() override
    {
        cout << "EBook: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "File Size: " << file_size << " MB" << endl;
    }
};

class Audiobook : public LibraryResource
{
private:
    int duration;

public:
    Audiobook(string title, string author, double price, int duration)
        : LibraryResource(title, author, price), duration(duration) {}

    void resourceDetails() override
    {
        cout << "Audiobook: " << endl;
        cout << "Title: " << title << " Author: " << author << endl;
        cout << "Price: " << price << " Duration: " << duration << " minutes" << endl;
    }
};

int main()
{
    LibraryResource *resource_list[100];

    resource_list[0] = new Book("The Alchemist", "Paulo Coelho", 500, CoverType::Hardcover);
    resource_list[1] = new EBook("1984", "George Orwell", 300, 2.5);
    resource_list[2] = new Audiobook("Becoming", "Michelle Obama", 700, 120);

    for (int i = 0; i < 3; i++)
    {
        resource_list[i]->resourceDetails();
        cout << endl;
    }

    return 0;
}