#pragma once
#include "string"
#include "vector"
#include "OrderBookEntry.h"


class csvread{
    public:
        csvread();
        static std::vector<OrderBookEntry> csvReader(std::string csvFile);
    
    private:
        static std::vector<std::string> tokenise(std::string csvLine, char seperator);
        static OrderBookEntry stringtoOBE(std::vector<std::string> string);
};