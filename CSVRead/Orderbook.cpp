#include <map>
#include <iostream>
#include "Orderbook.h"


OrderBook::OrderBook(std::string filename){
    // std::cout << "call OrderBook constuctor" << std::endl;

    orders = csvread::csvReader(filename);
}

std::vector<std::string> OrderBook::getKnownProject(){
    std::map<std::string, bool> prodmap;
    std::vector<std::string> products;
    
    for(OrderBookEntry& a : orders)
    {
        prodmap[a.product] = true;
    }

    for(auto const& e: prodmap){
        products.push_back(e.first);
    }

    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, 
                                                 std::string product,
                                                 std::string timestamp){
    std::vector<OrderBookEntry> res;
    for (OrderBookEntry&e : orders){
        if(e.orderType == type &&
           e.product == product && 
           e.timestamp == timestamp){
            res.push_back(e);
        }
    }
    return res;

}

double OrderBook::getHighPrice(std::vector<OrderBookEntry> & orders){
    double max = orders[0].price;
    for (OrderBookEntry& e : orders){
        if (e.price > max){
            max = e.price;
        }
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry> & orders){
    double min = orders[0].price;
    for (OrderBookEntry& e : orders){
        if (e.price < min){
            min = e.price;
        }
    }
    return min;
}

std::string OrderBook::getEarliesetTime(){
    std::string earliest = orders[0].timestamp;
    return earliest;
}