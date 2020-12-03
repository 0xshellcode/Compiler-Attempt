from pwn import *
import time
import colorama

colorama.init()

inputs  =  [ "if a then b;", "while a5 = 8 do if a = 9 then c = 4;", "if x > 9 then y = 13;", "if y > 943 then x = 20;", "begin while a5 = 8 do if a = 9 then c = 4; end;"]
testingStatus = log.progress("Progress")
inputsStatus = log.progress("Inputs")

testingStatus.status("\033[32mShowing Inputs\033[0m")

for i in range(len(inputs)):
    inputsStatus.status(f"\033[32m{inputs[i]}\033[0m")
    time.sleep(2.5)


testingStatus.status("\033[32mParsing Inputs to Compiler\033[0m")
time.sleep(2.5)
testingStatus.status("\033[32mExecuting Compiler \033[0m")
time.sleep(2.5)
target = process("./Compiler")
for i in range(len(inputs)):
    target.send(inputs[i])
target.interactive()
