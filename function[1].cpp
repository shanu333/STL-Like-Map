#include <iostream>
#include "map.hpp"

using namespace std;

int main()
{
	map<int, int> m1;

	m1.insert(pair<int, int> (2,3));
	m1.insert(pair<int, int> (2,3));
	m1.insert(pair<int, int> (4,4));
	m1.insert(pair<int, int> (5,5));
	m1.insert(pair<int, int> (4,4));
	m1[2] = 4;
	m1[3] = 6;

	map<int, int>::iterator it1;
	map<int, int>::iterator it2;

	cout << "PRINTING BY ITERATOR" << endl;

	for (it1 = m1.begin(); it1 != m1.end(); it1++) {
		cout << (*it1).first << "  " << (*it1).second << endl;
	}

	cout << "PRINTING BY M[] NOTATION" << endl;

	for (int i = 0; i < m1.size(); i++) {
		cout << m1[i] << endl;
	}

	cout << endl;
	cout << m1.size() << " is the size of the map" << endl;

	m1.clear();

	if (m1.empty()) {
		cout << "MAP M1 IS EMPTY" << endl;
	}

	m1[1] = 2;
	m1[2] = 4;
	m1[3] = 6;

	cout << "CALLING COPY CONTRUCTOR" << endl;

	map<int, int> m2(m1);

	for (it2 = m2.begin(); it2 != m2.end(); it2++) {
		cout << (*it2).first << "   " << (*it2).second << endl;
	}
	cout << endl;
	cout << "CALLING COPY ASSIGNMENT" << endl;

	map<int, int> m3;

	m3 = m1;

	for (int i = 0; i < 100 ; i++) {
		if (m3.count(i)) {
			cout << m3[i] << endl;
		}
	}

	cout << endl;

	cout << "CHEKING LOWER BOUND AND UPPER BOUND" << endl;
	map<int, int> m4;
	m4[1] = 2;
	m4[2] = 4;
	m4[3] = 5;
	m4[4] = 6;

	it1 = m4.lower_bound(2);
	it2 = m4.upper_bound(3);
	
	cout << (*it1).first << "  " << (*it2).first << endl;
	pair<map<int, int>::iterator, map<int, int>::iterator> p_it;
	p_it = m4.equal_range(2);

	cout << "DEMONSTRATING EQUAL_RANGE" << endl;

	cout << (*p_it.first).first << "  " << (*p_it.second).first << endl;
	
	map<int, int> m6;
	m6[1] = 3;
	m6[2] = 4;

	map<int, int> m7(m6);
	map<int, int> m8(m6);

	cout << "COMPARING MAPS" << endl;
	if (m1 == m2) {
		cout << "maps are equal" << endl;
	} else {
		cout << "maps are not equal" << endl;
	}
	cout << endl;
	cout << "SWAPPING MAPS" << endl;

	m1.swap(m2);
	cout << endl;


	cout << "USING ERASES" << endl;

	map<int, int> m10;
	m10[1] = 2;
	m10[2] = 4;
	m10[3] = 6;
	m10[4] = 8;
	m10[5] = 10;
	m10[6] = 12;
	m10[7] = 14;
	m10[8] = 16;
	m10[8] = 18;
	int i = 0;
	for (it1 = m10.begin(); it1 != m10.end(); it1++) {
		cout << (*it1).first << "   " << (*it1).second << endl;
		i++;
	}

	cout << "ERASE BY KEY" << endl;
	m10.erase(3);
	i = 0;
	for (it1 = m10.begin(); it1 != m10.end(); it1++) {
		cout << (*it1).first << "   " << (*it1).second << endl;
		i++;
	}
	
	cout << "ERASE BY ITERATOR" << endl;

	map<int, int>::iterator it5;
	it5 = m10.begin();
	it5++;
	it5++;
	m10.erase(it5);
	for (it1 = m10.begin(); it1 != m10.end(); it1++) {
		cout << (*it1).first << "   " << (*it1).second << endl;
		i++;
	}

	map<int, int>::iterator it6 = m10.begin(); 

	
	return 0;
}
