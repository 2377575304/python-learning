#include <iostream>
#include <thread>

// 输出消息的函数
void printMessage1(const std::string& message) {
    for (int i = 0; i < 5; ++i) {
        std::cout << message << std::endl;
        // 模拟耗时操作
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
}

void printMessage2(const std::string& message) {
    for (int i = 0; i < 5; ++i) {
        std::cout << message << std::endl;
        // 模拟耗时操作
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

int main() {
    // 创建两个线程，分别执行不同的任务
    std::thread t1(printMessage1, "线程 1 正在运行");

    //执行lambda表达式
    std::thread t3([/*cipture 外部捕获的值*/](/*传递的参数*/){
        for(int i =0;i<99;i++){std::cout<<i<<"\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
    std::thread t2(printMessage2, "线程 2 正在运行");

    // 等待线程 t1 执行完毕
    if (t1.joinable()) {
        t1.join();
    }
    // 等待线程 t2 执行完毕
    if (t2.joinable()) {
        t2.join();
    }

    std::cout << "所有线程执行完毕，主线程结束。" << std::endl;

    return 0;
}
