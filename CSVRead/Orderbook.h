#pragma once
#include <string>
#include <vector>
#include "csvread.h"
#include "OrderBookEntry.h"


class OrderBook{
    public:
        /** constructor for reading the csvFile */ 
        OrderBook(std::string filename);

        /** return all known products in the data set using vector */
        std::vector<std::string> getKnownProject();

        /** return vector of products in sent filter */
        std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                              std::string product,
                                              std::string timestamp);

        /** return the price of highest bit in the sent */
        static double getHighPrice(std::vector<OrderBookEntry> & orders);

        /** return the price of lowest bit in the sent */
        static double getLowPrice(std::vector<OrderBookEntry> & orders);

        /** return the earliest time of the list */
        std::string getEarliesetTime();


    private:
        std::vector<OrderBookEntry> orders;
};