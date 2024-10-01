#include <iostream>
#include <string>
#include <limits>

int main()
{
	//=======================================================================================================
	//This is ok, one getline after another
	
	std::string firstName;
	std::string lastName;

	std::cout << "Please enter your first name: ";
	std::getline(std::cin, firstName);

	std::cout << "Please enter your last name: ";
	std::getline(std::cin, lastName);
	
	std::cout << "Your name is " << firstName + " " + lastName << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	//=======================================================================================================
	//It begins to become a problem if you enter two or more characters for either of the inputs
	//This happens because the second buffer accepts the extra input of the first char input

	char firstNameInitial;
	std::cout << "Please enter the initial for your first name: ";
	std::cin >> firstNameInitial;

	//Uncomment this line to fix issue - this will ignore all extra garbage
	//std::cin.ignore(std::numeric_limits<int>::max(), '\n');
	
	char lastNameInitial;
	std::cout << "Please enter the initial for your last name: ";
	std::cin >> lastNameInitial;

	std::cout << "Your initials are " << firstNameInitial << " and " << lastNameInitial << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	//=======================================================================================================
	//Worse yet, you could enter an invalid character instead of a requested number
	//This will keep the loop below running indefinitely since it now contains garbage data

	int choice = 0;

	do
	{
		std::cout << "> ";
		std::cin >> choice;
		
		//Uncomment to reset the buffer to a working state and clear it of any garbage characters
		//std::cin.clear();
		//std::cin.ignore(std::numeric_limits<int>::max(), '\n');

	} while (choice < 1 || choice > 5);

	std::cout << "You entered the value " << choice << std::endl;

	system("pause");
	return 0;
}