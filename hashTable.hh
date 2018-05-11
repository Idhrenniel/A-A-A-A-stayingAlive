#ifndef _HASHTABLE_HH
#define _HASHTABLE_HH

class hashTable {
	private:
		int size;
		vector<int> table;

	public:
		hashTable(size);
		
		void addElement(int elem);
		bool findElement(int elem);
		void output();
};

#endif