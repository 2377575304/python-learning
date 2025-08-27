#include <iostream>
#include <thread>
#include <mutex>

#include <condition_variable> 
#include <queue>

std::queue<int> task_queue;//任务队列
std::condition_variable cv;

//chcp 65001 临时指定编码为utf-8
std::mutex mtx;

void producer()
{
    for(int i =0;i<10;i++)
{
        std::unique_lock<std::mutex> lock(mtx);
        task_queue.push(i);
        std::cout<<"生产任务："<<i<<std::endl;
        cv.notify_all();//通知所有线程                                                 
    }
}

void consumer()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[&](){return !task_queue.empty();});
        int task = task_queue.front();//获取任务
        task_queue.pop();
        lock.unlock();
        std::cout<<"消费任务："<<task<<std::endl;
    }
}


// 输出消息的函数
void printMessage1(const std::string& message) {
    for (int i = 0; i < 5; ++i) {
        std::cout << message << std::endl;
        // 模拟耗时操作
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

void printhello(int *a)
{   
    
    
    for(int i =0;i<*a;i++)
    {   std::lock_guard<std::mutex> lock(mtx);//构造时自动枷锁
        std::cout<<"hello world"<<a<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    //自动解锁
}

void printMessage2(const std::string& message) {
    for (int i = 0; i < 5; ++i) {
        std::cout << message << std::endl;
        // 模拟耗时操作
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {

    int a = 2;
    int* ptr = &a;
    
    // 创建两个线程，分别执行不同的任务
    std::thread t1(producer);
    std::thread t2(consumer);
//std::thread t2(printMessage2, "线程 2 正在运行");
    //执行lambda表达式
    std::thread t3([/*cipture 外部捕获的值*/](/*传递的参数*/){
        for(int i =0;i<10;i++){std::cout<<i<<"\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
    
    std::thread t4(printhello, ptr);//引用传递
    std::cout<<std::ref(a)<<"\n";   //输出引用地址
    std::cout<<&a<<"\n";            //输出变量地址
    std::cout<<ptr<<"\n";       //输出引用指向的变量值
    std::cout<<a<<"\n";             //输出变量值

    // 等待线程 t1 执行完毕
    if (t1.joinable()) {
        t1.join();
    }
    // 等待线程 t2 执行完毕
    if (t2.joinable()) {
        t2.join();
    }
    // 等待线程 t3 执行完毕
    if (t3.joinable()) {
        t3.join();
    }
     if (t4.joinable()) {
        t4.join();
    }

    std::cout << "所有线程执行完毕，主线程结束。" << std::endl;

    return 0;
}
