#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<iomanip>

using namespace std;

class Calculator
{
public: 
	class Powers
	{
	public:
		//2. square
		//3. cubes
		//4. exponential values
		//8. constant e

		static double sqr(double valueOne)
		{
			return valueOne * valueOne;
		}
		static double cube(double valueOne)
		{
			return valueOne * valueOne * valueOne;
		}
		static double expo(double valueOne, double valueTwo)
		{
			double temp = valueOne;
			for (int i = 1; i < valueTwo; i++)
				temp *= valueOne;
			return temp;
		}
		static double constE(double valueOne)
		{
			double E = 2.718281828;
			return pow(E, valueOne);
		}
	};

	class Roots
	{
	public:
		//5. square root
		//6. cube root 
		//7. xth root 

		static double sqrR(double valueOne)
		{
			return pow(valueOne, 0.5);
		}
		static double cubeR(double valueOne)
		{
			return pow(valueOne, 0.3333333);
		}
		static double xthR(double valueOne, double valueTwo) 
		{
			return pow(valueOne, 1 / valueTwo);
		}
	};

	class Trignomatric
	{
	public:
		//11. sin, cos, tan, cosec, sec and cot.

		static double sinFunc(double valueOne)
		{
			return (sin(valueOne * 3.141592 / 180) < 0.001 ? 0 : sin(valueOne * 3.141592 / 180));
		}
		static double cosFunc(double valueOne)
		{
			return (cos(valueOne * 3.141592 / 180) < 0.001 ? 0 : cos(valueOne * 3.141592 / 180));
		}
		static double tanFunc(double valueOne)
		{
			return (valueOne == 90 ? 236 : tan(valueOne * 3.141592 / 180));    // infinity check //  236 -> infinity ASCII 
		}
		static double csecFunc(double valueOne)
		{
			return (1 / (sin(valueOne * 3.141592 / 180)));    // csc = 1/sin(x)
		}
		static double secFunc(double valueOne)
		{
			return (valueOne == 90 ? 236 : (1 / (cos(valueOne * 3.141592 / 180))));  // sec = 1/cos(x)  // infinity check //  236 -> infinity ASCII 
		}
		static double cotFunc(double valueOne) 
		{
			return (1 / (tan(valueOne * 3.141592 / 180)));   // cot = 1/tan(x)
		}
	};

	class Basic
	{
	public:
		// add, subtract, multipliction, division.

		static double add(double valueOne, double valueTwo)
		{
			return valueOne + valueTwo;
		}
		static double sub(double valueOne, double valueTwo)
		{
			return valueOne - valueTwo;
		}
		static double multi(double valueOne, double valueTwo)
		{
			return valueOne * valueTwo;
		}
		static double div(double valueOne, double valueTwo)
		{
			return valueOne / valueTwo;
		}
	};

	class Advance
	{
	public:
		//1. inverse
		//9. natural log
		//10. factorial

		static double invrs(double valueOne)
		{
			return 1 / valueOne;
		}
		static double nLog(double valueOne)
		{
			return log(valueOne);
		}
		static double fact(double valueOne)
		{
			for (double i = valueOne - 1; i >= 0; i--)
			{
				if (i != 0)
					valueOne *= i;
			}
			return valueOne;
		}
	};

	static int menu()
	{
		int selection;
		cout << "1. Inverse" << endl;
		cout << "2. Square" << endl;
		cout << "3. Cube" << endl;
		cout << "4. Exponential" << endl;
		cout << "5. Square Root" << endl;
		cout << "6. Cube Root" << endl;
		cout << "7. xth Root" << endl;
		cout << "8. Power e" << endl;
		cout << "9. Natural Log" << endl;
		cout << "10. Factorial" << endl;
		cout << "11. Sin of x" << endl;
		cout << "12. Cos of x" << endl;
		cout << "13. Tan of x" << endl;
		cout << "14. Csc of x" << endl;
		cout << "15. Sec of x" << endl;
		cout << "16. Cot of x" << endl;
		cout << "17. Addition" << endl;
		cout << "18. Subtraction" << endl;
		cout << "19. Multiplication" << endl;
		cout << "20. Division" << endl;
		cout << "-------------------------------------------------" << endl;
		
		cout << "Enter your Choice Number: ";
		cin >> selection;
		while (selection <= 0 || selection > 20)
		{
			cout << "Error: Input is out of range..! Input again: ";
			cin >> selection;
		}
		return selection;
	}
	
	// -----------FILE HANDLING.-----------------
	static void wright(string str, double num1, double result, double num2 = NULL)
	{
		ofstream out;
		out.open("file.txt", ios::app);
		if (out.is_open())
		{
			if(num2 != NULL)
				out << setw(5) << left << num1 << setw(15) << left << str << setw(6) << left << num2 << setw(5) << right << "Result: " << result << endl;
			else
				out << setw(5) << left << num1 << setw(21) << left << str << setw(6) << right << "Result: " << result << endl;
		}
		out.close();
	}

	static void read()
	{
		string str;
		ifstream in;
		in.open("file.txt");
		if (in)
		{
			while (!in.eof())
			{
				getline(in, str);
				cout << str << endl;
			}
		}
		else
			cout << "File not opened!";

		in.close();
	}

};



int main()
{
	double result, valueOne, valueTwo;
	char yesNo = 'y';

	while (yesNo == 'y' || yesNo == 'Y')
	{
		switch (Calculator::menu())
		{
		case 1:     // inverse.	
			cout << "(Inverse)" << endl << "Input Value: ";
			cin >> valueOne;
			result = Calculator::Advance::invrs(valueOne);
			Calculator::wright("Inverse.", valueOne, result);  // wright in file
			break;

		case 2:   // square.
			cout << "(Square)" << endl << "Input Value: ";
			cin >> valueOne;
			result = Calculator::Powers::sqr(valueOne);
			Calculator::wright("Square.", valueOne, result);
			break;

		case 3:  // cube.
			cout << "(Cube)" << endl << "Input Value: ";
			cin >> valueOne;
			result = Calculator::Powers::cube(valueOne);
			Calculator::wright("Cube.", valueOne, result);
			break;

		case 4: // exponential
			cout << "(Exponential)" << endl << "Input Base: ";
			cin >> valueOne;
			cout << "Input Exponent: ";
			cin >> valueTwo;
			result = Calculator::Powers::expo(valueOne, valueTwo);
			Calculator::wright("Exponent", valueOne, result, valueTwo);
			break;

		case 5:  // square root 
			cout << "(Square Root)" << endl << "Input Value: ";
			cin >> valueOne;
			result = Calculator::Roots::sqrR(valueOne);
			Calculator::wright("Square Root.", valueOne, result);

			break;

		case 6: // cube root 
			cout << "(Cube Root)" << endl << "Input Value: ";
			cin >> valueOne;
			result = Calculator::Roots::cubeR(valueOne);
			Calculator::wright("Cube Root.", valueOne, result);

			break;

		case 7: // xth root
			cout << "(xth Root)" << endl << "Input Base: ";
			cin >> valueOne;
			cout << "xth root value: ";
			cin >> valueTwo;
			result = Calculator::Roots::xthR(valueOne, valueTwo);
			Calculator::wright("Under Root", valueOne, result, valueTwo);

			break;

		case 8: // power e
			cout << "(Exponent of e)" << endl << "Input exponent Value: ";
			cin >> valueOne;
			result = Calculator::Powers::constE(valueOne);
			Calculator::wright("Exponent of 'e'.", valueOne, result);
			break;

		case 9: // natural log
			cout << "(Natural Log)" << endl << "Input Value to find its Natural log: ";
			cin >> valueOne;
			result = Calculator::Advance::nLog(valueOne);
			Calculator::wright("Natural Log.", valueOne, result);
			break;

		case 10:  // factorial 
			cout << "(Factorial)" << endl << "Input Value: ";
			cin >> valueOne;
			result = Calculator::Advance::fact(valueOne);
			Calculator::wright("Factorial.", valueOne, result);
			break;

		case 11: // sin
			cout << "(Sin of x)" << endl << "Input x Value: ";
			cin >> valueOne;
			result = Calculator::Trignomatric::sinFunc(valueOne);
			Calculator::wright("Sin.", valueOne, result);
			break;

		case 12: // cos
			cout << "(Cos of x)" << endl << "Input x Value: ";
			cin >> valueOne;
			result = Calculator::Trignomatric::cosFunc(valueOne);
			Calculator::wright("Cos.", valueOne, result);
			break;

		case 13: // tan
			cout << "(Tan of x)" << endl << "Input x Value: ";
			cin >> valueOne;
			result = Calculator::Trignomatric::tanFunc(valueOne);
			Calculator::wright("Tan.", valueOne, result);
			break;

		case 14: // cosec
			cout << "(Cosec of x)" << endl << "Input x Value: ";
			cin >> valueOne;
			result = Calculator::Trignomatric::csecFunc(valueOne);
			Calculator::wright("Cosec.", valueOne, result);
			break;

		case 15: // sec
			cout << "(Sec of x)" << endl << "Input x Value: ";
			cin >> valueOne;
			result = Calculator::Trignomatric::secFunc(valueOne);
			Calculator::wright("Sec.", valueOne, result);
			break;

		case 16: // cot
			cout << "(Cot of x)" << endl << "Input x Value: ";
			cin >> valueOne;
			result = Calculator::Trignomatric::cotFunc(valueOne);
			Calculator::wright("Cot.", valueOne, result);

			break;

		case 17: // add
			cout << "(Addition)" << endl << "Input 1st Value: ";
			cin >> valueOne;
			cout << "Input 2nd Value: ";
			cin >> valueTwo;
			result = Calculator::Basic::add(valueOne, valueTwo);
			Calculator::wright("Add", valueOne, result, valueTwo);
			break;

		case 18: // subtract
			cout << "(Subtraction)" << endl << "Input 1st Value: ";
			cin >> valueOne;
			cout << "Input 2nd Value: ";
			cin >> valueTwo;
			result = Calculator::Basic::sub(valueOne, valueTwo);
			Calculator::wright("Subtract", valueOne, result, valueTwo);
			break;

		case 19: // multiply
			cout << "(Multiplication)" << endl << "Input 1st Value: ";
			cin >> valueOne;
			cout << "Input 2nd Value: ";
			cin >> valueTwo;
			result = Calculator::Basic::multi(valueOne, valueTwo);
			Calculator::wright("Multiplied", valueOne, result, valueTwo);
			break;

		case 20: // divide
			cout << "(Division)" << endl << "Input 1st Value: ";
			cin >> valueOne;
			cout << "Input 2nd Value: ";
			cin >> valueTwo;
			result = Calculator::Basic::div(valueOne, valueTwo);
			Calculator::wright("Divided by", valueOne, result, valueTwo);
			break;
		}

		// Ternory operator is not working with diff data types.
		//cout << "Result: " << (result == 236 ? "Infinity": result) << endl << endl;
		
		cout << "Result: ";
		if (result == 236)
			cout << "Infinity";
		else
			cout << result;
		cout << endl << endl;
		
		cout << "Do you want to calculate more if yes enter 'y' or 'Y' else enter any other: ";
		cin >> yesNo;

		system("cls");
	}

	cout << "<< Your Calculations >>" << endl << endl;
	Calculator::read();                    // read file 

	return 0;
}
