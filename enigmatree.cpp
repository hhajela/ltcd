#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;

class Solution
{
    private:

    map<int,vector<int>> mapNodes;

    vector<vector<bool>> vecEdges;


    public:

    int MinCorrections(const vector<pair<int,int>> & vecConnections, vector<bool> vecActValues, const vector<bool> & vecExpValues)
    {
        //build tree
        BuildTree(vecConnections);

        /*
        for (auto & connection : vecConnections)
        {
            if (mapNodes.find(connection.first-1) == mapNodes.end())                
                mapNodes[connection.first-1] = vector<int> {connection.second-1};
            else
                mapNodes[connection.first-1].push_back(connection.second-1);
        }
        */

        //compute min cost of correction starting at root
        return MinCorrectionCost(0, vecActValues, vecExpValues);
    }

    void PrintTree()
    {
        for (auto & item : mapNodes)
        {
            cout << "Node " << item.first << " has children ";
            for (auto & child : item.second)
            {
                cout << child << " ";
            }
            cout << endl;
        }
    }

    void BuildTree(const vector<pair<int,int>> & vecConnections)
    {
        //build tree starting at root lvl
        vector<bool> processed(vecConnections.size(),false);
        queue<int> processThese;
        processThese.push(1);

        //at each level, find all children for each node among the unprocessed edges
        while(!processThese.empty())
        {
            int index = processThese.front();
            processThese.pop();

            for(int i=0; i<vecConnections.size(); i++)
            {
                if (processed[i]) continue;

                if (vecConnections[i].first == index)
                {
                    if (mapNodes.find(index-1) == mapNodes.end())
                        mapNodes[index-1] = vector<int> {vecConnections[i].second -1};
                    else
                        mapNodes[index-1].push_back(vecConnections[i].second -1);

                    processed[i] = true;
                    processThese.push(vecConnections[i].second);
                    
                }
                else if (vecConnections[i].second == index)
                {
                    if (mapNodes.find(index-1) == mapNodes.end())
                        mapNodes[index-1] = vector<int> {vecConnections[i].first -1};
                    else
                        mapNodes[index-1].push_back(vecConnections[i].first -1);
                    
                    processed[i] = true;
                    processThese.push(vecConnections[i].first);
                }
            }
        }

    }

    void BuildTree2(const vector<pair<int,int>> & vecConnections, int nSize)
    {
        vecEdges.resize(nSize);

        for(auto & vec : vecEdges) vec.resize(nSize);

        for (auto & connection : vecConnections)
        {
            vecEdges[connection.first-1][connection.second -1] = true;
            vecEdges[connection.second-1][connection.first -1] = true; 
        }
    }

    int MinCorrectionCost(int nodeIndex, vector<bool> vecActValues, const vector<bool> & vecExpValues, bool flipped=false)
    {
        // min cost to correct node at node index = min(cost to fix just this + min cost (for each node in subtree), cost to flip whole subtree(1) + min cost (fix each subtree)

        //base case, node is a leaf
        if (mapNodes.find(nodeIndex) == mapNodes.end())
            return (flipped ? !vecActValues[nodeIndex] : vecActValues[nodeIndex]) ^ vecExpValues[nodeIndex];
        else
        {
            int costForThisNode = (flipped ? !vecActValues[nodeIndex] : vecActValues[nodeIndex]) ^ vecExpValues[nodeIndex];
            
            int sum = 0;
            //sum up cost for the subtree nodes
            for (auto & node : mapNodes[nodeIndex])
            {
                sum += MinCorrectionCost(node, vecActValues, vecExpValues, flipped);
            }

            int sumFlipped = 0;
            //sum up cost for the subtree nodes flipped
            for (auto & node : mapNodes[nodeIndex])
            {
                sumFlipped += MinCorrectionCost(node, vecActValues, vecExpValues, !flipped);
            }

            return min(costForThisNode + sum, 1 + !costForThisNode + sumFlipped);
        }
    }

    int MinCorrectionCost(int nIndex, vector<bool> vecActValues, vector<bool> vecExpValues, bool flipped = false)
    {
        if (vecEdges[])
    }
};

int main()
{
    /*
    7
    3 7
    1 7
    7 4
    3 2
    1 6
    5 1
    1 0 1 1 1 1 0
    0 0 1 0 1 0 1
    */

    vector<pair<int,int>> vecConnections = {{3,7},{1,7},{7,4},{3,2},{1,6},{5,1}};

    vector<bool> vecActValues = {1,0,1,1,1,1,0};
    vector<bool> vecExpValues = {0,0,1,0,1,0,1};

    Solution S1;

    cout << S1.MinCorrections(vecConnections, vecActValues, vecExpValues) << endl;
    S1.PrintTree();

    return 0;
}