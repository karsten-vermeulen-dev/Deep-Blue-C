#pragma once
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

void RemoveEvenNumbers()
{
	std::deque<int> numbers = { 11, 20, 34, 5, 10, 44, 7, 6 };

	//Uncomment to use this method -> pass the Lambda object code as a function argument
	/*auto it = std::remove_if(numbers.begin(), numbers.end(),
		[](int number) { return (number % 2 == 0); });*/

	auto IsEven = [](int number)
	{
		return (number % 2 == 0);
	};

	auto it = std::remove_if(numbers.begin(), numbers.end(), IsEven);
	numbers.erase(it, numbers.end());

	std::cout << "Removing even numbers from container..." << std::endl;

	for (const auto& number : numbers)
	{
		std::cout << number << ", ";
	}

	std::cout << std::endl << std::endl;
}

void RemoveVowels()
{
	std::vector<std::string> objects
	{
		"Chair",
		"Apple",
		"Orange",
		"Table",
		"Gun",
		"Ammunition",
		"Axe"
	};

	auto IsVowel = [](const std::string& name)
	{
		char vowels[] = { 'A', 'E', 'I', 'O', 'U' };

		for (auto vowel : vowels)
		{
			if (name[0] == vowel)
			{
				return true;
			}
		}

		return false;
	};

	auto it = std::remove_if(objects.begin(), objects.end(), IsVowel);
	objects.erase(it, objects.end());

	std::cout << "Removing object names that begin with a vowel..." << std::endl;

	for (const auto& object : objects)
	{
		std::cout << object << std::endl;
	}

	std::cout << std::endl;
}

void SortLength()
{
	std::vector<std::string> players
	{
		"John",
		"Harry",
		"Tim",
		"Lilly",
		"Jo",
		"Margaret",
		"Amy"
	};

	auto SortByLength = [](const std::string& lhs, const std::string& rhs)
	{
		return lhs.size() < rhs.size();
	};

	std::sort(players.begin(), players.end(), SortByLength);

	std::cout << "Sorting names by their length..." << std::endl;

	for (const auto& player : players)
	{
		std::cout << player << std::endl;
	}

	std::cout << std::endl;
}

void RemovePuntuation()
{
	std::string sentence = "Hello, how are you? I am fine!";

	auto RemovePuntuation = [](char letter)
	{
		char punctuation[] = { '.', ',', '?', '!', ':', ' ' };

		for (auto p : punctuation)
		{
			if (letter == p)
			{
				return true;
			}
		}

		return false;
	};

	auto it = std::remove_if(sentence.begin(), sentence.end(), RemovePuntuation);
	sentence.erase(it, sentence.end());

	std::cout << "Removing punctuation from sentence..." << std::endl;

	std::cout << sentence << std::endl << std::endl;
}

void main()
{
	RemoveEvenNumbers();
	RemoveVowels();
	SortLength();
	RemovePuntuation();

	system("pause");
}