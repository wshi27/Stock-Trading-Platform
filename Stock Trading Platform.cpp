#include <iostream> 

#include <map>
#include <string>
#include <iomanip>
using namespace std;
int main ()
{
    map<string, double> open_prices, current_prices;
    string ticker;
    double price; 
    char x;
 
    cout<<"Enter ticker symble follow by ticker price: "<<endl;
 
    while (!cin.eof())
{
    cin>>ticker>>price;
    map<string, double>::iterator it;
    it=current_prices.find(ticker);
 
    if(it == current_prices.end())
    {
     open_prices[ticker] = price;
     current_prices[ticker] = price;
     }
 
    else
    {
        if (price > it->second)
        cout<<endl<<"Ticker "<<ticker<<" up "<<price - it->second<<endl<<endl;
        else if (price < it->second)
        cout<<endl<<"Ticker "<<ticker<<" down "<<it->second - price<<endl<<endl;
        else
        cout<<endl<<"Ticker "<<ticker<<" no change in price."<<endl<<endl;
 
         it->second = price;
     }
}
         cout<<"Ticker"<<setw(10)<<"open"<<setw(15)<<"close"<<endl;
     
      map<string,double>::iterator ii=current_prices.begin();
     
    for( map<string, double>::iterator i=open_prices.begin(); i!=open_prices.end(); ++i)  
    {  
         cout << i->first<< setw(14)<< i->second <<setw(14)<< ii->second << endl;
         ++ii;
    }       
    cout<<"Thank you for using this program"<<endl;
    system("pause");
    return 0;
}
