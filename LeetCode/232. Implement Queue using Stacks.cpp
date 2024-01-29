#include <stack>

class MyQueue
{
public:
	MyQueue()
	{

	}

	void push(int x)
	{
		_in.push(x);
	}

	int pop()
	{
		InternalSort();

		auto ret = _out.top();
		_out.pop();
		return ret;
	}

	int peek()
	{
		InternalSort();

		return _out.top();
	}

	bool empty()
	{
		return _in.empty() && _out.empty();
	}

private:
	void InternalSort()
	{
		if (_out.empty())
		{
			while (!_in.empty())
			{
				_out.push(_in.top());
				_in.pop();
			}
		}
	}

private:
	std::stack<int> _in;
	std::stack<int> _out;
};
