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
    webpage = '''
    <html>
    <head>
    <title>Home</title>
    </head>
    <body>
    <h1>Homepage of 
    Username:
    ''' + session["username"] + "<br><br><a href='" + url_for("logout") + "'>Logout</a></h1>"
    # ''' + session["username"] + "<br><br> discount_rate:" + request.cookies.get('discount') + "<br><br><a href='" + url_for("logout") + "'>Logout</a></h1>"

    resp = make_response(webpage)
    # resp.set_cookie('discount','10')
    return resp

@app.route("/logout")
def logout():
    session.pop("username", None)
    response = make_response(render_template("login.html"))
    # Deleting a cookie forces its expiration immediately
    response.delete_cookie('GFG')

    return response
    # return render_template("login.html")

# main driver function
if __name__ == "__main__":
    # run() method of Flask class runs the application
    # on the local development server.
    app.run(host="0.0.0.0", port=5004)
