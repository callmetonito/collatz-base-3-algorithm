# Base 3 (ternary) Algorithm for the Collatz conjecture

The modified **Collatz function**

$$ f(n) = \begin{cases}
\frac{n}{2} & \text{if n even}\\
\frac{3n + 1}{2} & \text{if n odd} 
\end{cases} $$


The **Collatz conjecture** states that for any n, by applying $f(n)$. enough times we eventually reach 1. Applying it for an even number we call it an even step, and for an odd number an odd step.  

Base 3 or ternary presents an integer as a number sequence and could only consist of the digits 0,1, and 2. Numerical parity of such an integer is determined by number of digits 1 in a number sequence – even number of 1s (including case when there are no 1s) means the sequence presents an even number, and odd number of 1s means an odd number. 

**Algorithm** does not need to check parity and count 1s to provide even or odd steps. What it does is division by 2. Thus, the divisor is 2 and the possible remainders at any digit are 0 and 1. These remainders define the state of operation. The initial state is 0, assuming no initial remainder. Algorithm is processing digits from Most Significant Digit (leftmost) to rightmost till it passes the rightmost digit, does an output and sets the state of operation. And after the rightmost digit of the sequence is processed and if the last state of operation is set 1, assuming reminder is 1, then Algorithm append 2 (as a digit) to the right side of that sequence. Considering it as result of an odd step.  


## Algorithm

For input digits\
Set operation = 0\
**If** operation = 0 then\
**If** digit 0 output 0 set operation 0\
**Elseif** digit 1 output 0 set operation 1\
**Elseif** digit 2 output 1 set operation 0\
**Else** (operation = 1) then\
**If** digit 0 output 1 set operation 1\
**Elseif** digit 1 output 2 set operation 0\
**Elseif** digit 2 output 2 set operation 1\
**Until** no input digit and if operation 1 then output 2

## Operation state and output Table


| Input digit | Operation   |Output digit| Next Operation  |
|  ---------- | ----------- |----------- |---------------- |
| 0           | 0           |  0         |  0              |
| 1           | 0           |  0         |  1              |
| 2           | 0           |  1         |  0              |
| 0           | 1           |  1         |  1              |
| 1           | 1           |  2         |  0              |
| 2           | 1           |  2         |  1              |

As you can notice operation state is changed only when input is digit 1.\
For the rightmost digit of the sequence the state of next operation is also set nevertheless it is the last digit of the sequence to proceed. 

As the code uses an algorithm in a cycle it won’t stop and the result would be a new sequence of digits which starts processing and so on while break condition occurs.

As a number sequence could start with 1 or 2 and could not start with 0. Code eliminates leading zero which appears when a number sequence starts with 1 and algorithm within operation 0 outputs 0.  

The input number sequence is step 0 because $f^0(n)=n$. The code counts number of steps, so after first sequence is finally processed the next step is step 1 and so on.

When algorithm step by step comes to 1 (as a result) it enters 1–2 loop (*trivial cycle*), so code breaks if result is 1. 

The reason why Algorithm **adds digit 2** as an odd step instead of 1 (as well-known Collatz sequence odd step is $3n + 1$ ) 
when the last state operation is set to 1 is the following:\
Consider odd step on numbers of the form $2n + 1$

$$ \frac{3(2n+1) + 1}{2} = 3n +2 $$

For more obvious way to show idea of <ins>appending 2</ins>, Collatz function could be modified as

$$ T(n) = \begin{cases} 
\frac{n}{2} & \text{if n even}\\
\frac{(n – 1)}{2} 3 + 2 & \text{if n odd} 
\end{cases} $$

Result for odd step on numbers of the form $2n + 1$ equals to $3 \frac{(2n + 1) – 1}{2} + 2 = 3n +2$

To demonstrate how this algorithm works I share code and some exe files.




