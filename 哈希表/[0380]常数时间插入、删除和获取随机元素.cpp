#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<map>
#include<ctime>

using namespace std;


class RandomizedSet 
{
private:
	unordered_map<int, int> NumMapCode;
	unordered_map<int, int> CodeMapNum;
	int size;
public:
	/** Initialize your data structure here. */
	RandomizedSet() 
	{
		this->size = 0;
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) 
	{
		if (NumMapCode.count(val) == 0)
		{
			NumMapCode.insert({ val,size });
			CodeMapNum.insert({ size,val });
			size++;
			return true;
		}
		else return false;

	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) 
	{
		if (NumMapCode.count(val) > 0)
		{
			int code = NumMapCode[val];
			if (code < size - 1)
			{
				CodeMapNum[code] = CodeMapNum[size - 1];
				int num = CodeMapNum[size - 1];
				NumMapCode[num] = code;
			}
			CodeMapNum.erase(size - 1);
			NumMapCode.erase(val);
			size--;
			return true;
		}
		else return false;
	}

	/** Get a random element from the set. */
	int getRandom() 
	{
		int code = rand() % size;
		return CodeMapNum[code];
	}
};