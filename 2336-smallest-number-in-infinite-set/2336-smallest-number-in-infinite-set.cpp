#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class SmallestInfiniteSet {
public:
    int currentSmallest = 1;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;

    SmallestInfiniteSet() {}

    int popSmallest() {
        if (!pq.empty()) {
            int n = pq.top();
            pq.pop();
            st.erase(n);
            return n;
        } else {
            return currentSmallest++;
        }
    }

    void addBack(int num) {
        if (st.find(num) == st.end() && num < currentSmallest) {
            pq.push(num);
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
