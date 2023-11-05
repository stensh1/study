//Orshak Ivan, 7362, lab 5, 10.12.2018

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

std::vector<int> prefix_func(const std::string &s) 
{
	std::vector<int> p(s.length());

	int k = 0;
	p[0] = 0;

	for (int i = 1; i < s.length(); ++i) {
		while (k > 0 && s[k] != s[i]) {
			k = p[k - 1];
		}
		if (s[k] == s[i]) {
			++k;
		}
		p[i] = k;
	}

	return p;
}

int find(std::string &haystack, std::string &needle) 
{
	if (haystack.length() < needle.length()) 
		throw std::string("Образ больше строки");

	if (!needle.length()) 
		throw std::string("Образ отсутствует");

	std::map<char, int> stop_table;
	std::map<int, int> suffics_table;

	for (int i = 0; i < needle.length(); ++i) 
		stop_table[needle[i]] = i;

	std::string rt(needle.rbegin(), needle.rend());
	std::vector<int> p = prefix_func(needle), pr = prefix_func(rt);

	for (int i = 0; i < needle.length() + 1; ++i) 
		suffics_table[i] = needle.length() - p.back();

	for (int i = 1; i < needle.length(); ++i) 
	{
		int j = pr[i];
		suffics_table[j] = std::min(suffics_table[j], i - pr[i] + 1);
	}

	for (int shift = 0; shift <= haystack.length() - needle.length();) 
	{
		int pos = needle.length() - 1;

		while (needle[pos] == haystack[pos + shift]) 
		{
			if (pos == 0) return shift;
			--pos;
		}

		if (pos == needle.length() - 1) 
		{
			auto stop_symbol = stop_table.find(haystack[pos + shift]);
			int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);
			shift += stop_symbol_additional;
		}
		else 
			shift += suffics_table[needle.length() - pos - 1];
	}

	return -1;
}

int main() 
{
	setlocale(LC_ALL, "ru");
	std::string haystack;
	std::string needle;
	std::cout << "Введите строку: ";
	std::getline(std::cin, haystack);
	std::cout << "Введите образ: ";
	std::getline(std::cin, needle);

	try 
	{
		int result = find(haystack, needle);
		std::cout << "Образ начинается с " << result << " индекса." << std::endl;
	}
	catch (std::string &str) 
	{
		std::cout << "Что-то случилось: " << str << std::endl;
	}

	system("pause");
	return 0;
}