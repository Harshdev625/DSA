#include <bits/stdc++.h>
using namespace std;

class DisjointIntervals 
{
    set<int> s;
public:
    DisjointIntervals()
    {
        // Intialise your data structure here.
    }
    
    void addInteger(int val) 
    {   
        // Add the integer to the stream.
        s.insert(val);
    }

    vector<vector<int>> getDisjointIntervals() 
    {
        // Return the disjoint intervals.
        vector<vector<int>> v;

        if (!s.size()) return v;

        int start = *s.begin();
        int finish = start;

        for (auto i = next(s.begin()); i != s.end(); ++i) {
            if (*i == finish + 1) {
                finish += 1;
            }
            else {
                vector<int> a;
                a.push_back(start);
                a.push_back(finish);
                v.push_back(a);
                start = *i;
                finish = start;
            }
        }

        vector<int> a;
        a.push_back(start);
        a.push_back(finish);
        v.push_back(a);

        return v;
    }
};
