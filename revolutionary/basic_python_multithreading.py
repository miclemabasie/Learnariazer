from time import time
import threading
from threading import Thread
from time import sleep
print("The program is live")

def fun1_thread():
    print("function is woking")
    for i in range(10):
        sleep(2)
        print(f"First Thread: {str(i)}")

def fun2_thread():
    for i in range(10):
        sleep(2)
        print(f"Second Thread: {str(i)}")


def main_func():
    start = time()
    # fun1_thread()
    # fun2_thread()
    thread1 = Thread(target= fun1_thread)
    thread2 = Thread(target= fun2_thread)
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()
    end = time()
    print(f"Function took {end - start} time to complete")


if __name__ == "__main__": 
    main_func()