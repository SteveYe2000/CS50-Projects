import sqlite3
from flask import Flask, redirect, render_template, request

app = Flask(__name__)

client = sqlite3.connect("client.db", check_same_thread=False)
csr = client.cursor()

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
        csr.execute("INSERT INTO clients (fullname, phonenumber, email, message) VALUES (?, ?, ?, ?)",
                       (name, phone, email, message))
        client.commit()
        return redirect("/register")
    else:
        return render_template("book.html")


@app.route("/register")
def register():
    name = list(csr.execute("SELECT FullName FROM clients ORDER BY Time DESC LIMIT 1;"))
    phone = list(csr.execute("SELECT PhoneNumber FROM clients ORDER BY Time DESC LIMIT 1;"))
    email = list(csr.execute("SELECT Email FROM clients ORDER BY Time DESC LIMIT 1;"))
    message = list(csr.execute("SELECT Message FROM clients ORDER BY Time DESC LIMIT 1;"))
    return render_template("register.html", name=name, phone=phone, email=email, message=message)
