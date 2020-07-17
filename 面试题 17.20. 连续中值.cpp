// 面试题 17.20. 连续中值

// 随机产生数字并传递给一个方法。你能否完成这个方法，在每次产生新值时，寻找当前所有值的中间值（中位数）并保存。

// 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

// 例如，

// [2,3,4] 的中位数是 3

// [2,3] 的中位数是 (2 + 3) / 2 = 2.5

// 设计一个支持以下两种操作的数据结构：

// void addNum(int num) - 从数据流中添加一个整数到数据结构中。
// double findMedian() - 返回目前所有元素的中位数。
// 示例：

// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2


class MedianFinder {
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<>> right;

    void resize() {
        if(left.size() >= right.size()+2) {
            right.push(left.top());
            left.pop();
        }else if(right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

public:
    /** initialize your data structure here. */
    MedianFinder() {
        left.push(INT_MIN);
        right.push(INT_MAX);
    }
    
    void addNum(int num) {
        int lmax = left.top(), rmin = right.top();
        if(num <= lmax) {
            left.push(num);
        }else {
            right.push(num);
        }
        resize();
    }
    
    double findMedian() {
        if(left.size() == right.size()) {
            int lmax = left.top(), rmin = right.top();
            double res = lmax + rmin;
            return res / 2;
        }
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */