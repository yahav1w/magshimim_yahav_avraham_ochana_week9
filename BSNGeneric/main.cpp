
#include "iostream"
#include "BSNode.hpp"

int main()
{
	int ints[] = { 15, 2, 1, 4, 3, 6, 11, 8, 10, 9, 5, 12, 13, 7, 14 };
	std::string strings[] = { "E","B","C","A","F","Z","12","X","Y","J","L","I","K","H","P" };
	
	for (int i = 0;i < 15;i++)
	{
		std::cout << ints[i] << " ";
	}
	std::cout << "\n";
	for (int i = 0;i < 15;i++)
	{
		std::cout << strings[i] << " ";
	}
	std::cout << "\n";
	BSNode<int> bsInt = BSNode<int>(ints[0]);
	for (int i = 1;i < 15;i++)
	{
		bsInt.insert(ints[i]);
	}
	BSNode<std::string> bsStr = BSNode<std::string>(strings[0]);
	for (int i = 1;i < 15;i++)
	{
		bsStr.insert(strings[i]);
	}
	bsInt.printNodes();
	std::cout << "\n";
	bsStr.printNodes();



	return 0;
}