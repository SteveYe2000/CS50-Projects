# Ansel Adams (Interactive Website)
#### Video Demo:  [Watch it here!](https://drive.google.com/file/d/1fR1LiaQrni7R8iJVcCj3j4pZONYLEWfi/view?usp=sharing).
#### Description: This project is about building an interactive website for a photography company called Ansel Adams.

## Languages
This project includes the applications of popular web development langugaes such as JavaScript, CSS, HTML, Python, Flask and SQL.

# Project Contents
Inside the main directory called final-project, there are two main directories with each name being called static and templates. There are also one app.py file which is to run Flask, one client.db file which is to setup the database using SQL and one README.md file for the explaination of the project itself.

## app.py
This is a Python file that consist of programs to run both Flask web framework and Python scripts to ensure the webpage is running smoothly when launched. This includes adding routes to different web pages and responing correctly to different requests from the clients' side. In addition, this file is also linked to SQL for setting up database, retreiving data and displaying them on the templates such as register.html. Please refer to video demo for more infomation.

## client.db
This is a SQL database that is being set up using Python and another web framework called Flask. It contains data from clients who wish to make booking and get in touch. Personal information such as emails, phone numbers, names and notes are all residing in this file.

## Static Directory
In this directory, there are three sub-directories and they are named css-sheets, js-files and resources. As their names suggest, the css-sheets directory consists of css files for styling the web pages. The js-files directory contains JavaScript files for the functionalities of the buttons and links on the web pages. Lastly, the resources directory composes of beautiful and styling images for the decorations of the web pages.

### CSS-Sheets Directory
Contains styling sheets for each web pages. There are two css files inside this folder. File named styles.css is used for styling the index.html which resides within the templates directory. Another file named stylescommon.css is used for decorating all the other pages such as about.html, book.html, register.html and services.html that are also inside the template folder.

### Js-Files Directory
As its name suggests, there are four JavaScript files inside this folder. The book_btn.js file is used for making buttons work inside the book.html page. The buttons.js file is used for the functionalities of every other buttons inside the index.html page. In the same essence, both registers_btn.js and services_btn.js serves their functionalies for register.html and services.html.

## Templates Directory
This folder contains all the necessary HTML pages that are required to build the website. With each files within the directory named after its purposes, it should be convinent to grasp breif knowledge of what each HTML files does. For example, index.html is the main page of the website as its name suggests. Similarly, about.html, layout.html, book.html and etc are also names after its functionalities. Please refer to video demo for more infomation.
