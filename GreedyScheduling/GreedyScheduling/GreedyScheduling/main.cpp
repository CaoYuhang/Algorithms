#include <list>
#include <iostream>
#include <fstream>


using namespace std;


struct Work
{
	int weight;
	int length;
	Work(int w, int l):weight(w), length(l){};
};


bool operator < (const Work A, const Work B)
{
	if(((float)A.weight / A.length) == ((float)B.weight / B.length))
		return A.weight > B.weight;
	else
		return ((float)A.weight / A.length) > ((float)B.weight / B.length);

}


int main()
{
	ifstream file("data.txt");
	int tmp;
	file >> tmp;
	list<Work> worklist;
	int weight;
	int length;
	while(!file.eof())
	{
		file >> weight;
		file >> length;
		Work tmp_work(weight, length);
		worklist.push_back(tmp_work);
	}
	worklist.sort();
	long long sum = 0;
	long long finish_time = 0;
	for(list<Work>::iterator iter = worklist.begin(); iter != worklist.end(); iter++)
	{
		finish_time += iter->length;
		sum += iter->weight * finish_time;
	}
	cout << "Total weighted finish time: " << sum;
	
	return 0;
}
