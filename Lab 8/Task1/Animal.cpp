#include <iostream>
#include <string>

using namespace std;

class Animal
{
    string nameOfAnimal;
    string habitat_area;
    string sound;
    int weight;
    int height;

public:
    Animal(string Animal_Name, string Habitat_area, string animal_sound, int wt, int ht)
        : nameOfAnimal(Animal_Name), habitat_area(Habitat_area), sound(animal_sound), weight(wt), height(ht) {}

    void displayInformation()
    {
        cout << "Name: " << nameOfAnimal << endl;
        cout << "Habitat Area: " << habitat_area << endl;
        cout << "Sound: " << sound << endl;
        cout << "Weight: " << weight << endl;
        cout << "Height: " << height << endl;
    }

    void changeWeight(int wt)
    {
        weight = wt;
    }

    void make_sound()
    {
        cout << sound << endl;
    }
};

class Cow : public Animal
{
private:
    double milkProductionInLiters;

public:
    Cow(string Animal_Name, string Habitat_area, int wt, int ht, double milk_ProductionInLiters)
        : Animal(Animal_Name, Habitat_area, "moo", wt, ht), milkProductionInLiters(milk_ProductionInLiters) {}

    void make_sound()
    {
        cout << "The cow says: ";
        Animal::make_sound();
    }

    double getMilkProduction()
    {
        return milkProductionInLiters;
    }
};

class Chicken : protected Animal
{
private:
    int dailyEggCount;

public:
    Chicken(string Animal_Name, string Habitat_area, int wt, int ht, int egg_Count)
        : Animal(Animal_Name, Habitat_area, "buck buck", wt, ht), dailyEggCount(egg_Count) {}

    void make_sound()
    {
        cout << "The chicken says: ";
        Animal::make_sound();
    }

    int getEggCount()
    {
        return dailyEggCount;
    }
};

class Cat : private Animal
{
public:
    Cat(string Animal_Name, string Habitat_area, int wt, int ht)
        : Animal(Animal_Name, Habitat_area, "meow", wt, ht) {}

    void make_sound()
    {
        cout << "The cat says: ";
        Animal::make_sound();
    }
};

class PetCat : public Cat
{
private:
    string petName;

public:
    PetCat(string Animal_Name, string Habitat_area, int wt, int ht, string pet_Name) : Cat(Animal_Name, Habitat_area, wt, ht), petName(pet_Name) {}

    void make_sound()
    {
        cout << "Cat Name - " << petName << " says: ";
        Cat::make_sound();
    }
};

int main()
{
    Cow cow("Cow", "Farm", 100, 15, 10.5);
    cow.displayInformation();
    cow.make_sound();
    cout << "Milk Production: " << cow.getMilkProduction() << " L" << endl;

    cout << endl;

    Chicken chicken("Chicken", "Farm", 12, 22, 3);
    // chicken.displayInformation();  public function of base class not allowed in private inheritance
    chicken.make_sound();
    cout << "Daily Egg Count: " << chicken.getEggCount() << endl;

    cout << endl;

    Cat cat("Cat", "CatHouse", 4, 25);
    cat.make_sound();

    cout << endl;

    PetCat petCat("Cat", "CatHouse", 4, 25, "Persian");
    petCat.make_sound();

    return 0;
}
