# Spec

See https://db4.us/cmpe279/project3.html

CMPE 279 Project 3: Salted Password Signup Implementation (5%)


Due: Nov 30, 2026 11:59pm by email, to bhavpreet.judge@sjsu.edu and michael.lam01@sjsu.edu

Given an unfinished blog application:

https://db4.us/cmpe279/blogapp279.tar

download it, extract it, and try it out.

tar xvf blogapp279.tar

and the result will be in a directory named blogapp279:

$ ls -l blogapp279  
total 32
-rw-r--r--  1 shungkai.lam  staff    51 Nov  7 15:18 blog.txt  
-rw-r--r--  1 shungkai.lam  staff  4207 Nov  7 15:17 blogapp.py  
-rw-r--r--  1 shungkai.lam  staff    11 Nov  7 15:34 passwd.txt  
drwxr-xr-x  2 shungkai.lam  staff    64 Nov  7 15:21 static  
drwxr-xr-x  4 shungkai.lam  staff   128 Nov  7 15:20 templates  

$ cd blogapp279  
$ python blogapp.py

Upon trying out the blog app, you will notice that only hardcoded accounts admin and guest work.

From the login page, there is signup link that is not fully implemented.

At this point, the signup code will read the following fields from the signup form:

username (an email)  
password  
password again to confirm the first password entry.

The signup code now writes 2 lines to the file passwd.txt per user signup:

username  
password

Storing plain passwords in a file is not secure because when a hacker has stolen the password file,
all user passwords are exposed.

One line of defense is to store the passwords in one way hashes, such that hackers cannot reverse
the hashes back to the passwords.

But the hackers can still take a brute force approach, such as trying out a common set of passwords
from a dictionary to generate many hashes and see if the stolen password file set has any matches.

To improve the password security further, a technique called salting is used.

Basically, a random string (salt) is appended to the user created password to make the result
highly unlikely to be a common string such as ones from the dictionary.


https://www.geeksforgeeks.org/techtips/what-is-password-salting/


To implement salted passwords, try out the following code:


https://db4.us/cmpe279/DemoSalt.py

and integrate the following 2 functions into the blog application:

def hash_password_pbkdf2(plain_text_password: str)

def verify_password_pbkdf2(plain_text_password: str, stored_salt: bytes, stored_hash: bytes) -> bool:

Using salt, you will need to store 3 lines per user in the file passwd.txt:

user (email)  
salt  
hashed_password

After implementing the salted passwords in signup_action, you will need to enhance the login_action
code so it will read the file passwd.txt to enable users login.

You will need to read for an user line that matches the login user, then verify the login password by
calling verify_password_pbkdf2() passing in 3 parameters:

1. the entered login password
2. the salt from passwd.txt
3. the hashed password from passwd.txt

The call of

hashlib.pbkdf2_hmac( 'sha256', login_password.encode('utf-8'), salt_from_passwd.txt, 600000)

should yield a hash that matches the hashed password from passwd.txt .

Submission instruction:

Create a tarball by:

tar cvf ./blogapp279.tar ./blogapp279

where ./blogapp279 is the same directory that you started with, plus your salt password implementation
enhancement.

***Send one single email with 1 attachment (the tarball blogapp279.tar) to:
bhavpreet.judge@sjsu.edu and michael.lam01@sjsu.edu

Email subject should have: CMPE 279 project3 solution from 
