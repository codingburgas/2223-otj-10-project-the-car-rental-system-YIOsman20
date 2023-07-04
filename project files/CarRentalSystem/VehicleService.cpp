#include "VehicleModel.h"
#include "VehicleService.h"

// Constructor
VehicleService::VehicleService(const std::string& filename) : repository(filename)
{

}

// Create a new vehicle record
void VehicleService::createVehicle(int id,int year, const std::string& make, const std::string& model,int price)
{
    VehicleModel vehicle(id,year, make, model,price);

    repository.addVehicle(vehicle);
}

// Read all vehicle records
std::vector<VehicleModel> VehicleService::getAllVehicles()
{
    return repository.getVehicles();
}

// Update an existing vehicle record
void VehicleService::updateVehicle(int oldId,int oldYear, const std::string& oldMake, const std::string& oldModel,int oldPrice,int newId, int newYear, const std::string& newMake, const std::string& newModel,int newPrice)
{
    VehicleModel oldVehicle(oldId,oldYear, oldMake, oldModel,oldPrice);
    VehicleModel newVehicle(newId,newYear, newMake, newModel,newPrice);
    repository.updateVehicle(oldVehicle, newVehicle);
}

// Delete a vehicle record
void VehicleService::deleteVehicle(int id,int year, const std::string& make, const std::string& model,int price)
{
    VehicleModel vehicle(id,year, make, model,price);
    repository.removeVehicle(vehicle);
}
