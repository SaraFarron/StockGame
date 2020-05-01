#include <iostream>
#include <string>
#include <ctime>

using namespace std;

//класс товаров
class Product {
	int price;
	int number;
public:
	int GetPrice() {
		return price;
	}
	void SetPrice(int priceV) {
		price = priceV;
	}
	int GetNumber() {
		return number;
	}
	void SetNumber(int amount) {
		number = amount;
	}
};

Product gold, iron, tin, plumbum, silver, nikel, oil, gas, copper;

//стек
class stack {
	int temp;
public:
	int GetTemp() {
		return temp;
	}
	void SetTemp(int tem) {
		temp = tem;
	}
};

stack number;

void setPrices();
void overnight();
void showPrices(int *money);
void Deal(int*money);
int discover(string arg);
int selling(string arg, int* amountN);
int dismount(string product);
void getP(string arg);

int main() {
	setPrices();
	int money=10000;
	cout << "your starting budget is " << money << " coins, current prices are:" << endl;

newday:
	showPrices(&money);
	Deal(&money);
	overnight();
	cout << "New day, prices have changed" << endl;
	goto newday;
}

//ставит базовую цену (и не только ее)
void setPrices() {
	gold.SetPrice(1000);
	iron.SetPrice(100);
	tin.SetPrice(80);
	plumbum.SetPrice(70);
	silver.SetPrice(500);
	nikel.SetPrice(120);
	oil.SetPrice(40);
	gas.SetPrice(25);
	copper.SetPrice(50);
	gold.SetNumber(0);
	iron.SetNumber(0);
	tin.SetNumber(0);
	plumbum.SetNumber(0);
	silver.SetNumber(0);
	nikel.SetNumber(0);
	oil.SetNumber(0);
	gas.SetNumber(0);
	copper.SetNumber(0);
}

//изменяет цены за ночь
void overnight() {
	 gold.SetPrice(gold.GetPrice() + rand() % 10 - 5);
	 iron.SetPrice(iron.GetPrice() + rand() % 10 - 5);
	 tin.SetPrice(tin.GetPrice() + rand() % 10 - 5);
	 plumbum.SetPrice(plumbum.GetPrice() + rand() % 10 - 5);
	 silver.SetPrice(silver.GetPrice() + rand() % 10 - 5);
	 nikel.SetPrice(nikel.GetPrice() + rand() % 10 - 5);
	 oil.SetPrice(oil.GetPrice() + rand() % 10 - 5);
	 gas.SetPrice(gas.GetPrice() + rand() % 10 - 5);
	 copper.SetPrice(copper.GetPrice() + rand() % 10 - 5);
}

//показывает цены
void showPrices(int *money) {
	cout << endl <<"gold= " << gold.GetPrice();
	cout << endl << "iron= " << iron.GetPrice();
	cout << endl << "tin= " << tin.GetPrice();
	cout << endl << "plumbum= " << plumbum.GetPrice();
	cout << endl << "silver= " << silver.GetPrice();
	cout << endl << "nikel= " << nikel.GetPrice();
	cout << endl << "oil= " << oil.GetPrice();
	cout << endl << "gas= " << gas.GetPrice();
	cout << endl << "copper= " << copper.GetPrice() << endl;
	cout << endl << "you have " << *money << " coins" << endl;
}

//обработчик комманд
void Deal(int*money) {
begin:
	string trading, amount, product;
	cin >> trading >> amount >> product;
	if (trading == "buy")
	{
		int amountN = stoi(amount);
		number.SetTemp(amountN);
		amountN = -amountN;
		int temp;
		if (*money + (temp=discover(product)) * amountN < 0)
		{
			cout << "Not enough money\n";
			goto begin;
		}
		else
		{
			getP(product);
			*money = *money + temp * amountN;
		}
	}
	else if (trading == "sell")
	{
		int amountN = stoi(amount);
		int result;
		if (result=selling(product,&amountN))
		{
			money = money - result;
		}
		else
		{
			goto begin;
		}
	}
	else if (trading=="show")
	{
		int temp;
		if ((temp=dismount(product))!=-1)
		{
			cout << "\nyou have " << temp << " " << product << endl;
			goto begin;
		}
		else
		{
			cout << "invalid syntax man" << endl;
			goto begin;
		}
	}
	else
	{
		goto begin;
	}
}

//покупка
int discover(string arg) {
	if (arg == "gold")
	{
		return gold.GetPrice();
	}
	else if (arg == "iron")
	{
		return iron.GetPrice();
	}
	else if (arg == "tin")
	{
		return tin.GetPrice();
	}
	else if (arg == "plunmbum")
	{
		return plumbum.GetPrice();
	}
	else if (arg == "silver")
	{
		return silver.GetPrice();
	}
	else if (arg == "nikel")
	{
		return nikel.GetPrice();
	}
	else if (arg == "oil")
	{
		return oil.GetPrice();
	}
	else if (arg == "gas")
	{
		return gas.GetPrice();
	}
	else if (arg == "copper")
	{
		return copper.GetPrice();
	}
	else
	{
		cout << "invalid syntax" << endl;
		return 0;
	}
}

//продажа
int selling(string arg, int* amountN) {
	if (arg == "gold" && (gold.GetNumber() >= *amountN))
	{
		gold.SetNumber(gold.GetNumber() - *amountN);
		return gold.GetPrice()* * amountN;
	}
	else if (arg == "iron" && iron.GetNumber() >= *amountN)
	{
		iron.SetNumber(iron.GetNumber() - *amountN);
		return iron.GetPrice()* *amountN;
	}
	else if (arg == "tin" && tin.GetNumber() >= *amountN)
	{
		tin.SetNumber(tin.GetNumber() - *amountN);
		return tin.GetPrice()* *amountN;
	}
	else if (arg == "plunmbum" && plumbum.GetNumber() >= *amountN)
	{
		plumbum.SetNumber(plumbum.GetNumber() - *amountN);
		return plumbum.GetPrice()* *amountN;
	}
	else if (arg == "silver" && silver.GetNumber() >= *amountN)
	{
		silver.SetNumber(silver.GetNumber() - *amountN);
		return silver.GetPrice()* *amountN;
	}
	else if (arg == "nikel" && nikel.GetNumber() >= *amountN)
	{
		nikel.SetNumber(nikel.GetNumber() - *amountN);
		return nikel.GetPrice()* *amountN;
	}
	else if (arg == "oil" && oil.GetNumber() >= *amountN)
	{
		oil.SetNumber(oil.GetNumber() - *amountN);
		return oil.GetPrice()* *amountN;
	}
	else if (arg == "gas" && gas.GetNumber() >= *amountN)
	{
		gas.SetNumber(gas.GetNumber() - *amountN);
		return gas.GetPrice()* *amountN;
	}
	else if (arg == "copper" && copper.GetNumber() >= *amountN)
	{
		copper.SetNumber(copper.GetNumber() - *amountN);
		return copper.GetPrice()* *amountN;
	}
	else
	{
		cout << "invalid syntax or not enough " << arg << endl;
		//goto begin;
		return 0;
	}
}

//количество
int dismount(string arg) {
	if (arg == "gold")
	{
		return gold.GetNumber();
	}
	else if (arg == "iron")
	{
		return iron.GetNumber();
	}
	else if (arg == "tin")
	{
		return tin.GetNumber();
	}
	else if (arg == "plunmbum")
	{
		return plumbum.GetNumber();
	}
	else if (arg == "silver")
	{
		return silver.GetNumber();
	}
	else if (arg == "nikel")
	{
		return nikel.GetNumber();
	}
	else if (arg == "oil")
	{
		return oil.GetNumber();
	}
	else if (arg == "gas")
	{
		return gas.GetNumber();
	}
	else if (arg == "copper")
	{
		return copper.GetNumber();
	}
	else
	{
		cout << "invalid syntax" << endl;
		return -1;
	}
}

//начисление товара
void getP(string arg) {
	if (arg == "gold")
	{
		gold.SetNumber(gold.GetNumber()+number.GetTemp());
	}
	else if (arg == "iron")
	{
		iron.SetNumber(iron.GetNumber() + number.GetTemp());
	}
	else if (arg == "tin")
	{
		tin.SetNumber(tin.GetNumber() + number.GetTemp());
	}
	else if (arg == "plunmbum")
	{
		plumbum.SetNumber(plumbum.GetNumber() + number.GetTemp());
	}
	else if (arg == "silver")
	{
		silver.SetNumber(silver.GetNumber() + number.GetTemp());
	}
	else if (arg == "nikel")
	{
		nikel.SetNumber(nikel.GetNumber() + number.GetTemp());
	}
	else if (arg == "oil")
	{
		oil.SetNumber(oil.GetNumber() + number.GetTemp());
	}
	else if (arg == "gas")
	{
		gas.SetNumber(gas.GetNumber() + number.GetTemp());
	}
	else if (arg == "copper")
	{
		copper.SetNumber(copper.GetNumber() + number.GetTemp());
	}
	else
	{
		cout << "invalid syntax" << endl;
	}
}