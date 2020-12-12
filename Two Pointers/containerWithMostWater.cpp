#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
    public:
    int containerWithMostWater(vector<int> A)
    {
        int i, j;
        int start, end, area, max;
        start = 0;
        end = A.size()-1;
        vector<int> coordinates;
        for(i = 0; i < A.size(); i++)
            coordinates.push_back(A[i]);
        sort(coordinates.begin(), coordinates.end());

        area = coordinates[0]*(A.size()-1);
        max = area;
        for(i = 1; i < coordinates.size(); i++)
        {
            // coordinates[i];
            for(j = start; j <= end; j++)
                if(A[j] >= coordinates[i])
                    break;
            start = j;
            for(j = end; j >= start; j--)
                if(A[j] >= coordinates[i])
                    break;
            end = j;
            area = (end-start)*coordinates[i];
            // cout << "Start: " << start << "\n";
            // cout << "End: " << end << "\n";
            // cout << "Height: " << coordinates[i] << "\n";
            // cout << "Area: " << area << "\n\n";
            if(max < area)
                max = area;
        }
        return max;
    }
};

int main()
{
    vector<int> A{1,5,4,3};
    Solution* s = new Solution();
    int size = s->containerWithMostWater(A);
    cout << "Max Area: " << size;
}