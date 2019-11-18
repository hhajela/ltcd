#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
    
    string MostBookedRoom(vector<string> vecBookings)
    {
        //keep track of bookings of each room
        //return max booked room
        unordered_map<string,int> mapBookings;
        
        
        string maxBookedRoom = vecBookings[0].substr(1,2);
        
        for(string & booking : vecBookings)
        {
            if (booking[0] == '-')
                continue;
            
            mapBookings[booking.substr(1,2)]++;
            
            if (mapBookings[booking.substr(1,2)] > mapBookings[maxBookedRoom])
            {
                //update most booked room
                maxBookedRoom = booking.substr(1,2);
            }
            else if (mapBookings[booking.substr(1,2)] == mapBookings[maxBookedRoom])
            {
                //pick lexicographically greater one
                maxBookedRoom = maxBookedRoom.compare(booking.substr(1,2)) < 0 ? maxBookedRoom :booking.substr(1,2);
            }
        }
        
        return maxBookedRoom;
    }
    
};

int main()
{
    vector<string> vecBookings = {"+1A", "+3E", "-1A", "+4F", "+1A", "-3E"};
    Solution S1;
    cout << S1.MostBookedRoom(vecBookings);
}
