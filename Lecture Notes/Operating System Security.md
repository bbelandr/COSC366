# The Operating System
The operating system is a layer of software to provide access to Hardware. The operating system provides:
* **Abstraction** of complex hardware
	* Programs do not need to know exact hardware and how the hardware operates
* **Protected Access** to shared resources
* **Communication**
* **Security**
Examples of Operating Systems:
* Windows
	* Windows 3.1 (1992)
		* If a program crashed, the entire OS may crash as well
			* The blue screen of death could happen (BSOD)
		* Many parts of memory are shared between programs
	* Windows 95
		* Unique memory addresses for different programs
		* If a program crashed, the entire OS may crash as well
	* Windows XP
		* Finally a program crash wouldn't crash the whole system
### Protecting Storage
##### Permissions
Some times, you have multiple users on the same machine. The operating system protects files from the different users through **file permissions.**
* File owner
* File group owner
* Everyone else
Most permissions are formatted like this: 
```
rwxr-xr-x
111101101
7  5  5  
```
In this case, the permissions are turned into 755 as a number in octal. This means:
* The owner can read, write, and execute
* The group can read and execute
* Everyone else can read and execute
##### User IDs
Users must be distinguished between one another. To do this, the operating system distributes a user ID, or a UID.
There is one special user called the *root*. The root has access to everything within the system. Windows has similar concepts with Admin and System accounts. The UID of root is typically 0.

**Where are these things stored?**
Here is where everything is on a UNIX system:
* UIDs are stored in /etc/passwd
* Passwords are stored in /etc/shadow and is readable only by root and are encrypted.
### The Big Question
How do you change a password without having to request root privileges by using sudo?
