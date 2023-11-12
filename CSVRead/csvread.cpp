#include "csvread.h"
#include <fstream>
#include <iostream>

csvread::csvread(){

}

std::vector<OrderBookEntry> csvread::csvReader(std::string csvFile_name){
    std::vector<std::string> entries;
    std::vector<OrderBookEntry> res;
    std::string line;
    std::ifstream csvFile{csvFile_name};
    if (csvFile.is_open())
    {
        std::cout << "File Open " << std::endl;
        // Open file
        while(std::getline(csvFile,line)){
            // std::cout << "Read " << line << std::endl;
            entries = csvread::tokenise(line, ',');
            res.push_back(csvread::stringtoOBE(entries));
        }
    }
    std::cout << "CSVReader::readCSV read " << res.size() << " entries" << std::endl;
    return res;
}

std::vector<std::string> csvread::tokenise(std::string csvLine, char seperator){
    std::vector<std::string> tokens;
    int start, end;
    std::string token;

    start = csvLine.find_first_not_of(seperator,0);
    do
    {
        end = csvLine.find_first_of(seperator, start);
        if (start == csvLine.length() || start == end)
        {
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

OrderBookEntry csvread::stringtoOBE(std::vector<std::string> tokens){
    double price,amount;
    if(tokens.size() != 5){
        std::cout << "Bad Line" << std::endl;
        throw std::exception{};
    }
    // now we have for object
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch (const std::exception &e)
    {
        std::cout << "Bad float " << tokens[3] << std::endl;
        std::cout << "Bad float " << tokens[4] << std::endl;
        throw;
    }
    OrderBookEntry obe{
        price,
        amount,
        tokens[0],
        tokens[1],
        OrderBookEntry::stringToOrderBookType(tokens[2])};
    return obe;
}