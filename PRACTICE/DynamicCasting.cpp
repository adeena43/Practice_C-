#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
    virtual void speak() const {
        std::cout << "Animal speaks\n";
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof\n";
    }
};

class Cat: public Animal{
	public:
		void speak() const override{
			std::cout<<"Meow!!\n";
		}
};

class Lion: public Animal{
	public:
		void speak() const override{
			std::cout<<"Roarrr!!\n";
		}
};

void makeSpeak(Animal& animal)
{
	const Dog* dog = dynamic_cast<Dog*>(&animal);
	if(dog)
	{
		dog->speak();
	}
	
	const Cat* cat = dynamic_cast<Cat*>(&animal);
	if(cat)
	{
		cat->speak();
	}
	
	const Lion* lion = dynamic_cast<Lion*>(&animal);
	if(lion)
	{
		lion->speak();
	}
	
	animal.speak();	
}

int main()
{
	Animal ani;
	Dog d1;
	Cat c1;
	Lion l1;
	makeSpeak(ani);
	makeSpeak(d1);
	makeSpeak(c1);
	makeSpeak(l1);
	
}
