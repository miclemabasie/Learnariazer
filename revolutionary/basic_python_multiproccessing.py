import multiprocessing
from multiprocessing import Process


def print_func(continent="Africa"):
    print("The name of continent is: {}".format(continent))

def multiprocessfunc():
    print("Number of cpu : ", multiprocessing.cpu_count())
    names = ["Asia", "America", "Europe"]
    procs = []
    proc = Process(target=print_func) # instantiating without any arguments
    procs.append(proc)
    proc.start()

    # instantiate process with arguments
    for name in names:
        # print(name)
        proc = Process(target=print_func, args=[name])
        procs.append(proc)
        proc.start()


    # complete the processes
    for proc in procs:
        proc.join()

    print("Done!")

if __name__ == "__main__":
    multiprocessfunc()