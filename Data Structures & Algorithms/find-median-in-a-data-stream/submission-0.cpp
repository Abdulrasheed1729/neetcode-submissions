class MedianFinder {
   private:
    priority_queue<int, vector<int>, std::greater<int>> large;  // a min heap
    priority_queue<int> small;                                  // a max heap
   public:
    MedianFinder() {}

    void addNum(int num) {
        // push to the max heap
        small.push(num);

        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            auto v = small.top();
            large.push(v);
            small.pop();
        }

        if (small.size() > large.size() + 1) {
            auto v = small.top();
            large.push(v);
            small.pop();
        }

        if (large.size() > small.size() + 1) {
            auto v = large.top();
            small.push(v);
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        } else if (large.size() > small.size()) {
            return large.top();
        }

        return (static_cast<double>(small.top()) + static_cast<double>(large.top())) / 2;
    }
};
