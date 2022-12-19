#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class IVehicle {
public:
	virtual bool drive(float kilometers) = 0;
	virtual void refuel() = 0;
	virtual void printStatus() = 0;
};

class Bicycle : public IVehicle {
protected:
	float mileage = 0;
public:
	~Bicycle() {};

	bool drive(float kilometers) {
		mileage += kilometers;
		return true;
	}

	void refuel() {};

	void printStatus() {
		cout << mileage << endl;
	}
};

class Vehicle : public IVehicle {//class AbstractCar

protected:
	float mileage = 0.0;
	float fuel = 0.0;

	float capacity;
	float fuel_flow;
public:
	~Vehicle() {};

	bool drive(float kilometers) {
		float calculation = ((kilometers / 100.0) * fuel_flow);
		float maxCapacity = capacity / ((kilometers / 100.0) * fuel_flow);
		float remains = kilometers;
		if (calculation <= fuel) {
			mileage += kilometers;
			fuel -= calculation;
			cout << endl;
			cout << "Distance was drove" << endl;
			cout << endl;
			return true;
		}
		else {
			while(remains > maxCapacity){
				cout << "Not petrol" << endl;
				refuel();
				cout << "refuel" << endl;
				remains -= maxCapacity;
				mileage += maxCapacity;
				fuel -= capacity;
			}
			if (remains > 0.0) {
				refuel();
				mileage += remains;
				fuel -= calculation;
			}
		}
	}


	void refuel() {
		fuel = capacity;
	}

	void printStatus() {
		cout << endl;
		cout << mileage << endl;
		cout << fuel << endl;
		cout << endl;
	}

};

class Sedan : public Vehicle {

public:
	Sedan() {
		cin >> this->capacity;
		cin >> this->fuel_flow;
	};
	~Sedan() {};
};

class Bus : public Vehicle {

public:
	Bus() {
		cin >> this->capacity;
		cin >> this->fuel_flow;
	};
	~Bus() {};
};

class Suv : public Vehicle {

public:
	Suv() {
		cin >> this->capacity;
		cin >> this->fuel_flow;
	};
	~Suv() {};
};

struct RoutePoint {
	float xKm;
	float yKm;
	string name;

	RoutePoint(float xKm, float yKm, string name) {
		this->xKm = xKm;
		this->yKm = yKm;
		this->name = name;
	}
};

class Route {
private:
	vector<RoutePoint>points;
public:
	Route() {};
	~Route() {};

	void addPoint(const RoutePoint& point) {
		points.push_back(point);
	}
	void run(IVehicle* vehicle) {
		if (points.size() > 1) {
			float distance = 0.0;
			for (int i = 0; i < points.size() - 1; i++) {
				distance = sqrt( pow( (points[i + 1].xKm - points[i].xKm), 2) + pow((points[i + 1].yKm - points[i].yKm), 2));
				vehicle->drive(distance);
			}
		}
		else {
			cout << "Error" << endl;
		}
	}
	void checkArgc(int argc){
		if (argc < 2) {
			cout << "Error of parameters" << endl;
			exit(1);
		}
	}

	void openFile(string place){
		string path = "C:/Users/crazy/Desktop" + place;
		
		ifstream file(path);

		if (file.is_open()){
			cout << endl;
			cout << "File open" << endl;
			cout << endl;
			
			string txt;
			
			float x, y;

			while (!file.eof()){
				int count = 1;
				switch (count){
					case 1:
						file >> txt;
						x = atof( (txt).c_str() );
						count++;

					case 2:
						file >> txt;
						y = atof( (txt).c_str() );
						count++;
					case 3:
						file >> txt;

						addPoint(RoutePoint(x, y, txt));

						count = 1;
				}
					
			}

		}
		else{
			cout << "File not open" << endl;
		}
	}
};

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