from tkinter import *
import math

win = Tk()
win.geometry("650x400")
win.resizable(0, 0)
win.title("Calculator")

def btn_click(item):
    global expression
    expression = expression + str(item)
    input_text.set(expression)

def bt_clear():
    global expression
    expression = ""
    input_text.set("")

def bt_equal():
    try:
        global expression
        result = str(eval(expression))
        input_text.set(result)
        expression = ""
    except:
        input_text.set("Error")
        expression = ""

def scientific_calculation(func):
    global expression
    try:
        result = func(float(eval(expression)))
        input_text.set(result)
        expression = ""
    except:
        input_text.set("Error")
        expression = ""

expression = ""
input_text = StringVar()

input_frame = Frame(win, width=312, height=50, bd=0, highlightbackground="black", highlightcolor="black", highlightthickness=2)
input_frame.pack(side=TOP)

input_field = Entry(input_frame, font=('arial', 18, 'bold'), textvariable=input_text, width=50, bg="#eee", bd=0, justify=RIGHT)
input_field.grid(row=0, column=0)
input_field.pack(ipady=10)

btns_frame = Frame(win, width=312, height=350, bg="grey")
btns_frame.pack()

# Calculator buttons
buttons = [
    (38,"C", bt_clear, 0, 0, 1, 3),
    (10,"/", lambda: btn_click("/"), 0, 3, 1, 1),
    (10,"7", lambda: btn_click(7), 1, 0, 1, 1),
    (10,"8", lambda: btn_click(8), 1, 1, 1, 1),
    (10,"9", lambda: btn_click(9), 1, 2, 1, 1),
    (10,"*", lambda: btn_click("*"), 1, 3, 1, 1),
    (10,"4", lambda: btn_click(4), 2, 0, 1, 1),
    (10,"5", lambda: btn_click(5), 2, 1, 1, 1),
    (10,"6", lambda: btn_click(6), 2, 2, 1, 1),
    (10,"-", lambda: btn_click("-"), 2, 3, 1, 1),
    (10,"1", lambda: btn_click(1), 3, 0, 1, 1),
    (10,"2", lambda: btn_click(2), 3, 1, 1, 1),
    (10,"3", lambda: btn_click(3), 3, 2, 1, 1),
    (10,"+", lambda: btn_click("+"), 3, 3, 1, 1),
    (10,"0", lambda: btn_click(0), 4, 0, 1, 2),
    (10,".", lambda: btn_click("."), 4, 2, 1, 1),
    (10,"=", bt_equal, 4, 3, 1, 1),
    (10,"sin", lambda: scientific_calculation(math.sin), 0, 4, 1, 1),
    (10,"cos", lambda: scientific_calculation(math.cos), 1, 4, 1, 1),
    (10,"tan", lambda: scientific_calculation(math.tan), 2, 4, 1, 1),
    (10,"√", lambda: scientific_calculation(math.sqrt), 3, 4, 1, 1),
]

# Create calculator buttons
for (width, text, command, row, col, rowspan, columnspan) in buttons:
    btn = Button(btns_frame, text=text, fg="black", width=width, height=3, bd=0, bg="#eee", cursor="hand2", command=command)
    btn.grid(row=row, column=col, rowspan=rowspan, columnspan=columnspan, padx=1)






win.mainloop()
