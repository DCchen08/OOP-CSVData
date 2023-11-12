#include <iostream>
#include "string"
#include "vector"
#include <fstream>
#include "final3.h"

std::vector<std::string> tokenise(std::string csvLine, char seperator){
    std::vector<std::string> tokens;
    int start, end;
    std::string token;
    start = csvLine.find_first_not_of(seperator, 0);
    do{
        end = csvLine.find_first_of(seperator, start);
        if(start == csvLine.length() || start == end){
            break;
        }
        if (end >= 0){
            token = csvLine.substr(start, end - start);
        }
        else{
            token = csvLine.substr(start, csvLine.length() - start);
        }
        tokens.push_back(token);
        start = end + 1;
    } while (end > 0);
    return tokens;
}

int main(){
    std::string line;
    std::fstream csvFile{"Electric_Vehicle_Population_Data.csv"};
    std::vector<std::string> tokens;
    
    if (csvFile.is_open())
    {
        while(std::getline(csvFile,line)){
            std::cout << "Read " << line << std::endl;
            tokens = tokenise(line, ',');
            // std::cout << tokens.size() << std::endl;
            if (tokens.size() != 17)
            {
                std::cout << "Bad Line" << std::endl;
                continue;
            }
            try{
                std::string VIN = tokens[0];
                std::string County = tokens[1];
                std::string City = tokens[2];
                std::string State = tokens[3];
                double PostaCode = std::stod(tokens[4]);
                double ModeYear = std::stod(tokens[5]);
                std::string Make = tokens[6];
                std::string Model = tokens[7];
                std::string ElectricVehicleType = tokens[8];
                std::string CleanAlternativeFuelVehicleEligbility = tokens[9];
                double ElectricRange = std::stod(tokens[10]);
                double BaseMSPR = std::stod(tokens[11]);
                double LegislativeDistric = std::stod(tokens[12]);
                double DOLVehicleID = std::stod(tokens[13]);
                std::string VehicleLocation = tokens[14];
                std::string ElectricUtility = tokens[15];
                double CensusTract = std::stod(tokens[16]);
                electric_car data_collection(VIN,
                                             County,
                                             City,
                                             State,
                                             PostaCode,
                                             ModeYear,
                                             Make,
                                             Model,
                                             ElectricVehicleType,
                                             CleanAlternativeFuelVehicleEligbility,
                                             ElectricRange,
                                             BaseMSPR,
                                             LegislativeDistric,
                                             DOLVehicleID,
                                             VehicleLocation,
                                             ElectricUtility,
                                             CensusTract);
            }
            catch (std::exception& e) 
            {
                std::cerr << "Exception: " << e.what() << std::endl;
            }

            for (std::string&t : tokens){
                std::cout << t << std::endl;
            }
        }
        csvFile.close();
    }

    return 0;
}