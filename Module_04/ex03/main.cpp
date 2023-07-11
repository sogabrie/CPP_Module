#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSourc.hpp"
#include "Character.hpp"
#include <cstdlib>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

//////////////////////////////

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);

////////////////////////////////

	me->use(0, *bob);
	me->use(1, *bob);

////////////////////////////////

	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	me->use(5, *bob);
	me->use(-15, *bob);
	me->use(15, *bob);

///////////////////////////////

	delete bob;
	delete me;
	delete src;

	// system("leaks run");
	return (0);
}