#include <iostream>
#include <memory>
#include <map> 

class Car 
{
    public:
    Car(std::string brand, std::string colour):name(brand), color(colour){}

    friend std::ostream& operator<<(std::ostream& os , Car& object)
    {
        std::cout << "Samochod marki " << object.name << " w kolorze " << object.color << "\n";
        return os;
    }

    private:
    std::string name; 
    std::string color; 

};

class CarFactory
{
    public: 
    static CarFactory& getInstance(std::string brand)
    {
        static std::map<std::string,std::unique_ptr<CarFactory>> factories;
        if(factories.find(brand) == factories.end())
        {
            factories[brand] = std::unique_ptr<CarFactory>(new CarFactory(brand));
        }

        return *factories[brand];

    }

    Car createCar(std::string colour)
    {
        return Car(brand, colour);
    }

    bool operator==(const CarFactory& other)
    {
        return brand == other.brand;
    }

    private:
    std::string brand;

    CarFactory(std::string name):brand(name){}
};

int main(){
    CarFactory& fordFactory = CarFactory::getInstance("ford");
    CarFactory& fordFactory2 = CarFactory::getInstance("ford");
    CarFactory& toyotaFactory = CarFactory::getInstance("toyota");

    Car greenFord = fordFactory.createCar("zielony");
    Car redToyota = toyotaFactory.createCar("czerwony");

    std::cout<<greenFord<<redToyota<<(&fordFactory == &fordFactory2)<<std::endl;

    // poniższy kod powoduje błąd kompilacji

    // CarFactory customFactory("wlasna");
    // CarFactory namelessFactory;

    // Car customCar("wlasny");
    // Car namelessCar;
}
// Wyjscie:
// Samochod marki ford w kolorze zielony
// Samochod marki toyota w kolorze czerwony
// 1