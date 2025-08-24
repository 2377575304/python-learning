#
#自动化刷抖音
#
import threading
import time
import pyautogui
import keyboard

# 全局变量用于线程间通信
running = True
stop_event = threading.Event()

class AutoClickThread(threading.Thread):
    def __init__(self):
        super().__init__()
        self.daemon = True  # 设置为守护线程
        
    def run(self):
        print("自动化线程启动")
        while not stop_event.is_set():
            pyautogui.press("s")
            print("按下了 S 键")
            time.sleep(5)
        print("自动化线程停止")

class MonitorThread(threading.Thread):
    def __init__(self):
        super().__init__()
        self.daemon = True
        
    def run(self):
        print("监控线程启动")
        while not stop_event.is_set():
            if keyboard.is_pressed('esc'):
                print("检测到ESC键，准备停止所有线程")
                stop_event.set()  # 设置停止事件
                break
            time.sleep(0.1)  # 每100ms检查一次
        print("监控线程停止")

def main():
    print("=== 多线程自动化程序 ===")
    print("按 ESC 键退出程序")
    
    # 创建线程实例
    auto_thread = AutoClickThread()
    monitor_thread = MonitorThread()
    
    # 启动线程
    auto_thread.start()
    monitor_thread.start()
    
    # 主线程等待
    try:
        while running:
            if stop_event.is_set():
                break
            time.sleep(0.1)
    except KeyboardInterrupt:
        print("\n主线程被中断")
        stop_event.set()
    
    # 等待所有线程结束
    auto_thread.join(timeout=1)
    monitor_thread.join(timeout=1)
    
    print("程序已退出")

if __name__ == '__main__':
    main()