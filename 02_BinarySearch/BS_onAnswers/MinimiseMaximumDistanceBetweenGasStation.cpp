#include<iostream>
#include<vector>

using namespace std;

class Solution{
  
  public:
  int gap(vector<int> &stations)
  {
    int maxgap = 0;
    for(int i = 1;i<stations.size();i++)
    {
      int gap = stations[i] - stations[i-1];

      maxgap = max(maxgap,gap);
    }
    return maxgap;
  }

  int nofStations(vector<int> &stations, float mid)
  {
    int count = 0;
    for(int i=1 ;i<stations.size();i++)
    {
      int gap = stations[i] - stations[i-1];
      count += int(gap / mid);
    }
    return count;
  }

  float station(vector<int> &stations, int k)
  {
    float low = 0.0;
    float high = gap(stations);

    while (high - low > 1e-6)  // Precision threshold
    {
      float mid = (low + high)/2.0;

      int count = 0;
      
      count = nofStations(stations, mid);

      if(count > k) low = mid;
      else high = mid;
    }

    return high;
  }
};


int main()
{
  Solution solution;
  vector<int> stations = {0,10,30,60};
  int k = 3;

  float result = solution.station(stations, k);
  cout << "Minimum maximum distance: " << result << endl;

  return 0;
}