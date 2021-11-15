# Overview

I wanted to see how SQL worked and to see if it could be a functional method of storing data of any games that I make in the future. I This is done through SQLite and makes for a very effecient solution for storing key data like positions on a plane, user log in info and so on. I also think the biggest help this little adventure will serve is that I can now list that I am familiar with SQL and can work on it if needed, with a bit more knowledge though.

This program (though, still a work in progress) can create a SQL database locally and add and access its data through the SQLite source code (link below). How it works is that the SQLite source code is a .c file which I can include in my program, allowing me to make a database or connect to a local database through a directory address. I manipulate the database through SQLite's execute function. I can build SQL statements through functions that add to a query string to then be executed against the database

I wrote this program to learn SQL, and to see if it could help me in any of my current or future projects as a reliable and effecient means of storing data. Another reason is to assist me in any future job positions I might have or be trying to apply for.

[Software Demo Video](https://youtu.be/T58JfSaBrHw)

# Relational Database

SQLite, which creates a .db file

There are no specific lasting tables or structure to the database. The program allows you to make and edit your own without restriction

# Development Environment

SQLite

C++

Visue Studio

# Useful Websites

* [SQL W3School](https://www.w3schools.com/sql/)
* [SQLite Documentation for C/C++](https://www.sqlite.org/cintro.html)
* [SQLite Source-Code Download](https://www.sqlite.org/download.html)

# Future Work

* I need to work on making the other functions that assist in assembling a SQL statement
* Use the datebase for something more specific, maybe make a log in
* I like the open idea of no SQL injection protection because its more fun to practice SQL injection, but to learn as much as possible, I want to practice SQL injection mitigation
