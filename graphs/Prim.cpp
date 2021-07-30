#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef long long int ll;
typedef vector<int> vi;
const int inf = INT_MAX;
// prims algo using adjacency matrix representation
// tim complezity = O(n^2)
const int V = 5;

// Driver code
int main()
{
	/* Let us create the following graph
		2 3
	(0)--(1)--(2)
	| / \ |
	6| 8/ \5 |7
	| / \ |
	(3)-------(4)
			9	 */
    int V = 5;



	int adjMat[V+1][V+1] = {  { 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 2, 0, 6, 0 },
						{ 0, 2, 0, 3, 8, 5 },
						{ 0, 0, 3, 0, 0, 7 },
						{ 0, 6, 8, 0, 0, 9 },
						{ 0, 0, 5, 7, 9, 0 } };
    int A = V;
    vector<int> mstSet (A+1, 0);
    vector<int> key(A+1, inf), parent(A+1,-1);
    //mstSet.insert(1);
    key[1] = 0;
    parent[1] = -1;
    for(int c =0;c<A;c++){
        int min = INT_MAX,minkey;
        for(int i=1;i<=A;i++){
            if(mstSet[i]==0 && key[i] < min) minkey = i, min = key[i];
            //cout<<minkey<<" i = :"<<i<<endl;
        }
        mstSet[minkey] = 1;
        for(int i=1;i<A+1;i++){
            if(adjMat[minkey][i] && mstSet[i]==0 && adjMat[minkey][i] < key[i]){
                parent[i] = minkey;
                key[i] = adjMat[minkey][i];
            }
        }
    }
    //cout<<"Edge \tWeight\n";
	long long ans = 0;
	for (int i = 1; i < A+1; i++){
		ans += adjMat[i][parent[i]];
		cout<<parent[i]<<" - "<<i<<" \t"<<adjMat[i][parent[i]]<<" \n";

	}

	return 0;
}
