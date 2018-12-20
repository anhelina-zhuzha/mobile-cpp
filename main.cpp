#include <iostream>
#include "Tariff.h"
/*
 * StorageInterface
 * Storage implement the same interface so that the classes can refer
 * to the interface not the concrete Storage
 */
class StorageInterface {
public:
    virtual std::string getName() = 0;
    virtual Tariff* getByName(std::string name) = 0;
};

/*
 * Concrete Storage
 * define Storage to be created
 */
class FileStorage : public StorageInterface {
public:
    std::string getName() {
        return "File Storage";
    }

    Tariff *getByName(std::string name) override {
        return new Tariff("Жужа Стубент (File storage)", 20.99);
    }
};

/*
 * Concrete Storage
 * define Storage to be created
 */
class MemoryStorage: public StorageInterface {
public:
    std::string getName() {
        return "Memory storage";
    }

    Tariff *getByName(std::string name) override {
        return new Tariff("Жужа Студент (Memory storage)", 10.99);
    }
};

/*
 * Factory
 * contains the implementation for all of the methods
 * to manipulate Storage except for the factory method
 */
class StorageFactoryInterface {
public:
    virtual StorageInterface* createStorage() = 0;
};

/*
 * Concrete Factory
 * implements factory method that is responsible for creating
 * one or more concrete products ie. it is class that has
 * the knowledge of how to create the Storage
 */
class FileStorageFactory : public StorageFactoryInterface {
public:
    StorageInterface* createStorage() {
        return new FileStorage();
    }
};

class MemoryStorageFactory : public StorageFactoryInterface {
public:
    StorageInterface* createStorage() {
        return new MemoryStorage();
    }
};

int main()
{
    StorageFactoryInterface *fileFactory= new FileStorageFactory();

    StorageInterface *s1 = fileFactory->createStorage();
    Tariff* tariff =  s1->getByName("student");
    std::cout << "Storage: " << s1->getName() << std::endl;
    std::cout << "Tariff: " << tariff ->getName() << std::endl;
    std::cout << "Price: " << tariff->getPrice() << std::endl;
    std::cout << "\n\n";

    StorageFactoryInterface *memoryFactory = new MemoryStorageFactory();
    StorageInterface *s2 = memoryFactory->createStorage();
    Tariff* tariff2 =  s2->getByName("student");
    std::cout << "Storage: " << s2->getName() << std::endl;
    std::cout << "Tariff: " << tariff2->getName() << std::endl;
    std::cout << "Price: " << tariff2->getPrice() << std::endl;




    return 0;
}