#include <iostream>
#include <string>

using namespace std;

class LibraryResource
{
protected:
    string title;
    string author;
    double price;
    int no_of_copies;

public:
    LibraryResource(string title, string author, double price)
        : title(title), author(author), price(price), no_of_copies(1) {}

    virtual double get_price()
    {
        return price;
    }

    void set_no_of_copies(int no_of_copies)
    {
        this->no_of_copies = no_of_copies;
    }

    int get_no_of_copies()
    {
        return no_of_copies;
    }

    virtual void resourceDetails() = 0;
};

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
        cout << "No. of Copies: " << get_no_of_copies() << endl;
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
        cout << "No. of Copies: " << get_no_of_copies() << endl;
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
        cout << "No. of Copies: " << get_no_of_copies() << endl;
    }
};

void sort_resources_price(LibraryResource **resource_list, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (resource_list[i]->get_price() > resource_list[j]->get_price())
            {
                LibraryResource *temp = resource_list[i];
                resource_list[i] = resource_list[j];
                resource_list[j] = temp;
            }
        }
    }
}

int main()
{
    LibraryResource *resource_list[100];

    resource_list[0] = new Book("The Alchemist", "Paulo Coelho", 500, CoverType::Hardcover);
    resource_list[1] = new EBook("1984", "George Orwell", 300, 2.5);
    resource_list[2] = new Audiobook("Becoming", "Michelle Obama", 700, 120);

    resource_list[0]->set_no_of_copies(50);
    resource_list[1]->set_no_of_copies(5);
    resource_list[2]->set_no_of_copies(1);

    resource_list[3] = new Book("Sapiens", "Yuval Noah Harari", 1000, CoverType::Paperback);
    resource_list[4] = new EBook("Digital Minimalism", "Cal Newport", 400, 3.2);
    resource_list[5] = new Audiobook("Atomic Habits", "James Clear", 1200, 180);
    resource_list[6] = new Book("Dune", "Frank Herbert", 800, CoverType::Hardcover);
    resource_list[7] = new EBook("The Subtle Art of Not Giving a F*ck", "Mark Manson", 350, 1.8);
    resource_list[8] = new Audiobook("Educated", "Tara Westover", 600, 150);
    resource_list[9] = new Book("Harry Potter and the Philosopher's Stone", "J.K. Rowling", 450, CoverType::Paperback);

    sort_resources_price(resource_list, 10);

    /** Display sorted resources */
    for (int i = 0; i < 10; i++)
    {
        resource_list[i]->resourceDetails();
        cout << endl;
    }

    return 0;
}