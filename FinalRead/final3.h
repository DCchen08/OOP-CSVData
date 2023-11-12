#pragma once
#include "string"

class electric_car{
    public:
        electric_car(std::string _VIN,
                     std::string _County,
                     std::string _City,
                     std::string _State,
                     double _PostalCode,
                     double _ModelYear,
                     std::string _Make,
                     std::string _Model,
                     std::string _ElectricVehicleType,
                     std::string _CleanAlternativeFuelVehicleEligbility,
                     double _ElectricRange,
                     double _BaseMSPR,
                     double _LegislativeDistric,
                     double _DOLVehicleID,
                     std::string _VehicleLocation,
                     std::string _ElectricUtility,
                     double _Census14Tract);

        std::string VIN;
        std::string County;
        std::string City;
        std::string State;
        double PostalCode;
        double ModelYear;
        std::string Make;
        std::string Model;
        std::string ElectricVehicleType;
        std::string CleanAlternativeFuelVehicleEligbility;
        double ElectricRange;
        double BaseMSPR;
        double LegislativeDistric;
        double DOLVehicleID;
        std::string VehicleLocation;
        std::string ElectricUtility;
        double CensusTract;
        
};