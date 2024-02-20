#cyberSecurity 
# To anticipate attackers, we must think like attackers

___
## Examples of Security Issues:
* Someone was able to retrieve their car after service just by giving the attendant her last name
	* This allows someone to get a free car just by knowing the last name of someone who has placed their car into the garage
* Someone steals your Chipotle order that you placed online
* Wearing a yellow vest to a park and getting into the park for free
---
## How this Applies to Computer Security
Attackers will be malicious and will try to find bugs and flaws in order to exploit them
### There is no such thing as security, just degrees of insecurity
Make it not worth the attacker's time
### Undesired Behaviors
* Reveals information users want to hide
	* File [[Metadata]] not being cleared

> [!NOTE]
> Metadata can reveal information about when, who, and where the file was made

* Modified information or functionality
* Denies access to a service
# Thinking Like a Defender
Remember these core things:
* Assume the adversary knows everything
* Plan for attacks
* Security is not free but it is essential
Security unaware users have specific security requirements but usually no security expertise. With this in mind, you also have to think of usability vs security. 
## Annual Loss Expectancy (ALE)
How much a vulnerability will cost us.

Defined by the annual rate of occurrence * Single Loss Expectancy. Once this is calculated, it can be impacted by defense costs.  

___
For example, a DDoS attack would cost $10k per incident, and we expect 2 attacks per year. The ALE = $20k. 
* Defense X costs $1k/year and reduces the cost of each incident to $5k. 
* Defense Y costs $19k/year and reduces the likelihood of an attack to once every 10 years.
**Defense X is the best option when you math it out.**
___
## Fuzzing
Using a program to generate input that could potentially reveal vulnerabilities within code.
	Fuzzing can produce millions of test cases
	While fuzzing is powerful, it doesn't always account for everything.

| Mutation-Based (Dumb) fuzzing | Add anomalies to existing good inputs |
| ---- | ---- |
| Generative (Smart) fuzzing | Generate inputs from specification of |
| Evolutionary fuzzing | ??? |
## Vulnerability Marketplace
### Bug Bounty Programs
Companies like google will pay out to whoever discovers a vulnerability within their system. Google has given out $31k to people who have found vulnerabilities.

### Zerodium
Acquiring zero-day exploits
* This usually means selling information back to customers like government agencies and private organizations.
### Black Market
Bad juju, don't be evil

# Software Security
## [[Buffer Overflow]] #attack
![[171px-Stack_Overflow_2.png]]

### Stack Frame Layout 101 (in a 32-bit machine)
#### Functions
* Assigns to each element of X exactly one element of Y.
* A group of statements that together perform a task.
* Every C program has at least one function, which is main().
Functions will normally have a name, arguments, local variables, return address, and a return value.

#### Memory Layout
All programs are stored in memory. 
Sometimes when a program needs additional memory, it uses virtual memory (VRAM)
* Addresses mapped to memory are almost always mapped as virtual addresses, not physical
	* Stuff like 0xffffffff is probably a virtual address

##### How it looks
Here is a representation of memory:

| Stack |
| ---- |
| Heap |
| BSS |
| Data |
| Text |
	The stack and heap are dynamically sized at runtime, and data and text are known at compile time.
	The heap expands upward, and the stack expands downward.
	The top is 0xffffffff, and the bottom is 0x00000000 (in a 32 bit machine). This chunk of memory is 4 GB.
##### Adding Variables and Arguments from a Function
Arguments are pushed to the stack in ***reverse order***. For example:
```c
int makeChicken(int numChickens, bool isDelicious, bool isBurnt)
```
isBurnt gets pushed first, isDelicous is next, and then numChickens is last. These end up at the top of the stack near 0xffffffff

Local variables are pushed in the ***same order*** as they appear in the code. These are pushed near the bottom at 0x00000000. 

Here is what the stack may look like after pushing everything from a function:

| 0xffffffff | Extra stuff from top of Stack |
| ---- | ---- |
|  | Caller's data |
|  | arg3 |
|  | arg2 |
|  | arg1 |
|  | ??? unknown stuff |
|  | ??? unknown stuff |
|  | char local1[4] |
|  | int local2 |
|  | int local3 |
| 0x00000000 | extra stuff from bottom of stack |
What is inside the "???"
* The Return Address is the first (return $eip)
* The Previous Frame Pointer is the second (prev. $ebp)
### Consequences
Overwriting the return address with random addresses can point to
* An invalid instruction
* Non-existing address
* Access violation
* Attacker's code
#### Shell Code
* Generic name used for "adversarial machine instructions"
* Most common form was code that ran exec("/bin/sh");
* Opening step in building is to write a short program that does what you want
* Dump the machine code
So we know what the shell code does, but where do we find it in memory so we can overwrite the return address there?
* NOP (no op)
	* NOP instructions do nothing
* To increase the chances of jumping to the correct address, we fill the buffer with NOP instructions and place the malicious code at the end of the buffer.