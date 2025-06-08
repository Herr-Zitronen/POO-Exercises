# Biblioteca App

## Overview
The Biblioteca App is a library management system that allows users to manage a collection of physical and electronic books. Users can add new books, search for existing ones, and manage their borrowing status. The application is designed to be user-friendly and modular, making it easy to extend and maintain.

## Project Structure
The project is organized into the following directories and files:

```
biblioteca-app
├── src
│   ├── main.cpp               # Entry point of the application
│   ├── Cliente.h              # Header file for the Cliente class
│   ├── Cliente.cpp            # Implementation of the Cliente class
│   ├── Libro.h                # Header file for the Libro class
│   ├── Libro.cpp              # Implementation of the Libro class
│   ├── LibroFisico.h          # Header file for the LibroFisico class
│   ├── LibroFisico.cpp        # Implementation of the LibroFisico class
│   ├── LibroElectronico.h      # Header file for the LibroElectronico class
│   ├── LibroElectronico.cpp    # Implementation of the LibroElectronico class
│   ├── Biblioteca.h            # Header file for the Biblioteca class
│   ├── Biblioteca.cpp          # Implementation of the Biblioteca class
│   ├── Interfaz.h             # Header file for the Interfaz class
│   └── Interfaz.cpp           # Implementation of the Interfaz class
├── Makefile                   # Build instructions for the project
└── README.md                  # Documentation for the project
```

## Features
- **User Management**: Add and display users of the library.
- **Book Management**: Add physical and electronic books to the library's catalog.
- **Search Functionality**: Search for books by title.
- **Borrowing System**: Manage the borrowing status of books.

## Building the Project
To build the project, navigate to the project directory and run the following command:

```
make
```

This will compile the source files and create an executable.

## Running the Application
After building the project, you can run the application using the following command:

```
./biblioteca-app
```

## Contributing
Contributions to the project are welcome. Please feel free to submit issues or pull requests.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.