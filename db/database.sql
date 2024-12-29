

DROP DATABASE IF EXISTS `nexinch`;
CREATE DATABASE IF NOT EXISTS `nexinch`;

GRANT ALL PRIVILEGES ON auth.* TO 'nex_admin'@'localhost';

USE `nexinch`;

CREATE TABLE `departments` (
    `id` INT AUTO_INCREMENT PRIMARY KEY,
    `name` VARCHAR(100),
    `description` VARCHAR(255)
);

CREATE TABLE `users` (
    `id` INT AUTO_INCREMENT PRIMARY KEY,
    `first_name` VARCHAR(255),
    `last_name` VARCHAR(255),
    `username` VARCHAR(255),
    `phone` VARCHAR(15),
    `email` VARCHAR(255),
    `role` VARCHAR(50),
    `address` VARCHAR(255),
    `pob` VARCHAR(255),
    `dob` DATE,
    `password` VARCHAR(255),
    `is_admin` BOOLEAN DEFAULT FALSE,
    `department_id` INT,
    FOREIGN KEY (`department_id`) REFERENCES `departments`(`id`)
);



CREATE TABLE `attendance` (
    `id` INT AUTO_INCREMENT PRIMARY KEY,
    `date` DATE,
    `checkintime` TIME,
    `checkouttime` TIME,
    `name` VARCHAR(255)
);

-- Inserting departments
INSERT INTO `departments` (`name`, `description`) VALUES
('Finance', 'Handles financial matters'),
('IT', 'Handles information technology');

-- Inserting users
INSERT INTO `users` (`first_name`, `last_name`, `username`, `phone`, `email`, `role`, `address`, `pob`, `dob`, `password`, `is_admin`, `department_id`) VALUES
('John', 'Doe', 'johndoe', '1234567890', 'john.doe@example.com', 'Manager', '123 Main St', 'New York', '1990-01-01', 'password123', FALSE, 1),
('Jane', 'Doe', 'janedoe', '0987654321', 'jane.doe@example.com', 'Employee', '456 Elm St', 'Los Angeles', '1995-05-05', 'pass321word', FALSE, 2),
('Alice', 'Smith', 'asmith', '1112223333', 'alice.smith@example.com', 'Employee', '789 Oak St', 'Chicago', '1988-08-08', 'password456', FALSE, 1),
('Bob', 'Johnson', 'bjohnson', '4445556666', 'bob.johnson@example.com', 'Employee', '101 Pine St', 'Houston', '1980-12-12', 'pass987word', FALSE, 2),
('Eve', 'Taylor', 'etaylor', '7778889999', 'eve.taylor@example.com', 'Employee', '202 Maple St', 'Miami', '1999-03-03', 'password789', FALSE, 1),
('Michael', 'Brown', 'mbrown', '6667778888', 'michael.brown@example.com', 'Employee', '303 Cedar St', 'Seattle', '1992-10-10', 'pass654word', FALSE, 2),
('Emma', 'Wilson', 'ewilson', '5554443333', 'emma.wilson@example.com', 'Employee', '404 Birch St', 'San Francisco', '1993-07-07', 'password321', FALSE, 1),
('William', 'Martinez', 'wmartinez', '2223334444', 'william.martinez@example.com', 'Employee', '505 Spruce St', 'Boston', '1985-04-04', 'pass123word', FALSE, 2),
('Olivia', 'Garcia', 'ogarcia', '9998887777', 'olivia.garcia@example.com', 'Employee', '606 Walnut St', 'Dallas', '1975-06-06', 'passwordabc', FALSE, 1),
('James', 'Lopez', 'jlopez', '3332221111', 'james.lopez@example.com', 'Employee', '707 Pineapple St', 'Atlanta', '1970-09-09', 'passwxyzord', FALSE, 2);

-- Inserting attendance records
INSERT INTO `attendance` (`date`, `checkintime`, `checkouttime`, `name`) VALUES
('2024-03-22', '09:00:00', '17:00:00', 'John Doe'),
('2024-03-22', '09:15:00', '17:15:00', 'Jane Doe'),
('2024-03-22', '09:30:00', '17:30:00', 'Eve Taylor'),
('2024-03-22', '09:45:00', '17:45:00', 'Micheal Brown'),
('2024-03-22', '10:00:00', '18:00:00', 'Emma Wilson');
