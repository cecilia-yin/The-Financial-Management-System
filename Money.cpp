
#include "Money.h"

Money::Money() {
	dollar=0;
	cent=0;
}
Money::Money(int dollars, int cents) {
     dollar=dollars;
	 if (dollar<0)
	 	{
	 		dollar=0;
	 	}
	//consider cents when it's less than 100
	if (cents<100) {
		cent=cents;
		if(cents<0) {
			cent=0;
		}

	}

	// consider cents when it's more than 100
	if (cents>=100) {
		dollar=(cents/100)+dollar;
		cent=cents%100;
	}
}

int Money::getDollars() const {

	return dollar;
}

int Money::getCents() const {

	return cent;
}

int Money::asCents() const {

	return cent+dollar*100;
}

void Money::addDollars(int dollars) {
	if(dollars>0) {
		dollar +=dollars;
	}
}

void Money::addCents(int cents) {
	if (cents > 0) {
		dollar += (cent + cents) / 100;
		cent = (cent + cents) % 100;
	}
}

void Money::subtractDollars(int dollars) {

	if ((dollars>0) && (dollar-dollars>=0)) {
		dollar=dollar-dollars;
	}

}

void Money::subtractCents(int cents) {

	int centOriginal=cent;
	if ((cents>=0) && ((dollar*100+cent)-cents>=0) ) {
		cent=((dollar*100+cent)-cents)%100;
		dollar=((dollar*100+centOriginal)-cents)/100;
	}

}

void Money::add(const Money &other) {
	int newDollar=other.getDollars();
	int newCent=other.getCents();
	addDollars(newDollar);
	addCents(newCent);

}

void Money::subtract(const Money &other) {
	int compareValue = other.cent + other.dollar * 100;
	int total = cent + dollar * 100;
	if (total >= compareValue) {
		subtractCents(other.cent);
		subtractDollars(other.dollar);
	}
}

void Money::split(Money &other) {

    int newDollar=other.dollar;
    int newCent=other.cent;

	addDollars(newDollar);
	addCents(newCent);

	dollar=(dollar/2);
    other.dollar=dollar;

    cent=(cent/2);
    other.cent=cent;
}

Money::~Money() {
	//TODO: implement
}
