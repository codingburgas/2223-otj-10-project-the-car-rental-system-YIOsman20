# 2223-10: On the job training (OTJ) project

The Vehicle Management System is a console-based application built in C++ that allows users to manage vehicle records. It provides basic CRUD (Create, Read, Update, Delete) operations for vehicle data, which are stored in a text file.

## Features

- Add a new vehicle: Users can input the year, make, and model of a vehicle to add it to the records.
- View all vehicles: Users can see a list of all the vehicles stored in the system.
- Update a vehicle: Users can update the information of an existing vehicle by specifying the old and new details.
- Delete a vehicle: Users can remove a vehicle from the records by providing its information.

## Components

The project consists of the following components:

- **VehicleModel**: A C++ class representing a vehicle, storing its year, make, and model information.
- **VehicleRepository**: A class responsible for data operations on vehicle records, such as creating, reading, updating, and deleting records in a text file.
- **VehicleService**: A class that acts as an interface between the higher-level application logic and the `VehicleRepository`, providing methods for managing vehicle data.
- **VehicleController**: A controller class that handles user interactions, providing a menu-driven console interface for managing vehicle records.
- **VehicleView**: A view class that displays messages and information to the user.

## Usage

1. Clone the repository to your local machine.
2. Compile the source files using a C++ compiler (e.g., g++).
3. Run the compiled executable file.
4. Follow the on-screen instructions to interact with the Vehicle Management System.

## File Structure

The project files are organized as follows:

CarRentalSystem  
├── CarRentalSystem.PL  
   ├── Controllers  
      ├── VehicleController.h # Header file for the VehicleController class  
   ├── Views  
      ├── VehicleView.h # Header file for the VehicleView class  
├── CarRentalSystem.BLL  
   ├── Services  
      ├── VehicleService.h # Header file for the VehicleService class  
├── CarRentalSystem.DAL  
   ├── Models  
      ├── VehicleModel.h # Header file for the VehicleModel class  
   ├── Repositories  
      ├── VehicleRepository.h # Header file for the VehicleRepository class  
├── CarRentalSystem.Implementations  
   ├── Vehicle  
      ├── VehicleModel.cpp # Implementation file for the VehicleModel class  
      ├── VehicleRepository.cpp # Implementation file for the VehicleRepository class  
      ├── VehicleService.cpp # Implementation file for the VehicleService class  
      ├── VehicleController.cpp # Implementation file for the VehicleController class  
      ├── VehicleView.cpp # Implementation file for the VehicleView class  
├── CarRentalSystem.Source  
   ├── main.cpp # Main entry point of the application  
     


## Future Enhancements

- Implement additional validation and error handling for user input.
- Add sorting and filtering capabilities to view the vehicle records based on specific criteria.
- Integrate a database system for more efficient and scalable data storage.

