#include "VehicleController.h"
#include <string>
#include <Windows.h>
#include <sstream>


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
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(consoleHandle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        // Display menu options
        std::cout << "+----------------------+" << std::endl;
        std::cout << "| Vehicle Management   |" << std::endl;
        std::cout << "+----------------------+" << std::endl;
        std::cout << "| 1. Add a new vehicle |" << std::endl;
        std::cout << "| 2. View all vehicles |" << std::endl;
        std::cout << "| 3. Update a vehicle  |" << std::endl;
        std::cout << "| 4. Delete a vehicle  |" << std::endl;
        std::cout << "| 0. Exit              |" << std::endl;
        std::cout << "+----------------------+" << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;
        system("cls");
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



            std::vector<VehicleModel> vehicles;
            std::ifstream file("Vehicles.txt");
            int id = 0;
            if (file.is_open())
            {
                std::string line;
                
                while (std::getline(file, line))
                {
                    std::stringstream lineString(line);
                    std::string token;

                    std::getline(lineString, token, ',');
                   
                    std::stringstream(token) >> id;

                   
                }
                file.close();
            }
            id++;


            std::cout << "Enter model: ";
            std::getline(std::cin, model);

            service.createVehicle(id,year, make, model);
            system("cls");
            std::cout << "Vehicle added successfully." << std::endl;
            system("pause");
            system("cls");

            break;
        }
        case 2: 
        {
            std::vector<VehicleModel> vehicles = service.getAllVehicles();

            if (vehicles.empty()) 
            {
                std::cout << "No vehicles found." << std::endl;
                system("pause");
                system("cls");
            }
            else 
            {
                int counter = 1;
                std::cout << "Vehicle List:" << std::endl << std::endl;

                for (const auto& vehicle : vehicles) 
                {
                    std::cout << "Vehicle " << counter++ << std::endl;
                    vehicle.displayInfo();

                    std::cout << std::endl;
                }
                system("pause");
                system("cls");
            }
            break;
        }
        case 3: 
        {
            int id;
            int oldYear, newYear;
            std::string oldMake, oldModel, newMake, newModel;
            std::vector<VehicleModel> vehicles = service.getAllVehicles();

            if (vehicles.empty())
            {
                std::cout << "No vehicles found." << std::endl;
                system("pause");
                system("cls");
            }
            else
            {
                int counter = 1;
                std::cout << "Vehicle List:" << std::endl << std::endl;

                for (const auto& vehicle : vehicles)
                {
                    std::cout << "Vehicle " << counter++ << std::endl;
                    vehicle.displayInfo();

                    std::cout << std::endl;
                }
            }

            std::cout << "Enter the details of the vehicle to update:" << std::endl;
            std::cout << "Enter Id: ";
            std::cin >> id;

            /*std::cout << "Enter old year: ";
            std::cin >> oldYear;

            std::cout << "Enter old make: ";
            std::cin.ignore();
            std::getline(std::cin, oldMake);






            std::cout << "Enter old model: ";
            std::getline(std::cin, oldModel);
            */

            std::cout << "Enter new year: ";
            std::cin >> newYear;

            std::cout << "Enter new make: ";
            std::cin.ignore();
            std::getline(std::cin, newMake);

            std::cout << "Enter new model: ";
            std::getline(std::cin, newModel);



            service.updateVehicle(id, 0, "oldMake", "oldModel", 0, newYear, newMake, newModel);
            system("pause");
            system("cls");

            break;
        }
        case 4: 
        {
            std::vector<VehicleModel> vehicles = service.getAllVehicles();

            if (vehicles.empty())
            {
                std::cout << "No vehicles found." << std::endl;
                system("pause");
                system("cls");
            }
            else
            {
                int counter = 1;
                std::cout << "Vehicle List:" << std::endl << std::endl;

                for (const auto& vehicle : vehicles)
                {
                    std::cout << "Vehicle " << counter++ << std::endl;
                    vehicle.displayInfo();

                    std::cout << std::endl;
                }

            }
            int year,id;
            std::string make, model;

            std::cout << "Enter the details of the vehicle to delete:" << std::endl;

            std::cout << "Enter id: ";
            std::cin >> id;
           // std::cout << "Enter year: ";
           // std::cin >> year;

            //std::cout << "Enter make: ";
            //std::cin.ignore();
            //std::getline(std::cin, make);

            //std::cout << "Enter model: ";
            //std::getline(std::cin, model);

            service.deleteVehicle(id, 9, "make", "a");
            system("pause");
            system("cls");

            break;
        }
        case 0:
            std::cout << "Exiting the application. Goodbye!" << std::endl;

            break;
        default:

            std::cout << "Invalid choice. Please try again." << std::endl;
            system("pause");
            system("cls");
        }

        std::cout << std::endl;

    } 
    while (choice != 0);
}