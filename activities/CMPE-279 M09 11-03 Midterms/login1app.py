from flask import Flask, render_template, request, redirect, url_for, session, make_response

app = Flask(__name__)
app.secret_key = "your_secret_key"

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

        # Dummy user validation
        if username == "admin" and password == "password":
            return "success<br>"
        else:
            return "failure<br>"

# main driver function
if __name__ == "__main__":
    # run() method of Flask class runs the application
    # on the local development server.
    app.run(host="0.0.0.0", port=5004)
