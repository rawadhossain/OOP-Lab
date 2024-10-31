#include <iostream>
#include <string>
#include <list>
using namespace std;

struct YouTubeChannel
{
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscribersCount)
    {
        this->Name = name;
        this->SubscribersCount = subscribersCount;
    }

    bool operator==(const YouTubeChannel &channel) const
    {
        return this->Name == channel.Name;
    }
};

ostream &operator<<(ostream &COUT, YouTubeChannel &ytChannel)
{
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;

    return COUT;
}

struct MyCollection
{
    list<YouTubeChannel> lst;

    void operator+=(YouTubeChannel &channel)
    {
        this->lst.push_back(channel);
    }
    void operator-=(YouTubeChannel &channel)
    {
        this->lst.remove(channel);
    }
};

ostream &operator<<(ostream &COUT, MyCollection &myCollection)
{
    for (YouTubeChannel ytChannel : myCollection.lst)
        COUT << ytChannel << endl;

    return COUT;
}

int main()
{
    YouTubeChannel yt1 = YouTubeChannel("CodeBeauty", 75000);
    YouTubeChannel yt2 = YouTubeChannel("My second channel", 80000);

    cout << yt1 << endl;
    cout << yt2 << endl;

    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    // myCollection -= yt2;

    cout << myCollection;

    cin.get();
}