#auther:xiao
#date:2023-08-10
#version:1.0
#description:自动点击s键(自动刷抖音)
import pyautogui
import time
import keyboard 
import threading

#running = True
#stop_event = threading.Event()



def main():
    # get_position()  ss
    print("press esc to exits")
    while True:
        pyautogui.press("s") 
        time.sleep(5)
        if keyboard.is_pressed('esc'):  
             break

def get_position():
    while True:
        x, y = pyautogui.position()
        print(x, y)
        time.sleep(0.5)    


if __name__ == '__main__':
    main()