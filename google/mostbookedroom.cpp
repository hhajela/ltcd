#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
	public:

	string MostBookedRoom(const vector<string>& vecBookings)
	{
		//store occurrences of all rooms in map
		//keep track of most booked room
		//
		if(vecBookings.empty()) return "";
		
		string mostBooked = vecBookings[0].substr(1,2);
		unordered_map<string,int> mapBookings;

		for(auto & strBooking : vecBookings)
		{
			if (strBooking[0] == '-') continue;

			string booking = strBooking.substr(1,2);

			mapBookings[booking]++;

			if (mapBookings[booking] > mapBookings[mostBooked])
				mostBooked = booking;
			else if (mapBookings[booking] == mapBookings[mostBooked])
			{
				//pick lexicographically smaller

				mostBooked = booking.compare(mostBooked) < 0 ? booking : mostBooked;
			}
		}

		return mostBooked;
	}
};

int main()
{
    vector<string> vecBookings = {"+1A", "+3E", "-1A", "+4F", "+1A", "-3E"};
    Solution S1;
    cout << S1.MostBookedRoom(vecBookings) << endl;
}
