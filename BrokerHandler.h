/* 
 * File:   BrokerHandler.h
 * Author: maxim
 */

#ifndef BROKERHANDLER_H
#define	BROKERHANDLER_H

#include <vector>
#include <set>
#include <functional>

typedef std::function<double (const int)> RateFun;

static const int MAX_AMOUNT = 100;

struct Broker{
    const double price;
    int total;
    RateFun get_rate;
    
    double buy_coins(int amount){
        total += amount;
        return get_rate(amount);        
    }
    
    
    Broker(double pr, std::function<double (double, const int)> rf): 
            price(pr), total(0), get_rate(std::bind(rf, price, std::placeholders::_1)){
        //get_rate = std::bind(rf, price, std::placeholders::_1);
    };
    
};


class BrokerHandler{
    static BrokerHandler* instance;
public:
    static BrokerHandler* get_instance();
    
    /*
     *Currently we expect relatively small amount of brokers
     * so we will ask every broker for rate and pick the best one.
     * If we will have more of them we can sacrifice some space and gain some speed
     * using 9 indexes (10 - 100 with step 10) for all possible rates.
     * Currently we assume that rate for bigger amount is always better
     * than for smaller.
     */
    double buy_best_rate(int amount);    
    void add_broker(Broker br);
    void finish_transaction();
    void clear_brokers();
    std::vector<int> get_total();
    
protected:
    BrokerHandler(){};
    //~BrokerHandler(){};
    
private:

    std::vector<Broker> broker_storage;
    std::set<int> marked_brokers;
    
};


#endif	/* BROKERHANDLER_H */

