#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;



void compress();
int binarySearch(vector<int>& v, int key, int low, int high);



int main()
{
	compress();

	cout << endl;
	cout << endl;

	return 0;
}



void compress()
{
	vector<int> input{ -102, 1, 134565589, 134565589, -102, 66666668, 134565589, 66666668, -102, 1, -2 };
	vector<int> compressed(input.size(), 0);
	vector<int> sorted;

	int assign = 0; 
	int s = input.size(); 


	cout << "Size of the input : " << s << endl;
	cout << endl;

	cout << "input : " << endl;
	for (int i = 0; i < s; i++)
	{
		cout << input.at(i) << "  ";
	}
	cout << endl;
	cout << endl;


	cout << "\nCompressing................." << endl;

	sorted = input; // copying
	sort(sorted.begin(), sorted.end());


	auto x = unique(sorted.begin(), sorted.end());
	sorted.erase(x, sorted.end()); // erasing duplicate entries

	
	int n = sorted.size(); 


	for (int i = 0; i < n; i++)
	{
		cout << setw(10) << sorted.at(i) << "\tMapped with \t" << i << endl;
	}
	cout << endl;


	for (int i = 0; i < s; i++)
	{
		int index;

		index = binarySearch(sorted, input.at(i), 0, n - 1);

		compressed.at(i) = index;
	}


	cout << endl;
	cout << "Compressed array : ";

	n = compressed.size(); // size of compressed vector
	for (int i = 0; i < n; i++)
	{
		cout << compressed.at(i) << "  ";
	}
	cout << endl;
}



int binarySearch(vector<int>& v, int key, int low, int high)
{
	if (low > high) return -1; // search not possible

	int mid = (low + high) / 2;

	if (key == v.at(mid)) return mid; // found!
	else if (key > v.at(mid)) return binarySearch(v, key, mid + 1, high); // search in left
	else return binarySearch(v, key, low, mid - 1); // search in right
}
