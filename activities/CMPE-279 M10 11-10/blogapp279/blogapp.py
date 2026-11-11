from flask import Flask, render_template, request, redirect, url_for, session, make_response
from pathlib import Path
import time

app = Flask(__name__)
app.secret_key = "your_secret_key"
app.config['SESSION_COOKIE_SAMESITE'] = 'Strict'
app.config['SESSION_COOKIE_SECURE'] = False  # Set to True only in production with HTTPS
#app.config.update(
#    SESSION_COOKIE_SAMESITE='None',
#    SESSION_COOKIE_SECURE=False,  # Mandatory when SameSite='None'
#    SESSION_COOKIE_HTTPONLY=True
#)
@app.route("/")
def hello_world():
    return redirect(url_for("login"))

@app.route("/signup")
def signup():
    return render_template("signup.html")

@app.route("/signup_action",methods = ["POST","GET"])
#
# This method needs to be enhanced...
#
def signup_action():
    if request.method == "POST":
        username = request.form["email"]
        password = request.form["password"]
        password2 = request.form["password2"]
        # Dummy user validation
        if (username != "admin" and username != "guest" and password == password2):
            passwdfile = open("passwd.txt", "a")  # append mode
            passwdfile.write(username+"\n")
            passwdfile.write(password+"\n")
            passwdfile.close()

    return render_template("login.html")

# main driver function
@app.route("/login")
def login():
    if len(session) == 0:
        return render_template("login.html")
    else:
        return redirect(url_for("homepage"))

@app.route("/login_action",methods = ["POST","GET"])
def login_action():
    if request.method == "POST":
        username = request.form["username"]
        password = request.form["password"]
        print("username="+username)
        # Dummy user validation
        if (username == "admin" or username == "guest") and password == "password":
            session["username"] = username
            print("before redirect to homepage username="+session["username"])
            #session.modified = True
            #time.sleep(1)
            return redirect(url_for("homepage"))

    return render_template("login.html")

@app.route("/homepage_action",methods = ["POST","GET"])
def homepage_action():
    if request.method == "POST":
        inputtext = session["username"] + ":" + request.form["inputtext"]
        if inputtext == "":
            return homepage()
        print(inputtext)
# To append a line (of message) named inputtext to a file named blog.txt:
        blogfile = open("blog.txt", "a")  # append mode
        blogfile.write(inputtext+"\n")
        blogfile.close()
    return redirect(url_for("homepage"))

@app.route("/homepage")
def homepage():
    if len(session) == 0:
      return render_template("login.html")
    print("after redirect to homepage username="+session["username"])
    webpage = '''
    <html>
    <head>
    <title>Home</title>
    </head>
    <body>
    <p style='text-align:left;'>
    <h1>Welcome to the CMPE 279 blog 
    <span style='float:right;'>
    Username:
    ''' + session["username"] + " <a href='" + url_for("logout") + "'>Logout</a></h1></span></p>"

    webpage += '''
    <form action = 'homepage_action' method = 'post'>
    Enter your message here:
    <br>
    <textarea id='inputtext' name='inputtext' rows='2' cols='100'></textarea>
    <br>
    <input type = 'submit' value = 'Submit' />
    <br>
    '''   

# To read from a file named blog.txt:
    blog = ""
    file_path = Path("blog.txt")
    if file_path.is_file():
      print("The file blog.txt exists.")
      with open("blog.txt", "r") as blogfile:
        blog = blogfile.read().rstrip()
      blogfile.close()

# To split all the lines (messages) of the blog file into multiple lines in bloglist:
    bloglist = blog.split("\n")

# To render as many textareas as there are messages from the blog
    for i in range(len(bloglist)-1,-1,-1):
        webpage += \
        "<br><textarea id='blogtext"+str(i)+"' name='blogtext"+str(i)+"' rows='2' cols='100'>"+bloglist[i]+"</textarea>"

    return make_response(webpage)

@app.route("/logout")
def logout():
    session.pop("username", None)
    return render_template("login.html")

# main driver function
if __name__ == "__main__":

        # run() method of Flask class runs the application
        # on the local development server.
        app.run(host="0.0.0.0",port=5005)
