from flask import Flask, make_response

# Initialize the Flask application
app = Flask(__name__)

# Define the route for the root URL
@app.route("/")
def hello_world():
    response = make_response("<p>Hello, World!</p>")
    response.status_code = 222
    return response

# Run the development server locally
if __name__ == "__main__":
    app.run(debug=True)
