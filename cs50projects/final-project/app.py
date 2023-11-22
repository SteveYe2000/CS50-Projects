from cs50 import SQL
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

client = SQL("sqlite:///client.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/about")
def about():
    return render_template("about.html")


@app.route("/services")
def services():
    return render_template("services.html")


@app.route("/book", methods=["GET", "POST"])
def book():
    if request.method == "POST":
        name = request.form.get("fullname")
        phone = request.form.get("phonenumber")
        email = request.form.get("email")
        message = request.form.get("message")
        client.execute("INSERT INTO clients (fullname, phonenumber, email, message) VALUES (?, ?, ?, ?)",
                       name, phone, email, message)
        return redirect("/register")
    else:
        return render_template("book.html")


@app.route("/register")
def register():
    name = client.execute("SELECT FullName FROM clients ORDER BY Time DESC LIMIT 1;")
    phone = client.execute("SELECT PhoneNumber FROM clients ORDER BY Time DESC LIMIT 1;")
    email = client.execute("SELECT Email FROM clients ORDER BY Time DESC LIMIT 1;")
    message = client.execute("SELECT Message FROM clients ORDER BY Time DESC LIMIT 1;")
    return render_template("register.html", name=name, phone=phone, email=email, message=message)
