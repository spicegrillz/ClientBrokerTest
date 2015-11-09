/* 
 * File:   ClientTestSuite.cpp
 * Author: maxim
 */

#include <gtest/gtest.h>
#include "ClientStorage.h"
#include <iostream>

using namespace std;

class TestSuite : public testing::Test {
protected:

    static void SetUpTestCase() {
        auto bh = BrokerHandler::get_instance();
        double br1_price = 1.49, br2_price = 1.52;
        bh->add_broker(Broker(br1_price, 
                [](double price, int amount)->double{ 
                    return price * amount + price * amount * 0.05;
        }));
        bh->add_broker(Broker(br2_price, 
                [](double price, int amount)->double{ 
                    double commission = 0.03;
                    if(amount > 40 && amount <= 80)
                        commission = 0.025;
                    else if(amount > 80)
                        commission = 0.02;
                    return price * amount + price * amount * commission;
        }));
        
    }

    static void TearDownTestCase() {
        
    }
};


TEST_F(TestSuite, case1) {
    cout << "Client A buys 10";
    auto bought = ClientStorage::get_instance()->get_client("A").buy_coins(10);
    ASSERT_EQ(15.645, bought) << "\n Client A failed to buy 10";
    cout << " at " << bought << endl;
}

TEST_F(TestSuite, case2) {
    cout << "Client B buys 40";
    auto bought = ClientStorage::get_instance()->get_client("B").buy_coins(40);
    ASSERT_EQ(62.58, bought) << "\n Client B failed to buy 40";
    cout << " at " << bought << endl;
}

TEST_F(TestSuite, case3) {
    cout << "Client A buys 50";
    auto bought = ClientStorage::get_instance()->get_client("A").buy_coins(50);
    ASSERT_EQ(77.9, bought) << "\n Client A failed to buy 50";
    cout << " at " << bought << endl;
}

TEST_F(TestSuite, case4) {
    cout << "Client B buys 100";
    auto bought = ClientStorage::get_instance()->get_client("B").buy_coins(100);
    ASSERT_EQ(155.04, bought) << "\n Client B failed to buy 100";
    cout << " at " << bought << endl;
}

TEST_F(TestSuite, case5) {
    cout << "Client B sells 80";
    auto bought = ClientStorage::get_instance()->get_client("B").sell_coins(80);
    ASSERT_EQ(124.64, bought) << "\n Client B failed to sell 80";
    cout << " at " << bought << endl;
}

TEST_F(TestSuite, case6) {
    cout << "Client C sells 70";
    auto bought = ClientStorage::get_instance()->get_client("C").sell_coins(70);
    ASSERT_EQ(109.06, bought) << "\n Client C failed to sell 70";
    cout << " at " << bought << endl;
}

TEST_F(TestSuite, case7) {
    cout << "Client A buys 130";
    auto bought = ClientStorage::get_instance()->get_client("A").buy_coins(130);
    ASSERT_EQ(201.975, bought) << "\n Client A failed to buy 130";
    cout << " at " << bought << endl;
}

TEST_F(TestSuite, case8) {
    cout << "Client B sells 60";
    auto bought = ClientStorage::get_instance()->get_client("B").sell_coins(60);
    ASSERT_EQ(93.48, bought) << "\n Client B failed to sell 60";
    cout << " at " << bought << endl;
}

TEST_F(TestSuite, case9) {
    cout << "Report client net positions\n";
    double net = ClientStorage::get_instance()->get_client("A").report_net();
    EXPECT_EQ(296.156, net) << "\n Client A incorrect net position";
    cout << "Client A " << net;
    
    net = ClientStorage::get_instance()->get_client("B").report_net();
    EXPECT_EQ(0, net) << "\n Client B incorrect net position";
    cout << " Client B " << net;
    
    net = ClientStorage::get_instance()->get_client("C").report_net();
    EXPECT_EQ(-109.06, net) << "\n Client C incorrect net position";
    cout << " Client C " << net << endl;
}

TEST_F(TestSuite, case10) {
    cout << "Report number of Digicoins transacted by Broker\n";
    
    auto br_total = BrokerHandler::get_instance()->get_total();
    EXPECT_EQ(80, br_total[0]) << "Incorrect total amount for Broker 1";
    cout << "Broker 1 " << br_total[0];
    
    EXPECT_EQ(460, br_total[1]) << "Incorrect total amount for Broker 2";
    cout << " Broker 2 " << br_total[1] << endl;
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

