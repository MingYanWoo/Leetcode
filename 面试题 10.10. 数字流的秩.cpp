// 面试题 10.10. 数字流的秩

// 假设你正在读取一串整数。每隔一段时间，你希望能找出数字 x 的秩(小于或等于 x 的值的个数)。请实现数据结构和算法来支持这些操作，也就是说：

// 实现 track(int x) 方法，每读入一个数字都会调用该方法；

// 实现 getRankOfNumber(int x) 方法，返回小于或等于 x 的值的个数。

// 注意：本题相对原题稍作改动

// 示例:

// 输入:
// ["StreamRank", "getRankOfNumber", "track", "getRankOfNumber"]
// [[], [1], [0], [0]]
// 输出:
// [null,0,null,1]
// 提示：

// x <= 50000
// track 和 getRankOfNumber 方法的调用次数均不超过 2000 次



class StreamRank {
public:
    int data[50001];
    StreamRank() {
        for(int i = 0; i < 50001; i++) {
            data[i] = 0;
        }
    }
    
    void track(int x) {
        data[x]++;
    }
    
    int getRankOfNumber(int x) {
        int sum = 0;
        for(int i = 0; i <= x; i++) {
            sum += data[i];
        }
        return sum;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */