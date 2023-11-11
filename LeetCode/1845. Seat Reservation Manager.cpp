#include <vector>
#include <set>

class SeatManager
{
public:
	SeatManager(int n)
		: _seat(1), _maxSeat(n + 1)
	{

	}

	int reserve()
	{
		if (!_remainSeat.empty())
		{
			int seat = *_remainSeat.begin();
			_remainSeat.erase(_remainSeat.begin());
			return seat;
		}
		else 
		{
			return _seat++;
		}
	}

	void unreserve(int seatNumber)
	{
		_remainSeat.insert(seatNumber);
	}

private:
	int _seat;
	int _maxSeat;
	std::set<int> _remainSeat;
};