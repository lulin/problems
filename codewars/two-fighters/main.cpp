#include <string>
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

class Fighter {
private:
  std::string name;

  int health;

  int damagePerAttack;

public:
  Fighter(std::string name, int health, int damagePerAttack) {
    this->name = name;
    this->health = health;
    this->damagePerAttack = damagePerAttack;
  }

  ~Fighter(){};

  std::string getName() { return name; }

  int getHealth() { return health; }

  int getDamagePerAttack() { return damagePerAttack; }

  void setHealth(int value) { health = value; }
};

std::string declareWinner(Fighter *fighter1, Fighter *fighter2,
                          std::string firstAttacker) {
  assert(fighter1 && fighter2);
  int survive1 = (fighter1->getHealth() - 1) / fighter2->getDamagePerAttack();
  int survive2 = (fighter2->getHealth() - 1) / fighter1->getDamagePerAttack();
  if (firstAttacker == fighter1->getName())
    return survive1 >= survive2 ? fighter1->getName() : fighter2->getName();
  else
    return survive2 >= survive1 ? fighter2->getName() : fighter1->getName();
}

int main(int argc, char *argv[]) {
  Fighter f1("heh", 10, 2);
  Fighter f2("haha", 5, 4);
  cout << "winner is " << declareWinner(&f1, &f2, f1.getName()) << endl;
  cout << "winner is " << declareWinner(&f1, &f2, f2.getName()) << endl;
  return 0;
}