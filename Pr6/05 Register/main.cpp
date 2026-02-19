#include "Register.h"
// Define the selector/modifier for any of 4 bytes in a 32-bits word

int main()
{
	{
		RegisterArray test = {
			0xFFFFFF11, 0xEEEEEE11, 0xDDDDDD11, 0xCCCCCC11
		};

		cout<<hex<<test;
		cycleShiftLeft(test, 0, 4);	
		cycleShiftLeft(test, 1, 8); 	
		cycleShiftLeft(test, 2, 12); 	
		cycleShiftLeft(test, 3, 16);
		cout<<test;
	}
	{
		RegisterPile test = {
			0xFFFFFF11, 0xEEEEEE11, 0xDDDDDD11, 0xCCCCCC11
		};

		cout<<hex<<test;
		cycleShiftLeft(test, reg_a, 4);	
		cycleShiftLeft(test, reg_b, 8); 	
		cycleShiftLeft(test, reg_c, 12); 	
		cycleShiftLeft(test, reg_d, 16);
		cout<<test;
	}
	{
		HiddenRegisterPile hiddenreg;
		hiddenreg.*HiddenRegisterPile::reg_a();
		cout << cycleShiftLeft(hiddenreg, &HiddenRegisterPile::reg_a, 0) << endl;
		cout << cycleShiftLeft(hiddenreg, &HiddenRegisterPile::reg_b, 4) << endl;
		cout << cycleShiftLeft(hiddenreg, &HiddenRegisterPile::reg_c, 8) << endl;
		cout << cycleShiftLeft(hiddenreg, &HiddenRegisterPile::reg_d, 12) << endl;
	}
	return 0;
}