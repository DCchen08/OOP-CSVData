#pragma once
#include <string>


enum class OrderBookType
{
    bid,
    ask,
    unknown
};

class OrderBookEntry
{
public:
    OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType);
    static OrderBookType stringToOrderBookType(const std::string& s);
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
    double price;
    double amount;

    double getprice();
    // double computeAveratePrice(std::vector<OrderBookEntry>&entries);
    // double computeLowerPrice(std::vector<OrderBookEntry>&entries);
    // double computeHighPrice(std::vector<OrderBookEntry> &entries);
};

