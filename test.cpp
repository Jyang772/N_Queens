#include <iostream>

using namespace std;

int Number_of_Solutions = 0;
int Number_of_Recursions = 0;
const int N = 4;

int position[N+1];     //create int array named position with N number of elements

// Check if a position is safe
bool isSafe(int queen_number, int row_position)
{
	// Check each queen before this one
	for (int i = 1; i < queen_number; i++)   (since k = 1,2,3,4. There is the same amount of loop iterations as 0,1,2,3)
	{
		// Get another queen's row_position
		int other_row_pos = position[i];

		// Now check if they're in the same row or diagonals
		if (other_row_pos == row_position || // Same row
			other_row_pos == row_position - (queen_number - i) || // Same diagonal
			other_row_pos == row_position + (queen_number - i))   // Same diagonal
			return false;
	}
	return true;
}


// Recursively generate a tuple like [0 0 0 0], then [0 0 0 1] then etc...
void solve(int k)
{
	//cout << "In solve()" << endl;
	if (k == N+1) // We placed N-1 queens (0 included), problem solved!
	{
		// Solution found!
		cout << "Solution: ";
		for (int i = 1; i <= N; i++)
			cout << position[i] << " ";
		Number_of_Solutions++;
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= N; i++) // Generate ALL combinations
		{
			// Before putting a queen (the k-th queen) into a row, test it for safeness
			//cout << k << " " << i << endl;
			if (isSafe(k, i))
			{
			//	cout << "K: " << k << " I: " << i << endl;
				position[k] = i;
				// Place another queen
				solve(k+1);
			//	cout << "Back!" << endl;

			}
		}
	}
}

int main()
{
	solve(1);       //starting at 1

	//cout << Number_of_Solutions << endl;
	//cout << Number_of_Recursions << endl;

	system("PAUSE");
	return 0;
}












