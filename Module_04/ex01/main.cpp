#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();
	const WrongCat* i3 = new WrongCat();
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound();
	meta2->makeSound();
	i3->makeSound();

	delete meta2;
	delete i2;
	delete meta;

	Animal **mas = new Animal*[100];

	for (size_t i = 0; i < 100; i++)
	{
		if (i < 50)
		{
			mas[i] = new Dog();
		}
		else
		{
			mas[i] = new Cat();
		}
	}

	delete j;
	delete i;

	for (size_t i = 0; i < 100; i++)
		mas[i]->makeSound();

	for (size_t i = 0; i < 100; i++)
	{
		delete mas[i];
		mas[i] = 0;
	}
	
	delete[] mas;
	mas = 0;

	system("leaks run");
	
	return (0);
}