#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std; 

int solve(vector<int> weight, vector<int> value, int index, int capacity)
{
	//base case
	//if only 1 item to steal, then just compare its weight with the knapsack capacity
	if(index == 0)
	{
		if(weight[0] <= capacity)
			return value[0];
		else
			return 0;
	}

	int include = 0;
	if(weight[index] <= capacity)
	{
		include = value[index] + solve(weight, value, index-1, capacity - weight[index]);
	}

	int exclude = 0 + solve(weight, value, index-1, capacity);

	int ans = max(include, exclude);

	return ans;
	
}

int solveMem(vector<int> weight, vector<int> value, int index, int capacity, vector<vector<int>>& dp)
{
	//base case
	//if only 1 item to steal, then just compare its weight with the knapsack capacity
	if(index == 0)
	{
		if(weight[0] <= capacity)
			return value[0];
		else
			return 0;
	}

	if(dp[index][capacity] != -1)
		return dp[index][capacity];

	int include = 0;
	if(weight[index] <= capacity)
	{
		include = value[index] + solveMem(weight, value, index-1, capacity - weight[index], dp);
	}

	int exclude = 0 + solveMem(weight, value, index-1, capacity, dp);

	dp[index][capacity] = max(include, exclude);

	return dp[index][capacity];
	
}

int solveTab(vector<int> weight, vector<int> value, int n, int capacity)
{
	vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

	for(int w = weight[0]; w <= capacity; w++)
	{
		if(weight[0] <= capacity)
			dp[0][w] = value[0];
		else
			dp[0][w] = 0;
	}

	for(int index = 1; index < n; index++)
	{
		for(int w = 0; w <= capacity; w++)
		{
			int include = 0;

			if(weight[index] <= w)
				include = value[index] + dp[index-1][w - weight[index]];
			
			int exclude = 0 + dp[index-1][w];

			dp[index][w] = max(exclude, include);
		}
	}

	return dp[n-1][capacity];
}

int solveTabSO(vector<int> weight, vector<int> value, int n, int capacity)
{
	vector<int> prev(capacity+1, 0);
	vector<int> curr(capacity+1, 0);

	for(int w = weight[0]; w <= capacity; w++)
	{
		if(weight[0] <= capacity)
			prev[w] = value[0];
		else
			prev[w] = 0;
	}

	for(int index = 1; index < n; index++)
	{
		for(int w = 0; w <= capacity; w++)
		{
			int include = 0;

			if(weight[index] <= w)
				include = value[index] + prev[w - weight[index]];
			
			int exclude = 0 + prev[w];

			curr[w] = max(exclude, include);
		}
		prev = curr;
	}

	return prev[capacity];
}

int solveTabSO1(vector<int> weight, vector<int> value, int n, int capacity)
{
	//solving with only one array.
	vector<int> curr(capacity+1, 0);

	for(int w = weight[0]; w <= capacity; w++)
	{
		if(weight[0] <= capacity)
			curr[w] = value[0];
		else
			curr[w] = 0;
	}

	for(int index = 1; index < n; index++)
	{
		//not possible to solve with only one array while going from left to right
		//but possible to solve with only one array while going from RIGHT to LEFT

		for(int w = capacity; w >= 0; w--)
		{
			int include = 0;

			if(weight[index] <= w)
				include = value[index] + curr[w - weight[index]];
			
			int exclude = 0 + curr[w];

			curr[w] = max(exclude, include);
		}

	}

	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	// return solve(weight, value, n-1, maxWeight);

	// vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
	// return solveMem(weight, value, n-1, maxWeight, dp);


    // return solveTabSO(weight, value, n, maxWeight);


    return solveTabSO1(weight, value, n, maxWeight);
}


int main()
{
    int n;
    cin >> n;

    vector<int> weight(n), value(n);

    for(int i = 0; i < n; i++)
        cin >> weight[i];

    for(int i = 0; i < n; i++)
        cin >> value[i];

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weight, value, n, maxWeight) << endl;

    return 0;
}
