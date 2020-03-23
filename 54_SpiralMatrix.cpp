#include <iostream>
#include <vector>

using namespace std;

vector<int> SpiralTraversal(vector<vector<int>> matrix)
{
	//sanity checks
	if (matrix.empty()) return vector<int>();

	//keep track of move direction and available steps
	bool movHz = true; //moving horizontally
	bool movRv = false; //moving vertically
	int hzMaxSteps = matrix[0].size(); //total horizontal steps
	int vtMaxSteps = matrix.size()-1; //total vertical steps
	int i=0,j=0; //starting pos

	vector<int> vecSpiral;

	while(true)
	{
		//no more steps available
		if( (movHz ? hzMaxSteps : vtMaxSteps) <= 0)
			break;

		//move ahead available number of steps in the correct direction
		if (movHz)
			for(int x =0; x<hzMaxSteps; x++)
				vecSpiral.push_back(movRv ? matrix[i][j--] : matrix[i][j++]);
		else
			for(int x =0; x<vtMaxSteps; x++)
				vecSpiral.push_back(movRv ? matrix[i--][j] : matrix[i++][j]);

		//fix overshoot
		if (movHz)
			movRv ? j++ : j--;
		else
			movRv ? i++ : i--;

		//update max steps
		movHz ? hzMaxSteps-- : vtMaxSteps--;


		//change direction
		movHz = !movHz;

		//change reverse or forward order
		//if going from v to h
		movRv = movHz ? !movRv : movRv;

		//change indices to new starting position
		if (movHz)
			movRv ? j-- : j++;
		else
			movRv ? i-- : i++;
	}

	return vecSpiral;

}

int main()
{
	int m,n;

	cin >> m;
	cin >> n;

	vector<vector<int>> matrix(m,vector<int>(n));

	for (int i =0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cin >> matrix[i][j];
	}

	vector<int> vecResult = SpiralTraversal(matrix);

	for(auto & num : vecResult)
		cout << num <<  " ";
	cout << endl;
	return 0;
}
