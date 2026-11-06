from flask import Flask

# Initialize the Flask application
app = Flask(__name__)

# Define the route for the root URL
@app.route("/")
def hello_world():
    return "<p>Hello, World!</p>"

# Run the development server locally
if __name__ == "__main__":
    app.run(port=5000, debug=True)
