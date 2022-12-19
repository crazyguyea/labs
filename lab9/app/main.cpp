#include <iostream>
#include "C:\Users\crazy\Downloads\Lab_9\Objects\objects.h"
using namespace std;

int main(int argc, char* argv[]) {

Route route;
route.checkArgc(argc);

IVehicle* vehicle[4] = { new Sedan, new Bicycle, new Bus, new Suv };

string place = argv[1];
route.openFile(place);

for (int i = 0; i < 4; i++){
    route.run(vehicle[i]);
    vehicle[i]->printStatus();
}

return 0;
}
