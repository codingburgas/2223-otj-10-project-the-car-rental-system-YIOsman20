#include <iostream>
#include <cstring>
#pragma once

// VehicleModel.h - Header file for the VehicleModel class

#ifndef VEHICLEMODEL_H
#define VEHICLEMODEL_H

// Class representing a vehicle
class VehicleModel 
{
    private:
        // Member variables
        int id;
        int year;           // Year of manufacture
        std::string make;   // Make of the vehicle
        std::string model;  // Model of the vehicle
        int price;

    public:
        // Constructor
        VehicleModel(int id,int year, const std::string& make, const std::string& model,int price);

        // Destructor
        ~VehicleModel();

        // Getter methods
        int getId() const;
        int getYear() const;
        std::string getMake() const;
        std::string getModel() const;
        int getPrice() const;

        // Setter methods
        void setId(int id);
        void setYear(int year);
        void setMake(const std::string& make);
        void setModel(const std::string& model);
        void setPrice(int price);

        // Other methods
        void displayInfo() const;
};

#endif
