#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>

using namespace std;

long maxPoints(vector<int> elements){
        long maxPoints = 0;
        
        set<int> uniqElements;
        unordered_map<int, size_t> countElements;
        
        unordered_map<int, size_t> pointsElements;
        size_t tmax = 0;
        int tmaxElement = 0;
        
        for(auto i: elements)
        {
                uniqElements.insert(i);
                countElements[i]++;
        }

        cout<<"\nUnique: "<<uniqElements.size();
        for(auto i: uniqElements)
            cout<<"\t"<<i;
        cout<<endl;

        while(!uniqElements.empty())
        {
                for(auto i: uniqElements)
                {
                        pointsElements[i] = i*countElements[i];
                        if( uniqElements.find(i-1) != uniqElements.end() )
                        {
                                pointsElements[i] -= (i-1) * countElements[i-1];
                        }
                        if( uniqElements.find(i+1) != uniqElements.end() )
                        {
                                pointsElements[i] -= (i+1) * countElements[i+1];
                        }
                }

                tmaxElement = *uniqElements.begin();
                tmax = pointsElements[ tmaxElement ];
                for(auto i: uniqElements)
                {
                        if( pointsElements[i] > tmax )
                        {
                                tmax = pointsElements[i];
                                tmaxElement = i;
                        }
                }
                
                maxPoints += tmaxElement* countElements[tmaxElement];
                uniqElements.erase(tmaxElement);
        }
        return maxPoints;
}

int main()
{
    vector<int> myArray = {3, 3, 4, 2};

    // cout<<"\nUnique: "<<myArray.size();
    // for(auto i: myArray)
    //     cout<<"\t"<<i;
    // cout<<endl;

    long maxPoint = maxPoints(myArray);

    cout<<maxPoint<<endl;

}