/*
Muhammad Raheel L1F24BSCS0786
Pf Section B12 Assignment One problem Three b

2.	Write complete C++ code that reads length 
and width of many rectangles from a text file 
“rects.txt” and then displays on screen area, 
perimeter of each rectangle, the average area, average 
perimeter, maximum area and perimeter, minimum area
and perimeter.

*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	const int n = 10;
	int len[n] = {}, width[n] = {};
	int areaArr[n], periArr[n];
	int area = 0, perimeter = 0, total = 0, sum = 0, sum2 = 0;
	int largest = INT_MIN, largest2 = INT_MIN;
	int smallest = INT_MAX, smallest2 = INT_MAX;
	float finalAverage = 0, finalPerimeter = 0;

	ifstream read("rectangles.txt");
	if (!read)
	{
		cout << "Error in opening file";
		return 1;
	}

	int temp, i = 0;
	while (read >> temp && i < 2 * n)
	{
		if (i % 2 == 0)
			len[i / 2] = temp;
		else
			width[i / 2] = temp;
		i++;
	}

	int rectCount = i / 2;

	cout << "Rectangles (Length x Width):\n";
	for (int j = 0; j < rectCount; j++)
	{
		cout << "Rectangle " << j + 1 << ": " << len[j] << " x " << width[j] << endl;
	}

	cout << "\nAreas: { ";
	for (int i = 0; i < rectCount; i++)
	{
		area = len[i] * width[i];
		areaArr[i] = area;
		cout << area;
		if (i != rectCount - 1) cout << ", ";
		sum += area;
	}
	cout << " }" << endl;

	cout << "Perimeters: { ";
	for (int i = 0; i < rectCount; i++)
	{
		perimeter = 2 * (len[i] + width[i]);
		periArr[i] = perimeter;
		cout << perimeter;
		if (i != rectCount - 1) cout << ", ";
		sum2 += perimeter;
	}
	cout << " }" << endl;

	finalAverage = (float)sum / rectCount;
	finalPerimeter = (float)sum2 / rectCount;
	cout << "\nAverage Area: " << finalAverage;
	cout << "\nAverage Perimeter: " << finalPerimeter << endl;

	for (int i = 0; i < rectCount; i++)
	{
		if (areaArr[i] > largest) largest = areaArr[i];
		if (areaArr[i] < smallest) smallest = areaArr[i];
	}

	for (int i = 0; i < rectCount; i++)
	{
		if (periArr[i] > largest2) largest2 = periArr[i];
		if (periArr[i] < smallest2) smallest2 = periArr[i];
	}

	cout << "\nMaximum Area: " << largest;
	cout << "\nMinimum Area: " << smallest;
	cout << "\nMaximum Perimeter: " << largest2;
	cout << "\nMinimum Perimeter: " << smallest2 << endl;

	return 0;
}
