
#include "basics.h"

int totalCents(int dollars, int cents) {
	int total=-1;
	if ((dollars<0) || (cents<0)){
		return total;
	} else {
		 total=dollars*100+cents;
	}
	 return total;
}

int sumAsCents(int moneyOneDollars, int moneyOneCents, int moneyTwoDollars, int moneyTwoCents) {
	int sum=-1;
	if (moneyOneDollars<0 || moneyOneCents<0 ||moneyTwoDollars <0 || moneyTwoCents<0) {
		return sum;
	}
	else {
		sum=moneyOneDollars*100+moneyOneCents+moneyTwoDollars*100+moneyTwoCents;
	}
	return sum;
}

int split(int moneyOneDollars, int moneyOneCents, int moneyTwoDollars, int moneyTwoCents) {
	int split=-1;
	if (moneyOneDollars<0 || moneyOneCents<0 ||moneyTwoDollars <0 || moneyTwoCents<0) {
			return split;
	}else {
		split=sumAsCents(moneyOneDollars, moneyOneCents, moneyTwoDollars, moneyTwoCents)/2;
	}
	return split;
}

