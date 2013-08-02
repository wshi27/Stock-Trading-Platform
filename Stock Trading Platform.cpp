#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SalesOrder
{
      public:
             void createOrder(int, int, int);
             bool executable(int);
             void execute(void);
             SalesOrder(int, int, int, bool);
             
              int bid;
              int lt;
              int account;
              bool complete;
};

int main()
{
    vector<SalesOrder> allOrders;
    string type = "menu";
    int acc, bPrice, lot;
    int offerP = 1000000;
    int i, e;
    
    cout<<"Welcom to WeiTrade!"<<endl;
    
  while (type == "menu" && e!=1)
  {
    cout<<"Please type any of the follow commands"<<endl<<endl;
    cout<<"bid"<<endl<<"offer"<<endl<<"menu"<<endl<<"quit"<<endl<<endl;
    
    cin>>type;
    if (type == "bid")
    {  
       cout<<endl<<"enter account #, bid price and number of lots"<<endl;
       cin>>acc>>bPrice>>lot;
       SalesOrder newSalesOrder(bPrice, lot, acc, false);
       cout<<"Creating Sales Order - Account Number: "<<acc<<", Bid Price: "
       <<bPrice<<", Lots: "<<lot<<endl<<endl;
        if (offerP <= bPrice)
          newSalesOrder.execute();
       allOrders.push_back(newSalesOrder);
       type = "menu"; 
    }
    else if (type == "offer")
         { cout<<"enter offer price:"<<endl;
         cin>>offerP;
         for (i=0; i< allOrders.size(); i+=1)
             { 
          if(allOrders[i].executable(offerP))
               {
            allOrders[i].execute();
               }
             }
         type = "menu";
         }
    else if (type == "quit")
    {
         cout<<"Thanks for using WeiTrade."<<endl; 
         e=1;
    }  
    else 
         cout<<"Invalid Entry"<<endl;  

  }
system ("PAUSE");
return 0;
}
          
SalesOrder::SalesOrder(int bidPrice, int lots, int accountnumber, bool)
{ 
  bid = bidPrice;
  lt = lots;
  account = accountnumber;
  complete = false;
  
};

bool SalesOrder::executable(int offerPrice)
{
     if(offerPrice <= bid && complete == false)
     return true;
     return false;
}

void SalesOrder::execute(void)
{
     cout<<"Executing Sales Order - Account Number: " <<
            account<<" Bid Price: "<<bid<<" Lots: "<< lt<<endl<<endl;
    complete=true;

};
