// LEETCODE -> Flatten Nested List Iterator
/*
    class NestedInteger {
       public:
        // Return true if this NestedInteger holds a single integer, rather than a nested list.
        bool isInteger() const;

        // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
        int getInteger() const;

        // Return the nested list that this NestedInteger holds, if it holds a nested list
        // The result is undefined if this NestedInteger holds a single integer
        const vector<NestedInteger> &getList() const;
    };
*/
/*
    #include <bits/stdc++.h>
    using namespace std;
    class NestedIterator {
        vector<int> flattenedList;
        int index;
    public:
        NestedIterator(vector<NestedInteger> &nestedList) {
            flattenUtility(nestedList);
            index = 0;
        }
        void flattenUtility(vector<NestedInteger> &nestedList){
            for(auto itr : nestedList){
                if(itr.isInteger())
                    flattenedList.push_back(itr.getInteger());
                else flattenUtility(itr.getList());
            }
        }    
        int next() {
            return flattenedList[index++];           
        }
        bool hasNext() {
            return index != flattenedList.size();
        }
    };
*/