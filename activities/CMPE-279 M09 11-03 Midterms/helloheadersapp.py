from flask import Flask, request
import json

# Initialize the Flask application
app = Flask(__name__)

# Define the route for the root URL
@app.route("/")
def hello_world():
    webpage = "<p>Hello world!</p>"
    for header, value in request.headers.items():
        webpage = webpage + (f"{header}: {value}") + "<br>"
    webpage = webpage + "<br>" + request.headers["User-Agent"]
    return webpage

# Run the development server locally
if __name__ == "__main__":
    app.run(port=5000, debug=True)
