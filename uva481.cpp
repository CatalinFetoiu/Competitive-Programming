#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;



void lis(vector<int> v)
{
	

	int index;
	//int len;
	vector<int>::iterator low;
	vector<int> tailTable;
	tailTable.push_back(v[0]);
	vector<int> parent;
	parent.resize(v.size());
	parent[0] = -1;
	vector<int> indices;
	indices.push_back(0);
	
	for(int i = 1; i < v.size(); i++)
	{
		if(v[i] < tailTable[0])
		{
			tailTable[0] = v[i];
			indices[0] = i;
			parent[i] = -1;
		}
		else if(v[i] > tailTable[tailTable.size() - 1])
		{
			parent[i] = indices[indices.size() - 1];
			tailTable.push_back(v[i]);
			indices.push_back(i);
		}
		else
		{
			low = lower_bound(tailTable.begin(), tailTable.end(), v[i]);
			index = low - tailTable.begin(); //e ceil direct aici
			cout << index << " ";
			
			parent[i] = indices[index - 1];
			tailTable[index] = v[i];
			indices[index] = i;
		}
		cout << tailTable.size() << endl;
	}
	cout << endl;
	
	stack<int> st;
	
	printf("%d\n", tailTable.size());
	printf("-\n");
	index = indices[indices.size() - 1];
	
	while(index != -1)
	{
		st.push(v[index]);
		index = parent[index];
	}
	while(!st.empty())
	{
		printf("%d\n", st.top());
		st.pop();
	}
	
} 












int main()
{
	vector<int> v;
	int n;
	while(scanf("%d", &n) != EOF)
	{
		v.push_back(n);
	}
	
	lis(v);
	v.clear();
	
	return 0;
}
	






