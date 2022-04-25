#include "engine/universe_master.h"

int main(int argc, char const *argv[])
{
  UniverseMaster universe = UniverseMaster();

  Entity* entity1 = new Entity("Oui");
  entity1->addPhysic();
  entity1->getPhysic()->setMass(1);

  Entity* entity2 = new Entity("Non");
  
  universe.addEntity(entity1);
  universe.addEntity(entity2);
  
  universe.update();
  
  return 0;
}
