// 面试题 03.02. 栈的最小值

// 请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。


// 示例：

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.



class MinStack {
public:
    /** initialize your data structure here. */
    std::stack<int> stack;
    std::stack<int> helper;
    MinStack() {

    }
    
    void push(int x) {
        stack.push(x);
        if(!helper.empty()) {
            if(x  < helper.top()) {
                helper.push(x);
            }else {
                helper.push(helper.top());
            }
        }else {
            helper.push(x);
        }
    }
    
    void pop() {
        stack.pop();
        helper.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */