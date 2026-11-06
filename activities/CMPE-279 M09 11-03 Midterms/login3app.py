from flask import Flask, render_template, request, redirect, url_for, session, make_response

app = Flask(__name__)
app.secret_key = "your_secret_key"
print(type(app))
print(__name__)

# Define the route for the root URL
@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"

@app.route("/login")
def login():
    if "username" in session:
        return redirect(url_for("homepage"))
    return render_template("login.html")

@app.route("/login_action", methods=["POST", "GET"])
def login_action():
    if request.method == "POST":
        username = request.form["username"]
        password = request.form["password"]

        if username == "admin" and password == "password":
            session["username"] = username
            return redirect(url_for("homepage"))

    return render_template("login.html")

@app.route("/homepage")
def homepage():
    if "username" not in session:
        return render_template("login.html")
    webpage = '''
    <html>
    <head>
    <title>Home</title>
    </head>
    <body>
    <h1>Homepage of 
    Username:
    ''' + session["username"] + " <a href='" + url_for("logout") + "'>Logout</a></h1>"

    return webpage

@app.route("/logout")
def logout():
    session.pop("username", None)
    return render_template("login.html")

# main driver function
if __name__ == "__main__":
    # run() method of Flask class runs the application
    # on the local development server.
    app.run(port=5000)
