### Features

- Interpret Monty .98 bytecode files (.m)
- Compatible with Ubuntu 16.04 LTS
- Support identification, interpretation, execution of monty bytecode files (.m)
####Contributors:
			Carter Clements: github.com/javaPhish
			Andrew Graf: github.com/humeinstein
#Monty Interpreter
####Operations:
		

![](https://img.shields.io/badge/release-V%3A1.01-orange) ![](https://img.shields.io/badge/holberton%20approved-pending-yellow)


###FlowChart
```flow
st=>start: ./file file.m
op=>operation: Contains Monty bytecode
cond=>condition: Successful Yes: Run Code
e=>end: print to STDOUT

st->op->cond
cond(yes)->e
cond(no)->op
```
