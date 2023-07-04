// VehicleModel.cpp - Implementation file for the VehicleModel class
#include <iostream>
#include <cstring>
#include "VehicleModel.h"

// Constructor
VehicleModel::VehicleModel(int id,int year, const std::string& make, const std::string& model,int price) 
{
    this->id = id;
    this->year = year;
    this->make = make;
    this->model = model;
    this->price = price;
}

// Destructor
VehicleModel::~VehicleModel() 
{
    // Destructor implementation goes here if needed
}

// Getter methods
int VehicleModel::getId() const
{
    return id;
}
int VehicleModel::getYear() const
{
    return year;
}

std::string VehicleModel::getMake() const 
{
    return make;
}

std::string VehicleModel::getModel() const 
{
    return model;
}
int VehicleModel::getPrice() const
{
    return price;
}

// Setter methods
void VehicleModel::setId(int id)
{
    this->id = id;
}
void VehicleModel::setYear(int year) 
{
    this->year = year;
}

void VehicleModel::setMake(const std::string& make) 
{
    this->make = make;
}

void VehicleModel::setModel(const std::string& model) 
{
    this->model = model;
}
void VehicleModel::setPrice(int price)
{
    this->price = price;
}
void VehicleModel::displayBudgetInfo(int budget, int duration) const
{
    if (price * duration <= budget)
    {
        std::cout << "+----------------------+" << std::endl;
        std::cout << "Id:" << id << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Make: " << make << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "+----------------------+" << std::endl;
        std::cout << std::endl;

    }
}

void VehicleModel::displayInfo() const 
{
    std::cout << "+----------------------+" << std::endl;
    std::cout << "Id:" << id << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Make: " << make << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "+----------------------+" << std::endl;
    std::cout << std::endl;

}

