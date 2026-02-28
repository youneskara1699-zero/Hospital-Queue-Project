🏥 Hospital Queue Management System (C++)

📌 Overview


This project is a C++ console application that simulates a hospital patient queue system using FIFO (First In, First Out) logic.
It models how patients are registered, queued, served, and tracked in a hospital department.

The project uses C++ STL containers (queue, stack) and applies object-oriented programming principles.

⚙️ Features


Register patients with automatic ticket IDs

Track total, served, and waiting patients

Calculate estimated serving time per patient

Display patients from left-to-right (FIFO)

Display patients from right-to-left (reverse order)

Serve the next patient in the queue

Display detailed ticket information for all waiting patients

🧱 Core Concepts Used


Object-Oriented Programming (OOP)

Encapsulation

STL queue and stack

FIFO queue behavior

Time and date handling

Console-based simulation

🗂️ Project Structure


HospitalQueue class

Manages patient registration and serving

Stores patient tickets in a queue

PatientTicket structure

Holds ticket ID, date/time, waiting count, and serve time

main()

Demonstrates system usage

▶️ How It Works


A hospital department is created with an average serve time

Patients are registered and added to the queue

Each patient receives a unique ticket

The system tracks waiting and served patients

Patients are served in the order they arrive

🧪 Example Usage


Register multiple patients

Print queue information

Display patients in normal and reverse order

Serve a patient

View updated queue status

🛠️ Requirements


C++17 or later

Any C++ compiler (GCC, Clang, MSVC)

Console/Terminal environment


🎯 Learning Objectives

Understand real-world queue systems

Practice STL containers

Learn safe iteration over queues

Apply clean OOP design in C++
