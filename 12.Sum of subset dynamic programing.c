// A recursive solution for subset sum problem

#include <stdio.h>
#include <stdbool.h>

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0)
		return false;

	// If last element is greater than sum,
	// then ignore it
	if (set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);

	// Else, check if sum can be obtained by any
	// of the following:
	// (a) including the last element
	// (b) excluding the last element
	return isSubsetSum(set, n - 1, sum)
		|| isSubsetSum(set, n - 1, sum - set[n - 1]);
}

// Driver code
int main()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}

