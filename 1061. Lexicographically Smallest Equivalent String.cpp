#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findParent(int node, vector<int>&parent)
    {
        int curr = node;
        while(parent[curr] != curr) curr = parent[curr];
        return curr;
    }
    void merge(int node1, int node2, vector<int>&parent)
    {
        int parent1 = findParent(node1, parent);
        int parent2 = findParent(node2, parent);
        if (parent1 == parent2) return;
        
        int minParent = min(parent1, parent2);
        int maxParent = max(parent1, parent2);
        parent[maxParent] = minParent;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<int>parent(26);
        for (int i = 0; i < 26; i++) parent[i] = i;
        for (int i = 0; i < n; i++) merge(s1[i] - 'a', s2[i] - 'a', parent);
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) 
        {
            int minParentIdx = findParent(baseStr[i] - 'a', parent);
            char minParent = minParentIdx + 'a';
            ans.push_back(minParent);
        }
        return ans;
    }
};