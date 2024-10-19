#include <iostream>
#include <string>
using namespace std;

// Interface equivalent in C++
class A
{
public:
    void hello(); // Pure virtual function
};

// Enum class for Week
enum class Week
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
    // these are enum constants
    // public, static and final
    // since its final you cannot create child enums
    // type is Week
};

// Class to handle Week functionality
class WeekHandler : public A
{
public:
    Week week;

    WeekHandler(Week w) : week(w)
    {
        cout << "Constructor called for " << getDayString() << endl;
    }

    void hello()
    {
        cout << "hey how are you" << endl;
    }

    string getDayString()
    {
        switch (week)
        {
        case Week::Monday:
            return "Monday";
        case Week::Tuesday:
            return "Tuesday";
        case Week::Wednesday:
            return "Wednesday";
        case Week::Thursday:
            return "Thursday";
        case Week::Friday:
            return "Friday";
        case Week::Saturday:
            return "Saturday";
        case Week::Sunday:
            return "Sunday";
        default:
            return "Unknown";
        }
    }
};

int main()
{
    WeekHandler week(Week::Monday);
    week.hello();
    cout << "Week value: " << week.getDayString() << endl; // Equivalent to Week.valueOf("Monday")
    // for(Week day : Week.values()) {
    //     cout << day << endl;
    // }

    // cout << week.ordinal();
    return 0;
}
