#include <iostream>
#include <string>

using namespace::std;

int printIndent(int x)
{
    while (x>0)
    {
	cout << " ";
	x--;
    }
}

int factorial(int n)
{
    int fact = 1;
    if (n>0)
    {
	fact = n * factorial(n-1);
    }

    return fact;
}

int factorialWithTrace(int n,int indent)
{
    printIndent(indent);
    cout << "Entering factorialWithTrace(" << n << ")" << endl;
    int fact = 1;
    if (n>0)
    {
	int answer = factorialWithTrace(n-1,indent+2);
	fact = n * answer;
	printIndent(indent);
	cout << "Back from factorialWithTrace(" << n-1 << ") and the answer is " << answer << endl;
    }

    printIndent(indent);
    cout << "Returning the value " << fact << " from factorialWithTrace(" << n << ")" << endl;
    return fact;
}

void writeBackwards(const string s)
{
    if (s.length() > 0)
    {
	cout << s.back();
	writeBackwards(s.substr(0,s.length()-1));
    }
}

void writeBackwards2(const string s)
{
    if (s.length() > 0)
    {
	writeBackwards2(s.substr(1,s.length()));
	cout << s.front();
    }
}

void writeArray(const int arr[], int first, int last)
{
    if (first <= last)
    {
	cout << arr[first] << " ";
	writeArray(arr,first+1,last);
    }
}

void writeArrayBackwards(const int arr[], int first, int last)
{
    if (first <= last)
    {
	cout << arr[last] << " ";
	writeArrayBackwards(arr,first,last-1);
    }
}

int binarySearch(const int arr[], int first, int last, int target)
{
    int index = 0;
    if (first > last)
    {
	index = -1;
    }
    else
    {
	int mid = first + (last - first)/2;
	if (arr[mid] == target)
	{
	    index = mid;
	}
	else
	{
	    if (target < arr[mid])
	    {
		index = binarySearch(arr,first,mid-1,target);
	    }
	    else
	    {
		index = binarySearch(arr,mid+1,last,target);
	    }
	}
    }
    return index;
}

int main()
{
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Recursive factorial(7) = ";
    cout << factorial(7) << endl;
    cout << "Recursive factorialWithTrace(3): " << endl;
    factorialWithTrace(3,2);

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Writing backwards \"cat\": ";
    writeBackwards("cat");
    cout << endl;
    cout << "Writing backwards2 \"cat\": ";
    writeBackwards2("cat");
    cout << endl;

    int arr[] = {1,2,3,4,5,6,7};
    cout << "----------------------------------------------------------------------" << endl;    
    cout << "Working with this array: ";
    writeArray(arr,0,6);
    cout << endl;

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Writing array backwards: ";
    writeArrayBackwards(arr,0,6);
    cout << endl;

    cout << "----------------------------------------------------------------------" << endl;
    int target = 3;
    cout << "Binary search for " << target << " --> found at " << binarySearch(arr,0,6,target) << endl;
    target = 1;
    cout << "Binary search for " << target << " --> found at " << binarySearch(arr,0,6,target) << endl;
    target = 7;
    cout << "Binary search for " << target << " --> found at " << binarySearch(arr,0,6,target) << endl;
    target = 11;
    cout << "Binary search for " << target << " --> found at " << binarySearch(arr,0,6,target) << endl;
    return 0;
}
