// HistogramProg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>


using namespace std;

#include "Histogram.h"
#include "HistogramProg.h"
#include "RandomEIntegerGenerator.h"

int main()
{


	/*
	* GENERATE VISUAL CONSOLE
	*/

	//DATASTORAGE INITIATION
	auto g_Log = std::make_unique<Logger>();

	//HISTOGRAM INITIATION
	Hist::Histogram g_Hist(std::move(g_Log));


	//LOOP UNTIL THIS IS TRUE
	bool bEnd = false;

	system("CLS");

	char input[3] = { 0, 0, 0 };

	int iRand = -1;

	while (!bEnd)
	{
		input[0] = 0;


		PrintMenu();
		cout << "Menu: ";
		cin.getline(input, 3);
		int iInput = atoi(input);

		switch (iInput)
		{

		case 1:			//ADD
			cout << "Give number to 1-5!: ";
			cin.getline(input, 3);
			iInput = atoi(input);
			g_Hist.add(static_cast<Hist::EInteger>(iInput));
			break;
		case 2:			//getMode
			cout << "Value is: ";
			cout << g_Hist.getMode();
			cout << " \n";
			break;
		case 3:			//getMinValue
			cout << "Value is: ";
			cout << g_Hist.getMinValue();
			cout << " \n";
			break;
		case 4:			//getMaxValue
			cout << "Value is: ";
			cout << g_Hist.getMaxValue();
			cout << " \n";
			break;
		case 5: //Get Count
			cout << "Count is: ";
			cout << g_Hist.getCount();
			cout << "\n";
			break;
			/******************************************************/
		case 10: //GENEREATE ONE RANDOM NUMBER
			WriteRandom(g_Hist, 1);
			break;
			//GENEREATE n+1 RANDOM NUMBERS
		case 11:
			cout << "Give number to 1-99!: ";
			cin.getline(input, 3);
			iInput = atoi(input);

			if (iInput < 1 and iInput > 99)
			{
				cout << " \n Value is not in range!";
			}
			else
			{
				WriteRandom(g_Hist, iInput);
			}

			break;
			/******************************************************/
		case 20: //Write Data
			WriteData(g_Hist);
			break;
			/******************************************************/
		case 90: //END CASE NOT RELEATED TO SOFTWARE
			std::cout << "THIS IS A TEST";
			break;
		case 99:
			bEnd = true;
			break;
		default:
			break;
		}

		//CONFIRMATION	
		system("pause");

		system("CLS");


	}



}

void WriteData(const Hist::Histogram& g_Hist)
{
	int iCount = 0;

	cout << "VECTOR DATA  \n";

	if (g_Hist.getCount() == 0) { cout << "NO DATA!\n"; return; };

	for (int i = 0; i < g_Hist.getCount(); i++)
	{
		cout << g_Hist.getOneData(i);
		cout << " ";

		if (iCount++ > 49)
		{
			cout << "\n";
			iCount = 0;
		}
	}

	cout << "\n";
	cout << "DATA END\n";

}


void WriteRandom(Hist::Histogram& g_Hist, int count)
{
	Hist::RandomEIntegerGenerator c_Rand;

	Hist::EInteger iRand = Hist::Zero;

	cout << "Writing (";
	cout << count;
	cout << ") Randoms\n";
	for (int i = 0; i < count; i++)
	{
		Hist::EInteger iRand = c_Rand();//c_Rand.GetRand();
		g_Hist.add(iRand);
	}

	cout << "end\n";

}

void PrintMenu()
{
	cout << "*************************************\n";
	cout << "Operations\n";
	cout << " 1 - ADD\n";
	cout << " 2 - getMode\n";
	cout << " 3 - getMinValue\n";
	cout << " 4 - getMaxValue\n";
	cout << " 5 - Count\n";

	cout << "10 - Generate One random\n";
	cout << "11 - Generate X number of randoms\n";

	cout << "20 - Show data\n";

	cout << "90 - Test\n";
	cout << "99 - Exit\n";

	cout << "*************************************\n";
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
