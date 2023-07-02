#include "VehicleController.h"
#include <string>

// Constructor
VehicleController::VehicleController(const std::string& filename):service(filename) 
{
}

// Run the vehicle management application
void VehicleController::run() 
{
    int choice;

    do 
    {
        // Display menu options
        std::cout << "Vehicle Management Application" << std::endl;
        std::cout << "1. Add a new vehicle" << std::endl;
        std::cout << "2. View all vehicles" << std::endl;
        std::cout << "3. Update a vehicle" << std::endl;
        std::cout << "4. Delete a vehicle" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        // Handle user's choice
        switch (choice) 
        {
        case 1: 
        {
            int year;
            std::string make, model;

            std::cout << "Enter year: ";
            std::cin >> year;

            std::cout << "Enter make: ";
            std::cin.ignore();
            std::getline(std::cin, make);

            std::cout << "Enter model: ";
            std::getline(std::cin, model);

            service.createVehicle(year, make, model);

            std::cout << "Vehicle added successfully." << std::endl;

            break;
        }
        case 2: 
        {
            std::vector<VehicleModel> vehicles = service.getAllVehicles();

            if (vehicles.empty()) 
            {
                std::cout << "No vehicles found." << std::endl;
            }
            else 
            {
                std::cout << "Vehicle List:" << std::endl;

                for (const auto& vehicle : vehicles) 
                {
                    vehicle.displayInfo();

                    std::cout << std::endl;
                }
            }
            break;
        }
        case 3: 
        {
            int oldYear, newYear;
            std::string oldMake, oldModel, newMake, newModel;

            std::cout << "Enter the details of the vehicle to update:" << std::endl;

            std::cout << "Enter old year: ";
            std::cin >> oldYear;

            std::cout << "Enter old make: ";
            std::cin.ignore();
            std::getline(std::cin, oldMake);

            std::cout << "Enter old model: ";
            std::getline(std::cin, oldModel);

            std::cout << "Enter new year: ";
            std::cin >> newYear;

            std::cout << "Enter new make: ";
            std::cin.ignore();
            std::getline(std::cin, newMake);

            std::cout << "Enter new model: ";
            std::getline(std::cin, newModel);

            service.updateVehicle(oldYear, oldMake, oldModel, newYear, newMake, newModel);

            break;
        }
        case 4: 
        {
            int year;
            std::string make, model;

            std::cout << "Enter the details of the vehicle to delete:" << std::endl;

            std::cout << "Enter year: ";
            std::cin >> year;

            std::cout << "Enter make: ";
            std::cin.ignore();
            std::getline(std::cin, make);

            std::cout << "Enter model: ";
            std::getline(std::cin, model);

            service.deleteVehicle(year, make, model);

            break;
        }
        case 0:
            std::cout << "Exiting the application. Goodbye!" << std::endl;

            break;
        default:

            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;

    } 
    while (choice != 0);
}